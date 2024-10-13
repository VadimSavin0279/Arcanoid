#pragma once
#include "GameStatePlaying.h"
#include "GameStateExitDialog.h"
#include "GameStateMainMenu.h"
#include "GameStateGameOver.h"
#include <assert.h>

namespace ApplesGame
{
	enum class GameStateType
	{
		None = 0,
		MainMenu,
		Playing,
		GameOver,
		ExitDialog
	};

	enum class GameStateChangeType
	{
		None, Push, Pop, Switch
	};

	class GameState
	{
	private:
		GameStateType type = GameStateType::None;
		void* data = nullptr;
		bool isExclusivelyVisible = false;
	public:
		GameState(GameStateType type): type(type)
		{
			switch (type)
			{
			case GameStateType::MainMenu:
			{
				data = new GameStateMainMenuData();
				break;
			}
			case GameStateType::Playing:
			{
				data = new GameStatePlayingData();
				break;
			}
			case GameStateType::GameOver:
			{
				data = new GameStateGameOverData();
				break;
			}
			case GameStateType::ExitDialog:
			{
				data = new GameStateExitDialogData();
				break;
			}
			default:
				assert(false);
				break;
			}
		}

		~GameState()
		{
			switch (type)
			{
			case GameStateType::MainMenu:
			{
				(*(GameStateMainMenuData*)data).ShutdownGameStateMainMenu();
				delete (GameStateMainMenuData*)data;
				break;
			}
			case GameStateType::Playing:
			{
				(*(GameStatePlayingData*)data).ShutdownGameStatePlaying();
				delete (GameStatePlayingData*)data;
				break;
			}
			case GameStateType::GameOver:
			{
				(*(GameStateGameOverData*)data).ShutdownGameStateGameOver();
				delete (GameStateGameOverData*)data;
				break;
			}
			case GameStateType::ExitDialog:
			{
				(*(GameStateExitDialogData*)data).ShutdownGameStateExitDialog();
				delete (GameStateExitDialogData*)data;
				break;
			}
			default:
				assert(false);
				break;
			}

			data = nullptr;
		}
		
		bool isExclusiveVisible() const;

		void HandleWindowEventGameState(sf::Event& event);
		void UpdateGameState(float timeDelta);
		void DrawGameState(sf::RenderWindow& window);
	};
}