#include "stdafx.h"
#include "TableHandle.h"



TableHandle::TableHandle()
{
}

TableHandle::TableHandle(unsigned int uiCol)
{
	// lable the columns
	for (unsigned int i = 0; i < uiCol; i++)
		vsColNames.push_back("Col #" + to_string(i));

}

TableHandle::TableHandle(vector<string> vsColnames)
{
	// lable the columns
	vsColNames = vsColnames;

}

int TableHandle::addRow(vector<double> vdRow)
{
	// initial validation
	if (vdRow.size() != vsColNames.size()) {
		cout << "Incompatible rowsizes added in addRow()\n";
		return 0;
	}

	// add the row
	vvdTable.push_back(vdRow);
	return 1;
}


void TableHandle::print()
{
	//todo: caclulate the optimal initial values 
	//initial values
	vector<unsigned int> vuiColWith = uiGetColWiths();

	// calculate the total with of the table
	unsigned int uiTabWith = vuiColWith.size() + 1;
	for (unsigned int uiWith : vuiColWith)
		uiTabWith += uiWith;
	
	// ----------------------------------------------------------------------------------------------
	// print the table description
	// ----------------------------------------------------------------------------------------------
	cout << TOPLEFT << setfill(FLATBAR) << setw(uiTabWith-1) << TOPRIGHT << endl;
	cout << VERTBAR << leftText(sTabDesc, uiTabWith-2) << VERTBAR << endl;

	// ----------------------------------------------------------------------------------------------
	// print column Names
	// ----------------------------------------------------------------------------------------------
	cout << LEFTINT;
	for (unsigned int i = 0; i < vuiColWith.size()-1; i++) {
		cout << setfill(FLATBAR) << setw(vuiColWith[i]+1) << TOPINT;
	}
	cout << setfill(FLATBAR) << setw(vuiColWith[vuiColWith.size()-1]+1) << RIGHTINT << endl;

	
	cout << VERTBAR;
	for (unsigned int i = 0; i < vsColNames.size(); i++)
		cout << leftText(vsColNames[i], vuiColWith[i]) << VERTBAR;
	cout << endl;

	// ----------------------------------------------------------------------------------------------
	// print data
	// ----------------------------------------------------------------------------------------------
	cout << LEFTINT;
	for (unsigned int i = 0; i < vuiColWith.size() - 1; i++) {
		cout << setfill(FLATBAR) << setw(vuiColWith[i] + 1) << CENTINT;
	}
	cout << setfill(FLATBAR) << setw(vuiColWith[vuiColWith.size() - 1] + 1) << RIGHTINT << endl;

	for (unsigned int uiRow = 0; uiRow < vvdTable.size(); uiRow++) {
		// make the line
		if (uiRow != 0) {
			cout << LEFTINT;
			for (unsigned int i = 0; i < vuiColWith.size() - 1; i++) {
				cout << setfill(FLATBAR) << setw(vuiColWith[i] + 1) << CENTINT;
			}
			cout << setfill(FLATBAR) << setw(vuiColWith[vuiColWith.size() - 1] + 1) << RIGHTINT << endl;
		}

		//print a row
		cout << VERTBAR;
		for (unsigned int i = 0; i < vsColNames.size(); i++)
			cout << leftText(vvdTable[uiRow][i], vuiColWith[i]) << VERTBAR;
		cout << endl;

	}
	

	// ----------------------------------------------------------------------------------------------
	// finish table lines
	// ----------------------------------------------------------------------------------------------
	cout << BUTLEFT;
	for (unsigned int i = 0; i < vuiColWith.size() - 1; i++) {
		cout << setfill(FLATBAR) << setw(vuiColWith[i] + 1) << BUTINT;
	}
	cout << setfill(FLATBAR) << setw(vuiColWith[vuiColWith.size() - 1] + 1) << BUTRIGHT << endl;

}

void TableHandle::print(string description)
{
	sTabDesc = description;
	print();
}

void TableHandle::exportTableCSV(string sName)
{
	ofstream myfile;
	myfile.open(sName + ".csv");

	myfile << sTabDesc;
	myfile << "\n";

	for (unsigned int i = 0; i < vsColNames.size(); i++) {
		myfile << vsColNames[i];
		(i==vsColNames.size()-1) ? myfile << "\n" : myfile << ",";
	}
	for (vector<double> vdRow: vvdTable) {
		for (unsigned int i = 0; i < vsColNames.size(); i++) {
			myfile << to_string(vdRow[i]);
			(i == vsColNames.size() - 1) ? myfile << "\n" : myfile << ",";
		}
	}

	myfile.close();
}

TableHandle::~TableHandle()
{
}

string TableHandle::leftText(string sText, unsigned int uiWith)
{
	string sReturn = "";
	for (unsigned int i = 0; i < uiWith; i++) {
		if (i < sText.length())
			sReturn += sText.at(i);
		else
			sReturn += ' ';
	}

	return sReturn;
}

string TableHandle::leftText(double dNum, unsigned int uiWith)
{
	string sText = to_string(dNum);
	string sReturn = "";
	for (unsigned int i = 0; i < uiWith; i++) {
		if (i < sText.length())
			sReturn += sText.at(i);
		else
			sReturn += ' ';
	}

	return sReturn;
}

vector<unsigned int> TableHandle::uiGetColWiths()
{
	// setup variables
	vector<unsigned int> vuiRes;
	string sText;
	

	// for each colum
	for (unsigned int uiCol = 0; uiCol < vsColNames.size(); uiCol++) {
		// for each element
		unsigned int uiColWith = DEFAULT_COL_WITH;

		for (unsigned int uiCell = 0; uiCell < vvdTable.size(); uiCell++) {
			if (to_string(vvdTable[uiCell][uiCol]).length() > uiColWith)
				uiColWith = to_string(vvdTable[uiCell][uiCol]).length();
		}
		vuiRes.push_back(uiColWith);
	}

	// return the resoult
	return vuiRes;
}
