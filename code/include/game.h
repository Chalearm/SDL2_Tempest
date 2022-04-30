//  
//
//     game
//
//     define in header game
//     class game
//     
//     it is the game structure controling each step for the game cycle ( init, render, update and etc)
//
//
#ifndef __GAME__
#define __GAME__


#include <iostream>
#include <random>
#include "gameState.h"
#include "sdlHandler.h"
#include "menuGame.h"
using namespace std;

class game
{
private:
	bool m_isRunning;
	std::shared_ptr<SDLHandler> theSdlHandler;
	std::shared_ptr<gameState> m_menuGame;

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
