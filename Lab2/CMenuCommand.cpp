#include <iostream>
#include <vector>
#include "CMenuCommand.h"
#include "CCreateCTable.h"
#include "CChangeTableLength.h"
#include "CDeleteCTable.h"
#include "CDeleteAll.h"
#include "CChangeName.h"
#include "CCloneCTable.h"
#include "CChangeCellValue.h"
#include "CPrintAllCTables.h"
#include "CPrintMinValue.h"
#include "CBack.h"
#include "CVariables.h"

using namespace std;

const string S_NAME="Back";
const string S_COMMAND="back";
const string S_EMPTY_COMMAND="Pusta komenda";
const string S_DELETE="Usunieto: ";


CMenuCommand::CMenuCommand(CMenu * cParent)
{
	s_name = S_NAME;
	s_command = S_COMMAND;
	pc_command = new CBack(cParent);
}//CMenuCommand::CMenuCommand(CMenu * cParent)

CMenuCommand::CMenuCommand(vector<CTable*> *pvObjects, string sName, string sCommand)
{
	s_name = sName;
	s_command = sCommand;
	this->pv_objects = pvObjects;
}// CMenuCommand::CMenuCommand(vector<CTable*> *pvObjects, string sName, string sCommand)

CMenuCommand::CMenuCommand(CMenu * pcParent, CMenu * pc_FinalMenu, vector<CTable*>* pvObjects)
{
	pc_command = new CBack(pcParent, pc_FinalMenu, pvObjects);
	s_name = S_NAME;
	s_command = S_COMMAND;
}// CMenuCommand::CMenuCommand(CMenu * pcParent, CMenu * pc_FinalMenu, vector<CTable*>* pvObjects)

CMenuCommand::CMenuCommand(string sName,string sCommand,string sHelp)
{
    s_name=sName;
    s_command=sCommand;
    s_help=sHelp;
}//CMenuCommand::CMenuCommand(string sName,string sCommand,string sHelp)

/* Modyfikacja zadania 2
CMenuCommand::CMenuCommand(CMenu * pcParent, CMenu * pc_FinalMenu, vector<CTable*>* pvObjects,string sname,string scommand)
{
	pc_command = new CBack(pcParent, pc_FinalMenu, pvObjects);
	s_name = sname;
	s_command = scommand;
}//CMenuCommand::CMenuCommand(CMenu * pcParent, CMenu * pc_FinalMenu, vector<CTable*>* pvObjects,string sname,string scommand)
*/

CMenuCommand::~CMenuCommand()
{
	//cout << S_DELETE << s_name << endl;
	delete pc_command;
}// CMenuCommand::~CMenuCommand()

void CMenuCommand::vRun()
{
	if (pc_command != NULL)
	{
		pc_command->vRunCommand();
	}// if (pc_command != NULL)
	else cout << S_EMPTY_COMMAND << endl;
}// void CMenuCommand::vRun()

void CMenuCommand::vCreateCTable()
{
	pc_command = new CCreateCTable(pv_objects);
}// void CMenuCommand::vCreateCTable()

string CMenuCommand::sGetName()
{
	return s_name;
}// string CMenuCommand::sGetName()

string CMenuCommand::sGetCommand()
{
	return s_command;
}// string CMenuCommand::sGetCommand()

string CMenuCommand::sHelp()
{
    if(pc_command!=NULL)
    {
        return pc_command->sHelp;
    }// if(pc_command!=NULL)
    else if(s_help!="")
    {
        return s_help;
    }//   else if(s_help!="")
    else
    {
        cout<<S_EMPTY_COMMAND<<endl;
    }//else
}//string CMenuCommand::sHelp()

void CMenuCommand::vAddCreateCTable()
{
	pc_command = new CCreateCTable(pv_objects);
}// void CMenuCommand::addCreateCTable()

void CMenuCommand::vAddChangeTableLength()
{
	pc_command = new CChangeTableLength(pv_objects);
}// void CMenuCommand::addChangeTableLength()

void CMenuCommand::vAddDeleteCTable()
{
	pc_command = new CDeleteCTable(pv_objects);
}// void CMenuCommand::addDeleteCTable()

void CMenuCommand::vAddDeleteAll()
{
	pc_command = new CDeleteAll(pv_objects);
}// void CMenuCommand::addDeleteAll()

void CMenuCommand::vAddChangeName()
{
	pc_command = new CChangeName(pv_objects);
}// void CMenuCommand::addDeleteAll()

void CMenuCommand::vAddCCloneCTable()
{
	pc_command = new CCloneCTable(pv_objects);
}// void CMenuCommand::addCCloneCTable()

void CMenuCommand::vAddCChangeCellValue()
{
	pc_command = new CChangeCellValue(pv_objects);
}// void CMenuCommand::addCCloneCTable()

void CMenuCommand::vAddCPrintAllCTables()
{
	pc_command = new CPrintAllCTables(pv_objects);
}// void CMenuCommand::CPrintAllCTables()
