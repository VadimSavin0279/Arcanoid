#include "GameStateWin.h"
#include <assert.h>
#include "Game.h"
#include "Application.hpp"

namespace ApplesGame
{
	void GameStateWinData::Init()
	{
		assert(font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		menu.GetRootItem()->hintText.setFont(font);
		menu.GetRootItem()->hintText.setString("Win! Restart Game?");

		menu.GetRootItem()->hintText.setCharacterSize(48);
		menu.GetRootItem()->hintText.setFillColor(sf::Color::Red);
		menu.GetRootItem()->SetChildrenOrientation(Orientation::Horizontal);
		menu.GetRootItem()->SetChildrenAlignment(Alignment::Middle);
		menu.GetRootItem()->SetChildrenSpacing(10.f);
		menu.GetRootItem()->SetChildren({ &yesItem, &noItem });
		menu.GetRootItem()->InitMenuItem();

		yesItem.text.setString("Yes");
		yesItem.text.setFont(font);
		yesItem.text.setCharacterSize(24);

		noItem.text.setString("No");
		noItem.text.setFont(font);
		noItem.text.setCharacterSize(24);

		menu.SelectMenuItem(&yesItem);

		background.setFillColor(sf::Color(0, 0, 0, 128)); // Semi-transparent black
	}

	void GameStateWinData::HandleWindowEvent(const sf::Event& event)
	{
		Game& game = Application::Instance().GetGame();

		if (!menu.GetSelectedItem())
		{
			return;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				menu.CollapseSelectedItem();
			}
			else if (event.key.code == sf::Keyboard::Enter)
			{
				if (menu.GetSelectedItem() == &yesItem)
				{
					game.SwitchGameState(GameStateType::Playing);
				}
				else if (menu.GetSelectedItem() == &noItem)
				{
					game.SwitchGameState(GameStateType::MainMenu);
				}
				else
				{
					menu.ExpandSelectedItem();
				}
			}

			Orientation orientation = menu.GetSelectedItem()->GetParent()->GetChildrenOrientation();
			if (orientation == Orientation::Vertical && event.key.code == sf::Keyboard::Up ||
				orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::Left)
			{
				menu.SelectPreviousMenuItem();
			}
			else if (orientation == Orientation::Vertical && event.key.code == sf::Keyboard::Down ||
				orientation == Orientation::Horizontal && event.key.code == sf::Keyboard::Right)
			{
				menu.SelectNextMenuItem();
			}
		}
	}

	void GameStateWinData::Update(float timeDelta)
	{

	}

	void GameStateWinData::Draw(sf::RenderWindow& window)
	{

		sf::Vector2f windowSize = (sf::Vector2f)window.getSize();

		background.setSize(windowSize);
		window.draw(background);

		sf::Text* hintText = &menu.GetCurrentMenuContext()->hintText;
		hintText->setOrigin(GetItemOrigin(*hintText, { 0.5f, 0.f }));
		hintText->setPosition(windowSize.x / 2.f, 150.f);
		window.draw(*hintText);

		menu.DrawMenu(window, windowSize / 2.f, { 0.5f, 0.f });
	}
}