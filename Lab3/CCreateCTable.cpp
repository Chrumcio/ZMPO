#include "CCreateCTable.h"
#include "Utilities.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

const string DEFAULT = "1. domyslny";
const string PARAMETRIC = "2. parametryczny";
const string NAME = "Nazwa: ";
const string NUMBER_OF_CELLS = "Liczba komorek : ";
const string HELP = "Tworzenie nowych obiektow CTable";

CCreateCTable::CCreateCTable(vector <CTable*> *pvObjects)
{
	this->pv_objects = pvObjects;
	s_help = HELP;
}// CCreateCTable::CCreateCTable(vector <CTable*> *pvObjects)

void CCreateCTable::vRunCommand()
{
	string s_command;
	int i_command;
	cout << DEFAULT << endl << PARAMETRIC << endl;
	getline(cin, s_command);
	if (bIsInt(s_command))
	{
		i_command = atoi(s_command.c_str());
		if (i_command > 0 && i_command < 3)
		{
			switch (i_command)
			{
			case 1:
				pv_objects->push_back(new CTable());
				break;
			case 2:
			{
				cout << NAME;
				string s_name;
				getline(cin, s_name);
				cout << NUMBER_OF_CELLS;
				string s_cells;
				getline(cin, s_cells);
				if (bIsInt(s_cells))
				{
					int i_cells = atoi(s_cells.c_str());
					if (i_cells > 0)
					{
						pv_objects->push_back(new CTable(s_name, i_cells));
					}// if (i_cells <= 0)
				}// if (bIsInt(s_cells))
				else vPrintWrongNumber();
				break;
			}// case 2:
			}// switch (i_command)
		}// if (i_command > 0 && i_command < 3)
		else vPrintWrongNumber();
	}// if (bIsInt(s_command))
	else vPrintWrongNumber();
}// void CCreateCTable::vRunCommand()
