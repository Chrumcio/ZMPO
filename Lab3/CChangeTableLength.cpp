#include "Utilities.h"
#include "CChangeTableLength.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

const string CHOOSE_ELEMENT = "Wybierz element: ";
const string ENTER_LENGTH = "Podaj nowa dlugosc: ";
const string HELP = "Zmiana dlugosci CTable";

CChangeTableLength::CChangeTableLength(vector<CTable*>* pvObjects)
{
	this->pv_objects = pvObjects;
	s_help = HELP;
}// CChangeTableLength::CChangeTableLength(vector<CTable*>* pvObjects)

void CChangeTableLength::vRunCommand()
{
	vPrintObjectsInfo(*pv_objects);
	cout << CHOOSE_ELEMENT;
	string s_element;
	getline(cin, s_element);
	if (bIsInt(s_element))
	{
		int i_element = atoi(s_element.c_str());
		if (i_element > 0 && i_element <= pv_objects->size())
		{
			cout << ENTER_LENGTH;
			string s_length;
			getline(cin, s_length);
			if (bIsInt(s_length))
			{
				int i_length = atoi(s_length.c_str());
				if (i_length > 0)
				{
					(*pv_objects)[i_element - 1]->vSetTableLength(i_length);
				}// if (i_length > 0)
				else vPrintWrongNumber();
			}// if (bIsInt(s_length))
			else vPrintWrongNumber();
		}// if (i_element > 0 && i_element <= v_objects.size())
		else vPrintMissingElement();
	}// if (bIsInt(s_element))
	else vPrintWrongNumber();
}// void CChangeTableLength::vRunCommand()

