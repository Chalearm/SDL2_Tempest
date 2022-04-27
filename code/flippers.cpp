#include "flippers.h"


flippers::flippers(std::shared_ptr<std::vector<walkPath<double> > > &refLanes,const point<double>& refPoint):
enemy(refLanes,refPoint),
m_p1(),
m_p2(),
m_p3(),
m_p4()
{}

flippers::~flippers()
{

}

flippers::flippers(const flippers& obj):
enemy(obj),
m_p1(obj.m_p1),
m_p2(obj.m_p2),
m_p3(obj.m_p3),
m_p4(obj.m_p4)
{

}

flippers& flippers::operator=(const flippers& obj)
{
	if (this != &obj)
	{
		enemy::operator=(obj);
		m_p1 = obj.m_p1;
		m_p2 = obj.m_p2;
		m_p3 = obj.m_p3;
		m_p4 = obj.m_p4;
	}
	else
	{
		// Do nothing
	}
	return *this;
}
void flippers::move()
{

}
