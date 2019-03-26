#include "CMenu.h"
#include "CMenuCommand.h"
#include <iostream>
#include "CMenuItem.h"
#include "Utilities.h"
#include <cstddef>
using namespace std;

const string NO_COMMAND = "Brak komendy";
const string DEFALUT_MENU = "Domyslne menu";
const string DEFAULT_MENU_COMMAND = "mainmenu";
const string DELETE_MENU = "Usuwam menu: ";
const string ENTER_COMMAND = "Wprowadz komende: ";
const string HELP = "help ";
const string SEARCH = "search ";

CMenu::CMenu()
{
	s_name = DEFALUT_MENU;
	s_command = DEFAULT_MENU_COMMAND;
}// CMenu::CMenu()

CMenu::CMenu(string sName, string sCommand)
{
	s_name = sName;
	s_command = sCommand;
}// CMenu::CMenu(string sName, string sCommand)

CMenu::~CMenu()
{
	//cout << DELETE_MENU << s_name << endl;
	for (int i = 0; i < v_c_menu_items.size(); i++)
	{
		delete v_c_menu_items[i];
	}// for (int i = 0; i < v_c_menu_items.size(); i++)
}

void CMenu::vRun()
{
	while (true)
	{
		string input;
		bool b_is_command = false;
        bool b_is_help = false;
        bool b_is_search = false;
        string s_input;
		int i_index_of_command = 0;
		vPrintCommands();
		cout << ENTER_COMMAND;
		getline(cin, input);
		for (int index = 0; index < v_c_menu_items.size(); index++)
		{
			if (input == v_c_menu_items[index]->sGetCommand())
			{
				b_is_command = true;
				i_index_of_command = index;
			}// if (input == v_c_menu_items[i]->sGetCommand())
			else if (s_input == HELP + v_c_menu_items[index]->sGetCommand())
			{
				b_is_help = true;
				cout << v_c_menu_items[index]->sHelp() << endl;
			}// else if (input == "help" + v_c_menu_items[index]->sGetName)
		}// for (int i = 0; i < v_c_menu_items.size(); i++)
		if (s_input[0] == 's' && s_input[1] == 'e' && s_input[2] == 'a' && s_input[3] == 'r' && s_input[4] == 'c' && s_input[5] == 'h')
		{
			CMenu *pc_parent = this;
			if (this->c_menu_parent != NULL) CMenu *pc_parent = c_menu_parent;
			while (pc_parent->c_menu_parent != NULL)
			{
				pc_parent = pc_parent->c_menu_parent;
			}// if (this->c_menu_parent == NULL)

			for (int index = 0; index < pc_parent->v_c_menu_items.size(); index++)
			{
				if (s_input == SEARCH + pc_parent->v_c_menu_items[index]->sGetCommand())
				{
					b_is_search = true;
					cout << " -> " << pc_parent->sGetName() << " -> " << pc_parent->v_c_menu_items[index]->sGetCommand() << endl;
				}// if (input == v_c_menu_items[i]->sGetCommand())
			}// for (int index = 0; index < v_c_menu_items.size(); index++)\

			for (int i = 0; i < pc_parent->v_c_menu.size(); i++)
			{
				for (int j = 0; j < pc_parent->v_c_menu[i]->v_c_menu_items.size(); j++)
				{
					if (s_input == SEARCH + pc_parent->v_c_menu[i]->v_c_menu_items[j]->sGetCommand())
					{
						b_is_search = true;
						cout << " -> " << pc_parent->sGetName() << " -> " << pc_parent->v_c_menu[i]->sGetName() << " -> " << pc_parent->v_c_menu[i]->v_c_menu_items[j]->sGetCommand() << endl;
					}// if (input == "search " + v_c_menus[i]->v_c_menu_items[j]->sGetCommand())
				}// for (int j = 0; j < v_c_menus[i]->v_c_menu_items.size(); j++)
			}// for (int i = 0; i < v_c_menus.size(); i++)
		}// if (s_input[0] == 's' && s_input[1] == 'e' && s_input[2] == 'a' && s_input[3] == 'r' && s_input[4] == 'c' && s_input[5] == 'h')

		if (b_is_command == false && b_is_help == false && b_is_search == false)
		{
			cout << NO_COMMAND << endl;
		}// if (b_is_command == false)
		else if (b_is_help == false && b_is_search == false)
		{
			v_c_menu_items[i_index_of_command]->vRun();
		}// else
	}// while (true)
}// void CMenu::vRun()

string CMenu::sGetName()
{
	return s_name;
}// string CMenu::sGetName()

string CMenu::sGetCommand()
{
	return s_command;
}// string CMenu::sGetCommand()

CMenu* CMenu::cAddSubmenu(string sName, string sCommand)
{
    for(int i=0;i<v_c_menu_items.size();i++)
    {
        if(v_c_menu_items.at(i)->sGetName()==sName || v_c_menu_items.at(i)->sGetCommand()==sCommand)
        {
            return NULL;
        }//if(v_c_menu_items.at(i)->sGetName()==sName || v_c_menu_items.at(i)->sGetCommand()==sCommand)
    }// for(int i=0;i<v_c_menu_items.size();i++)
	CMenu* c_new_menu = new CMenu(sName, sCommand);
	c_new_menu->c_menu_parent = this;
	CMenuCommand* tempBack = new CMenuCommand(this);
	c_new_menu->vAddToVector(tempBack);
	v_c_menu_items.push_back(c_new_menu);
	return c_new_menu;
}//void CMenu::addSubmenu(string sName, string sCommand)

void CMenu::vPrintCommands()
{
	cout << endl;
	//cout << " -> " << this->sGetCommand();
	//cout << endl << this->sGetName() + " (" + this->sGetCommand() + "): " << endl;
	for (int i = 0; i < v_c_menu_items.size(); i++)
	{
		cout << i + 1 << ". " << v_c_menu_items[i]->sGetName() << " (" << v_c_menu_items[i]->sGetCommand() << ")." << endl;
	}// for (int i = 0; i < v_c_menu_items.size(); i++)
}// void CMenu::vPrintCommands()

void CMenu::vAddToVector(CMenuItem* pcItem)
{
	v_c_menu_items.push_back(pcItem);
}// void CMenu::addToVector(CMenuItem* pcItem)

