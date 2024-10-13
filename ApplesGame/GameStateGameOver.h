#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "GameStateData.h"

namespace ApplesGame
{
	class GameStateGameOverData : public GameStateData
	{
	private:
		sf::Font font;

		float timeSinceGameOver = 0.f;

		sf::Text gameOverText;
		sf::Text hintText;

	public:
		GameStateGameOverData()
		{
			Init();
		}

		void Init() override;
		void HandleWindowEvent(const sf::Event& event) override;
		void Update(float timeDelta) override;
		void Draw(sf::RenderWindow& window) override;
	};
}