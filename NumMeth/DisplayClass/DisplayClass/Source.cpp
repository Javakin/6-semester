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
	vector<string> vsColName = {"Time", "x0", "f", "g","j"};

	for (string s : vsColName)
		cout << s << "\n";
	cout << endl;

	TableHandle tab(vsColName);
	tab.print("Printing Tab#1");

	vector<double> vdR1 = { 1.05, 151.57878 ,1, 884.8, 15.58 };
	tab.addRow(vdR1);
	tab.print("Printing Tab#2");


	system("pause");
	return 0;
}

