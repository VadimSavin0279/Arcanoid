#include "Block.h"

namespace ApplesGame
{

	void Block::SetBlockPosition(const Position2D& position)
	{
		blockPosition = position;
	}

	Position2D Block::GetBlockPosition() const
	{
		return blockPosition;
	}

	Rectangle Block::GetBlockCollider() const 
	{
		return { blockPosition.x - BLOCK_SIZE / 2.f, blockPosition.y - BLOCK_SIZE / 2.f, BLOCK_SIZE, BLOCK_SIZE };
	}

	void Block::Draw(sf::RenderWindow& window)
	{
		if (!isDead)
		{
			shape.setPosition(blockPosition.x, blockPosition.y);
			window.draw(shape);
		}
	}

	void Block::UpdateBlock(const float deltaTime)
	{

	}
	
}