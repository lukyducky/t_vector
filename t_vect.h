#ifndef _T_VECT_H
#define _T_VECT_H
#include <iostream>

template <class T>
class vect{
public:
	vect(); //default CTOR
	vect(int n);
	vect(const T a[], int n);
	vect(const vect<T>& v); //copy CTOR
	~vect(){ delete[]p; } //our DTOR

	int ub(){ return (getSize() == 3)? true: false; } //gives upper bound
	int getSize(){ return size; }

	void setP(T x, T y, T z) //set your position, or your x-y-z's.
	{
		if (!ub()) //if it is not in bounds
		{
			cerr << "illegal size" << endl; //print error message
			exit(1); //exit program
		}
		else //if it is in bounds
		{
			//set our values: 0 -> x,  1 -> y, 2-> z
			p[0] = x; 
			p[1] = y;
			p[2] = z;
		}
	}

	friend std::ostream& operator <<(std::ostream&os, const vect<T>& v)
	{
		os << "(" << v.p[0] << ", " << v.p[1] << ", " << v.p[2] << ")";
		return os;
	}

	vect<T>& cross(const vect<T>& v); //cross product

	T dot(const vect<T>& v); //dot product

	//operator overloader
	vect<T>& operator = (const vect<T>& v); 
	vect<T>& operator + (const vect<T>& v);
	vect<T>& operator - (const vect<T>& v);

	//scalar multiplucation overloading
	friend vect<T>& operator * (T s, const vect<T>& v)
	{
		vect<T> *out = new vect<T>; //new vect out
		out->setP(s*v.p[0], s*v.p[1], s*v.p[2]); //setting out to hold the product
		return *out; //return data at out

	}

	//same as the previous
	friend vect<T>& operator * (const vect<T>& v, T s)
	{
		vect<T> *out = new vect<T>; //new vect out
		out->setP(s*v.p[0], s*v.p[1], s*v.p[2]); //setting out to hold the product
		return *out; //return data at out

	}

	vect<T>& operator += (const vect<T>& v);
	vect<T>& operator -= (const vect<T>& v);
	
	



private: //private data members
	int size;//size is an int
	T *p; //poiter p of type T; is our position in the array
};





#endif
