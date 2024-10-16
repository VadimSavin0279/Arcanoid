#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <assert.h>
#include "Constants.h"
#include "GameStateData.h"

namespace ApplesGame
{
	class GameStateExitDialogData : public GameStateData
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
			Init();
		}

		void Init() override;
		void HandleWindowEvent(const sf::Event& event) override;
		void Update(float timeDelta) override;
		void Draw(sf::RenderWindow& window) override;
	};
}