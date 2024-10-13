#pragma once
#include "Math.h"
#include "Constants.h"

namespace ApplesGame
{
	enum class PlayerDirection
	{
		None = 0, Left, Right
	};

	class Player
	{
	private:
		Position2D playerPosition = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f };

		float playerSpeed = 400;

		PlayerDirection playerDirection = PlayerDirection::Left;

		sf::RectangleShape shape;

	public:
		Player()
		{
			shape.setSize({ PLAYER_WIDTH, PLAYER_HEIGHT });
			shape.setFillColor(sf::Color::Blue);
			shape.setOrigin({ PLAYER_WIDTH / 2 , PLAYER_HEIGHT / 2 });
		}

		void SetPlayerPosition(const Position2D& position);
		Position2D GetPlayerPosition() const;

		void SetPlayerDirection(const PlayerDirection direction);
		PlayerDirection GetPlayerDirection() const;

		void SetPlayerSpeed(const float speed);
		float GetPlayerSpeed() const;

		Rectangle GetPlayerCollider() const;

		void DrawPlayer(sf::RenderWindow& window);

		void UpdatePlayer(const float deltaTime);
	};
}