#include "cassert"
#include "Game.h"
#include "Application.hpp"

namespace ApplesGame 
{
	void Game::HandleWindowEvents(sf::RenderWindow& window)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window if close button or Escape key pressed
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (gameStateStack.size() > 0)
			{
				(*gameStateStack.back()).HandleWindowEventGameState(event);
			}
		}
	}

	bool Game::UpdateGame(float timeDelta)
	{
		if (gameStateChangeType == GameStateChangeType::Switch)
		{
			// Shutdown all game states
			while (gameStateStack.size() > 0)
			{
				delete gameStateStack.back();
				gameStateStack.pop_back();
			}
		}
		else if (gameStateChangeType == GameStateChangeType::Pop)
		{
			// Shutdown only current game state
			if (gameStateStack.size() > 0)
			{
				gameStateStack.pop_back();
			}
		}

		// Initialize new game state if needed
		if (pendingGameStateType != GameStateType::None)
		{
			GameState* newState = new GameState{ pendingGameStateType };
			gameStateStack.push_back(newState);
		}

		gameStateChangeType = GameStateChangeType::None;
		pendingGameStateType = GameStateType::None;
		pendingGameStateIsExclusivelyVisible = false;

		if (gameStateStack.size() > 0)
		{
			(*gameStateStack.back()).UpdateGameState(timeDelta);
			return true;
		}

		return false;
	}

	void Game::DrawGame(sf::RenderWindow& window)
	{
		if (gameStateStack.size() > 0)
		{
			std::vector<GameState*> visibleGameStates;
			for (auto it = gameStateStack.rbegin(); it != gameStateStack.rend(); ++it)
			{
				visibleGameStates.push_back(*it);
				if ((*it)->isExclusiveVisible())
				{
					break;
				}
			}

			for (auto it = visibleGameStates.rbegin(); it != visibleGameStates.rend(); ++it)
			{
				
				(*it)->DrawGameState(window);
			}
		}
	}

	void Game::ShutdownGame()
	{
		// Shutdown all game states
		while (gameStateStack.size() > 0)
		{
			delete gameStateStack.back();
			gameStateStack.pop_back();
		}

		gameStateChangeType = GameStateChangeType::None;
		pendingGameStateType = GameStateType::None;
		pendingGameStateIsExclusivelyVisible = false;
	}

	void Game::PushGameState(GameStateType stateType, bool isExclusivelyVisible)
	{
		pendingGameStateType = stateType;
		pendingGameStateIsExclusivelyVisible = isExclusivelyVisible;
		gameStateChangeType = GameStateChangeType::Push;
	}

	void Game::PopGameState()
	{
		pendingGameStateType = GameStateType::None;
		pendingGameStateIsExclusivelyVisible = false;
		gameStateChangeType = GameStateChangeType::Pop;
	}

	void Game::SwitchGameState(GameStateType newState)
	{
		pendingGameStateType = newState;
		pendingGameStateIsExclusivelyVisible = false;
		gameStateChangeType = GameStateChangeType::Switch;
	}
}