#include "Utilities.h"
#include "CChangeCellValue.h"
#include <iostream>
#include <stdlib.h>
#include "CVariables.h"

using namespace std;

const string S_CHOOSE_ELEMENT="Wybierz element: ";
const string S_CHOOSE_CELL="Wybierz komorke: ";
const string S_ENTER_VALUE="Wprowadz wartosc: ";

CChangeCellValue::CChangeCellValue(vector<CTable*>* pvObjects)
{
	this->pv_objects = pvObjects;
}// CChangeCellValue::CChangeCellValue(vector<CTable*>* pvObjects)

void CChangeCellValue::vRunCommand()
{
	vPrintInfo(*pv_objects);
	cout << S_CHOOSE_ELEMENT;
	string s_element;
	getline(cin, s_element);
	if (bIsInt(s_element))
	{
		int i_element = atoi(s_element.c_str());
		if (i_element > 0 && i_element <= pv_objects->size())
		{
			cout <<S_CHOOSE_CELL;
			string s_cell;
			getline(cin, s_cell);
			if (bIsInt(s_cell))
			{
				int i_cell = atoi(s_cell.c_str());
				if (i_cell > 0 && i_cell <= (*pv_objects)[i_element - 1]->iGetTableLength())
				{
					cout <<S_ENTER_VALUE;
					string s_val;
					getline(cin, s_val);
					if (bIsInt(s_val))
					{
						int i_val = atoi(s_val.c_str());
						(*pv_objects)[i_element - 1]->bSetValue(i_cell, i_val);
					}// if (bIsInt(s_cell))
					else vPrintWrong();
				}// if (i_cell > 0 && i_cell <= v_objects[i_element5 - 1]->iGetTableLength())
				else vPrintWrong();
			}// if (bIsInt(s_cell))
			else vPrintWrong();
		}// if (i_element > 0 && i_element <= v_objects.size())
		else vPrintMissingElement();
	}// if (bIsInt(s_element))
	else vPrintWrong();

}// void CChangeCellValue::vRunCommand()

