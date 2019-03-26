#include "Utilities.h"
#include <iostream>
#include <vector>
#include <string>
#include "CVariables.h"

const string S_WRONG_NUMBER="Zla liczba";
const string S_WRONG_ELEMENT="Zly element";

void vPrintWrong()
{
	cout << S_WRONG_NUMBER << endl;
}// void vPrintWrongNumber()

void vPrintMissingElement()
{
	cout << S_WRONG_ELEMENT << endl;
}// void vPrintMissingElement()

void vPrintInfo(vector <CTable*> vObjects)
{
	for (int i = 0; i < vObjects.size(); i++) {
		cout << i + 1 << ". ";
		cout << vObjects[i]->sGetInfo() << endl;
	}// for (int i = 0; i < objects.size(); i++) {
}// void vPrintObjectsInfo(vector <CTable*> objects)

bool bIsInt(string sInput)
{
	for (int i = 0; i < sInput.length(); i++)
	{
		char c_char = sInput[i];
		if (c_char < '0' || c_char > '9')
            return false;
	}//for (int i = 0; i < sInput.length(); i++)
	return true;
}// bool bIsInt(string sInput)

void vDeleteCTables(vector<CTable*> vObjects)
{
	for (int i = 0; i < vObjects.size(); i++)
	{
		delete vObjects[i];
	}// 	for (int i = 0; i < objects.size(); i++)
}// void deleteCTables(vector<CTable*> objects)

