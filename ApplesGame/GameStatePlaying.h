#pragma once
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Player.h"
#include "GameStateData.h"
#include "vector"
#include "Block.h"

namespace ApplesGame
{
	class GameStatePlayingData : public GameStateData
	{
	private:
		sf::Font font;

		Player player;
		Ball ball;

		std::vector<Block> blocks;

		sf::Texture playerTexture;

		int score = 0;

	public:
		GameStatePlayingData()
		{
			Init();
		}

		void Init() override;
		void HandleWindowEvent(const sf::Event& event) override;
		void HandleGame();
		void Update(float timeDelta) override;
		void Draw(sf::RenderWindow& window) override;

		bool isGameOver(const Ball& ball, const Player& player);
		void ChangeVelocityVectorAfterColissionWithPlayer(const Player& player, Ball& ball, const Orientation& orientation);
		void ChangeVelocityVectorAfterColissionWithObjects(Ball& ball, const Orientation& orientation);
	};
}