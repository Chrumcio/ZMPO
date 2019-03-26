#include "CMenu.h"
#include "CMenuCommand.h"
#include <iostream>
#include "CMenuItem.h"
#include "Utilities.h"
#include <sstream>
#include <stdlib.h>
#include "CVariables.h"
using namespace std;

const string NO_COMMAND = "Brak komendy";
const string DEFALUT_MENU = "Domyslne menu";
const string DEFAULT_MENU_COMMAND = "mainmenu";
const string DELETE_MENU = "Usuwam menu: ";
const string ENTER_COMMAND = "Wprowadz komende: ";
const string HELP = "help ";
const string SEARCH = "search ";
const string BACK = "back";
const string EXIT = "exit";
const string SIGN = "Oczekiwany znak: ";
const string UNEXPECTED_SIGN = "Nieoczekiwany znak: ";
const string EMPTY = "Puste menu";
const string S_SUBMENU1 = "submenu1";
const string S_ADD_CTABLE = "Dodaj CTable";
const string S_CHANGE_TABLE_LENGTH = "Zmien dlugosc tablicy";
const string S_DELETE_CTABLE = "Usun CTable";
const string S_DELETE_ALL = "Usun wszystko";
const string S_CHANGE_NAME = "Zmien nazwe";
const string S_CLONE = "Sklonuj CTable";
const string S_SET_VALUE = "Zmien wartosc w komorce";
const string S_ALL_TABLES = "Wyswietl wszystkie tablice";
const string S_DOT=". ";
const string S_BRACKET_ONE=" (";
const string S_BRACKET_TWO="): ";
const string S_BRACKET_THREE=").";
const string S_BRACKET_FOUR="('";
const string S_DETACHMENT="','";
const string S_DETACHMENT_ONE="';";
const string S_COMMA=",";
const string s_BRACKET_FIVE="('";
const string S_CLOSE_BRACKET=")";
const string S_COMMAND_BRACKET="['";
const string S_COMMAND_BRACKET_CLOSE="']";
const string S_SPEECH_MARK="'";
const string S_COMMA_SPACE=", ";
const string S_SPEECH_MARK_SPACE="' ";
const string S_SEMICOLON="; ";
const string S_CLOSE_BRACKET_SPACE=") ";
const string S_OPEN_BRACKET_SPACE="( ";
const string S_TWO_BRACKETS=") lub ( ";
const string S_OPEN_COMMAND_BRACKET="[ ";
const string S_BAD_SIGN="ZLY ZNAK";
const string S_UNNECESSARY="NIEPOTRZEBNY ZNAK ";
const string S_FAULT="BLAD";
const string S_THREE_OPTIONS=") lub ( lub [ ";

const char S_OPEN_BRACKET='(';
const char S_QUOTATION_MARK='\'';
const char S_COMMA_SIGN=',';
const char S_SEMICOLON_SIGN=';';
const char S_CLOSE_BRACKET_SIGN=')';
const char S_OPEN_COMMAND_SIGN='[';
const char S_CLOSE_COMMAND_SIGH=']';

CMenu::CMenu()
{
	s_name = DEFALUT_MENU;
	s_command = DEFAULT_MENU_COMMAND;
	c_parent = NULL;
}// CMenu::CMenu()

CMenu::CMenu(string sName, string sCommand)
{
	s_name = sName;
	s_command = sCommand;
	c_parent = NULL;
}// CMenu::CMenu(string sName, string sCommand)

CMenu::~CMenu()
{
	for (int i = 0; i < v_c_menu_items.size(); i++)
	{
		delete v_c_menu_items[i];
	}// for (int i = 0; i < v_c_menu_items.size(); i++)
}// CMenu::~CMenu()

