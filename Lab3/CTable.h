#pragma once
#include <string>
using namespace std;

class CTable
{
public:
	static const string DEFAULT_NAME;
	static const int DEFAULT_LENGTH;
	static const int DEFAULT_VALUE;

	CTable();
	CTable(string sName, int iTableLen);
	CTable(CTable &pcOther);
	~CTable();

	void vGetMin();
	int *iGetTable();
	void vSetName(string sName);
	void vSetTableLength(int iTableLength);
	int iGetTableLength();
	void vCloneValuesLength(CTable &pcOther);
	bool bSetValue(int iIndex, int iValue);
	int iGetValue(int iIndex);
	string sGetInfo();

private:
	string s_name;
	int i_table_length;
	int *pi_table;
};// class CTable
