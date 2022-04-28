#include "tanker.h"
#include <cmath>

tanker::tanker(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale, const point<double>& refPoint):
enemy(refLanes,scale,refPoint),
m_line1(point<double>(0.0,2.0),point<double>(2.0,4.0)),
m_line2(point<double>(2.0,4.0),point<double>(4.0,2.0)),
m_line3(point<double>(2.0,4.0),point<double>(4.0,2.0)),
m_line4(point<double>(2.0,0.0),point<double>(0.0,2.0))
{
   m_speed = enemy::randomFn(0.06,0.01);
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
    std::vector<aLine<double> > vect;
    vect.push_back(m_line1); 
    vect.push_back(m_line2);
    vect.push_back(m_line3); 
    vect.push_back(m_line4);
    return vect;

}

point<double> tanker::findPointOnTheLine(const aLine<double> &l1, const double& distanceOnTheLine)
{
    const double slope = l1.slope();
    const double teta = atan(slope);
    return l1[P1] + point<double>(distanceOnTheLine*cos(teta),distanceOnTheLine*sin(teta));
}

void tanker::move()
{
   /*

    walkPath<double> aWalkpath = refLanes->at(m_beingLane);
    m_refPoint = (aWalkpath[LLEFT][P1] + aWalkpath[LRIGHT][P2])*0.5*scale;
   */
    //swapP1P2
    if ((m_isTimeUp) && (m_currentPosition <= 1.0))
    {
        //eulidianDis

        walkPath<double> aWalkpath = m_refLanes->at(m_beingLane);
        const point<double> p1 = findPointOnTheLine(aWalkpath[LLEFT],aWalkpath[LLEFT].eulidianDis()*m_currentPosition);
        const point<double> p2 = findPointOnTheLine(aWalkpath[LRIGHT].swapP1P2(),aWalkpath[LRIGHT].eulidianDis()*m_currentPosition);
        const double widthRatio = 2.0/aLine<double>(aWalkpath[LLEFT][P1],aWalkpath[LRIGHT][P2]).eulidianDis();
        const double newBaseLine = aLine<double>(p1,p2).eulidianDis();
        const double sizeForNewTanker = widthRatio*newBaseLine;

        std::cout<<"mx euDi ll and lr :"<<aLine<double>(aWalkpath[LLEFT][P2],aWalkpath[LRIGHT][P1]).eulidianDis()<<"\n";
        std::cout<<" euDis ll and lr :"<<aLine<double>(aWalkpath[LLEFT][P1],aWalkpath[LRIGHT][P2]).eulidianDis()<<" p1 p2 eu:"<<newBaseLine<<"\n";
        std::cout<<" p1 x,y :"<<p1[X]<<" "<<p1[Y]<<" lL(X,Y):"<<aWalkpath[LLEFT][P1][X]<<" "<<aWalkpath[LLEFT][P1][Y]<<" \n";
        std::cout<<" p2 x,y :"<<p2[X]<<" "<<p2[Y]<<" lR(X,Y):"<<aWalkpath[LRIGHT][P2][X]<<" "<<aWalkpath[LRIGHT][P2][Y]<<" \n";
        std::cout<<" refpoint :"<<m_refPoint[X]<<" "<<m_refPoint[Y]<<"\n";

        const point<double> p3 = findPointOnTheLine(aLine<double>(p1,p2),(newBaseLine - sizeForNewTanker)*0.5);
        const point<double> p4 = findPointOnTheLine(aLine<double>(p1,p2),sizeForNewTanker+(newBaseLine - sizeForNewTanker)*0.5);
        m_line1 = aLine<double>(p3,p4)*m_scale + m_refPoint*(800.0/640.0);
   //     m_line1 = m_line1*(800.0/640.0);

       // m_line2 = aLine<double>(m_refPoint,point<double>(640,480))*(800.0/640.0);

        // the tanker body as 4 constant lines
        const aLine<double> l1(point<double>(0.0,2.0),point<double>(2.0,4.0));
        const aLine<double> l2(point<double>(2.0,4.0),point<double>(4.0,2.0));
        const aLine<double> l3(point<double>(4.0,2.0),point<double>(2.0,0.0));
        const aLine<double> l4(point<double>(2.0,0.0),point<double>(0.0,2.0));
        const point<double> offsetPoint(-2,-2);
      //  const double multiVal = 0.5*m_scale;
  //      m_line1 = ( l1 + offsetPoint+(aWalkpath[LLEFT][P1] + aWalkpath[LRIGHT][P2])*0.5)*m_scale + m_refPoint;
        //m_line2 = ( l2 + offsetPoint+(aWalkpath[LLEFT][P1] + aWalkpath[LRIGHT][P2])*0.5)*m_scale + m_refPoint;

        m_line3 = ( l3 + offsetPoint+(aWalkpath[LLEFT][P1] + aWalkpath[LRIGHT][P2])*0.5)*m_scale + m_refPoint;
        m_line4 = ( l4 + offsetPoint+ (aWalkpath[LLEFT][P1] + aWalkpath[LRIGHT][P2])*0.5)*m_scale + m_refPoint;

        //std::cout<<" sdsfdfd ";
        m_currentPosition += m_speed;

    }
    else
    {
        // Do nothing
    }
    enemy::move();

}