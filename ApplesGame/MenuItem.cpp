#include "MenuItem.h"
#include <assert.h>

namespace ApplesGame
{
	void MenuItem::InitMenuItem()
	{
		for (auto& child : children)
		{
			child->parent = this;
		}
	}

	bool MenuItem::IsEnabled() const
	{
		return isEnabled;
	}

	std::vector<MenuItem*>& MenuItem::GetChildren()
	{
		return children;
	}

	void MenuItem::SetChildren(std::vector<MenuItem*> children)
	{
		this->children = children;
	}

	MenuItem* MenuItem::GetParent()
	{
		return parent;
	}

	void MenuItem::SetParent(MenuItem* parent)
	{
		this->parent = parent;
	}

	sf::Text* MenuItem::GetText()
	{
		return &text;
	}

	sf::Color MenuItem::GetSelectedColor() const
	{
		return selectedColor;
	}

	sf::Color MenuItem::GetDeselectedColor() const
	{
		return deselectedColor;
	}

	Orientation MenuItem::GetChildrenOrientation() const
	{
		return childrenOrientation;
	}

	Alignment MenuItem::GetChildrenAlignment() const
	{
		return childrenAlignment;
	}

	float MenuItem::GetChildrenSpacing() const
	{
		return childrenSpacing;
	}
}