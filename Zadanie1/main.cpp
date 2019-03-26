#include <iostream>
#include "CTable.h"
#include <string>
#include <vector>
#include <sstream>
#include "CVariables.h"

using namespace std;

const string S_QUESTION_VECTOR_LENGTH="Enter vector length";
const string S_CHOOSE_STEP="Choose step";
const string S_CREATE_OBJECT="[1] Create object ";
const string S_SET_TABLE_LENGTH="[2] Enter table length";
const string S_DELETE_OBJECT="[3] Delete object";
const string S_DELETE_ALL_OBJECTS="[4] Delete all objects";
const string S_SET_NAME="[5] Set name";
const string S_CLONE_OBJECT="[6] Clone object";
const string S_GET_INFO_ABOUT_OBJECT="[7] Get info about object";
const string S_SET_VALUE="[8] Set value at index";
const string S_SUM_OBJECT="[9] v_sum1";
const string S_SUM_RATE="[10] v_sum2";
const string S_EXIT="[11] End";
const string S_WRONG_ARGUMENT="Wrong argument, try one more";
const string S_CREATE_DEFAULT="[1] Create default object";
const string S_CREATE_OBJECT_VALUES="[2] Create object with your data";
const string S_CREATE_OBJECT_COPY="[3] Create object's copy";
const string S_QUESTION_TABLE_LENGTH="Enter table length";
const string S_QUESTION_OBJECT_NAME="Enter object name";
const string S_TABLE_INDEX="Enter table index";
const string S_QUESTION_OBJECT_COPY="Enter object index to make copy";
const string S_VECTOR_EMPTY="Vector null";
const string S_QUESTION_OBJECT_DELETE="Enter index to delete object";
const string S_OUT_OF_RANGE="Out of range";
const string S_SET_NAME_INDEX="Enter table index to set object's name";
const string S_OBJECT_GET_INFO="Enter table index to get info about object";
const string S_ENTER_VALUE="Enter value";
const string S_GET_USER_VALUE= "It isn't a number!";
const int I_CREATE_OBJECT=1;
const int I_SET_TABLE_LENGTH=2;
const int I_DELETE_OBJECT=3;
const int I_DELETE_ALL_OBJECTS=4;
const int I_SET_NAME=5;
const int I_CLONE_OBJECT=6;
const int I_GET_INFO_ABOUT_OBJECT=7;
const int I_SET_VALUE=8;
const int I_SUM_ONE=9;
const int I_SUM_TWO=10;
const int I_EXIT=11;

int iCheckValue(string s_user_choice,int c_vector_size);
int iCheckAnotherValue(string s_table_length);
void vProjectMain();

