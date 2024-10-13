#pragma once

#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "GameStateData.h"
#include "Menu.h"

namespace ApplesGame
{
	class GameStateWinData : public GameStateData
	{
	private:
		sf::Font font;

		MenuItem yesItem;
		MenuItem noItem;

		Menu menu;

		sf::RectangleShape background;

	public:
		GameStateWinData()
		{
			Init();
		}

		void Init() override;
		void HandleWindowEvent(const sf::Event& event) override;
		void Update(float timeDelta) override;
		void Draw(sf::RenderWindow& window) override;
	};
}