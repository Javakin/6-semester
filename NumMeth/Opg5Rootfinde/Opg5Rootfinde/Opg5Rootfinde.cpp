// Opg5Rootfinde.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <nr3.h>
#include "rootsv2.h"
#include <iostream>
#include <math.h>

using namespace std;

struct funk {
	funk() {}
	Doub operator()(Doub x) const { return x - cos(x); }
};


int main()
{
	funk fx;
	cout << "The value is:" << fx(0) << endl;
	
	rtbis(fx, 0, 3.1415 / 2, 1e-8);
	rtsec(fx, 0, 3.1415 / 2, 1e-16);
	rtflsp(fx, 0, 3.1415 / 2, 1e-16);
	zriddr(fx, 0, 3.1415 / 2, 1e-16);
	rtnewt(fx, 0, 3.1415 / 2, 1e-16);

	system("pause");
    return 0;
}

