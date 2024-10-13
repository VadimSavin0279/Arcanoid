#pragma once
#include "GameStatePlaying.h"
#include "GameStateExitDialog.h"
#include "GameStateMainMenu.h"
#include "GameStateGameOver.h"
#include "GameStateWin.h"
#include <assert.h>

namespace ApplesGame
{
	enum class GameStateType
	{
		None = 0,
		MainMenu,
		Playing,
		GameOver,
		Win,
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
		std::unique_ptr< GameStateData> data = nullptr;
		bool isExclusivelyVisible = false;
	public:
		GameState(GameStateType type): type(type)
		{
			switch (type)
			{
			case GameStateType::MainMenu:
			{
				data = std::make_unique<GameStateMainMenuData>();
				break;
			}
			case GameStateType::Playing:
			{
				data = std::make_unique<GameStatePlayingData>();
				break;
			}
			case GameStateType::GameOver:
			{
				data = std::make_unique<GameStateGameOverData>();
				break;
			}
			case GameStateType::Win:
			{
				data = std::make_unique<GameStateWinData>();
				break;
			}
			case GameStateType::ExitDialog:
			{
				data = std::make_unique<GameStateExitDialogData>();
				break;
			}
			default:
				assert(false);
				break;
			}
		}

		~GameState()
		{}
		
		bool isExclusiveVisible() const;

		void HandleWindowEventGameState(sf::Event& event);
		void UpdateGameState(float timeDelta);
		void DrawGameState(sf::RenderWindow& window);
	};
}