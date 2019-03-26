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
	CMenuCommand(string sName, string sCommand, string sHelp);
	~CMenuCommand();
	bool bRun();
	virtual void vSearch(vector<CMenuItem*>& pcFoundItems, string sSearchCmd);
	void vCreateCTable();
	virtual string sGetName();
	virtual string sGetCommand();
	void vAddCreateCTable();
	void vAddChangeTableLength();
	void vAddDeleteCTable();
	void vAddDeleteAll();
	void vAddChangeName();
	void vAddCCloneCTable();
	void vAddCChangeCellValue();
	void vAddCPrintAllCTables();
	void vAddCPrintMinValue();
	virtual string sGetHelp();
};
