#include "Application.hpp"

namespace ApplesGame
{
	Application& Application::Instance()
	{
		static Application instance;
		return instance;
	}
	
	Application::Application() : 
		window(sf::VideoMode(ApplesGame::SCREEN_WIDTH, ApplesGame::SCREEN_HEIGHT), GAME_NAME)
	{
		unsigned int seed = (unsigned int)time(nullptr);
		srand(seed);

	}

	void Application::Run()
	{
		sf::Clock game_clock;
		sf::Time lastTime = game_clock.getElapsedTime();

		// Game loop
		while (window.isOpen())
		{
			game.HandleWindowEvents(window);

			if (!window.isOpen())
			{
				break;
			}

			sf::Time currentTime = game_clock.getElapsedTime();
			float timeDelta = currentTime.asSeconds() - lastTime.asSeconds();
			lastTime = currentTime;
			if (game.UpdateGame(timeDelta))
			{
				window.clear();

				game.DrawGame(window);

				window.display();
			}
			else
			{
				window.close();
			}
		}
	}

	Application::~Application()
	{
		game.ShutdownGame();
	}
}