#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

namespace ApplesGame
{
	class Application
	{
	private:
		Game game;
		sf::RenderWindow window;

	public:
		Application(const Application& app) = delete;
		Application operator= (const Application&) = delete;

		void Run();

		static Application& Instance();

		Game& GetGame() { return game; }
	private:
		Application();
		~Application();
	};
}