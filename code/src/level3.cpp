#include <memory>
#include <vector>
#include "level3.h"
#include "point.h"
#include "walkPath.h"

level3::level3():
level()
{
    m_numberOfEnemy = g_numberOfEnemies_Lv3;
    std::shared_ptr<std::vector<walkPath<double> > > l_thelv3Path(new std::vector<walkPath<double> >());
    l_thelv3Path->push_back(walkPath<double>(
    point<double>(37.5,50),
    point<double>(0,50),
    point<double>(0,25),
    point<double>(37.5,43.75)));
    l_thelv3Path->push_back(walkPath<double>(
    point<double>(37.5,43.75),
    point<double>(0,25),
    point<double>(12.5,12.5),
    point<double>(40.625,40.625)));
    l_thelv3Path->push_back(walkPath<double>(
    point<double>(40.625,40.625),
    point<double>(12.5,12.5),
    point<double>(25.0,0),
    point<double>(43.75,37.5)));
    l_thelv3Path->push_back(walkPath<double>(
    point<double>(43.75,37.5),
    point<double>(25.0,0),
    point<double>(50,0),
    point<double>(50,37.5)));
    l_thelv3Path->push_back(walkPath<double>(
    point<double>(50,37.5),
    point<double>(50,0),
    point<double>(75,0),
    point<double>(56.25,37.5)));
    l_thelv3Path->push_back(walkPath<double>(
    point<double>(56.25,37.5),
    point<double>(75,0),
    point<double>(87.5,12.5),
    point<double>(59.375,40.625)));
    l_thelv3Path->push_back(walkPath<double>(
    point<double>(59.375,40.625),
    point<double>(87.5,12.5),
    point<double>(100,25),
    point<double>(62.5,43.75)));
    l_thelv3Path->push_back(walkPath<double>(
    point<double>(62.5,43.75),
    point<double>(100,25),
    point<double>(100,50),
    point<double>(62.5,50)));



    l_thelv3Path->push_back(walkPath<double>(
    point<double>(62.5,50),
    point<double>(100,50),
    point<double>(100,75),
    point<double>(62.5,56.25)));

    l_thelv3Path->push_back(walkPath<double>(
    point<double>(62.5,56.25),
    point<double>(100,75),
    point<double>(87.5,87.5),
    point<double>(59.375,59.375)));

    l_thelv3Path->push_back(walkPath<double>(
    point<double>(59.375,59.375),
    point<double>(87.5,87.5),
    point<double>(75,100),
    point<double>(56.25,62.5)));

    l_thelv3Path->push_back(walkPath<double>(
    point<double>(56.25,62.5),
    point<double>(75,100),
    point<double>(50,100),
    point<double>(50,62.5)));


    l_thelv3Path->push_back(walkPath<double>(
    point<double>(50,62.5),
    point<double>(50,100),
    point<double>(25,100),
    point<double>(43.75,62.5)));

    l_thelv3Path->push_back(walkPath<double>(
    point<double>(43.75,62.5),
    point<double>(25,100),
    point<double>(12.5,87.5),
    point<double>(40.625,59.375)));

    l_thelv3Path->push_back(walkPath<double>(
    point<double>(40.625,59.375),
    point<double>(12.5,87.5),
    point<double>(0,75),
    point<double>(37.5,56.25)));

    l_thelv3Path->push_back(walkPath<double>(
    point<double>(37.5,56.25),
    point<double>(0,75),
    point<double>(0,50),
    point<double>(37.5,50)));
    setWalkPathSet(l_thelv3Path);
}

level3::level3(const level3& obj):
level(obj)
{
}

level3::~level3()
{

}

level3& level3::operator=(const level3& obj)
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
void level3::init()
{
    level::init();
    m_currentStage = Level3;
}
void level3::render()
{
    level::render();
}
void level3::update()
{
    level::update();
}
void level3::handleEvents(const unsigned char& keyPress)
{
    level::handleEvents(keyPress);
}
void level3::clean()
{
    level::clean();
}