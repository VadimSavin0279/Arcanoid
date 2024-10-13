#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "GameStateData.h"

namespace ApplesGame
{
	class GameStateMainMenuData : public GameStateData
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
			Init();
		}

		void Init() override;
		void HandleWindowEvent(const sf::Event& event) override;
		void Update(float timeDelta) override;
		void Draw(sf::RenderWindow& window) override;
	};
}