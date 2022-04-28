#ifndef __TANKER__
#define __TANKER__
#include "enemy.h"
#include "aLine.h"

class tanker : public enemy
{
private:
    aLine<double> m_line1;
    aLine<double> m_line2;
    aLine<double> m_line3;
    aLine<double> m_line4;
public:
	tanker(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale, const point<double>& refPoint);
	~tanker();
	tanker(const tanker& obj);
	tanker& operator=(const tanker& obj);
	std::vector<aLine<double> > drawEnemy();
	void move();
};

#endif /* define (__TANKER__) */
