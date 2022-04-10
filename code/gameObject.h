#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__
 
class gameObject
{
private: 
public:
	gameObject();
	virtual ~gameObject();

	virtual void init();
	virtual void render();
	virtual void update();
	virtual void handleEvents();
	virtual void clean();
};

#endif /* define (__GAMEOBJECT__) */
