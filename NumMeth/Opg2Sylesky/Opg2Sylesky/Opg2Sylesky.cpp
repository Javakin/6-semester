// Opg2Sylesky.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <nr3.h>
#include "utilities.h"

using namespace std;

int main() {

	cout << "==========================\n";
	cout << "Display the Filip vector  \n";
	cout << "==========================\n";

	VecDoub xFilip(82); VecDoub yFilip(82);
	ifstream Filip("FilipData.dat");
	for (int i = 0; i < 82; i++) {
		Filip >> yFilip[i];
		Filip >> xFilip[i];
		//cout << xFilip[i] << "\t" << yFilip[i] << "\n";
	}

	cout << "==========================\n";
	cout << "Display the pontius vector\n";
	cout << "==========================\n";

	VecDoub xPont(40); VecDoub yPont(40);
	ifstream Pont("PontiusData.dat");
	for (int i = 0; i < 40; i++) {
		Pont >> yPont[i];
		Pont >> xPont[i];
		//cout << xPont[i] << "\t" << yPont[i] << "\n";
	}

	// Defiine the equations
	MatDoub A(40, 3);
	MatDoub b(40, 1);

	for (int i = 0; i < 40; i++)
	{
		A[i][0] = 1;
		A[i][1] = xPont[i];
		A[i][2] = xPont[i]*xPont[i];
	}

	// perform the decompositions

	// using choldc 

	// using ludcmp
	

	//calculate the solution


	// print soluiton
	util::print(A, "This is a test");
	
	util::print(xPont, "xPoint");
	util::print(yPont, "yPoint");

	system("pause");
	return 0;
}