bool CMenu::bRun()
{
	int i_help = 0;
	int i_command = 0;
	int i_search = 0;
	string s_input;
	bool b_back_requested = false;
	bool b_exit_requested = false;
	while (!b_back_requested && !b_exit_requested)
	{
		vPrintCommands();
		cout << ENTER_COMMAND;
		getline(cin, s_input);
		for (int i = 0; i < v_c_menu_items.size(); i++)
		{
			if (s_input == v_c_menu_items[i]->sGetCommand())
			{
				i_command = 1;
				b_exit_requested = v_c_menu_items[i]->bRun();
			}// if (input == v_c_menu_items[i]->sGetCommand())
			else if (s_input == HELP + v_c_menu_items[i]->sGetCommand())
			{
				i_help = 1;
				cout << v_c_menu_items[i]->sGetHelp() << endl;
			}// else if (input == "help" + v_c_menu_items[index]->sGetName)
		}// for (int i = 0; i < v_c_menu_items.size(); i++)

		string s_search = s_input.substr(0, SEARCH.length());
		if (s_search == SEARCH)
		{
			vector<CMenuItem*> v_search_results;
			vStartSearch(v_search_results, s_input.substr(SEARCH.length()));
			for (int i = 0; i < v_search_results.size(); i++)
			{
				cout << v_search_results[i]->sGetPath() << endl;
			}//for (int i = 0; i < v_search_results.size(); i++)
			if (s_search.size() == 0)cout << EMPTY << endl;
		}// 	if (s_search == SEARCH)
		else if (s_input == BACK)
		{
			b_back_requested = true;
		}//else if (s_input == BACK)
		else if (s_input == EXIT)
		{
			b_exit_requested = true;
		}//else if (s_input == EXIT)
		else if (i_command == 0 && i_help == 0 && i_search == 0)
		{
			cout << NO_COMMAND << endl;
		}// else if (i_command == 0 && i_help == 0 && i_search == 0)
	}// while (!b_deleted)

	return b_exit_requested;
} // void CMenu::bRun()

void CMenu::vSearch(vector<CMenuItem*>& pcFoundItems, string sSearchCmd)
{
	if (s_command == sSearchCmd)
	{
		pcFoundItems.push_back(this);
	}//if (s_command == sSearchCmd)
	for (int i = 0; i < v_c_menu_items.size(); i++)
	{
		v_c_menu_items[i]->vSearch(pcFoundItems, sSearchCmd);
	}//for (int i = 0; i < v_c_menu_items.size(); i++)
} // void CMenu::vSearch(vector<CMenuItem*>& pcFoundItems, string sSearchCmd)

string CMenu::sGetName()
{
	return s_name;
}// string CMenu::sGetName()

string CMenu::sGetCommand()
{
	return s_command;
}// string CMenu::sGetCommand()

CMenu* CMenu::vAddSubmenu(string sName, string sCommand)
{
	for (int i = 0; i < v_c_menu_items.size(); i++)
	{
		if (v_c_menu_items.at(i)->sGetName() == sName || v_c_menu_items.at(i)->sGetCommand() == sCommand)
		{
			return NULL;
		}//if(v_c_menu_items.at(i)->sGetName()==sName || v_c_menu_items.at(i)->sGetCommand()==sCommand)
	}// for(int i=0;i<v_c_menu_items.size();i++)
	CMenu* c_new_menu = new CMenu(sName, sCommand);
	c_new_menu->c_parent = this;
	CMenuCommand* tempBack = new CMenuCommand(this);
	c_new_menu->vAddToVector(tempBack);
	v_c_menu_items.push_back(c_new_menu);
	return c_new_menu;
}//void CMenu::addSubmenu(string sName, string sCommand)

void CMenu::vPrintCommands()
{
	cout << endl << this->sGetName() + S_BRACKET_ONE + this->sGetCommand() + S_BRACKET_TWO << endl;
	for (int i = 0; i < v_c_menu_items.size(); i++)
	{
		cout << i + 1 << S_DOT << v_c_menu_items[i]->sGetName() << S_BRACKET_ONE << v_c_menu_items[i]->sGetCommand() << S_BRACKET_THREE << endl;
	}// for (int i = 0; i < v_c_menu_items.size(); i++)
}// void CMenu::vPrintCommands()

void CMenu::vAddToVector(CMenuItem* pcItem)
{
	v_c_menu_items.push_back(pcItem);
}// void CMenu::addToVector(CMenuItem* pcItem)

