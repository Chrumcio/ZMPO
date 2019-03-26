#include "CCreateCTable.h"
#include "Utilities.h"
#include <iostream>
#include <stdlib.h>
#include "CVariables.h"

using namespace std;

const string S_DEFAULT="1.Domyslny";
const string S_PARAMETIC="2.Parametryczny";
const string S_NAME="Nazwa: ";
const string S_AMOUNT_OF_CELL="Liczba komorek: ";

CCreateCTable::CCreateCTable(vector <CTable*> *pvObjects)
{
	this->pv_objects = pvObjects;
}// CCreateCTable::CCreateCTable(vector <CTable*> *pvObjects)

void CCreateCTable::vRunCommand()
{
	string s_command;
	int i_command;
	cout << S_DEFAULT << endl << S_PARAMETIC << endl;
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
				cout << S_NAME;
				string s_name;
				getline(cin, s_name);
				cout << S_AMOUNT_OF_CELL;
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
				else vPrintWrong();
				break;
			}// case 2:
			}// switch (i_command)
		}// if (i_command > 0 && i_command < 3)
		else vPrintWrong();
	}// if (bIsInt(s_command))
	else vPrintWrong();
}// void CCreateCTable::vRunCommand()
