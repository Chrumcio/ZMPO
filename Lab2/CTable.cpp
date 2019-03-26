#include <iostream>
#include <cstring>
#include "CTable.h"
#include <sstream>

using namespace std;

const string CTable::DEFAULT_NAME="DEFAULT";
const int CTable::DEFAULT_VALUE=0;
const int CTable::DEFAULT_LENGTH=1;


CTable::CTable()
{
    s_name=DEFAULT_NAME;
    i_table_length=DEFAULT_LENGTH;
    pi_table=new int[i_table_length];
    fill_n(pi_table, i_table_length,DEFAULT_VALUE);
    cout<<"bezp:"<<s_name<<endl;
}

CTable::CTable(string sName, int iTableLen)
{
    s_name=sName;
    i_table_length=iTableLen;
    pi_table=new int[i_table_length];
    fill_n(pi_table, i_table_length, DEFAULT_VALUE);
    cout<<"parametr: "<<s_name<<endl;
}

CTable::CTable(CTable &pcOther)
{
    s_name=pcOther.s_name+"_copy";
    i_table_length=pcOther.i_table_length;
    pi_table=new int[i_table_length];
    memcpy(pi_table,pcOther.pi_table,i_table_length*sizeof(int));
    cout<<"kopiuj: "<<s_name<<endl;
}

CTable::~CTable()
{
    cout<<"usuwam"<<" "<<s_name<<endl;
    i_table_length=0;
    delete pi_table;
}

void CTable::vSetName(string sName)
{
    s_name=sName;
}

void CTable::vSetTableLength(int iTableLen)
{
    int *pi_new_table=new int[iTableLen];
    fill_n(pi_new_table, iTableLen, DEFAULT_VALUE);
    memcpy(pi_new_table, pi_table, min(i_table_length, iTableLen) * sizeof(int));
    delete [] pi_table;
    pi_table=pi_new_table;
    i_table_length=iTableLen;
}

void CTable::vCreateCopyTable(CTable *pcStarting,CTable *pcOther)
{
    delete [] pcStarting->pi_table;
    int *pi_new_table=new int[pcOther->iGetTableLength()];
    memcpy(pi_new_table,pcOther->pi_table,pcOther->iGetTableLength()*sizeof(int));
    pcStarting->pi_table=pi_new_table;
    pcStarting->i_table_length=pcOther->iGetTableLength();

}

CTable* CTable::cClone() {
	return new CTable(*this);
}

bool CTable::bSetValue(int iIndex, int iValue)
{
    if(iIndex>=i_table_length || iIndex<0)
        return false;
    else
    {
        pi_table[iIndex]=iValue;
        return true;
    }
}

bool CTable::bGetValue(int iIndex,int *piValue)
{
    if(iIndex>=i_table_length || iIndex<0)
        return false;
    else
    {
        *piValue = *(pi_table + iIndex);
        return true;
    }
}

int CTable::iGetTableLength()
{
    return i_table_length;
}

string CTable::sGetName()
{
    return s_name;
}

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
}

/*
void CTable::vSum(CTable *pcTab)
{
    int i_suma=0;
    for(int i=0;i<pcTab->iGetTableLength();i++)
    {
        i_suma+=pi_table[i];
    }//for(int i=0;i<pcTab->iGetTableLength();i++)
    cout<<i_suma<<endl;

}

void CTable::vSum(CTable CTab)
{
    int i_suma=0;
    for(int i=0;i<CTab.iGetTableLength();i++)
    {
        i_suma+=pi_table[i];
    }// for(int i=0;i<CTab.iGetTableLength();i++)
    cout<<i_suma<<endl;
}
*/
