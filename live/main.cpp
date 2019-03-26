#include <iostream>
#include "CValue.h"

using namespace std;

int main()
{
    CValue c_value_0,c_value_1,c_value_2,c_value_3;
    int *pi_int_value=new int(21);
    bool b_bool_value=false;
    c_value_0.vSetValue(&pi_int_value,false);
    c_value_1.vSetValue(pi_int_value,true);
    c_value_2.vSetValue(pi_int_value,false);
    c_value_3.vSetValue(&b_bool_value,false);
    cout<<c_value_0.bEquals(&c_value_1)<<endl;
    cout<<c_value_0.bEquals(&c_value_3)<<endl;
    cout<<c_value_1.bEquals(&c_value_2)<<endl;
    CValue c_value_4(c_value_1);
    CValue c_value_5(c_value_0);
    cout<<c_value_4.bEquals(&c_value_1)<<endl;
    cout<<c_value_5.bEquals(&c_value_0)<<endl;
    return 0;
}
