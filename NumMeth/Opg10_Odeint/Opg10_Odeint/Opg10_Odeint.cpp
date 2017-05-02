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
	rhs_van(Doub epss) : eps(epss) {} 
	void operator() (const Doub x, VecDoub_I &y, VecDoub_O &dydx) { 
		dydx[0] = y[1]; 
		dydx[1] = ((1.0 - y[0] * y[0])*y[1] - y[0]) / eps; 
	} 
};


int main()
{
	// *************************************************
	// part one
	// *************************************************

	const Int nvar = 2; 
	const Doub atol = 1.0e-3, rtol = atol, h1 = 0.01, hmin = 0.0, x1 = 0.0, x2 = 2.0; 
	VecDoub ystart(nvar); ystart[0] = 2.0; ystart[1] = 0.0; 
	Output out(20);
	rhs_van d(1.0e-3); 
	
	Odeint<StepperDopr5<rhs_van> > ode(ystart, x1, x2, atol, rtol, h1, hmin, out, d); 
	ode.integrate();

	// print thw putput

	cout << "printing.\n";
	for (Int i = 0; i<out.count; i++) 
		cout << out.xsave[i] << " " << out.ysave[0][i] << " " << out.ysave[1][i] << endl;

	// *************************************************
	// part two
	// *************************************************

	// *************************************************
	// part one
	// *************************************************

	// *************************************************
	// part one
	// *************************************************

	system("pause");
    return 0;
}

