#include "Barrier.h"
#include "Game.h"

namespace ApplesGame
{
	void InitBarrier(Barrier& barrier, const sf::Texture& texture)
	{
		barrier.sprite.setTexture(texture);
		SetSpriteSize(barrier.sprite, BARRIER_SIZE, BARRIER_SIZE);
		SetSpriteRelativeOrigin(barrier.sprite, 0.5f, 0.5f);
	}

	void SetBarrierPosition(Barrier& barrier, const Position2D& position)
	{
		barrier.barriersPositions = position;
	}

	Rectangle GetBarrierCollider(const Barrier& barier)
	{
		return { barier.barriersPositions.x - BARRIER_SIZE / 2.f, barier.barriersPositions.y - BARRIER_SIZE / 2.f, BARRIER_SIZE, BARRIER_SIZE };
	}

	void DrawBarrier(Barrier& barrier, sf::RenderWindow& window)
	{
		barrier.sprite.setPosition(barrier.barriersPositions.x, barrier.barriersPositions.y);
		window.draw(barrier.sprite);
	}
}
