#ifndef __GAME__
#define __GAME__


#include <iostream>
#include <random>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
using namespace std;

class game
{
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_isRunning;

	// createing an SDL texture
	SDL_Texture* m_pTexture; // the new sDL_Texture variable
	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // another rectangle


	// createing an SDL texture
	SDL_Texture* m_pAnimalTexture; // the new sDL_Texture variable
	SDL_Rect m_sourceAnimalRectangle; // the first rectangle
	SDL_Rect m_destinationAnimalRectangle; // another rectangle


	SDL_Texture* m_pTxtMsgTexture; // the new sDL_Texture variable

	// random fundion
	std::random_device rd;
	std::mt19937 gen;

	int randomFn(int max,int min);
	TTF_Font* m_font;
public:
	game();
	~game();

	bool init();
	void render();
	void update();
	void handleEvents();
	void clean();

	bool isRunning()const;

	void runGame();
};

#endif /* define (__GAME__) */
