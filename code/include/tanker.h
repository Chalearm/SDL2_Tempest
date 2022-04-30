//  
//
//     tanker
//
//     define in header tanker
//     class tanker
//     
//     tanker is a class for tanker object derived from enemy class
//
//

#ifndef __TANKER__
#define __TANKER__
#include "enemy.h"
#include "aLine.h"
#include "gameDataType.h"
#include "gameConstance.h"
#include "color.h"

class tanker : public enemy
{
private:
public:
	tanker(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale, const point<double>& refPoint);
	~tanker();
	tanker(const tanker& obj);
	tanker& operator=(const tanker& obj);
	std::vector<lineWithColor> drawEnemy();
	void move();
};

#endif /* define (__TANKER__) */
