#include "Ball.h"

namespace ApplesGame 
{
	void Ball::SetBallPosition(const Position2D& position)
	{
		ballPosition = position;
	}

	Circle Ball::GetBallCollider() const
	{
		return { ballPosition, BALL_SIZE / 2.f };
	}

	void Ball::DrawBall(sf::RenderWindow& window)
	{
		shape.setPosition(ballPosition.x, ballPosition.y);
		window.draw(shape);
	}

	void Ball::UpdateBall(const float deltaTime)
	{
		ballPosition.x += velocityVector.x * deltaTime;
		ballPosition.y += velocityVector.y * deltaTime;
	}

	Vector2D Ball::GetVelocityVector() const
	{
		return velocityVector;
	}

	void Ball::SetVelocityVector(const Vector2D& vector)
	{
		velocityVector = vector;
	}

	Position2D Ball::GetBallPosition() const
	{
		return ballPosition;
	}
}
