// Mandexer1.cpp :the task: use the svd algorithm to solve the exercise

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
	

#pragma region input
	// improt the files in the code
	MatDoub d1(500, 4);
	ifstream file1("d2");
	for (int i = 0; i < d1.nrows(); i++) {
		for (int j = 0; j < d1.ncols(); j++)
		{
			file1 >> d1[i][j];
		}
	}
#pragma endregion


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


	VecDoub zPoint(1000);
	for (int i = 0; i < zPoint.size(); i = i + 2)
	{
		zPoint[i] = d1[i/2][2];
		zPoint[i+1] = d1[i / 2][3];
	}
#pragma endregion


#pragma region SolveUsingSVD
	// solve the, problem using SVD 
	VecDoub_O q(4);
	SVD myStuff(A);
	myStuff.solve(zPoint, q);
	

	// display the soluiton and relevant. information on the screen
	util::print(q, "solution:");

	//util::print(myStuff.u, "U-vec:");
	util::print(myStuff.v, "V-vec:");
	util::print(myStuff.w, "W-vec:");
#pragma endregion


#pragma region pseudoinvers_solution
	// Soltion using pseudoinver 
	auto UT = util::Transpose(myStuff.u);
	auto b = zPoint;
	auto V = myStuff.v;
	auto Wi = myStuff.w;

	for (int i = 0; i < Wi.size(); i++)
	{
		if (Wi[i] < 0.05)
			Wi[i] = 0;
		else
			Wi[i] = 1 / Wi[i];
	}
	auto diagWi = util::diag(Wi);
	// perform calculation
	VecDoub x_sol = V*diagWi*UT*b;

	util::print(diagWi, "Diag-Wi:");
	util::print(x_sol, "This is the pseudoinvers_solution:");

#pragma endregion




#pragma region CalError
	// Calculate error ||Aq-z||
	auto q2 = A*q;
	double Error = 0;

	for (int i = 0; i < q2.size(); i++)
	{
		q2[i] = q2[i] - zPoint[i];
		Error += pow(q2[i], 2);
	}
	Error = sqrt(Error);
	cout << "The error is; " << Error << endl;
#pragma endregion


	// terminate the program
	system("pause");
	return 0;
}



