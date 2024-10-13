#pragma once
#include "Math.h"
#include "Constants.h"
#include "GameObject.h"

namespace ApplesGame
{
	class Ball : public GameObject
	{
	public:
		Ball() {
			shape.setFillColor(sf::Color::Blue);
			shape.setRadius(BALL_SIZE / 2);
			shape.setOrigin({ BALL_SIZE / 2 , BALL_SIZE / 2 });
		}

		void SetBallPosition(const Position2D& position);

		Circle GetBallCollider() const;

		void Draw(sf::RenderWindow& window);

		void UpdateBall(const float deltaTime);

		Vector2D GetVelocityVector() const;

		void SetVelocityVector(const Vector2D& vector);

		Position2D GetBallPosition() const;

	private:
		Position2D ballPosition;
		sf::CircleShape shape;
		Vector2D velocityVector = { 0, INITIAL_SPEED };
	};
}