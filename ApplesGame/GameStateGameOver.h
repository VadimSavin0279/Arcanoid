#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"

namespace ApplesGame
{
	class GameStateGameOverData
	{
	private:
		sf::Font font;

		float timeSinceGameOver = 0.f;

		sf::Text gameOverText;
		sf::Text hintText;

	public:
		GameStateGameOverData()
		{
			InitGameStateGameOver();
		}

		void InitGameStateGameOver();
		void ShutdownGameStateGameOver();
		void HandleGameStateGameOverWindowEvent(const sf::Event& event);
		void UpdateGameStateGameOver(float timeDelta);
		void DrawGameStateGameOver(sf::RenderWindow& window);
	};
}