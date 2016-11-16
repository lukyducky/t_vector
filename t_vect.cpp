#include "t_vect.h"
#include <iostream>
using namespace std;



template <class T>
vect<T>::vect() //default CTOR
{
	size = 3; //default size is 3
	p = new T[size]; //make an array of size 3
}

template <class T>
vect<T>::vect(int n) //CTOR for vect of size n
{
	if (n < 0) //ensures that size is positive
	{
		cerr << "illegal: size cannot be negative" << endl; //prints error message
		exit(1); //exits
	}

	size = n; //set size to n
	p = new T[n]; // make new array of size n

}

template <class T>
vect<T>::vect(const T a[], int n) //makes a vector from an existing array
{
	if (n < 0) //ensures that size is positive
	{
		cerr << "illegal: size cannot be negative" << endl; //prints error message
		exit(1); //exit
	}

	size = n; //sets size to n
	p = new T[size]; //makes a new array of size n; p points to this array
	for (int i = 0; i < size; i++)//loops through array
	{
		p[i] = a[i]; //sets values of p to values of array
	}
}


template <class T>
vect<T>::vect(const vect<T>& v) //copy CTOR
{
	size = v.size; //size is now v.size
	p = new T[size]; //make new array of size

	for (int i = 0; i < size; ++i) //loops through our array
	{
		p[i] = v.p[i]; //sets values of p to values of v.p
	}

}

template <class T>
vect<T>& vect<T>::cross(const vect<T>& v) //cross product
{
	vect<T>* out = new vect<T>; //new vect out to hold our values
	//find the x-y-z values using cross product equation
	out->p[0] = (this->p[1] * v.p[2]) - (this->p[2] * v.p[1]);
	out->p[1] = (this->p[2] * v.p[0]) - (this->p[0] * v.p[2]);
	out->p[2] = (this->p[0] * v.p[1]) - (this->p[1] * v.p[0]);
	return *out;//return out
}

template <class T>
T vect<T>::dot(const vect<T>& v) //dot product
{
	return (this->p[0] * v.p[0]) + (this->p[1] * v.p[1]) + (this->p[2] * v.p[2]); //multiple component size and add together
}

//operator overloader
template <class T>
vect<T>& vect<T>::operator = (const vect<T>& v) //assignment operator 
{
	int s = (size < v.size) ? size : v.size; //give s the smaller size
	for (int i = 0; i < size; i++) //looping through the array
	{
		this->p[i] = v.p[i]; //setting values of lhs to rhs
	}
	return *this; //return our lhs vector. 
}


template <class T>
vect<T>& vect<T>::operator + (const vect<T>& v)//overloading vector addition
{
	vect<T>*out = new vect<T>; //new vect out to hold our value
	out->setP(this->p[0] + v.p[0], this->p[1] + v.p[1], this->p[2] + v.p[2]); //adding component wise, and setting out to have the sum
	return *out; //return out

}

template <class T>
vect<T>& vect<T>::operator - (const vect<T>& v)//overloading vector substraction
{
	vect<T> *out = new vect<T>; //new vect out
	out->setP(this->p[0] - v.p[0], this->p[1] - v.p[1], this->p[2] - v.p[2]); //subtracting component wise; setting out to hold the difference
	return *out; //return data at out

}

//template <class T>
//vect<T>& operator * (T s, const vect<T>& v) //scalar multiplucation



template <class T>
vect<T>& vect<T>::operator += (const vect<T>& v) //overloading +=
{
	this->setP(this->p[0] + v.p[0], this->p[1] + v.p[1], this->p[2] + v.p[2]); //setting values of our lhs vector to be the sum of lhs and rhs; adding componentwise
	return *this; //returning our lhs

}

template <class T>
vect<T>& vect<T>::operator -= (const vect<T>& v)
{
	this->setP(this->p[0] - v.p[0], this->p[1] - v.p[1], this->p[2] - v.p[2]);//setting values of our lhs to be difference of lhs and rhs; subtracting component wise
	return *this; //returning the lhs
}

//explicit instantiation

template class vect<int>;
template class vect<float>;
//template class vect<double>;
//template class vect<char>;


