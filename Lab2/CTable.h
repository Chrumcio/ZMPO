#ifndef CTABLE_H
#define CTABLE_H
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

class CTable
{

private:
    string s_name;
    int i_table_length;
    int *pi_table;

public:
    static const string DEFAULT_NAME;
    static const int DEFAULT_LENGTH;
    static const int DEFAULT_VALUE;

    CTable();
    CTable(string sName, int iTableLen);
    CTable(CTable &pcOther);
    ~CTable();
    void vSetName(string sName);
    void vSetTableLength(int iTableLen);
    void vCreateCopyTable(CTable *pcStarting,CTable *pcOther);
    CTable *cClone();
    bool bSetValue(int iIndex, int iValue);
    bool bGetValue(int iIndex,int *piValue);
    int iGetTableLength();
    string sGetName();
    string sGetInfo();

    void vSum(CTable *pcTab);
    void vSum(CTable CTab);
};//class CTable

#endif // CTABLE_H