string CMenu::sMenuToString(CMenu* pcMenu)
{
	if (pcMenu->sGetName() == DEFALUT_MENU && pcMenu->sGetCommand() == DEFAULT_MENU_COMMAND)
	{
		s_menu_string += S_BRACKET_FOUR + pcMenu->sGetName() + S_DETACHMENT + pcMenu->sGetCommand() + S_DETACHMENT_ONE;
	}// if(pcMenu->sGetName()==DEFALUT_MENU && pcMenu->sGetCommand()==DEFAULT_MENU_COMMAND)
	char z;
	for (int i = 0; i < (pcMenu->v_c_menu_items.size()); i++)
	{
		z = (s_menu_string)[s_menu_string.length() - 1];
		if (z != ';') s_menu_string += S_COMMA; //wstawia przecinek po nawiasach
		CMenu* c_temp = dynamic_cast<CMenu*>(pcMenu->v_c_menu_items[i]); //nie rzuca wyjatku bo v_c_menu_items jest vektorem wskaznikow
		if (c_temp != NULL)
		{
			s_menu_string += s_BRACKET_FIVE + pcMenu->v_c_menu_items[i]->sGetName() + S_DETACHMENT + pcMenu->v_c_menu_items[i]->sGetCommand() + S_DETACHMENT_ONE;
			sMenuToString((CMenu*)pcMenu->v_c_menu_items[i]);
			s_menu_string += S_CLOSE_BRACKET;
		}//if (c_temp!=NULL)
		else
		{
			s_menu_string += S_COMMAND_BRACKET + pcMenu->v_c_menu_items[i]->sGetName() + S_DETACHMENT + pcMenu->v_c_menu_items[i]->sGetCommand() + S_DETACHMENT + (pcMenu->v_c_menu_items[i])->sGetHelp() + S_COMMAND_BRACKET_CLOSE;
		}//else
	}//for (int i = 0; i < (pcMenu->v_c_menu_items.size()); i++)
	return sAddBracket(s_menu_string);
}//string CMenu::sMenuToString(CMenu* pcMenu)

string CMenu::sAddBracket(string s_menu)
{
	return s_menu + S_CLOSE_BRACKET;
}//string CMenu::sAddBracket(string s_menu)

