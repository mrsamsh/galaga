#ifndef _GAME_H_
#define _GAME_H_

#include "header.hpp"
#include "starsField.hpp"
#include "Elements.hpp"
#include "StageM.hpp"

class Game {

public:

	Game();
	~Game();

	static short gameState;
	static int lives;
	static int numStages;

	static Elements mainElements;
	StarsField starsfield;
	StageM stageManager;


	void Draw();
	void Start();
	void update();
};


#endif // !_GAME_H_


