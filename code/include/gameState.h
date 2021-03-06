
//  
//
//     gameState
//
//     define in header gameState
//     class gameState
//     
//     is base class for the object how displays on the game
//

#ifndef __GAMESTATE__
#define __GAMESTATE__
#include "gameDataType.h" 

class gameState
{
private: 
public:
	gameState();
	virtual ~gameState();

	virtual void init();
	virtual void render();
	virtual void update();
	virtual void handleEvents(const unsigned char& keyPress = 0);
	virtual void clean();
	virtual GameScene getGameState() const;
};

#endif /* define (__GAMESTATE__) */
