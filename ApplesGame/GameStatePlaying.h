#pragma once
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Player.h"

namespace ApplesGame
{
	class GameStatePlayingData
	{
	private:
		sf::Font font;

		Player player;
		Ball ball;

		sf::Texture playerTexture;

	public:
		GameStatePlayingData()
		{
			InitGameStatePlaying();
		}

		void InitGameStatePlaying();
		void ShutdownGameStatePlaying();
		void HandleGameStatePlayingWindowEvent(const sf::Event& event);
		void HandleGame();
		void UpdateGameStatePlaying(float timeDelta);
		void DrawGameStatePlaying(sf::RenderWindow& window);

		bool isGameOver(const Ball& ball, const Player& player);
		void ChangeVelocityVectorAfterColissionWithPlayer(const Player& player, Ball& ball, const Orientation& orientation);
		void ChangeVelocityVectorAfterColissionWithObjects(Ball& ball, const Orientation& orientation);
	};
}