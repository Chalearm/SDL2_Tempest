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
#include "gameState.h"
#include "sdlHandler.h"
using namespace std;

class game
{
private:
	bool m_isRunning;
	std::shared_ptr<SDLHandler> theSdlHandler;
	std::shared_ptr<gameState> m_currentGameState;
	std::shared_ptr<gameState> m_oldGameState;
	std::map<GameScene,std::shared_ptr<gameState> > m_gameScene;

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
