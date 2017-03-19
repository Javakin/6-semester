// ManExerc1.cpp : Defines the entry point for the console application.
//

// Mandexer1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <nr3.h>
#include "utilities.h"
#include <svd.h>
#include <math.h>

using namespace std;

int main()
{
	// the task: use the svd algorithm to solve the exercise
	

	// improt the files in the code
	MatDoub d1(500, 4);
	ifstream file1("d2");
	for (int i = 0; i < d1.nrows(); i++) {
		for (int j = 0; j < d1.ncols(); j++)
		{
			file1 >> d1[i][j];
		}
	}
	//cout << cos(3.1415) << "  " << sin(0) << "\n";
	cout << 3 / 2;
	//util::print(d1, "d1");

#pragma region fill
	// setup  pontius
	MatDoub A(1000, 4);
	
	for (int i = 0; i < A.nrows(); i=i+2)
	{
		A[i][0] = 1;
		A[i][1] = 0;
		A[i][2] = cos(d1[i / 2][0]);
		A[i][3] = cos(d1[i / 2][0] + d1[i / 2][1]);
		
		A[i+1][0] = 0;
		A[i+1][1] = 1;
		A[i+1][2] = sin(d1[i / 2][0]);
		A[i+1][3] = sin(d1[i / 2][0] + d1[i / 2][1]);
	}
#pragma endregion

	VecDoub zPoint(1000);
	for (int i = 0; i < zPoint.size(); i = i + 2)
	{
		zPoint[i] = d1[i/2][2];
		zPoint[i+1] = d1[i / 2][3];
	}

	//util::print(A, "The a matrix");

	// solve the, problem using SVD 
	VecDoub_O x_pont_sol(4);
	SVD myStuff(A);
	myStuff.solve(zPoint, x_pont_sol);
	

	// display the soluiton and relevant. information on the screen
	util::print(x_pont_sol, "solution:");

	//util::print(myStuff.u, "U-vec:");
	util::print(myStuff.v, "V-vec:");
	util::print(myStuff.w, "W-vec:");

	// terminate the program
	system("pause");
	return 0;
}



