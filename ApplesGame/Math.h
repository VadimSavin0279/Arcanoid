#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
	class Sprite;
}

namespace ApplesGame
{
	struct Vector2D
	{
		float x = 0;
		float y = 0;

		float GetLenght() const
		{
			return (float)sqrt(pow(x, 2) + pow(y, 2));
		}

		Vector2D friend operator+(const Vector2D lhs, const Vector2D rhs)
		{
			return { lhs.x + rhs.x, lhs.y + rhs.y };
		}
	};

	using Position2D = Vector2D;

	struct Rectangle
	{
		Position2D position;
		Vector2D size;
	};

	struct Circle
	{
		Position2D center;
		float radius; 
	};

	enum class Orientation
	{
		Horizontal, Vertical
	};

	enum class Alignment
	{
		Min, Middle, Max 
	};

	Position2D GetRandomPositionInRectangle(const Rectangle& rect);

	bool hasCollideIn(const Rectangle& rect1, const Rectangle& rect2);

	bool hasCollideOut(const Rectangle& rect1, const Circle& circle2);

	Orientation FindEdgeOfColission(const Rectangle& rect, const Circle& circle);

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);

	sf::Vector2f GetSpriteScale(const sf::Sprite& sprite, const Vector2D& desiredSize);

	sf::Vector2f GetItemOrigin(const sf::Text& text, const sf::Vector2f& relativePosition);

	void DrawItemsList(
		sf::RenderWindow& window, 
		const std::vector<sf::Text*>& items, 
		float spacing, 
		Orientation orientation, 
		Alignment alignment, 
		const sf::Vector2f& position, 
		const sf::Vector2f& origin
	);
}