int main()
{
    int i_user_choice;
    int i_second_user_choice;
    int i_table_length;
    int i_table_index;
    int i_vector_index;
    int i_vector_length;
    int i_value;
    string s_user_choice;
    string s_object_name;
    string s_table_length;
    string s_table_index;
    string s_vector_index;
    string s_vector_length;
    string s_value;
    vector <CTable*> v_vector;


    cout<<S_QUESTION_VECTOR_LENGTH<<endl;
    cin>>s_vector_length;
    i_vector_length=iCheckAnotherValue(s_vector_length);
    v_vector.reserve(i_vector_length);

    while(true)
    {
        vProjectMain();
        cin>>s_user_choice;
        stringstream s_conversion(s_user_choice);
        s_conversion>>i_user_choice;
        while(i_user_choice<1 || i_user_choice>11)
        {
            cout<<S_WRONG_ARGUMENT<<endl;
            cin>>s_user_choice;
            stringstream s_conversion(s_user_choice);
            s_conversion>>i_user_choice;
        }//while(i_user_choice<1 || i_user_choice>9)
        switch(i_user_choice)
        {
        case I_CREATE_OBJECT:
            {
                cout<<S_CREATE_DEFAULT<<endl;
                cout<<S_CREATE_OBJECT_VALUES<<endl;
                cout<<S_CREATE_OBJECT_COPY<<endl;
                cin>>s_user_choice;
                stringstream s_conversion(s_user_choice);
                s_conversion>>i_second_user_choice;
                while(i_second_user_choice!=1 && i_second_user_choice!=2 && i_second_user_choice!=3)
                {
                    cout<<S_WRONG_ARGUMENT<<endl;
                    cin>>s_user_choice;
                    stringstream s_conversion(s_user_choice);
                    s_conversion>>i_second_user_choice;
                }// while(i_second_user_choice!=1 && i_second_user_choice!=2 & i_second_user_choice!=3)
                if(i_second_user_choice==1)
                {
                    CTable *c_new_object=new CTable();
                    v_vector.push_back(c_new_object);
                }//if(i_second_user_choice==1)
                else if(i_second_user_choice==2)
                {
                    cout<<S_QUESTION_OBJECT_NAME<<endl;
                    cin>>s_object_name;
                    cout<<S_QUESTION_TABLE_LENGTH<<endl;
                    cin>>s_table_length;
                    stringstream s_conversion(s_table_length);
                    s_conversion>>i_table_length;
                    while(i_table_length<1)
                    {
                        cout<<S_WRONG_ARGUMENT<<endl;
                        cin>>s_table_length;
                        stringstream s_conversion(s_table_length);
                        s_conversion>>i_table_length;
                    }//while(i_table_length<1)
                    CTable *c_new_object=new CTable(s_object_name,i_table_length);
                    v_vector.push_back(c_new_object);
                }// else if(i_second_user_choice==2)
                else if(i_second_user_choice==3)
                {
                    if(v_vector.size()==0)
                    {
                            cout<<S_VECTOR_EMPTY<<endl;
                            break;
                    }// if(v_vector.size()==0)
                    cout<<S_QUESTION_OBJECT_COPY<<endl;
                    cin>>s_user_choice;
                    i_user_choice=iCheckValue(s_user_choice,v_vector.size());
                    CTable *c_new_object=new CTable(*v_vector.at(i_user_choice-1));
                    v_vector.push_back(c_new_object);
                }//else if(i_help_choice==3)
                break;
            }//case I_CREATE_OBJECT:
        case I_SET_TABLE_LENGTH:
            {
                if(v_vector.size()==0)
                {
                    cout<<S_VECTOR_EMPTY<<endl;
                }// if(v_vector.size()==0)
                else
                {
                    cout<<S_TABLE_INDEX<<endl;
                    cin>>s_table_index;
                    i_table_index=iCheckValue(s_table_index,v_vector.size());
                    cout<<S_QUESTION_TABLE_LENGTH<<endl;
                    cin>>s_table_length;
                    i_table_length=iCheckAnotherValue(s_table_length);
                    v_vector.at(i_table_index-1)->vSetTableLength(i_table_length);
                }// else
                break;
            }//case I_SET_TABLE_LENGTH:
        case I_DELETE_OBJECT:
            {
                if(v_vector.size()==0)
                {
                    cout<<S_VECTOR_EMPTY<<endl;
                }//  if(v_vector.size()==0)
                else if(v_vector.size()==1)
                {
                    delete v_vector.at(0);
                    v_vector.clear();
                }//  else if(v_vector.size()==1)
                else
                {
                    cout<<S_QUESTION_OBJECT_DELETE<<endl;
                    cin>>s_table_index;
                    i_table_index=iCheckAnotherValue(s_table_index);
                    if(i_table_index>=v_vector.size())
                    {
                        cout<<S_OUT_OF_RANGE<<endl;
                    }//if(i_table_index>v_vector.size())
                    else
                    {
                        delete v_vector.at(i_table_index-1);
                        v_vector.erase(v_vector.begin()+i_table_index-1);
                    }//else
                }//else
                break;
            }//  case I_DELETE_OBJECT:
        case I_DELETE_ALL_OBJECTS:
            {
                if(v_vector.size()==0)
                {
                    cout<<S_VECTOR_EMPTY<<endl;
                }// if(v_vector.size()==0)
                else
                {
                    for(int i=0;i<v_vector.size();i++)
                    {
                        if(v_vector.at(i)!=NULL)
                            delete v_vector.at(i);
                    }//for(int i=0;i<v_vector.size();i++)
                    v_vector.clear();
                }//else
                break;
            }// case I_DELETE_ALL_OBJECTS:
        case I_SET_NAME:
            {
                if(v_vector.size()==0)
                {
                        cout<<S_VECTOR_EMPTY<<endl;
                }// if(v_vector.size()==0)
                else
                {
                    cout<<S_SET_NAME_INDEX<<endl;
                    cin>>s_table_index;
                    i_table_index=iCheckValue(s_table_index,v_vector.size());
                    cout<<S_QUESTION_OBJECT_NAME<<endl;
                    cin>>s_object_name;
                    v_vector.at(i_table_index-1)->vSetName(s_object_name);
                }//else
               break;
            }// case I_SET_NAME:
        case I_CLONE_OBJECT:
            {
                if(v_vector.size()==0)
                {
                    cout<<S_VECTOR_EMPTY<<endl;
                }//if(v_vector.size()==0)
                else
                {
                    cout<<S_TABLE_INDEX<<endl;
                    cin>>s_table_index;
                    i_table_index=iCheckAnotherValue(s_table_index);
                    v_vector.push_back(new CTable(v_vector.at(i_table_index-1)));
                }//if(v_vector.size()==0)
                break;
            }//   case I_CLONE_OBJECT:
        case I_GET_INFO_ABOUT_OBJECT:
            {
                if(v_vector.size()==0)
                {
                    cout<<S_VECTOR_EMPTY<<endl;
                }//if(v_vector.size()==0)
                else
                {
                    cout<<S_OBJECT_GET_INFO<<endl;
                    cin>>s_table_index;
                    i_table_index=iCheckValue(s_table_index,v_vector.size());
                    cout<<v_vector.at(i_table_index-1)->sGetInfo();
                }//else
                break;
            }// case I_GET_INFO_ABOUT_OBJECT:
        case I_SET_VALUE:
            {
                if(v_vector.size()==0)
                {
                    cout<<S_VECTOR_EMPTY<<endl;
                    break;
                }// if(v_vector.size()==0)
                cout<<S_TABLE_INDEX<<endl;
                cin>>s_vector_index;
                i_vector_index=iCheckValue(s_vector_index,v_vector.size());
                cout<<S_TABLE_INDEX<<endl;
                cin>>s_table_index;
                stringstream s_conversion(s_table_index);
                s_conversion>>i_table_index;
                while(i_table_index<=0 || i_table_index>v_vector.at(i_vector_index-1)->iGetTableLength())
                {
                    cout<<S_WRONG_ARGUMENT<<endl;
                    cin>>s_table_index;
                    stringstream s_conversion(s_table_index);
                    s_conversion>>i_table_index;
                }//while(i_table_index<0 || i_table_index>v_vector.at(i_vector_index)->iGetTableLength())
                cout<<S_ENTER_VALUE<<endl;
                cin>>s_value;
                stringstream s_conversion_second(s_value);
                s_conversion_second>>i_value;
                v_vector.at(i_vector_index-1)->bSetValue(i_table_index-1,i_value);
                break;
            }//case S_SET_VALUE:
        case I_SUM_ONE:
            {
                int i_wczytaj_suma;
                cout<<"Podaj index obiektu do zsumowanie wartosci"<<endl;
                cin>>i_wczytaj_suma;
                v_vector.at(i_wczytaj_suma)->vSum(v_vector.at(i_wczytaj_suma));
                break;
            }
        case I_SUM_TWO:
            {
                int i_wczytaj_suma;
                cout<<"Podaj index obiektu do zsumowanie wartosci"<<endl;
                cin>>i_wczytaj_suma;
                v_vector.at(i_wczytaj_suma)->vSum(*v_vector.at(i_wczytaj_suma));
                break;
            }
        case I_EXIT:
            {
                for (int i=0;i<v_vector.size();i++)
                {
                    if (v_vector.at(i)!=NULL)
                    {
                        delete v_vector.at(i);
                        v_vector.at(i)=NULL;
                    }// if (c_vector.at(i) != NULL)
                }// for (int i = 0; i <v_vector.size(); i++)
                v_vector.clear();
                return 0;
            }//case I_EXIT:
        }//switch(i_user_choice)
    }//while(true)
}// int main()

