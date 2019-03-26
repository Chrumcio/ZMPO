#include "Utilities.h"
#include "CChangeTableLength.h"
#include <iostream>
#include <stdlib.h>
#include "CVariables.h"

using namespace std;

const string S_CHOOSE_ELEMENT="Wybierz element: ";
const string S_ENTER_TABLE_LENGTH="Podaj nowa dlugosc";

CChangeTableLength::CChangeTableLength(vector<CTable*>* pvObjects)
{
	this->pv_objects = pvObjects;
}// CChangeTableLength::CChangeTableLength(vector<CTable*>* pvObjects)

void CChangeTableLength::vRunCommand()
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
			cout << S_ENTER_TABLE_LENGTH;
			string s_length;
			getline(cin, s_length);
			if (bIsInt(s_length))
			{
				int i_length = atoi(s_length.c_str());
				if (i_length > 0)
				{
					(*pv_objects)[i_element - 1]->vSetTableLength(i_length);
				}// if (i_length > 0)
				else vPrintWrong();
			}// if (bIsInt(s_length))
			else vPrintWrong();
		}// if (i_element > 0 && i_element <= v_objects.size())
		else vPrintMissingElement();
	}// if (bIsInt(s_element))
	else vPrintWrong();
}// void CChangeTableLength::vRunCommand()

