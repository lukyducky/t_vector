#include "t_vect.h"

using namespace std;


int main()
{
	vect<int> V1, V2;
	vect<float> V3, V4;

	V1.setP(1, 2, 3);
	V2.setP(2, 3, 5);
	V3.setP(3.4, 5.3, 1.2);
	V4 = V3;

	cout << "V1:" << V1  << endl;



	cout << V1 << " X " << V2 << "=" << V1.cross(V2) << endl;
	cout << V1 << "dot" << V2 << "=" << V1.dot(V2) << endl;
	


	
	cout << V1 << " + " << V2 << "=" << V1 + V2 << endl;


	cout << V1 << " - " << V2 << "=" << V1 - V2 << endl;

	V1 += V2;
	cout << "V1 += V2" << V1 << endl;
	V1 -= V2;
	cout << "V1 -= V2" << V1 << endl;
	cout << V3 << " = " << V4 << endl;
	cout << V4 << " x 4 = " << 4 * V4 << endl;
	cout << V3 << " x 5 = " << V3 * 5 << endl;



	system("pause");
}