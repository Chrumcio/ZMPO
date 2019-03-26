#include <iostream>
#include "CMenu.h"
#include "CTable.h"
#include "CMenuCommand.h"
#include "CVariables.h"

using namespace std;

const string S_SUBMENU1="submenu1";
const string S_SUBMENU1_COMMAND="sub";
const string S_ADD_CTABLE="Dodaj CTable";
const string S_ADD_CTABLE_COMMAND="dodaj";
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
	vector <CTable*> *v_objects_a = &v_objects;
	CMenu *c_menu = new CMenu();
	CMenuCommand *pc_back = new CMenuCommand(NULL, c_menu, &v_objects);
	c_menu->vAddToVector(pc_back);
    //modyfikacja zadania 2 w komentarzach
    // CMenuCommand *pc_exit = new CMenuCommand(NULL, c_menu, v_objects_a,S_EXIT,S_EXIT);
    //c_menu->vAddToVector(pc_exit);
    // CMenuCommand *pc_exit1 = new CMenuCommand(NULL, c_menu, v_objects_a,S_EXIT,S_EXIT);
    CMenu *c_sub_menu1 = c_menu->cAddSubmenu(S_SUBMENU1, S_SUBMENU1_COMMAND);
	//c_sub_menu1->vAddToVector(pc_exit1);
	CMenu *c_sub_menu2 = c_sub_menu1->cAddSubmenu(S_SUBMENU2, S_SUBMENU2_COMMAND);
	CMenuCommand *pc_exit2 = new CMenuCommand(NULL, c_menu, v_objects_a);
	//c_sub_menu2->vAddToVector(pc_exit2);
	CMenu *c_sub_menu3 = c_sub_menu1->cAddSubmenu(S_SUBMENU3, S_SUBMENU3_COMMAND);
	CMenuCommand *pc_exit3 = new CMenuCommand(NULL, c_menu, v_objects_a);
	//c_sub_menu3->vAddToVector(pc_exit3);

	CMenuCommand* c_command1 = new CMenuCommand(v_objects_a, S_ADD_CTABLE, S_ADD_CTABLE_COMMAND);
	c_command1->vAddCreateCTable();
	c_menu->vAddToVector(c_command1);
	CMenuCommand* c_command2 = new CMenuCommand(v_objects_a, S_CHANGE_TABLE_LENGTH, S_CHANGE_TABLE_LENGTH_COMMAND);
	c_command2->vAddChangeTableLength();
	c_menu->vAddToVector(c_command2);
	CMenuCommand* c_command3 = new CMenuCommand(v_objects_a, S_DELETE_CTABLE, S_DELETE_CTABLE_COMMAND);
	c_command3->vAddDeleteCTable();
	c_menu->vAddToVector(c_command3);
	CMenuCommand* c_command4 = new CMenuCommand(v_objects_a, S_DELETE_ALL, S_DELETE_ALL_COMMAND);
	c_command4->vAddDeleteAll();
	c_menu->vAddToVector(c_command4);
	CMenuCommand* c_command5 = new CMenuCommand(v_objects_a, S_CHANGE_NAME, S_CHANGE_NAME_COMMAND);
	c_command5->vAddChangeName();
	c_menu->vAddToVector(c_command5);
	CMenuCommand* c_command6 = new CMenuCommand(v_objects_a, S_CLONE, S_CLONE_COMMAND);
	c_command6->vAddCCloneCTable();
	c_menu->vAddToVector(c_command6);
	CMenuCommand* c_command7 = new CMenuCommand(v_objects_a, S_SET_VALUE, S_SET_VALUE_COMMAND);
	c_command7->vAddCChangeCellValue();
	c_menu->vAddToVector(c_command7);
	CMenuCommand* c_command8 = new CMenuCommand(v_objects_a, S_ALL_TABLES, S_ALL_TABLES_COMMAND);
	c_command8->vAddCPrintAllCTables();
	c_menu->vAddToVector(c_command8);
   // CMenuCommand* pc_back = new CMenuCommand(NULL, c_menu, v_objects_a);
	//c_menu->vAddToVector(pc_back);
	c_menu->vRun();

	delete c_menu;

	return 0;
}// int main()
