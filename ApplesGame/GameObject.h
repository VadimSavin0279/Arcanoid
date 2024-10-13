#pragma once
#include "SFML/Graphics.hpp"
#include "Math.h"

namespace ApplesGame
{
	class GameObject
	{
	public:
		virtual void Draw(sf::RenderWindow& window) = 0;
		virtual ~GameObject() = default;
	};
}