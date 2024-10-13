#include "GameStatePlaying.h"
#include <assert.h>
#include <iostream>
#include "Application.hpp"

namespace ApplesGame
{
	void GameStatePlayingData::InitGameStatePlaying()
	{
		Game& game = Application::Instance().GetGame();
		// set textures
		assert(playerTexture.loadFromFile(RESOURCES_PATH + "Player.png"));
		assert(font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		ball.SetBallPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });

		player.SetPlayerPosition({ game.GetScreenRect().size.x / 2.f, game.GetScreenRect().size.y * 0.9f});
		player.SetPlayerSpeed(INITIAL_SPEED);
		player.SetPlayerDirection(PlayerDirection::Right);
	}

	void GameStatePlayingData::ShutdownGameStatePlaying()
	{
		// We dont need to free resources here, because they will be freed automatically
	}

	void GameStatePlayingData::HandleGameStatePlayingWindowEvent(const sf::Event& event)
	{
		Game& game = Application::Instance().GetGame();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				game.PushGameState(GameStateType::ExitDialog, false);
			}
		}
	}

	void GameStatePlayingData::HandleGame()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.SetPlayerDirection(PlayerDirection::Left);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.SetPlayerDirection(PlayerDirection::Right);
		}
		else
		{
			player.SetPlayerDirection(PlayerDirection::None);
		}
	}

	void GameStatePlayingData::UpdateGameStatePlaying(float timeDelta)
	{
		Game& game = Application::Instance().GetGame();

		HandleGame();
		player.UpdatePlayer(timeDelta);

		ball.UpdateBall(timeDelta);

		if (hasCollideOut(player.GetPlayerCollider(), ball.GetBallCollider()))
		{
			Orientation collideOrient = FindEdgeOfColission(player.GetPlayerCollider(), ball.GetBallCollider());
			ChangeVelocityVectorAfterColissionWithPlayer(player, ball, collideOrient);
		}

		Circle ballShape = ball.GetBallCollider();

		if (hasCollideIn(game.GetScreenRect(), 
			{ballShape.center.x - BALL_SIZE / 2, ballShape.center.y - BALL_SIZE / 2, BALL_SIZE, BALL_SIZE}))
		{
			if (isGameOver(ball, player))
			{
				game.PushGameState(GameStateType::GameOver, false);
			}
			else {
				ChangeVelocityVectorAfterColissionWithObjects(ball, FindEdgeOfColission(game.GetScreenRect(), ball.GetBallCollider()));
			}
		}

		if (hasCollideIn(game.GetScreenRect(), player.GetPlayerCollider()))
		{
			player.SetPlayerSpeed(0);
			Position2D currentPosition = player.GetPlayerPosition();
			
			float newPosition = player.GetPlayerDirection() == PlayerDirection::Left ?
				currentPosition.x - INITIAL_SPEED * timeDelta : 
				currentPosition.x + INITIAL_SPEED * timeDelta;
			
			if (!hasCollideIn(game.GetScreenRect(), {newPosition - PLAYER_WIDTH / 2, currentPosition.y - PLAYER_HEIGHT / 2, PLAYER_WIDTH, PLAYER_HEIGHT}))
			{

				player.SetPlayerSpeed(INITIAL_SPEED);
			}
		}
		else {
			player.SetPlayerSpeed(INITIAL_SPEED);
		}
	}

	void GameStatePlayingData::ChangeVelocityVectorAfterColissionWithObjects(Ball& ball, const Orientation& orientation)
	{
		Vector2D ballVelocity = ball.GetVelocityVector();
		switch (orientation)
		{
		case Orientation::Horizontal:
			ball.SetVelocityVector({ ballVelocity.x, ballVelocity.y * -1 });
			break;
		case Orientation::Vertical:
			ball.SetVelocityVector({ ballVelocity.x * -1, ballVelocity.y });
			break;
		default:
			break;
		}
	}

	bool GameStatePlayingData::isGameOver(const Ball& ball, const Player& player)
	{
		return ball.GetBallPosition().y > player.GetPlayerPosition().y;
	}

	void GameStatePlayingData::ChangeVelocityVectorAfterColissionWithPlayer(const Player& player, Ball& ball, const Orientation& orientation)
	{
		switch (orientation)
		{
		case Orientation::Horizontal:
		{
			Position2D playerPosition = player.GetPlayerPosition();
			Vector2D ballVelocityVector = ball.GetVelocityVector();
			float lenghtBallVelocityVector = ballVelocityVector.GetLenght();
			Position2D ballPosition = ball.GetBallPosition();

			float multiplierOfAngle = 1 - abs(float(playerPosition.x - ballPosition.x)) / PLAYER_WIDTH;
			float y = multiplierOfAngle * INITIAL_SPEED;
			float x = (float)sqrt(pow(lenghtBallVelocityVector, 2) - pow(y, 2));

			x = ballPosition.x > playerPosition.x ? x : -x;
			y = ballVelocityVector.y < 0 ? y : -y;
			
			ball.SetVelocityVector({ x, y });
			break;
		}
		case Orientation::Vertical:
			break;
		default:
			break;
		}
	}

	void GameStatePlayingData::DrawGameStatePlaying(sf::RenderWindow& window)
	{
		player.DrawPlayer(window);
		ball.DrawBall(window);
	}
}
