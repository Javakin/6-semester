//
// The purpose of this project is to develop a standard class for displaying tables of data
// the source.cpp is for testing 
// Developed by Daniel Haraldson - 26-Apr-17
//


#include <iostream>
#include "TableHandle.h"
#include <string>
#include <vector>

#include <iomanip>

using namespace std;


int main()
{
	TableHandle tab(vector<string>{"Time", "x0", "f", "g", "j"});
	//tab.print("Printing Tab#1");

	vector<double> vdR1 = { 1.05, 1558758481.123456789 ,1, 884.8, 15.58 };
	tab.addRow(vdR1);
	tab.addRow(vdR1);
	tab.addRow(vdR1);
	tab.addRow(vdR1);
	tab.addRow(vdR1);
	tab.addRow(vdR1);


	tab.print("Numbers");
	tab.exportTableCSV("Numbers");

	//system("pause");
	return 0;
}

