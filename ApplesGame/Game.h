#pragma once
#include "Player.h"
#include "Ball.h"
#include "Barrier.h"
#include <vector>
#include "GameState.h"

namespace ApplesGame 
{
	class Game
	{
	private:
		GameStateType gameState = GameStateType::Playing;

		std::vector<GameState*> gameStateStack;
		GameStateChangeType gameStateChangeType = GameStateChangeType::None;
		GameStateType pendingGameStateType = GameStateType::None;
		bool pendingGameStateIsExclusivelyVisible = false;

	public:
		Game()
		{
			SwitchGameState(GameStateType::MainMenu);
		}

		Rectangle GetScreenRect()
		{
			return { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
		}

		void HandleWindowEvents(sf::RenderWindow& window);
		bool UpdateGame(float timeDelta);
		void DrawGame(sf::RenderWindow& window);
		void ShutdownGame();

		void PushGameState(GameStateType stateType, bool isExclusivelyVisible);
		void PopGameState();
		void SwitchGameState(GameStateType newState);
	};
}