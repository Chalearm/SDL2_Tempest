#include "gameState.h"
#define UNUSED(expr) do { (void)(expr); } while (0)
gameState::gameState()
{}

gameState::~gameState()
{}

void gameState::init()
{}

void gameState::render()
{}

void gameState::update()
{}

void gameState::handleEvents(const unsigned char& keyPress)
{
	UNUSED(keyPress);
}

void gameState::clean()
{}