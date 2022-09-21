#ifndef _ELEMENTS_H_
#define _ELEMENTS_H_

#include "header.hpp"
#include "Text.hpp"
#include "texture.hpp"
#include <vector>
#include "timer.hpp"
#include "LevelsElement.hpp"
#include "Rocket.hpp"
#include "Bullet.hpp"
#include "Patterns.hpp"

class Elements
{

private:

	int lives = 3;
	LevelsUP levels;



public:

	static Rocket rocket[2];
	static unsigned short RocketsNum;
	bool gameStarted = false;
	bool next = false;

	//state
	static int state;
	static bool rocketInitiated;
	static Patterns patterns;
    static std::vector<Bullet> bullets;
	static std::vector<Bullet> Shipsbullets;

	static unsigned int score;
	static void updateScore(unsigned int n);
	static bool FighterCapture;


	//Elements();
	//~Elements();
	void initElements();
	void renderStartScreen();
	void initRightNav();
	void renderRightNav();
	void starterAnim();
	void updateLives();
	void showStageNum();
	void flashScore();
	short introStarted;
	void reIntRocket();
	void initRockets();

	void shoot();

	static void SwapRockets();

	void gameOver();

	void bonus();

	void Update();
	void Draw();
	void nextStage();
};

#endif // !_ELEMENTS_H_
