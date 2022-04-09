#ifndef __GAME__
#define __GAME__


#include <iostream>
#include <SDL2/SDL.h>
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
