// Opg4-SVD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <nr3.h>
#include "utilities.h"
#include <svd.h>

using namespace std;

int main()
{
	// the task: use the svd algorithm to solve the exercise
	
	// improt the files in the code
	VecDoub xFilip(82); VecDoub yFilip(82);
	ifstream Filip("FilipData.dat");
	for (int i = 0; i < 82; i++) {
		Filip >> yFilip[i];
		Filip >> xFilip[i];
		//cout << xFilip[i] << "\t" << yFilip[i] << "\n";
	}

	VecDoub xPont(40); VecDoub yPont(40);
	ifstream Pont("PontiusData.dat");
	for (int i = 0; i < 40; i++) {
		Pont >> yPont[i];
		Pont >> xPont[i];
		//cout << xPont[i] << "\t" << yPont[i] << "\n";
	}

	// setup  pontius
	MatDoub Ap(40, 3);
	MatDoub Af(82,11);

	for (int i = 0; i < 40; i++)
	{
		Ap[i][0] = 1;
		Ap[i][1] = xPont[i];
		Ap[i][2] = xPont[i] * xPont[i];
	}

	for (int i = 0; i < Af.nrows(); i++)
	{
		for (int j = 0; j < Af.ncols(); j++)
		{
			Af[i][j] = pow(xFilip[i], j);
		}
	}

	//util::print(Ap, "This is a test");
	//util::print(Af, "This is a test");

	// solve the, problem using SVD 
	VecDoub_O x_pont_sol(3);
	SVD myStuff(Ap);
	myStuff.solve(yPont, x_pont_sol);
	
	VecDoub_O x_filip_sol(11);
	SVD filipSVD(Af);
	filipSVD.solve(yFilip, x_filip_sol, 0);
	
	// display the soluiton and relevant. information on the screen
	util::print(x_pont_sol, "Pontius solution:");
	util::print(x_filip_sol, "Pontius solution:");

	// terminate the program
	system("pause");
    return 0;
}

