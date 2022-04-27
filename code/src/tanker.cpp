#include "tanker.h"

tanker::tanker(std::shared_ptr<std::vector<walkPath<double> > >& refLanes,const double& scale, const point<double>& refPoint):
enemy(refLanes,scale,refPoint)
{

}
tanker::~tanker()
{}

tanker::tanker(const tanker& obj):
enemy(obj)
{}

tanker& tanker::operator=(const tanker& obj)
{
    if(this != &obj)
    {
    	enemy::operator=(obj);
    }
    else
    {
    	// Do nothing
    }
    return *this;
}
void tanker::move()
{

}