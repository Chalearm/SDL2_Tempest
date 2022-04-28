#ifndef __SPIKERS__
#define __SPIKERS__
#include "enemy.h"
#include "aLine.h"
#include "lineWithColor.h"

class spikers : public enemy
{
private:
    aLine<double> m_movingTrack;
    color m_trackColor;
    double m_walkTrack; // in percent > 80%
    int m_moveDirection; // +1 increase, -1 decrease

public:
	spikers(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale,const point<double>& refPoint);
    ~spikers();
    spikers(const spikers& obj);
    spikers& operator=(const spikers& obj);
    std::vector<lineWithColor> drawEnemy();
    void move();
};

#endif /* define (spikers) */
