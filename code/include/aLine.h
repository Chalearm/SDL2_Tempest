#ifndef __ALINE__
#define __ALINE__
#include <iostream>
#include <cmath>
#include "point.h"


template <class T>
class aLine
{
private:
	point<T> m_p1;
	point<T> m_p2;
public:
	aLine<T>(const point<T>& p1 = point<T>(),const point<T>& p2 = point<T>());
	aLine<T>(const aLine<T>& obj);
	~aLine<T>();
	aLine<T>& operator=(const aLine<T>& obj);
    bool operator==(const aLine<T>& obj);
    point<T> operator[](const lineType& val) const;
    aLine<T> operator*(const T& val)const;
    aLine<T> operator+(const point<T>& val)const;
    aLine<T> swapP1P2();
    T slope() const;
    T euclidianDis() const;

};

template <class T>
aLine<T>::aLine(const point<T>& p1,const point<T>& p2):
m_p1(p1),
m_p2(p2)
{}

template <class T>
aLine<T>::aLine(const aLine<T>& obj):
m_p1(obj.m_p1),
m_p2(obj.m_p2)
{}
template <class T>
aLine<T>::~aLine<T>()
{}

template <class T>
aLine<T> aLine<T>::operator*(const T& val) const
{
	return aLine<T>((*this)[P1]*val,(*this)[P2]*val);
}

template <class T>
aLine<T> aLine<T>::swapP1P2()
{
	return aLine<T>(m_p2,m_p1);
}

template <class T>
point<T> aLine<T>::operator[](const lineType& val) const
{
	point<T> ret = m_p1;
    switch(val)
    {
    	case P1:
    	    ret = m_p1;
    	break;
    	case P2:
    	    ret = m_p2;
    	break;
    	default:
    	    ret = m_p1;
    	break;
    }
    return ret;
}

template<class T>
aLine<T> aLine<T>::operator+(const point<T>& val)const
{
	return aLine<T>(m_p1+val,m_p2+val);
}

template <class T>
aLine<T>& aLine<T>::operator=(const aLine<T>& obj)
{
	if (this != &obj)
	{
        m_p1 = obj.m_p1;
        m_p2 = obj.m_p2;
	}
	else
	{
		// Do nothing
	}
	return *this;
}

template <class T>
bool aLine<T>::operator==(const aLine<T>& obj)
{
	return ((m_p1 == obj.m_p1) && (m_p2 == obj.m_p2));
}

template <class T>
T aLine<T>::euclidianDis() const
{
    return pow((m_p1-m_p2).norm2(),0.5);
}

template <class T>
T aLine<T>::slope() const
{
	point<T> aPoint = m_p2 - m_p1;
	return aPoint.dybydx();
}
#endif /* define (__aLine<T>__) */