CMenu* CMenu::cMenuFromString(string sMenuString)
{
	if (sMenuString.empty())
	{
		cout << EMPTY << endl;
		return NULL;
	}//if(sMenuString=="")
	CMenu* pc_main_menu = NULL;
	CMenu* pc_current_menu = NULL;
	int i_okragle=0;
	int i_kwadratowe=0;
	for (int i = 0; i < sMenuString.length(); i++)
	{
		if (sMenuString[i] == S_OPEN_BRACKET)
		{
		    i_okragle++;
			i++;
			if (sMenuString[i] == S_QUOTATION_MARK)
			{
				i++;
				int i_name = sMenuString.find(S_SPEECH_MARK, i);
				string s_name = sMenuString.substr(i, i_name - i);
				i = i_name + 1;
				if (sMenuString[i] != S_COMMA_SIGN)
				{
					cout << SIGN << S_COMMA_SPACE << i << endl;
					return NULL;
				}//(sMenuString[i] != S_COMMA_SIGN)
				else
				{
					i++;
					if (sMenuString[i] != S_QUOTATION_MARK)
					{
						cout << SIGN << S_SPEECH_MARK_SPACE << i << endl;
						return NULL;
					}//(sMenuString[i] != S_QUOTATION_MARK)
					else
					{
						i++;
						int i_command = sMenuString.find(S_SPEECH_MARK, i);
						string s_command = sMenuString.substr(i, i_command - i);
						i = i_command + 1;
						if (pc_current_menu != NULL)
						{
							CMenu* pc_new_menu = new CMenu(s_name, s_command);
							pc_new_menu->vSetParent(pc_current_menu);
							pc_current_menu->vAddToVector(pc_new_menu);
							pc_current_menu = pc_new_menu;
						}//	if (pc_current_menu != NULL)
						else
						{
							pc_current_menu = new CMenu(s_name, s_command);
							pc_main_menu = pc_current_menu;
						}//else
						if (sMenuString[i] != S_SEMICOLON_SIGN)
						{
							cout << SIGN << S_SEMICOLON << i << endl;
							return NULL;
						}//if (sMenuString[i] != S_SEMICOLON_SIGN)
						else
                        {
                            if(sMenuString[i-1]==S_QUOTATION_MARK && (sMenuString[i+1]==S_CLOSE_BRACKET_SIGN || sMenuString[i+1]==S_OPEN_COMMAND_SIGN || sMenuString[i+1]==S_OPEN_BRACKET))
                            {
                            }// if(sMenuString[i-1]==S_QUOTATION_MARK && (sMenuString[i+1]==S_CLOSE_BRACKET_SIGN || sMenuString[i+1]==S_OPEN_COMMAND_SIGN || sMenuString[i+1]==S_OPEN_BRACKET))
                            else
                            {
                                cout<<SIGN<<S_THREE_OPTIONS<<i<<endl;
                                return NULL;
                            }//else
                        }//else
					}//else
				}//else
			}//if (sMenuString[i] == S_QUOTATION_MARK)
			else
			{
				cout << SIGN << S_SPEECH_MARK_SPACE << i << endl;
				return NULL;
			}//else
		}// if (sMenuString[i] == S_OPEN_BRACKET)
		else if (sMenuString[i] == S_OPEN_COMMAND_SIGN)
		{
			i++;
			i_kwadratowe++;
			if (sMenuString[i] == S_QUOTATION_MARK)
			{
				i++;
				int i_name = sMenuString.find(S_SPEECH_MARK, i);
				string s_name = sMenuString.substr(i, i_name - i);
				i = i_name + 1;
				if (sMenuString[i] != S_COMMA_SIGN)
				{
					cout << SIGN << S_COMMA_SPACE << i << endl;
					return NULL;
				}// if(sMenuString[i] != S_COMMA_SIGN)
				else
				{
					i++;
					if (sMenuString[i] != S_QUOTATION_MARK)
					{
						cout << SIGN << S_SPEECH_MARK_SPACE << i << endl;
						return NULL;
					}//if(sMenuString[i]!='\'')
					else
					{
						i++;
						int i_command = sMenuString.find(S_SPEECH_MARK, i);
						string s_command = sMenuString.substr(i, i_command - i);
						i = i_command + 1;
						if (sMenuString[i] != S_COMMA_SIGN)
						{
							cout << SIGN << S_COMMA_SPACE << i << endl;
							return NULL;
						}//if(sMenuString[i]!=',')
						else
						{
							i++;
							if (sMenuString[i] != S_QUOTATION_MARK)
							{
								cout << SIGN << S_SPEECH_MARK_SPACE << i << endl;
								return NULL;
							}//if(sMenuString[i]!='\'')
							else
							{
								i++;
								int i_help = sMenuString.find(S_SPEECH_MARK, i);
								string s_help = sMenuString.substr(i, i_help - i);
								i=i_help+1;
								CMenuCommand* pc_new_command = new CMenuCommand(s_name, s_command, s_help);
								if (pc_new_command->sGetName() == S_ADD_CTABLE)
									pc_new_command->vAddCreateCTable();
								else if (pc_new_command->sGetName() == S_CHANGE_TABLE_LENGTH)
									pc_new_command->vAddChangeTableLength();
								else if (pc_new_command->sGetName() == S_DELETE_CTABLE)
									pc_new_command->vAddDeleteCTable();
								else if (pc_new_command->sGetName() == S_DELETE_ALL)
									pc_new_command->vAddDeleteAll();
								else if (pc_new_command->sGetName() == S_CHANGE_NAME)
									pc_new_command->vAddChangeName();
								else if (pc_new_command->sGetName() == S_CLONE)
									pc_new_command->vAddCCloneCTable();
								else if (pc_new_command->sGetName() == S_SET_VALUE)
									pc_new_command->vAddCChangeCellValue();
								else if (pc_new_command->sGetName() == S_ALL_TABLES)
									pc_new_command->vAddCPrintAllCTables();
								pc_current_menu->vAddToVector(pc_new_command);
								pc_new_command->vSetParent(pc_current_menu);
							}//else
						}//else
					}//else
				}//else
			}//if (sMenuString[i] == S_QUOTATION_MARK)
		}// else if (sMenuString[i] == S_OPEN_COMMAND_SIGN)
		else if (sMenuString[i] == S_CLOSE_COMMAND_SIGH)
		{
			i++;
			i_kwadratowe--;
			if (sMenuString[i] != S_COMMA_SIGN)
			{
				if (sMenuString[i] != S_CLOSE_BRACKET_SIGN)
				{
					cout << SIGN << S_CLOSE_BRACKET_SPACE << i << endl;
					return NULL;
				}//if (sMenuString[i] != S_CLOSE_BRACKET_SIGN)
				else
				{
				    i_okragle--;
					if (pc_current_menu->cGetParent() != NULL)
					{
						pc_current_menu = dynamic_cast<CMenu*>(pc_current_menu->cGetParent());
					}//if (pc_current_menu->cGetParent() != NULL)
				}//else
			}//if (sMenuString[i] != S_COMMA_SIGN)
			else
            {
                cout<<SIGN<<S_COMMA_SPACE<<i<<endl;
                return NULL;
            }//else
		}// else if (sMenuString[i] == S_CLOSE_COMMAND_SIGH)
		else if (sMenuString[i] == S_CLOSE_BRACKET_SIGN)
		{
		    i_okragle--;
		    if(i<sMenuString.length()-1)
            {
                if(sMenuString[i+1]!=S_CLOSE_BRACKET_SIGN)
                {
                    if(sMenuString[i+1]!=S_COMMA_SIGN)
                    {
                        cout<<SIGN<<S_COMMA_SPACE<<i<<endl;
                        return NULL;
                    }//if(sMenuString[i+1]!=S_COMMA_SIGN)
                    i++;
                }// if(sMenuString[i+1]!=S_CLOSE_BRACKET_SIGN)
                if (pc_current_menu->cGetParent() != NULL)
                {
                    pc_current_menu = dynamic_cast<CMenu*>(pc_current_menu->cGetParent());
                }//if (pc_current_menu->cGetParent() != NULL)
                if (sMenuString[i] == S_CLOSE_BRACKET_SIGN)
                {
                    i_okragle--;
                    if (pc_current_menu->cGetParent() != NULL)
                    {
                        pc_current_menu = dynamic_cast<CMenu*>(pc_current_menu->cGetParent());
                    }//if (pc_current_menu->cGetParent() != NULL)
                }// if (sMenuString[i] == S_CLOSE_BRACKET_SIGN)
            }//  if(i<sMenuString.length()-1)
		}//else if (sMenuString[i] == S_CLOSE_BRACKET_SIGN)
		else if (sMenuString[i] == S_SEMICOLON_SIGN)
		{
			i++;
			if (sMenuString[i] != S_OPEN_BRACKET)
			{
				cout << SIGN << S_TWO_BRACKETS << i << endl;
				return NULL;
			}//if (sMenuString[i] != S_OPEN_BRACKET)
			if (sMenuString[i] != S_OPEN_COMMAND_SIGN)
			{
				cout << SIGN << S_OPEN_COMMAND_BRACKET << i << endl;
				return NULL;
			}//if (sMenuString[i] != S_OPEN_COMMAND_SIGN)
		}// else if (sMenuString[i] == S_SEMICOLON_SIGN)
		else if (sMenuString[0] != S_OPEN_BRACKET)
		{
			cout << SIGN << S_OPEN_BRACKET_SPACE << i << endl;
			return NULL;
		}//else if (sMenuString[0] != S_OPEN_BRACKET)
		else if(sMenuString[i]==S_COMMA_SIGN)
		{
		    if(i<sMenuString.length())
            {
                if((sMenuString[i-1]==S_CLOSE_BRACKET_SIGN || sMenuString[i-1]==S_CLOSE_COMMAND_SIGH)&& (sMenuString[i+1]==S_CLOSE_BRACKET_SIGN || sMenuString[i+1]==S_CLOSE_COMMAND_SIGH))
                {
                    cout << S_BAD_SIGN <<i<< endl;
                    return NULL;
                }// if((sMenuString[i-1]==S_CLOSE_BRACKET_SIGN || sMenuString[i-1]==S_CLOSE_COMMAND_SIGH)&& (sMenuString[i+1]==S_CLOSE_BRACKET_SIGN || sMenuString[i+1]==S_CLOSE_COMMAND_SIGH))
            }//  if(i<sMenuString.length())
		}//else if(sMenuString[i]==S_COMMA_SIGN)
		else if(sMenuString[i]!=S_OPEN_BRACKET && sMenuString[i]!=S_CLOSE_BRACKET_SIGN && sMenuString[i]!=S_OPEN_COMMAND_SIGN && sMenuString[i]!=S_CLOSE_COMMAND_SIGH && sMenuString[i]!=S_SEMICOLON_SIGN && sMenuString[i]!=S_COMMA_SIGN)
        {
            cout<<S_UNNECESSARY<<i<<endl;
            return NULL;
        }// else if(sMenuString[i]!=S_OPEN_BRACKET && sMenuString[i]!=S_CLOSE_BRACKET_SIGN && sMenuString[i]!=S_OPEN_COMMAND_SIGN && sMenuString[i]!=S_CLOSE_COMMAND_SIGH && sMenuString[i]!=S_SEMICOLON_SIGN && sMenuString[i]!=S_COMMA_SIGN)
        else
        {
            cout<<S_FAULT<<i<<endl;
            return NULL;
        }//else
	}//for (int i = 0; i < sMenuString.length(); i++)
	//cout<<i_okragle<<" "<<i_kwadratowe<<endl;
	return pc_main_menu;
}//CMenu* CMenu::cMenuFromString(string sMenuString)*/
