#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__
 
class gameObject
{
private: 
public:
	gameObject();
	virtual ~gameObject() = 0;

	virtual void init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handleEvents() = 0;
	virtual void clean() = 0;
};

#endif /* define (__GAMEOBJECT__) */
