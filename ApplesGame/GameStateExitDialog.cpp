#include "GameStateExitDialog.h"
#include "Application.hpp"

namespace ApplesGame
{
	void GameStateExitDialogData::Init()
	{
		assert(font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		menu.GetRootItem()->hintText.setFont(font);
		menu.GetRootItem()->hintText.setString("Pause Game");
		
		menu.GetRootItem()->hintText.setCharacterSize(48);
		menu.GetRootItem()->hintText.setFillColor(sf::Color::Red);
		menu.GetRootItem()->SetChildrenOrientation(Orientation::Vertical);
		menu.GetRootItem()->SetChildrenAlignment(Alignment::Middle);
		menu.GetRootItem()->SetChildrenSpacing(10.f);
		menu.GetRootItem()->SetChildren({ &continueGameItem, &exitGameItem });
		menu.GetRootItem()->InitMenuItem();

		continueGameItem.text.setString("Continue Game");
		continueGameItem.text.setFont(font);
		continueGameItem.text.setCharacterSize(24);

		exitGameItem.text.setString("Exit To Main Menu");
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

		menu.SelectMenuItem(&continueGameItem);

		background.setFillColor(sf::Color(0, 0, 0, 128)); // Semi-transparent black
	}

	void GameStateExitDialogData::HandleWindowEvent(const sf::Event& event)
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
				if (menu.GetSelectedItem() == &continueGameItem)
				{
					game.PopGameState();
				}
				else if (menu.GetSelectedItem() == &exitGameItem)
				{
					menu.ExpandSelectedItem();
				}
				else if (menu.GetSelectedItem() == &yesItem)
				{
					game.SwitchGameState(GameStateType::MainMenu);
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

	void GameStateExitDialogData::Update(float timeDelta)
	{

	}

	void GameStateExitDialogData::Draw(sf::RenderWindow& window)
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
