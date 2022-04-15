#ifndef __GAMESTATE__
#define __GAMESTATE__
 
class gameState
{
private: 
public:
	gameState();
	virtual ~gameState();

	virtual void init();
	virtual void render();
	virtual void update();
	virtual void handleEvents();
	virtual void clean();
};

#endif /* define (__GAMESTATE__) */
