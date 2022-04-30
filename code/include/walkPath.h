//  
//
//     walkPath
//
//     define in header walkPath
//     class walkPath
//     
//     provides the scope area for all lanes as the set of line and point 
//     this is used for player and enemy movement and the sets is also used for 
//     creating the level as polygon. The set of line is a lane in a level:
//     - line at right side 
//     - line at left side
//     - line of edge
//
//

#ifndef __WALKPATH__
#define __WALKPATH__ 
#include <map>
#include <vector>
#include "point.h"
#include "aLine.h"

template <class T>
class walkPath
{
private:
	aLine<T> m_lLeft;
	aLine<T> m_lEdge;
	aLine<T> m_lRight;
public:
	walkPath(const point<T>& p1 = point<T>(), const point<T>& p2 = point<T>(), const point<T>& p3 = point<T>(), const point<T>& p4 = point<T>());
	walkPath(const aLine<T>& ll,const aLine<T>& le, const aLine<T>& lr);
	walkPath(const std::vector<point<T> >& obj);
	walkPath(const std::vector<aLine<T> >& obj);
	walkPath(const walkPath<T>& obj);
	walkPath(const std::map<WalkPathType,aLine<T> > &obj);
	walkPath<T>& operator=(const walkPath<T> &obj);
    walkPath<T> operator*(const T& val)const;
	bool operator==(const walkPath<T> &obj);
	aLine<T> operator[](const WalkPathType &val)const;
	walkPath<T> translate(const point<T>& aRefPoint)const;

};

template<class T>
walkPath<T>::walkPath(const point<T>& p1, const point<T>& p2, const point<T>& p3, const point<T>& p4):
m_lLeft(p1,p2),
m_lEdge(p2,p3),
m_lRight(p3,p4)
{}

template<class T>
walkPath<T>::walkPath(const aLine<T>& ll,const aLine<T>& le, const aLine<T>& lr):
m_lLeft(ll),
m_lEdge(le),
m_lRight(lr)
{}

template<class T>
walkPath<T> walkPath<T>::translate(const point<T>& aRefPoint)const
{
	return walkPath<T>(m_lLeft + aRefPoint, m_lEdge + aRefPoint, m_lRight + aRefPoint);
}

template<class T>
walkPath<T> walkPath<T>::operator*(const T& val)const
{
    return 	walkPath<T>(m_lLeft*val, m_lEdge*val, m_lRight*val);	
}

template<class T>
walkPath<T>::walkPath(const walkPath<T> &obj):
m_lLeft(obj.m_lLeft),
m_lEdge(obj.m_lEdge),
m_lRight(obj.m_lRight)
{}
template<class T>
walkPath<T>::walkPath(const std::map<WalkPathType,aLine<T> > &obj):
m_lLeft(obj[LLEFT]),
m_lEdge(obj[LEDGE]),
m_lRight(obj[LRIGHT])
{}

template<class T>
walkPath<T>& walkPath<T>::operator=(const walkPath<T> &obj)
{
	if (this != &obj)
	{
		m_lLeft = obj.m_lLeft;
		m_lEdge = obj.m_lEdge;
		m_lRight = obj.m_lRight;
	}
	else
	{
		// Do nothing
	}
	return *this;
}

template<class T>
walkPath<T>::walkPath(const std::vector<point<T> >& obj)
{
	if (obj.size() >= 4)
	{
		m_lLeft = aLine<T>(obj[0],obj[1]);
		m_lEdge = aLine<T>(obj[1],obj[2]);
		m_lRight = aLine<T>(obj[2],obj[3]);
	}
	else
	{
		// Do nothing
	}
}

template<class T>
walkPath<T>::walkPath(const std::vector<aLine<T> >& obj)
{
	if (obj.size() >= 3)
	{
        m_lLeft = obj[0];
        m_lEdge = obj[1];
        m_lRight = obj[2];
	}
	else
	{
		// Do nothing
	}
}

template<class T>
bool walkPath<T>::operator==(const walkPath<T> &obj)
{
	return ((m_lLeft == obj.m_lLeft) && (m_lEdge == obj.m_lEdge) && (m_lRight == obj.m_lRight));
}

template<class T>
aLine<T> walkPath<T>::operator[](const WalkPathType &val)const
{
	aLine<T> ret = m_lLeft;
    switch(val)
    {
    	case LLEFT:
    	    ret = m_lLeft;
    	break;
    	case LEDGE:
    	    ret = m_lEdge;
    	break;
    	case LRIGHT:
    	    ret = m_lRight;
    	break;
    	default:
    	    ret = m_lLeft;
    	break;
    }
    return ret;
}

#endif /* define (__WALKPATH__) */
