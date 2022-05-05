#include <memory>
#include <vector>
#include "level1.h"
#include "point.h"
#include "walkPath.h"

level1::level1():
level()
{
    std::shared_ptr<std::vector<walkPath<double> > > l_thelv1Path(new std::vector<walkPath<double> >());
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(40,60),
    point<double>(0,0),
    point<double>(25,0),
    point<double>(45,60)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(45,60),
    point<double>(25,0),
    point<double>(50,0),
    point<double>(50,60)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(50,60),
    point<double>(50,0),
    point<double>(75,0),
    point<double>(55,60)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(55,60),
    point<double>(75,0),
    point<double>(100,0),
    point<double>(60,60)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(60,60),
    point<double>(100,0),
    point<double>(100,25),
    point<double>(60,65)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(60,65),
    point<double>(100,25),
    point<double>(100,50),
    point<double>(60,70)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(60,70),
    point<double>(100,50),
    point<double>(100,75),
    point<double>(60,75)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(60,75),
    point<double>(100,75),
    point<double>(100,100),
    point<double>(60,80)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(60,80),
    point<double>(100,100),
    point<double>(75,100),
    point<double>(55,80)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(55,80),
    point<double>(75,100),
    point<double>(50,100),
    point<double>(50,80)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(50,80),
    point<double>(50,100),
    point<double>(25,100),
    point<double>(45,80)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(45,80),
    point<double>(25,100),
    point<double>(0,100),
    point<double>(40,80)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(40,80),
    point<double>(0,100),
    point<double>(0,75),
    point<double>(40,75)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(40,75),
    point<double>(0,75),
    point<double>(0,50),
    point<double>(40,70)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(40,70),
    point<double>(0,50),
    point<double>(0,25),
    point<double>(40,65)));
    l_thelv1Path->push_back(walkPath<double>(
    point<double>(40,65),
    point<double>(0,25),
    point<double>(0,0),
    point<double>(40,60)));
    setWalkPathSet(l_thelv1Path);
}

level1::level1(const level1& obj):
level(obj)
{}

level1::~level1()
{

}

level1& level1::operator=(const level1& obj)
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
void level1::init()
{
    level::init();
    m_currentStage = Level1;
}
void level1::render()
{
    level::render();
}
void level1::update()
{
    level::update();
}
void level1::handleEvents(const unsigned char& keyPress)
{
    level::handleEvents(keyPress);
}
void level1::clean()
{
    level::clean();
}
std::shared_ptr<std::vector<walkPath<double> > > level1::getWalkPaht()const
{
    return level::getWalkPaht();
}
void level1::setSDLHandler(const std::shared_ptr<SDLHandler> &obj)
{
    level::setSDLHandler(obj);
}