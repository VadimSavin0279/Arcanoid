#pragma once
#include "SFML/Graphics.hpp"
#include "Math.h"
#include <list>
#include "MenuItem.h"

namespace ApplesGame
{
	class Menu
	{
	private:
		MenuItem rootItem;
		MenuItem* selectedItem = nullptr;
	public:
		void SelectMenuItem(MenuItem* item);
		bool SelectPreviousMenuItem();
		bool SelectNextMenuItem();
		bool ExpandSelectedItem();
		bool CollapseSelectedItem();

		MenuItem* GetCurrentMenuContext();

		void DrawMenu(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f origin);

		MenuItem* GetRootItem()
		{
			return &rootItem;
		}

		MenuItem* GetSelectedItem()
		{
			return selectedItem;
		}
	};
}