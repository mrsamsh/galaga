#ifndef shape_H
#define shape_H

#include "header.hpp"

class shape {
public:
	GLfloat width, height, x, y, vectorLeft, vectorRight, vectorTop, vectorBottom, speedX, speedY, initX, initY;
	GLfloat R = 1.0f, G = 1.0f, B = 1.0f;
	void setColor(GLfloat R, GLfloat G, GLfloat B);
};

class rect : public shape {
public:
	rect();
	rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat speedX, GLfloat speedY);
	void init(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat speedX, GLfloat speedY);
	rect(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	void draw();
	void updateVectors();
};

class star : public rect {
public:
	GLfloat angleDir;
	star(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
};

#endif // shape_H
