#include "CValue.h"
#include <cstddef>

CValue::CValue(const CValue &pcOther)
{
    pv_value=pcOther.pv_value;
    b_owner=false;
}//CValue::CValue(CValue *pcOther)

CValue::~CValue()
{
    Delete();
}//CValue::~CValue()

bool CValue::bEquals(CValue *pcOther)
{
    if(pcOther!=NULL){
        if(this->pv_value==pcOther->pv_value)
        {
            return true;
        }
        return false;
    }
    return false;
}//bool CValue::bEquals(CValue *pcOther)

void CValue::vSetValue(void *pvValue,bool bOwner)
{
    Delete();
    this->pv_value=pvValue;
    this->b_owner=bOwner;
}//void CValue::vSetValue(void *pvValue,bool bOwner)

void CValue::Delete()
{
    if(this->b_owner==true)
        delete pv_value;
}
