#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <assert.h>
#include "Constants.h"

namespace ApplesGame
{
	class GameStateExitDialogData
	{
	private:
		sf::Font font;

		MenuItem continueGameItem;
		MenuItem exitGameItem;
		MenuItem yesItem;
		MenuItem noItem;

		Menu menu;

		sf::RectangleShape background;

	public:
		GameStateExitDialogData()
		{
			InitGameStateExitDialog();
		}

		void InitGameStateExitDialog();
		void ShutdownGameStateExitDialog();
		void HandleGameStateExitDialogWindowEvent(const sf::Event& event);
		void UpdateGameStateExitDialog(float timeDelta);
		void DrawGameStateExitDialog(sf::RenderWindow& window);
	};
}