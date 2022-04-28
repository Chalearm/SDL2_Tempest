#include "tanker.h"
#include <cmath>

tanker::tanker(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale, const point<double>& refPoint):
enemy(refLanes,scale,refPoint)
{
   m_speed = enemy::randomFn(0.04,0.017);
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

std::vector<aLine<double> > tanker::drawEnemy()
{
    return m_lines;
}
void tanker::move()
{

    if ((m_isTimeUp) && (static_cast<int>(m_currentPosition) <= 1))
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

        addToLineVect(p4,centerTop);
        addToLineVect(centerTop,p3);
        addToLineVect(p3,centerBottom);
        addToLineVect(centerBottom,p4);
        addToLineVect(p42,centerTop2);
        addToLineVect(centerTop2,p32);
        addToLineVect(p32,centerBottom2);
        addToLineVect(centerBottom2,p42);
        addToLineVect(p42,p4);
        addToLineVect(centerTop2,centerTop);
        addToLineVect(centerBottom2,centerBottom);
        addToLineVect(p32,p3);
        addToLineVect(p42,centerTop);
        addToLineVect(centerTop2,p3);
        addToLineVect(p32,centerBottom);
        addToLineVect(centerBottom2,p4);

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