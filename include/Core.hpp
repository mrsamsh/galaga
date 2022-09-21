#ifndef CORE_H
#define CORE_H

#include "header.hpp"
#include "CFG.hpp"
#include "Game.hpp"

class CCore
{
public:
	CCore(void);
	~CCore(void);

	void mainLoop();
	void Input();

	void Update();
	void Draw();

public:
	// ----- INPUT
	static bool keyLeft, keyRight;

	static bool spaceKey;

	static bool quitGame;


private:

	SDL_Window* window;
	SDL_Event* mainEvent;
	SDL_GLContext gContext;



	// ----- Game Object
	static Game *game;


};

#endif
