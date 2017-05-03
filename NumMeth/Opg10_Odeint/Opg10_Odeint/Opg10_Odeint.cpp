// Opg10_Odeint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "nr3.h"
#include "odeint.h"
#include "stepper.h"
#include "StepperDopr5.h"
#include "stepperross.h"
#include "TableHandle.h"
#include <vector>
#include <string>
#include "Opg10_Odeint.h"

using namespace std;

struct rhs_van { 
	Doub eps; 
	rhs_van() {} 
	void operator() (const Doub x, VecDoub_I &y, VecDoub_O &dydx) { 
		dydx[0] = y[0]*y[1]; 
		dydx[1] = pow(-y[0],2); 
	} 
};


int main()
{
	// *************************************************
	// part one
	// *************************************************
	const int numOfSamples = 20;
	const Int nvar = 2; 
	const Doub atol = 1.0e-6, rtol = atol, h1 = 0.01, hmin = 0.0, x1 = 0.0, x2 = 1.0; 
	VecDoub ystart(nvar); ystart[0] = 1.0; ystart[1] = 1.0; 
	Output out(numOfSamples);
	rhs_van d; 
	
	Odeint<StepperDopr5<rhs_van> > ode(ystart, x1, x2, atol, rtol, h1, hmin, out, d); 
	ode.integrate();

	// print the output
	TableHandle part1(vector<string>{ "t_i", "y1_i", "y2_i" });
	vector<double> vdRow(3);

	cout << "printing.\n";
	for (Int i = 0; i < out.count; i++) {
		vdRow[0] = (double)out.xsave[i];
		vdRow[1] = (double)out.ysave[0][i];
		vdRow[2] = (double)out.ysave[1][i];
		part1.addRow(vdRow);
	}

	part1.print("Printed part#1");
	part1.exportTableCSV("exe1_"+ to_string(numOfSamples));

	// *************************************************
	// part two
	// *************************************************

	Output out2(numOfSamples);

	Odeint<StepperRoss<rhs_van> > ode2(ystart, x1, x2, atol, rtol, h1, hmin, out2, d);
	ode2.integrate();

	// print the output
	TableHandle part2(vector<string>{ "t_i", "y1_i", "y2_i" });

	cout << "printing.\n";
	for (Int i = 0; i < out2.count; i++) {
		vdRow[0] = (double)out2.xsave[i];
		vdRow[1] = (double)out2.ysave[0][i];
		vdRow[2] = (double)out2.ysave[1][i];
		part2.addRow(vdRow);
	}

	part2.print("Printed part#2");
	part2.exportTableCSV("exe2_" + to_string(numOfSamples));



	system("pause");
    return 0;
}

