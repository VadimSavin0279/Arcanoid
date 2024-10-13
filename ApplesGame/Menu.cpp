#include "Menu.h"
#include <assert.h>

namespace ApplesGame
{
	void Menu::SelectMenuItem(MenuItem* item)
	{
		assert(item != &rootItem);

		if (selectedItem == item)
		{
			return;
		}

		if (item && !item->IsEnabled())
		{
			return;
		}

		if (selectedItem)
		{
			selectedItem->GetText()->setFillColor(selectedItem->GetDeselectedColor());
		}

		selectedItem = item;

		if (selectedItem)
		{
			selectedItem->GetText()->setFillColor(selectedItem->GetSelectedColor());
		}
	}

	bool Menu::SelectPreviousMenuItem()
	{
		if (selectedItem)
		{
			MenuItem* parent = selectedItem->GetParent();
			assert(parent);

			auto it = std::find(parent->GetChildren().begin(), parent->GetChildren().end(), selectedItem);
			if (it != parent->GetChildren().begin())
			{
				SelectMenuItem(*(--it));
				return true;
			}
		}

		return false;
	}

	bool Menu::SelectNextMenuItem()
	{
		if (selectedItem)
		{
			MenuItem* parent = selectedItem->GetParent();
			assert(parent);
			auto it = std::find(parent->GetChildren().begin(), parent->GetChildren().end(), selectedItem);
			if (it != parent->GetChildren().end() - 1)
			{
				SelectMenuItem(*(++it));
				return true;
			}
		}
		return false;
	}

	bool Menu::ExpandSelectedItem()
	{
		if (selectedItem && selectedItem->GetChildren().size() > 0)
		{
			SelectMenuItem(selectedItem->GetChildren().front());
			return true;
		}

		return false;
	}

	bool Menu::CollapseSelectedItem()
	{
		if (selectedItem && selectedItem->GetParent() && selectedItem->GetParent() != &rootItem)
		{
			SelectMenuItem(selectedItem->GetParent());
			return true;
		}
		return false;
	}

	MenuItem* Menu::GetCurrentMenuContext()
	{
		return selectedItem ? selectedItem->GetParent() : &rootItem;
	}

	void Menu::DrawMenu(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f origin)
	{
		MenuItem* expandedItem = GetCurrentMenuContext();

		std::vector<sf::Text*> texts;
		texts.reserve(expandedItem->GetChildren().size());
		for (auto& child : expandedItem->GetChildren())
		{
			if (child->IsEnabled())
			{
				texts.push_back((child->GetText()));
			}
		}

		DrawItemsList(window, texts, expandedItem->GetChildrenSpacing(), expandedItem->GetChildrenOrientation(), expandedItem->GetChildrenAlignment(), position, origin);
	}

}