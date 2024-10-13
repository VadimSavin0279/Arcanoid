#include "GameState.h"

namespace ApplesGame
{
	bool GameState::isExclusiveVisible() const
	{
		return isExclusivelyVisible;
	}
	void GameState::HandleWindowEventGameState(sf::Event& event)
	{
		switch (type)
		{
		case GameStateType::MainMenu:
		{
			(*(GameStateMainMenuData*)data).HandleGameStateMainMenuWindowEvent(event);
			break;
		}
		case GameStateType::Playing:
		{
			(*(GameStatePlayingData*)data).HandleGameStatePlayingWindowEvent(event);
			break;
		}
		case GameStateType::GameOver:
		{
			(*(GameStateGameOverData*)data).HandleGameStateGameOverWindowEvent(event);
			break;
		}
		case GameStateType::ExitDialog:
		{
			(*(GameStateExitDialogData*)data).HandleGameStateExitDialogWindowEvent(event);
			break;
		}
		default:
			assert(false);
			break;
		}
	}

	void GameState::UpdateGameState(float timeDelta)
	{
		switch (type)
		{
		case GameStateType::MainMenu:
		{
			(*(GameStateMainMenuData*)data).UpdateGameStateMainMenu(timeDelta);
			break;
		}
		case GameStateType::Playing:
		{
			(*(GameStatePlayingData*)data).UpdateGameStatePlaying(timeDelta);
			break;
		}
		case GameStateType::GameOver:
		{
			(*(GameStateGameOverData*)data).UpdateGameStateGameOver(timeDelta);
			break;
		}
		case GameStateType::ExitDialog:
		{
			(*(GameStateExitDialogData*)data).UpdateGameStateExitDialog(timeDelta);
			break;
		}
		default:
			assert(false);
			break;
		}
	}

	void GameState::DrawGameState(sf::RenderWindow& window)
	{
		switch (type)
		{
		case GameStateType::MainMenu:
		{
			(*(GameStateMainMenuData*)data).DrawGameStateMainMenu(window);
			break;
		}
		case GameStateType::Playing:
		{
			(*(GameStatePlayingData*)data).DrawGameStatePlaying(window);
			break;
		}
		case GameStateType::GameOver:
		{
			(*(GameStateGameOverData*)data).DrawGameStateGameOver(window);
			break;
		}
		case GameStateType::ExitDialog:
		{
			(*(GameStateExitDialogData*)data).DrawGameStateExitDialog(window);
			break;
		}
		default:
			assert(false);
			break;
		}
	}
}