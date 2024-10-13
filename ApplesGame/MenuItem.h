#pragma once
#include "SFML/Graphics.hpp"
#include "Math.h"
#include <list>

namespace ApplesGame
{
	class MenuItem
	{
	private:
		Orientation childrenOrientation = Orientation::Vertical;
		Alignment childrenAlignment = Alignment::Min;
		float childrenSpacing = 0;

		sf::Color selectedColor = sf::Color::Yellow;
		sf::Color deselectedColor = sf::Color::White;

		bool isEnabled = true;
		std::vector<MenuItem*> children;

		MenuItem* parent = nullptr;
	public:
		sf::Text text;
		sf::Text hintText;

	public:
		void InitMenuItem();

		bool IsEnabled() const;

		std::vector<MenuItem*>& GetChildren();
		void SetChildren(std::vector<MenuItem*> children);

		MenuItem* GetParent();
		void SetParent(MenuItem* parent);

		sf::Text* GetText();

		sf::Color GetSelectedColor() const;

		sf::Color GetDeselectedColor() const;

		Orientation GetChildrenOrientation() const;

		Alignment GetChildrenAlignment() const;

		float GetChildrenSpacing() const;

		void SetChildrenOrientation(Orientation orientation)
		{
			childrenOrientation = orientation;
		}

		void SetChildrenAlignment(Alignment aligment)
		{
			childrenAlignment = aligment;
		}

		void SetChildrenSpacing(float spacing)
		{
			childrenSpacing = spacing;
		}
	};
}