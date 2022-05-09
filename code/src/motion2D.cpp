#include "motion2D.h"

motion2D::motion2D(const std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint):
m_lines(),
m_refLanes(refLanes),
m_refPoint(refPoint),
m_bodyColor(COLORSET[NOCOLOR]),
m_scale(scale),
m_rd(),
m_gen(m_rd()),
m_timeCount(0.0),
m_startTime(std::clock()),
m_isTimeUp(false)
{

}

motion2D::motion2D(const motion2D& obj):
m_lines(obj.m_lines),
m_refLanes(obj.m_refLanes),
m_refPoint(obj.m_refPoint),
m_bodyColor(obj.m_bodyColor),
m_scale(obj.m_scale),
m_rd(),
m_gen(m_rd()),
m_timeCount(obj.m_timeCount),
m_startTime(obj.m_startTime),
m_isTimeUp(obj.m_isTimeUp)
{
}

motion2D& motion2D::operator=(const motion2D& obj)
{
    if (this != &obj)
    {
		m_lines = obj.m_lines;
		m_refLanes = obj.m_refLanes;
		m_refPoint = obj.m_refPoint;
		m_bodyColor = obj.m_bodyColor;
		m_scale = obj.m_scale;
		m_timeCount = obj.m_timeCount;
		m_startTime = obj.m_startTime;
		m_isTimeUp = obj.m_isTimeUp;
    }
    else
    {
    	// Do nothing
    }
    return *this;
}
motion2D::~motion2D()
{
    m_lines.clear();	
}

double motion2D::findTetaFromALine(const aLine<double> &l1)
{
	 const double l_slope = l1.slope(); 
	 double l_teta = 0;
	if (l1[P1][X] != l1[P2][X] )
	{
	    l_teta = atan(l_slope);
	}
	else
	{
	    l_teta = 1.570796; // pi/2
	}
    return l_teta;
}

void motion2D::addToLineVect(const point<double>& p1,const point<double>& p2, const color& col)
{
	m_lines.push_back(lineWithColor(scaleAndTranslate(aLine<double>(p1,p2)),col));
}
void motion2D::addToLineWitBodyColorVect(const point<double>& p1,const point<double>& p2)
{
   addToLineVect(p1,p2,m_bodyColor);
}

aLine<double> motion2D::scaleAndTranslate(const aLine<double>& obj)
{
    return obj*m_scale + m_refPoint;
}

point<double> motion2D::findPointOnTheLine(const aLine<double> &l1, const double& distanceOnTheLine)
{
    double l_xSign = 1.0;
    double l_ySign = 1.0;
    const double l_teta = findTetaFromALine(l1);
    if ((l1[P2][X] - l1[P1][X]) < 0.0)
    {
        l_xSign = -1.0;
    }
    else
    {
        // Do nothing
    } 
    if ((l1[P2][Y] < l1[P1][Y]))
    {
        l_ySign = -1.0;
    } 
    else
    {
        // Do nothing
    }
    double l_sinVal = sin(l_teta);
    double l_cosVal = cos(l_teta);
    if (l_sinVal < 0.0)
    {
        l_sinVal *= -1.0;
    }
    else
    {
    	   // Do nothing
    }

    if (l_cosVal < 0.0)
    {
        l_cosVal *= -1.0;
    }
    else
    {
    	  // Do nothing
    }
    const point<double> deltaPoint = point<double>(l_xSign*distanceOnTheLine*l_cosVal,l_ySign*distanceOnTheLine*l_sinVal);
    const point<double> resultPoint = l1[P1] + deltaPoint;
    return resultPoint;
}
point<double> motion2D::findPointInBetweenALane(const walkPath<double> &w,const double& percentageOfDistance, const double& percentageOfDistBetweenRLline) // 0 - 100% = 0.00 to 1.00
{
	point<double> retPoint;
	const double euclidientLeftline = w[LLEFT].EuclideanDis();
	const double euclidientRightline = w[LRIGHT].EuclideanDis();
	const double ditanceOfThePointAtLeftLine = euclidientLeftline*percentageOfDistance;
	const double ditanceOfThePointAtRightLine = euclidientRightline*percentageOfDistance;

	const point<double> pL = findPointOnTheLine(w[LLEFT],ditanceOfThePointAtLeftLine);
	const point<double> pR = findPointOnTheLine(w[LRIGHT].swapP1P2(),ditanceOfThePointAtRightLine);
	const double ditancePLR = aLine<double>(pL,pR).EuclideanDis();
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

void motion2D::setTimeCount(const double& time)
{
    m_timeCount = time;
}
bool motion2D::isTimeup()
{
	const double duration = ( std::clock() - m_startTime ) / (double) CLOCKS_PER_SEC;
	m_isTimeUp =  (duration > m_timeCount);
	bool ret = false;
	if (m_isTimeUp)
	{
		ret = true;
		m_startTime = std::clock();
	}
	else
	{
		// Do nothing
	}
	return ret;
}

double motion2D::randomFn(double max,double min)
{	
	std::uniform_real_distribution<> distrib(min,max);
	return distrib(m_gen);
}