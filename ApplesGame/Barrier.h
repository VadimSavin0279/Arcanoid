#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"

namespace ApplesGame
{
	struct Barrier
	{
		Position2D barriersPositions;
		sf::Sprite sprite;
	};

	class Game;

	void InitBarrier(Barrier& barrier, const sf::Texture& texture);

	void SetBarrierPosition(Barrier& barrier, const Position2D& position);

	Rectangle GetBarrierCollider(const Barrier& barier);

	void DrawBarrier(Barrier& barrier, sf::RenderWindow& window);
}