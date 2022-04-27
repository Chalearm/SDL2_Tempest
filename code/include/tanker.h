#ifndef __TANKER__
#define __TANKER__
#include "enemy.h"
#include "aLine.h"

class tanker : public enemy
{
private:

public:
	tanker(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale, const point<double>& refPoint);
	~tanker();
	tanker(const tanker& obj);
	tanker& operator=(const tanker& obj);
	void move();
};

#endif /* define (__TANKER__) */
