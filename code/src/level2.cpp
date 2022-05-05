#include <memory>
#include <vector>
#include "level2.h"
#include "point.h"
#include "walkPath.h"

level2::level2():
level()
{
    m_numberOfEnemy = g_numberOfEnemies_Lv2;
    std::shared_ptr<std::vector<walkPath<double> > > l_thelv2Path(new std::vector<walkPath<double> >());
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(37.5,50),
    point<double>(0,50),
    point<double>(12.5,25),
    point<double>(40.625,43.75)));
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(40.625,43.75),
    point<double>(12.5,25),
    point<double>(25,0),
    point<double>(43.75,37.5)));
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(43.75,37.5),
    point<double>(25,0),
    point<double>(50,0),
    point<double>(50,37.5)));
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(50,37.5),
    point<double>(50,0),
    point<double>(75,0),
    point<double>(56.25,37.5)));
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(56.25,37.5),
    point<double>(75,0),
    point<double>(87.5,25),
    point<double>(59.375,43.75)));
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(59.375,43.75),
    point<double>(87.5,25),
    point<double>(100,50),
    point<double>(62.5,50)));
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(62.5,50),
    point<double>(100,50),
    point<double>(87.5,75),
    point<double>(59.375,56.25)));
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(59.375,56.25),
    point<double>(87.5,75),
    point<double>(75,100),
    point<double>(56.25,62.5)));
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(56.25,62.5),
    point<double>(75,100),
    point<double>(50,100),
    point<double>(50,62.5)));
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(50,62.5),
    point<double>(50,100),
    point<double>(25,100),
    point<double>(43.75,62.5)));

    l_thelv2Path->push_back(walkPath<double>(
    point<double>(43.75,62.5),
    point<double>(25,100),
    point<double>(12.5,75),
    point<double>(40.625,56.25)));
    l_thelv2Path->push_back(walkPath<double>(
    point<double>(40.625,56.25),
    point<double>(12.5,75),
    point<double>(0,50),
    point<double>(37.5,50)));
    setWalkPathSet(l_thelv2Path);
}

level2::level2(const level2& obj):
level(obj)
{
}

level2::~level2()
{

}

level2& level2::operator=(const level2& obj)
{
    if (this != &obj)
    {
        level::operator=(obj);
    }
    else
    {
        // Do nothing
    }
    return *this;
}
void level2::init()
{
    level::init();
    m_currentStage = Level2;
}
void level2::render()
{
    level::render();
}
void level2::update()
{
    level::update();
}
void level2::handleEvents(const unsigned char& keyPress)
{
    level::handleEvents(keyPress);
}
void level2::clean()
{
    level::clean();
}
std::shared_ptr<std::vector<walkPath<double> > > level2::getWalkPaht()const
{
    return level::getWalkPaht();
}
void level2::setSDLHandler(const std::shared_ptr<SDLHandler> &obj)
{
    level::setSDLHandler(obj);
}