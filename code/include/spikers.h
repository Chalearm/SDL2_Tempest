#ifndef __SPIKERS__
#define __SPIKERS__
#include "enemy.h"
#include "aLine.h"

class spikers : public enemy
{
private:
    aLine<double> m_movingTrack;

public:
	spikers(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale,const point<double>& refPoint);
    ~spikers();
    spikers(const spikers& obj);
    spikers& operator=(const spikers& obj);
    std::vector<aLine<double> > drawEnemy();
    void move();
};

#endif /* define (spikers) */
