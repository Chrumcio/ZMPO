#pragma once
#include "CCommand.h"
#include "CMenuItem.h"
#include "CTable.h"
#include <string>
#include <vector>
#include "CMenu.h"
using namespace std;

class CMenuCommand : public CMenuItem
{
private:
	CCommand *pc_command;
	vector <CTable*> *pv_objects;
	string s_help;

public:
	CMenuCommand(CMenu* cParent);
	CMenuCommand(vector<CTable*> *pvObjects, string sName, string sCommand);
	CMenuCommand(CMenu *pcParent, CMenu *pc_FinalMenu, vector<CTable*> *pvObjects);
	CMenuCommand(string sName,string sCommand,string sHelp);
	//CMenuCommand(CMenu * pcParent, CMenu * pc_FinalMenu, vector<CTable*>* pvObjects,string sname,string scommand);
	~CMenuCommand();
	void vRun();
	void vCreateCTable();
	virtual string sGetName();
	virtual string sGetCommand();
	virtual string sHelp();
	void vAddCreateCTable();
	void vAddChangeTableLength();
	void vAddDeleteCTable();
	void vAddDeleteAll();
	void vAddChangeName();
	void vAddCCloneCTable();
	void vAddCChangeCellValue();
	void vAddCPrintAllCTables();
	void vAddCPrintSuma();
	void vAddCBack();
};
