#ifndef _LEVELS_H_
#define _LEVELS_H_

#include "header.hpp"
#include "timer.hpp"
#include "texture.hpp"
#include <vector>

class LevelsUP {
private:
	Timer t;
	LTexture levelImage;
	std::vector<LTexture*>levels;
	int lvlcount = 0;

public:


	LevelsUP();
	~LevelsUP();
	void reload();
	void renderLevels();

};


#endif // !_LEVELS_H_