void vProjectMain()
{
    cout<<S_CHOOSE_STEP<<endl;
    cout<<S_CREATE_OBJECT<<endl;
    cout<<S_SET_TABLE_LENGTH<<endl;
    cout<<S_DELETE_OBJECT<<endl;
    cout<<S_DELETE_ALL_OBJECTS<<endl;
    cout<<S_SET_NAME<<endl;
    cout<<S_CLONE_OBJECT<<endl;
    cout<<S_GET_INFO_ABOUT_OBJECT<<endl;
    cout<<S_SET_VALUE<<endl;
    cout<<S_SUM_OBJECT<<endl;
    cout<<S_SUM_RATE<<endl;
    cout<<S_EXIT<<endl;
}

int iCheckValue(string s_user_choice,int c_vector_size)
{
    int i_user_choice;
    stringstream s_conversion(s_user_choice);
    s_conversion>>i_user_choice;
    while(i_user_choice<=0 || i_user_choice>c_vector_size)
    {
        cout<<S_WRONG_ARGUMENT<<endl;
        cin>>s_user_choice;
        stringstream s_conversion(s_user_choice);
        s_conversion>>i_user_choice;
    }//while(i_user_choice<0 || i_user_choice>c_vector_size-1)
    return i_user_choice;
}

int iCheckAnotherValue(string s_table_length)
{
    int i_table_length;
    stringstream s_conversion(s_table_length);
    s_conversion>>i_table_length;
    while(i_table_length<=0)
    {
        string s_table_length;
        cout<<S_WRONG_ARGUMENT<<endl;
        cin>>s_table_length;
        stringstream s_conversation(s_table_length);
        s_conversation>>i_table_length;
    }//while(i_table_length<=0)
    return i_table_length;
}

