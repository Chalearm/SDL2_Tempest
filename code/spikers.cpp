#include "spikers.h"

class spikers : public enemy
{
private:
    aLine<double> m_movingTrack;

public:
	spikers(std::vector<walkPath<double> > &refLanes,const point<double>& refPoint);
    ~spikers();
    void move();
};



spikers::spikers(std::vector<walkPath<double> > &refLanes,const point<double>& refPoint):
enemy(refLanes,refPoint),
m_movingTrack()
{
	// random speed 1 - 3%
	m_speed = randomFn(3.0,1.0);
	// find the center point of the bottom line in the lane
    // to create a line of moving track

}

spikers::~spikers()
{

}

void spikers::move()
{

}