//  
//
//     point
//
//     define in header <point>
//     template<class T> class point<T>
//     
//     Point is a point in the XY plane or 2-dimensions has members only x and y, 
//     provides the basic operations in mathematic (+, -, * and /),
//     and extra methods as the following :
//     - norm-2 function
//     - Y/X ratio function
//     - compare function 
//     - accessibility (operator[]) to the X or Y member 
//
//     Exammple :
//     point<float> p1(3.0,0.0);
//     point<float> p2(3.0,4.0);
//     point<float> p3(0.0,0.0);
//     float ditanceP1P3 = (p2 - p3).norm2();
//

#ifndef __POINT__
#define __POINT__
#include <iostream>
#include <cmath>
#include "gameDataType.h"
template <class T>
class point
{
private:
	T m_x;
	T m_y;
public:
	point(const T& x = 0,const T& y = 0);
	point(const point<T>& obj);
	~point();
	point<T>& operator=(const point<T>& obj);
	point<T> operator+(const point<T>& obj)const;
    point<T> operator-(const point<T>& obj)const;
    point<T> operator/(const T val);
	point<T>& operator+=(const point<T>& obj);
    point<T>& operator-=(const point<T>& obj);
    point<T> operator*(const T& val)const;
    T operator[](const pointType val)const;
    bool operator==(const point<T>& obj);
    T yDividedByX()const;
    T norm2() const;

};


template <class T>
point<T>::point(const T& x,const T& y):
m_x(x),
m_y(y)
{}

template <class T>
point<T>::point(const point<T>& obj):
m_x(obj.m_x),
m_y(obj.m_y)
{}

template <class T>
point<T>::~point<T>()
{}

template <class T>
point<T>& point<T>::operator=(const point<T>& obj)
{
    if (this != &obj)
    {
        m_x = obj.m_x;
        m_y = obj.m_y;
    }
    else
    {
    	// Do nothing
    }
    return *this;
}

template <class T>
point<T> point<T>::operator/(const T val)
{
    return point<T>(m_x/val,m_y/val);
}

template <class T>
point<T> point<T>::operator+(const point<T>& obj)const
{
	return point<T>(m_x+obj.m_x,m_y+obj.m_y);
}

template <class T>
point<T> point<T>::operator-(const point<T>& obj)const
{
	return point<T>(m_x-obj.m_x,m_y-obj.m_y);
}

template <class T>
point<T> point<T>::operator*(const T& val)const
{
	return point<T>(m_x*val,m_y*val);
}

template <class T>
T point<T>::operator[](const pointType val)const
{
	T ret = m_x;
    switch(val)
    {
    	case X:
    	    ret = m_x;
    	break;
    	case Y:
    	    ret = m_y;
    	break;
    	default:
    	    ret = m_x;
    	break;
    }
    return ret;
}
template <class T>
point<T>& point<T>::operator+=(const point<T>& obj)
{
	if (this != &obj)
	{
		m_x += obj.m_x;
		m_y += obj.m_y;
	}
	else
	{
		m_x += m_x;
		m_y += m_y;
	}
    return *this;
}

template <class T>
point<T>& point<T>::operator-=(const point<T>& obj)
{
	if (this != &obj)
	{
		m_x -= obj.m_x;
		m_y -= obj.m_y;
	}
	else
	{
		m_x = 0;
		m_y = 0;
	}
    return *this;
}

template <class T>
T point<T>::yDividedByX() const
{
	T ret = T();
	if (m_x != T())
	{
         ret = m_y/m_x;
	}
	else
	{
		// Do nothing
	}
	return ret;
}
template <class T>
T point<T>::norm2() const
{
	return pow(m_x*m_x + m_y*m_y,0.5);
}
template <class T>
bool point<T>::operator==(const point<T>& obj)
{
	return ((m_x == obj.m_x) && (m_y == obj.m_y));
}
#endif /* define (__point__) */
