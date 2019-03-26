#include "CTable.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;


const string CTable::DEFAULT_NAME = "Default";
const int CTable::DEFAULT_LENGTH = 6;
const int CTable::DEFAULT_VALUE = -1;
const string BEZP = "bezp: ";
const string PARAMETER = "parametr: ";
const string COPY = "_copy";
const string COPY_OF = "kopiuj: ";
const string DELETE = "usuwam: ";
const string LEN = "len: ";
const string VALUES = "values: ";
const string MIN = "Min: ";


CTable::CTable()
{
	s_name = DEFAULT_NAME;
	i_table_length = DEFAULT_LENGTH;
	cout << BEZP << s_name << endl;

	pi_table = new int[i_table_length];
	fill_n(pi_table, i_table_length, DEFAULT_VALUE);
}// CTable::CTable()

CTable::CTable(string sName, int iTableLength)
{
	s_name = sName;
	i_table_length = iTableLength;
	cout << PARAMETER << s_name << endl;

	pi_table = new int[i_table_length];
	fill_n(pi_table, i_table_length, DEFAULT_VALUE);
}// CTable::CTable(string sName, int iTableLen)

CTable::CTable(CTable &pcOther)
{
	s_name = pcOther.s_name + COPY;
	i_table_length = pcOther.i_table_length;
	cout << COPY_OF + s_name;

	pi_table = new int[i_table_length];
	memcpy(pi_table, pcOther.pi_table, i_table_length * sizeof(int));

}// CTable::CTable(CTable &pcOther)

CTable::~CTable()
{
	delete[] pi_table;
	cout << DELETE + s_name << endl;
}// CTable::~CTable()

int* CTable::iGetTable()
{
	return pi_table;
}// int CTable::iGetTable()

void CTable::vSetName(string sName)
{
	s_name = sName;
}// void CTable::vSetName(string sName)

void CTable::vSetTableLength(int iTableLength)
{
	int *pi_new_table = new int[iTableLength];

	fill_n(pi_new_table, iTableLength, DEFAULT_VALUE);
	memcpy(pi_new_table, pi_table, min(i_table_length, iTableLength) * sizeof(int));

	delete[] pi_table;
	pi_table = pi_new_table;
	i_table_length = iTableLength;
}// void CTable::vSetTableLength(int iTableLength)

int CTable::iGetTableLength() {
	return i_table_length;
}// int CTable::iGetTableLength() {

bool CTable::bSetValue(int iIndex, int iValue)
{
	if (iIndex >= i_table_length || iIndex < 0)
		return false;
	else
	{
		pi_table[iIndex] = iValue;
		return true;
	}// else
}// bool CTable::bSetValue(int iIndex, int iValue)

int CTable::iGetValue(int iIndex)
{
	if (iIndex >= i_table_length || iIndex < 0)
		return -1;
	else
		return pi_table[iIndex];
} // int CTable::iGetValue(int iIndex)

void CTable::vCloneValuesLength(CTable &pcOther)
{
	delete[] pi_table;
	i_table_length = pcOther.i_table_length;

	pi_table = new int[i_table_length];
	memcpy(pi_table, pcOther.pi_table, i_table_length * sizeof(int));
}// void CTable::vCloneValuesLength(CTable & pcOther)

string CTable::sGetInfo()
{
    string s_info;
    ostringstream s_table_length;
    for(int i=0;i<i_table_length;i++)
    {
        ostringstream s_help;
        s_help<<pi_table[i];
        s_info+=s_help.str()+",";
    }// for(int i=0;i<i_table_length;i++)
    s_table_length<<i_table_length;
    return s_name+" "+"len:"+s_table_length.str()+" values: "+s_info;
}// string sGetInfo()

void CTable::vGetMin()
{
	int i_min;
	i_min = pi_table[0];
	for (int i = 0; i < i_table_length; i++)
	{
		if (i_min > pi_table[i])
		{
			i_min = pi_table[i];
		}// if (i_min < pi_table[i])
	}// for (int i = 0; i < i_table_length; i++)
	cout << endl << MIN << i_min << endl;
}// void CTable::vGetMin()

