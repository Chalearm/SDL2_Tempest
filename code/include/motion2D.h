//  
//
//     motion2D
//
//     define in header motion2D
//     abstract class motion2D
//     
//     motion2D is an abstract class providing the utility method for movement in the plane-XY or 2D.
//
//
#ifndef __MOTION2D__
#define __MOTION2D__
#include <random>
#include <vector>
#include <memory>
#include <ctime>
#include "color.h"
#include "point.h"
#include "walkPath.h"
#include "lineWithColor.h"

class motion2D
{
protected:

	std::vector<lineWithColor> m_lines;
	std::shared_ptr<std::vector<walkPath<double> > > m_refLanes; // (the reference of the lanns where enemy can go around)
	point<double> m_refPoint; // the center point of the level (polygon)
	color m_bodyColor;
	double m_scale;
     // random fundion
	std::random_device m_rd;
    std::mt19937 m_gen;

    // time counter
    double m_timeCount;
    std::clock_t m_startTime;
	bool m_isTimeUp;

	double findTetaFromALine(const aLine<double> &l1);
	void addToLineVect(const point<double>& p1,const point<double>& p2, const color& col);
	void addToLineWitBodyColorVect(const point<double>& p1,const point<double>& p2);
	aLine<double> scaleAndTranslate(const aLine<double>& obj);
	point<double> findPointOnTheLine(const aLine<double> &l1, const double& distanceOnTheLine);
	point<double> findPointInBetweenALane(const walkPath<double> &w,const double& percentageOfDistance =0.0, const double& percentageOfDistBetweenRLline = 0.0); // 0 - 100% = 0.00 to 1.00

    void setTimeCount(const double& time);
    bool isTimeup();

public:
    motion2D(std::shared_ptr<std::vector<walkPath<double> > > &refLanes, const double& scale, const point<double>& refPoint);
    motion2D(const motion2D& obj);
    motion2D& operator=(const motion2D& obj);
	virtual ~motion2D();
	virtual void move() = 0;
    double randomFn(double max,double min);
};

#endif /* define (__MOTION2D__) */
