#include "GameStateMainMenu.h"
#include <assert.h>
#include "Application.hpp"

namespace ApplesGame
{
	void GameStateMainMenuData::InitGameStateMainMenu()
	{
		assert(font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		menu.GetRootItem()->hintText.setString("Apples Game");
		menu.GetRootItem()->hintText.setFont(font);
		menu.GetRootItem()->hintText.setCharacterSize(48);
		menu.GetRootItem()->hintText.setFillColor(sf::Color::Red);
		menu.GetRootItem()->SetChildrenOrientation(Orientation::Vertical);
		menu.GetRootItem()->SetChildrenAlignment(Alignment::Middle);
		menu.GetRootItem()->SetChildrenSpacing(10.f);
		menu.GetRootItem()->SetChildren({ &startGameItem, &exitGameItem });
		menu.GetRootItem()->InitMenuItem();

		startGameItem.text.setString("Start Game");
		startGameItem.text.setFont(font);
		startGameItem.text.setCharacterSize(24);

		exitGameItem.text.setString("Exit Game");
		exitGameItem.text.setFont(font);
		exitGameItem.text.setCharacterSize(24);
		exitGameItem.hintText.setString("Are you sure?");
		exitGameItem.hintText.setFont(font);
		exitGameItem.hintText.setCharacterSize(48);
		exitGameItem.hintText.setFillColor(sf::Color::Red);
		exitGameItem.SetChildrenOrientation(Orientation::Horizontal);
		exitGameItem.SetChildrenAlignment(Alignment::Middle);
		exitGameItem.SetChildrenSpacing(10.f);
		exitGameItem.SetChildren({ &yesItem, &noItem });
		exitGameItem.InitMenuItem();

		yesItem.text.setString("Yes");
		yesItem.text.setFont(font);
		yesItem.text.setCharacterSize(24);

		noItem.text.setString("No");
		noItem.text.setFont(font);
		noItem.text.setCharacterSize(24);

		menu.SelectMenuItem(&startGameItem);
	}

	void GameStateMainMenuData::ShutdownGameStateMainMenu()
	{
		// No need to do anything here
	}

	void GameStateMainMenuData::HandleGameStateMainMenuWindowEvent(const sf::Event& event)
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
				if (menu.GetSelectedItem() == &startGameItem)
				{
					game.SwitchGameState(GameStateType::Playing);
				}
				else if (menu.GetSelectedItem() == &exitGameItem)
				{
					menu.ExpandSelectedItem();
				}
				else if (menu.GetSelectedItem() == &yesItem)
				{
					game.SwitchGameState(GameStateType::None);
				}
				else if (menu.GetSelectedItem() == &noItem)
				{
					menu.CollapseSelectedItem();
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

	void GameStateMainMenuData::UpdateGameStateMainMenu(float timeDelta)
	{

	}

	void GameStateMainMenuData::DrawGameStateMainMenu(sf::RenderWindow& window)
	{
		sf::Vector2f viewSize = (sf::Vector2f)window.getSize();

		sf::Text* hintText = &menu.GetCurrentMenuContext()->hintText;
		hintText->setOrigin(GetItemOrigin(*hintText, { 0.5f, 0.f }));
		hintText->setPosition(viewSize.x / 2.f, 150.f);
		window.draw(*hintText);

		menu.DrawMenu(window, viewSize / 2.f, { 0.5f, 0.f });
	}

}