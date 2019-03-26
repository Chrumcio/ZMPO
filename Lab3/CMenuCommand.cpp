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

#include "CBack.h"
using namespace std;

const string BACK = "back";
const string DELETED = "Usunieto: ";
const string EMPTY_COMMAND = "Pusta komenda.";
const string EMPTY="";

CMenuCommand::CMenuCommand(CMenu *pcParent)
{
	s_name = BACK;
	s_command = BACK;
	pc_command = new CBack(pcParent);
}// CMenuCommand::CMenuCommand(CMenu *pcParent)

CMenuCommand::CMenuCommand(vector<CTable*> *pvObjects, string sName, string sCommand)
{
	s_name = sName;
	s_command = sCommand;
	this->pv_objects = pvObjects;
}// CMenuCommand::CMenuCommand(vector<CTable*> *pvObjects, string sName, string sCommand)

CMenuCommand::CMenuCommand(CMenu *pcParent, CMenu *pc_FinalMenu, vector<CTable*> *pvObjects)
{
	pc_command = new CBack(pcParent, pc_FinalMenu, pvObjects);
	s_name = BACK;
	s_command = BACK;
}// CMenuCommand::CMenuCommand(CMenu * pcParent, CMenu * pc_FinalMenu, vector<CTable*>* pvObjects)

CMenuCommand::CMenuCommand(string sName, string sCommand, string sHelp) {
	s_name = sName;
	s_command = sCommand;
	s_help = sHelp;
}

CMenuCommand::~CMenuCommand()
{
	cout << DELETED << s_name << endl;
	delete pc_command;
}// CMenuCommand::~CMenuCommand()

bool CMenuCommand::bRun()
{
	if (pc_command != NULL)
	{
		pc_command->vRunCommand();
	}// if (pc_command != NULL)
	else cout << EMPTY_COMMAND << endl;

	return false;
} // void CMenuCommand::bRun()

void CMenuCommand::vSearch(vector<CMenuItem*>& pcFoundItems, string sSearchCmd)
{
    if (s_command == sSearchCmd)
    {
        pcFoundItems.push_back(this);
    }
} // void CMenuCommand::vSearch(vector<CMenuItem*>& pcFoundItems, string sSearchCmd)


string CMenuCommand::sGetHelp()
{
	if (pc_command != NULL)
	{
		return pc_command->sGetHelp();
	}// if (pc_command != NULL)
	else if (s_help != EMPTY)
	{
		return s_help;
	}// else if (s_help != "")
	else cout << EMPTY_COMMAND << endl;
}// void CMenuCommand::vRvGetHelpun()

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
