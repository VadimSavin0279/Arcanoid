#pragma once
#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include "Constants.h"


namespace ApplesGame
{
	class Block : public GameObject
	{
	private:
		Position2D blockPosition;

		sf::RectangleShape shape;

	public:
		Block()
		{
			shape.setSize({ BLOCK_SIZE, BLOCK_SIZE });
			shape.setFillColor(sf::Color::Yellow);
			shape.setOrigin({ BLOCK_SIZE / 2 , BLOCK_SIZE / 2 });
		}

		void SetBlockPosition(const Position2D& position);
		Position2D GetBlockPosition() const;

		Rectangle GetBlockCollider() const;

		void Draw(sf::RenderWindow& window);

		void UpdateBlock(const float deltaTime);

		bool isDead = false;
	};
}