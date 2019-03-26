#include <iostream>
#include "CMenu.h"
#include "CTable.h"
#include "Utilities.h"
#include "CMenuCommand.h"
#include <stdio.h>
#include <sstream>
#include "CVariables.h"

using namespace std;

const string S_SUBMENU1="submenu1";
const string S_SUBMENU1_COMMAND="sub";
const string S_ADD_CTABLE="Dodaj CTable";
const string S_ADD_CTABLE_COMMAND="dodaj";
const string S_ADD_CTABLE_ALT="dodajalt";
const string S_CHANGE_TABLE_LENGTH="Zmien dlugosc tablicy";
const string S_CHANGE_TABLE_LENGTH_COMMAND="dlugosc";
const string S_DELETE_CTABLE="Usun CTable";
const string S_DELETE_CTABLE_COMMAND="usun";
const string S_DELETE_ALL="Usun wszystko";
const string S_DELETE_ALL_COMMAND="usunwszystko";
const string S_CHANGE_NAME="Zmien nazwe";
const string S_CHANGE_NAME_COMMAND="nazwa";
const string S_CLONE="Sklonuj CTable";
const string S_CLONE_COMMAND="klonuj";
const string S_SET_VALUE="Zmien wartosc w komorce";
const string S_SET_VALUE_COMMAND="komorka";
const string S_ALL_TABLES="Wyswietl wszystkie tablice";
const string S_ALL_TABLES_COMMAND="wyswietl";
const string S_EXIT="exit";
const string S_SUBMENU2="submenu2";
const string S_SUBMENU3="submenu3";
const string S_SUBMENU2_COMMAND="sub2";
const string S_SUBMENU3_COMMAND="sub3";

int main()
{
    vector <CTable*> v_objects;
	CMenu *c_menu = new CMenu();
	/*CMenu *c_sub_menu1 = c_menu->vAddSubmenu(S_SUBMENU1, S_SUBMENU1_COMMAND);
    CMenu *c_sub_menu2 = c_sub_menu1->vAddSubmenu(S_SUBMENU2,S_SUBMENU2_COMMAND);
    CMenu *c_sub_menu3 = c_sub_menu1->vAddSubmenu(S_SUBMENU3,S_SUBMENU3_COMMAND);


	CMenuCommand *pc_command1 = new CMenuCommand(&v_objects, S_ADD_CTABLE, S_ADD_CTABLE_COMMAND);
	pc_command1->vAddCreateCTable();
	c_menu->vAddToVector(pc_command1);

	CMenuCommand *pc_command1alt = new CMenuCommand(&v_objects, S_ADD_CTABLE, S_ADD_CTABLE_ALT);
	pc_command1alt->vAddCreateCTable();
	c_sub_menu1->vAddToVector(pc_command1alt);

	CMenuCommand *pc_command2 = new CMenuCommand(&v_objects, S_CHANGE_TABLE_LENGTH, S_CHANGE_TABLE_LENGTH_COMMAND);
	pc_command2->vAddChangeTableLength();
	c_menu->vAddToVector(pc_command2);

	CMenuCommand *pc_command3 = new CMenuCommand(&v_objects, S_DELETE_CTABLE, S_DELETE_CTABLE_COMMAND);
	pc_command3->vAddDeleteCTable();
	c_menu->vAddToVector(pc_command3);

	CMenuCommand *pc_command4 = new CMenuCommand(&v_objects, S_DELETE_ALL, S_DELETE_ALL_COMMAND);
	pc_command4->vAddDeleteAll();
	c_menu->vAddToVector(pc_command4);

	CMenuCommand *pc_command5 = new CMenuCommand(&v_objects, S_CHANGE_NAME, S_CHANGE_NAME_COMMAND);
	pc_command5->vAddChangeName();
	c_menu->vAddToVector(pc_command5);

	CMenuCommand *pc_command6 = new CMenuCommand(&v_objects, S_CLONE, S_CLONE_COMMAND);
	pc_command6->vAddCCloneCTable();
	c_menu->vAddToVector(pc_command6);

	CMenuCommand *pc_command7 = new CMenuCommand(&v_objects, S_SET_VALUE, S_SET_VALUE_COMMAND);
	pc_command7->vAddCChangeCellValue();
	c_menu->vAddToVector(pc_command7);

	CMenuCommand *pc_command8 = new CMenuCommand(&v_objects, S_ALL_TABLES, S_ALL_TABLES_COMMAND);
	pc_command8->vAddCPrintAllCTables();
	c_menu->vAddToVector(pc_command8);

	string s_menu_string = c_menu->sMenuToString(c_menu);*/
	//string s_menu_string = c_menu->sMenuToString(c_menu);
	//string s_menu_string = c_menu->sMenuToString(c_menu);
	//cout << s_menu_string<<endl;

	//string s_menu_string = "('submenu1','sub';),('sub','sub1';),['p','p','h']";
	//string s_menu_string="('podmenu','NMM';('podmenu1','P1';),'P1',('podmenu1','pod1';),'pod1yfdghkdfhgk')";
	string s_menu_string="('aa','aa';('prw','prw';('prw2','prw2';)),['aaa','bbb','c'],('cc','cc';['dd','dd','dd']),['ha','hal','halowka'])";
	//s_menu_string="";
	//getline(cin, s_menu_string);
	CMenu* c_menu1=c_menu->cMenuFromString(s_menu_string);
	if (c_menu1 != NULL)
	{
		c_menu1->bRun();
		delete c_menu1;
	}
	delete c_menu;
	return 0;
}// int main()
