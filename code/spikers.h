#ifndef __SPIKERS__
#define __SPIKERS__
#include "enemy.h"
#include "aLine.h"

class spikers : public enemy
{
private:
    aLine<double> m_movingTrack;

public:
	spikers(std::vector<walkPath<double> > &refLanes,const point<double>& refPoint);
    ~spikers();
    void move();
};

#endif /* define (spikers) */
