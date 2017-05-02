// Opg10_Odeint.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "nr3.h"
#include "odeint.h"
#include "stepper.h"
#include "StepperDopr5.h"

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

	// print thw putput

	cout << "printing.\n";
	for (Int i = 0; i < out.count; i++) {
		cout << out.xsave[i] << " " << out.ysave[0][i] << " " << out.ysave[1][i] << endl;
	}


	// *************************************************
	// part two
	// *************************************************


	system("pause");
    return 0;
}

