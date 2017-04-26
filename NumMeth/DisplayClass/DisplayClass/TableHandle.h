/*
This class is to handle tables of data this invilves:
 - Inserting rows and collums
 - Deleating rows and collums
 - Displaying the table in an orderly facion
 - Exporting the table for externeal handling
*/


#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


// ascii definitions
#define TOPLEFT		(char) 218
#define TOPRIGHT	(char) 191
#define BUTRIGHT	(char) 217
#define BUTLEFT		(char) 192

#define FLATBAR		(char) 196
#define VERTBAR		(char) 179

#define CENTINT		(char) 197
#define TOPINT		(char) 194
#define BUTINT		(char) 193
#define LEFTINT		(char) 195
#define RIGHTINT	(char) 180

using namespace std;

class TableHandle
{
public:
	// constructor
	TableHandle();
	TableHandle(unsigned int uiCol);
	TableHandle(vector<string> vsColnames);

	// inserting
	int addRow(vector<double> vdRow);
	//void addCol(vector<double> vdCol, string sColName);
	void addRow(vector<double> vdRow, unsigned int uiIndex);
	//void addCol(vector<double> vdCol, string sColName, unsigned int uiIndex);

	// removing
	void remRow();
	//void remCol();
	void remRow(unsigned int uiIndex);
	//void remCol(unsigned int uiIndex);

	// displaying
	void print();
	void print(string description);

	// exporting
	void exportTable(string type);

	// destructor
	~TableHandle();

private:
	string centerText(string sText, unsigned int uiWith);
	string rightText(string sText, unsigned int uiWith);
	string leftText(string sText, unsigned int uiWith);
	string leftText(double dNum, unsigned int uiWith);

	vector<vector<double> > vvdTable; 
	vector<string> vsColNames;
	string sTabDesc = "";
};

