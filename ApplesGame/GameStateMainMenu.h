#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

namespace ApplesGame
{
	class GameStateMainMenuData
	{
	private:
		sf::Font font;

		MenuItem startGameItem;
		MenuItem exitGameItem;

		MenuItem yesItem;
		MenuItem noItem;

		Menu menu;

	public:
		GameStateMainMenuData()
		{
			InitGameStateMainMenu();
		}

		void InitGameStateMainMenu();
		void ShutdownGameStateMainMenu();
		void HandleGameStateMainMenuWindowEvent(const sf::Event& event);
		void UpdateGameStateMainMenu(float timeDelta);
		void DrawGameStateMainMenu(sf::RenderWindow& window);
	};
}