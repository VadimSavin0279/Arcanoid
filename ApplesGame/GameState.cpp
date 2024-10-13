#include "GameState.h"
#include "GameStateData.h"

namespace ApplesGame
{
	bool GameState::isExclusiveVisible() const
	{
		return isExclusivelyVisible;
	}
	void GameState::HandleWindowEventGameState(sf::Event& event)
	{
		data->HandleWindowEvent(event);	
	}

	void GameState::UpdateGameState(float timeDelta)
	{
		data->Update(timeDelta);
	}

	void GameState::DrawGameState(sf::RenderWindow& window)
	{
		data->Draw(window);
	}
}