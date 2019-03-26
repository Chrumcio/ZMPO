
class CValue
{
public:
    CValue(){b_owner=false;};
    CValue(const CValue &cval);
    ~CValue();
    bool bEquals(CValue *pcOther);
    void vSetValue(void *pvValue,bool bOwner);


private:
    void Delete();
    void *pv_value;
    bool b_owner;
};
