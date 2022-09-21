#ifndef _BULLET_H_
#define _BULLET_H_

#include "header.hpp"
#include "texture.hpp"
#include "Objects.hpp"

class Bullet: public GameObject {
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();

	bool fromRocket = false;
};

#endif // _BULLET_H_
