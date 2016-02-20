#include "point.hh"

template<class A> point<A>::point()
{
	X = 0;
	Y = 0;
	Z = 0;
}

template <class A> point<A>::point( A x, A y, A z)
{
	this->X = x;
	this->Y = y;
	this->Z = z;
}

template <class A> A point<A>::getX()
{
	return this->X;
}

template <class A> A point<A>::getY()
{
	return this->Y;
}

template <class A> A point<A>::getZ()
{
	return this->Z;
}

template <class A> void point<A>::setX( A x)
{
	this->X = x;
}

template <class A> void point<A>::setY( A y)
{
	this->Y = y;
}

template <class A> void point<A>::setZ( A z)
{
	this->Z = z;
}

template class point<int>;
template class point<double>;
