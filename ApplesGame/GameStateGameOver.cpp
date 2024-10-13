#include "GameStateGameOver.h"
#include <assert.h>
#include "Game.h"
#include "Application.hpp"

namespace ApplesGame
{
	void GameStateGameOverData::Init()
	{
		assert(font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		timeSinceGameOver = 0.f;

		gameOverText.setFont(font);
		gameOverText.setCharacterSize(48);
		gameOverText.setStyle(sf::Text::Bold);
		gameOverText.setFillColor(sf::Color::Red);
		gameOverText.setString("GAME OVER");
		gameOverText.setOrigin(GetItemOrigin(gameOverText, { 0.5f, 0.5f }));

		hintText.setFont(font);
		hintText.setCharacterSize(24);
		hintText.setFillColor(sf::Color::White);
		hintText.setString("Press Space to restart");
		hintText.setOrigin(GetItemOrigin(hintText, { 0.5f, 1.f }));
	}

	void GameStateGameOverData::HandleWindowEvent(const sf::Event& event)
	{
		Game& game = Application::Instance().GetGame();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				game.SwitchGameState(GameStateType::Playing);
			}
			else if (event.key.code == sf::Keyboard::Escape)
			{
				game.SwitchGameState(GameStateType::MainMenu);
			}
		}
	}

	void GameStateGameOverData::Update(float timeDelta)
	{
		timeSinceGameOver += timeDelta;

		sf::Color gameOverTextColor = (int)timeSinceGameOver % 2 ? sf::Color::Red : sf::Color::Yellow;
		gameOverText.setFillColor(gameOverTextColor);
	}

	void GameStateGameOverData::Draw(sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = window.getView().getSize();

		gameOverText.setPosition(viewSize.x / 2.f, viewSize.y / 2.f);
		window.draw(gameOverText);

		hintText.setPosition(viewSize.x / 2.f, viewSize.y - 10.f);
		window.draw(hintText);
	}
}
