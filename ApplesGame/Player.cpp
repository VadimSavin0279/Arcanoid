#include "Player.h"

namespace ApplesGame
{
	void Player::SetPlayerPosition(const Position2D& position)
	{
		playerPosition = position;
	}

	Position2D Player::GetPlayerPosition() const
	{
		return playerPosition;
	}

	void Player::SetPlayerDirection(const PlayerDirection direction) {
		playerDirection = direction;
	}

    PlayerDirection Player::GetPlayerDirection() const
	{
		return playerDirection;
	}

	void Player::SetPlayerSpeed(const float speed) {
		playerSpeed = speed;
	}

	inline float Player::GetPlayerSpeed() const
	{
		return playerSpeed;
	}

	Rectangle Player::GetPlayerCollider() const
	{
		return { playerPosition.x - PLAYER_WIDTH / 2, playerPosition.y - PLAYER_HEIGHT / 2, PLAYER_WIDTH, PLAYER_HEIGHT};
	}

	void Player::DrawPlayer(sf::RenderWindow& window)
	{
		shape.setPosition(playerPosition.x, playerPosition.y);
		window.draw(shape);
	}

	void Player::UpdatePlayer(const float deltaTime)
	{
		switch (playerDirection)
		{
		case PlayerDirection::Left:
			playerPosition.x -= playerSpeed * deltaTime;
			break;
		case PlayerDirection::Right:
			playerPosition.x += playerSpeed * deltaTime;
			break;
		default:
			break;
		}
	}
}
