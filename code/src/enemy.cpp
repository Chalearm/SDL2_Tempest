#include "enemy.h"

std::random_device enemy::s_rd;
std::mt19937 enemy::s_gen;

enemy::enemy(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint):
m_refPoint(refPoint),
m_lines(),
m_scale(scale),
m_currentPosition(0),
m_speed(0),
m_refLanes(refLanes),
m_beingLane(0),
m_isAlive(true),
m_timeToMove(0.01),  // 0.3 second
m_startTime(std::clock()),
m_isTimeUp(false)
{
	//m_refLanes = refLanes;
	m_beingLane = static_cast<int>(randomFn(refLanes->size()-1,0.0));
}

enemy::enemy(const enemy& obj):
m_refPoint(obj.m_refPoint),
m_lines(obj.m_lines),
m_currentPosition(obj.m_currentPosition),
m_speed(obj.m_speed),
m_refLanes(obj.m_refLanes),
m_beingLane(obj.m_beingLane),
m_isAlive(obj.m_isAlive),
m_timeToMove(obj.m_timeToMove),  // 0.3 second
m_startTime(obj.m_startTime),
m_isTimeUp(obj.m_isTimeUp)
{}


enemy& enemy::operator=(const enemy& obj)
{
    if (this != &obj)
    {
    	
    	m_refPoint = obj.m_refPoint;
    	m_lines = obj.m_lines;
      m_currentPosition = obj.m_currentPosition;
      m_speed = obj.m_speed;
      m_refLanes = obj.m_refLanes;
      m_beingLane = obj.m_beingLane;    // which lane where enemy stays
      m_isAlive = obj.m_isAlive;
      m_timeToMove = obj.m_timeToMove;
      m_isTimeUp = obj.m_isTimeUp;
        
       // enemy::enemy(obj);
    }
    else
    {
    	// Do nothing
    }
    return *this;
}

enemy::~enemy()
{
	m_isAlive = false;
}
bool enemy::isHitTheBullet(const point<double> &bulletPoint)
{
   return true;
}

std::vector<aLine<double> > enemy::drawEnemy()
{
	return m_lines;
}
bool enemy::isAlive()const
{	
	return m_isAlive;
}

void enemy::move()
{
	const double duration = ( std::clock() - m_startTime ) / (double) CLOCKS_PER_SEC;
	m_isTimeUp =  (duration > m_timeToMove);
	if (m_isTimeUp)
	{
		m_startTime = std::clock();
	}
	else
	{
		// Do nothing
	}

}

void enemy::addToLineVect(const point<double>& p1,const point<double>& p2)
{
	m_lines.push_back(scaleAndTranslate(aLine<double>(p1,p2)));
}

aLine<double> enemy::scaleAndTranslate(const aLine<double>& obj)
{
    return obj*m_scale + m_refPoint;
}

point<double> enemy::findPointInBetweenALane(const walkPath<double> &w,const double& percentageOfDistance, const double& percentageOfDistBetweenRLline) // 0 - 100% = 0.00 to 1.00
{
	point<double> retPoint;
	const double euclidientLeftline = w[LLEFT].euclidianDis();
	const double euclidientRightline = w[LRIGHT].euclidianDis();
	const double ditanceOfThePointAtLeftLine = euclidientLeftline*percentageOfDistance;
	const double ditanceOfThePointAtRightLine = euclidientRightline*percentageOfDistance;

	const point<double> pL = findPointOnTheLine(w[LLEFT],ditanceOfThePointAtLeftLine);
	const point<double> pR = findPointOnTheLine(w[LRIGHT].swapP1P2(),ditanceOfThePointAtRightLine);
	const double ditancePLR = aLine<double>(pL,pR).euclidianDis();
   if (percentageOfDistBetweenRLline == 0.0)
   {
   	retPoint = pL;
   }
   else if (percentageOfDistBetweenRLline == 1.0)
   {
   	retPoint = pR;
   }
   else
   {
   	retPoint = findPointOnTheLine(aLine<double>(pL,pR),ditancePLR*percentageOfDistBetweenRLline);
   }
   return retPoint;

}
point<double> enemy::findPointOnTheLine(const aLine<double> &l1, const double& distanceOnTheLine)
{
    const double slope = l1.slope();
    double teta = 0;
    if (l1[P1][X] != l1[P2][X] )
    {
        teta = atan(slope);
    }
    else
    {
        teta = 1.570796; // pi/2
    }
    /*
    std::cout<<__FUNCTION__<<" being lane:"<<m_beingLane<<std::endl;

    std::cout<<"ditance :"<<distanceOnTheLine<<" fullDist:"<<l1.euclidianDis()<<" "<<this<<std::endl;
    std::cout<<" P1(x,y) :"<<"("<<l1[P1][X]<<","<<l1[P1][Y]<<")"<<std::endl;
    std::cout<<" P2(x,y) :"<<"("<<l1[P2][X]<<","<<l1[P2][Y]<<")"<<" P2.y - p1.y ;"<<(l1[P2][Y]-l1[P1][Y])<<std::endl;
    std::cout<<" slope:"<<slope<<std::endl;
    std::cout<<" cos val:"<<cos(teta)<<std::endl;
    std::cout<<" sin val:"<<sin(teta)<<std::endl;
    */
    double xSign = 1.0;
    double ySign = 1.0;
    if ((l1[P2][X] - l1[P1][X]) < 0.0) xSign = -1.0;
    if ((l1[P2][Y] < l1[P1][Y])) ySign = -1.0;
    double sinVal = sin(teta);
    double cosVal = cos(teta);
    if (sinVal < 0.0)
    {
    	sinVal *= -1.0;
    }
    else
    {
    	// Do  nothing
    }
    if (cosVal < 0.0)
    {
    	cosVal *= -1.0;
    }
    else
    {
    	// Do  nothing
    }
    const point<double> deltaPoint = point<double>(xSign*distanceOnTheLine*cosVal,ySign*distanceOnTheLine*sinVal);
    point<double> resultPoint = l1[P1] + deltaPoint;
    /*
    std::cout<<" cos value :"<<deltaPoint[X]<<std::endl;
    std::cout<<" sine value :"<<deltaPoint[Y]<<std::endl;

    std::cout<<" result (x,y) :"<<"("<<resultPoint[X]<<","<<resultPoint[Y]<<")"<<std::endl;
    */
    return resultPoint;
}

double enemy::randomFn(double max,double min)
{	
	std::uniform_real_distribution<> distrib(min,max);
	return distrib(s_gen);
}