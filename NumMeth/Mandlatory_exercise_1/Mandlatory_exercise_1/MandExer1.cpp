// Mandexer1.cpp : Defines the entry point for the console application.
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
	/*
	
	// improt the files in the code
	MatDoub d1(500, 4);
	ifstream file1("d1");
	for (int i = 0; i < 82; i++) {
		double temp;
		file1 >> temp;
		cout << temp << "\n";
	}

	/*VecDoub xPont(40); VecDoub yPont(40);
	ifstream Pont("PontiusData.dat");
	for (int i = 0; i < 40; i++) {
		Pont >> yPont[i];
		Pont >> xPont[i];
		//cout << xPont[i] << "\t" << yPont[i] << "\n";
	}

	// setup  pontius
	MatDoub Ap(40, 3);


	*/
	//util::print(Af, "This is a test");

	// solve the, problem using SVD 
/*	VecDoub_O x_pont_sol(3);
	SVD myStuff(Ap);
	myStuff.solve(yPont, x_pont_sol);
	*/
	
	// display the soluiton and relevant. information on the screen
	//util::print(x_pont_sol, "Pontius solution:");

	
	// terminate the program
	system("pause");
    return 0;
}

