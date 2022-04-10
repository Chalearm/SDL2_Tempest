#ifndef __GAME__
#define __GAME__


#include <iostream>
#include <random>
#include "gameObject.h"
#include "sdlWindowHandler.h"
#include "sdlObject.h"
using namespace std;

class game
{
private:
	bool m_isRunning;
	SDLWindowHandler m_gameWindow;
	std::shared_ptr<SDLObject> m_pAnimal;

	// random fundion
	std::random_device rd;
	std::mt19937 gen;

	int m_animalFlipVal;
	int randomFn(int max,int min);
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
