#include "Text.hpp"
#include "Resources.hpp"

Text2D::Text2D() {

};

Text2D::~Text2D() {
	glDeleteTextures(1, &texture);
	//SDL_FreeSurface(sFont);
};


void Text2D::loadFont(std::string file, SDL_Color color, int size, std::string message, int x, int y) {


	this->color = color;

	glcolor[0] = color.r / 255.0f;
	glcolor[1] = color.g / 255.0f;
	glcolor[2] = color.b / 255.0f;

	color.r = 255;
	color.g = 255;
	color.b = 255;

	this->size = size;
	this->Message = message;
	this->x = (float)x;
	this->y = (float)y;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);


	font = TTF_OpenFont((Resources::getFont(file)).c_str(), size);

	if (font == NULL) {
		printf("Font Loading Error ! %s", SDL_GetError());
		return;
	}
	sFont = TTF_RenderText_Blended(font, Message.c_str(), color);

	if (sFont == NULL) {
		printf("Font Loading Error ! %s", SDL_GetError());
		return;
	}

	//Set OpenGl Color
	
	int w = sFont->w;
	int pitch = sFont->pitch / 4;
	uint32_t* pixels = (uint32_t*)sFont->pixels;
	uint32_t* data = new uint32_t[sFont->w * sFont->h];
	for (int i = 0; i < sFont->h; ++i)
	{
		memcpy(&data[i * w], &pixels[i * pitch], sizeof(uint32_t) * w);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sFont->w, sFont->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);

	delete[] data;

};

void Text2D::setText(std::string message) {

	glDeleteTextures(1, &texture);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	SDL_FreeSurface(sFont);

	color.r = 255;
	color.g = 255;
	color.b = 255;

	this->Message = message;
	sFont = TTF_RenderText_Blended(font, this->Message.c_str(), color);

	int w = sFont->w;
	int pitch = sFont->pitch / 4;
	uint32_t* pixels = (uint32_t*)sFont->pixels;
	uint32_t* data = new uint32_t[sFont->w * sFont->h];
	for (int i = 0; i < sFont->h; ++i)
	{
		memcpy(&data[i * w], &pixels[i * pitch], sizeof(uint32_t) * w);
	}

	//Set OpenGl Color
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sFont->w, sFont->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);

	delete[] data;
}

void Text2D::render() {


	glBindTexture(GL_TEXTURE_2D, texture);
	//glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	glPushMatrix();

	glBegin(GL_QUADS);

	glColor3f(glcolor[0], glcolor[1], glcolor[2]);

	glTexCoord2f(0, 0);
	glVertex2f(x, y);

	glTexCoord2f(0, 1);
	glVertex2f(x, y + sFont->h);

	glTexCoord2f(1, 1);
	glVertex2f(x + sFont->w, y + sFont->h);

	glTexCoord2f(1, 0);
	glVertex2f(x + sFont->w, y);

	glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);


}
