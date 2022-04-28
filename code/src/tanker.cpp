#include "tanker.h"
#include <cmath>

tanker::tanker(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale, const point<double>& refPoint):
enemy(refLanes,scale,refPoint)
{
   m_speed = enemy::randomFn(0.01,0.002);
   m_bodyColor = g_tankerColor;
}
tanker::~tanker()
{}

tanker::tanker(const tanker& obj):
enemy(obj)
{}

tanker& tanker::operator=(const tanker& obj)
{
    if(this != &obj)
    {
    	enemy::operator=(obj);
    }
    else
    {
    	// Do nothing
    }
    return *this;
}

std::vector<lineWithColor> tanker::drawEnemy()
{
    return m_lines;
}
void tanker::move()
{

    if (m_isAlive && (m_isTimeUp) && (static_cast<int>(m_currentPosition) <= 1))
    {
        m_lines.clear();
        //eulidianDis
        const double widthOfTanker = 0.4;// 0.01 - 1.0  (1% to 100%)
        const double heightOfTanker = 0.07; // 0.01 - 1.0 (1% to 100%) 100% is the length of the lanes
        walkPath<double> aWalkpath = m_refLanes->at(m_beingLane);
        const point<double> p4 = findPointInBetweenALane(aWalkpath,m_currentPosition,(1-widthOfTanker)*0.5);
        const point<double> p3 = findPointInBetweenALane(aWalkpath,m_currentPosition,widthOfTanker+(1-widthOfTanker)*0.5);
        const point<double> centerTop = findPointInBetweenALane(aWalkpath,m_currentPosition + heightOfTanker,0.5);
        const point<double> centerBottom = findPointInBetweenALane(aWalkpath,m_currentPosition - heightOfTanker,0.5);


        const point<double> p42 = findPointInBetweenALane(aWalkpath,m_currentPosition,(1-0.3*widthOfTanker)*0.5);
        const point<double> p32 = findPointInBetweenALane(aWalkpath,m_currentPosition,(0.3*widthOfTanker+(1-0.3*widthOfTanker)*0.5));
        const point<double> centerTop2 = findPointInBetweenALane(aWalkpath,m_currentPosition + 0.01,0.5);
        const point<double> centerBottom2 = findPointInBetweenALane(aWalkpath,m_currentPosition - 0.01,0.5);
//addToLineVect
        addToLineWitBodyColorVect(p4,centerTop);
        addToLineWitBodyColorVect(centerTop,p3);
        addToLineWitBodyColorVect(p3,centerBottom);
        addToLineWitBodyColorVect(centerBottom,p4);
        addToLineWitBodyColorVect(p42,centerTop2);
        addToLineWitBodyColorVect(centerTop2,p32);
        addToLineWitBodyColorVect(centerBottom2,p42);
        addToLineWitBodyColorVect(p42,p4);
        addToLineWitBodyColorVect(centerTop2,centerTop);
        addToLineWitBodyColorVect(centerBottom2,centerBottom);
        addToLineWitBodyColorVect(p32,p3);
        addToLineWitBodyColorVect(p42,centerTop);
        addToLineWitBodyColorVect(centerTop2,p3);
        addToLineWitBodyColorVect(p32,centerBottom);
        addToLineWitBodyColorVect(centerBottom2,p4);

        //std::cout<<" sdsfdfd ";
        m_currentPosition += m_speed;
        if (m_currentPosition > 1.0)
        {
            m_currentPosition = 1.0;
        }
        else
        {
            // Do nothing
        }

    }
    else
    {
        // Do nothing
    }
    enemy::move();

}