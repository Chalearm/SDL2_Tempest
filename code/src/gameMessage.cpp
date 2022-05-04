#include "gameMessage.h"
#define UNUSED(expr) do { (void)(expr); } while (0)

gameMessage::gameMessage()
{}
	
gameMessage::gameMessage(const gameMessage& obj)
{
    UNUSED(obj);
}
gameMessage::~gameMessage()
{}

void gameMessage::setStringVal(const int& selectedVal, const std::string& msg)
{
    UNUSED(selectedVal);
    UNUSED(msg);
}

void gameMessage::setLLIntVal(const int& selectedVal,const long long int& setVal)
{
    UNUSED(selectedVal);
    UNUSED(setVal);
}

void gameMessage::setDoubleValue(const int& selectedVal,const double& setVal)
{
    UNUSED(selectedVal);
    UNUSED(setVal);
}

unsigned char gameMessage::getUChar(const int& selectedVal)
{
    UNUSED(selectedVal);
    return '\0';
}

long long int gameMessage::getLLIntVal(const int& selectedVal)
{
    UNUSED(selectedVal);
	return 0;
}
double gameMessage::getDoubleVal(const int& selectedVal)
{
    UNUSED(selectedVal);
	return 0.0;
}

std::string gameMessage::getStrVal(const int& selectedVal)
{
    UNUSED(selectedVal);
	return std::string("");
}