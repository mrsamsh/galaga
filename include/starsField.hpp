#ifndef _STARSFIELD_
#define _STARSFIELD_

#include "header.hpp"
#include <vector>
#include "shapes.hpp"
#include "timer.hpp"

class StarsField {

public:
	void initSpace();
	void Render();
	void Update();
	static bool reverse;
	static bool easeDown;
	float revSpeed;

private:
	void moveStarsfield(rect &star);
	std::vector<star> starsField;
	float getNewSpeed();

};



#endif // !_STARSFIELD_
