#ifndef __GAMEMESSAGE__
#define __GAMEMESSAGE__
#include <iostream> 

class gameMessage
{
public:
	gameMessage();
	gameMessage(const gameMessage& obj);
	virtual ~gameMessage();

	virtual void setLLIntVal(const int& selectedVal,const long long int& setVal);
	virtual void setDoubleValue(const int& selectedVal, const double& setVal);
	virtual void setStringVal(const int& selectedVal, const std::string& msg);
	virtual long long int getLLIntVal(const int& selectedVal);
	virtual double getDoubleVal(const int& selectedVal);
	virtual std::string getStrVal(const int& selectedVal);
};

#endif /* define (__GAMEMESSAGE__) */
