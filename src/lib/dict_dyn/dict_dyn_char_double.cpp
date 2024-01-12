#include "dict_dyn.h"

DictDynCharDouble::DictDynCharDouble()
    : DictDyn(),
      m_tab_keys(),
      m_tab_values()
{

}

DictDynCharDouble::DictDynCharDouble(unsigned int nb_elem_max)
    : DictDyn(nb_elem_max),
      m_tab_keys(nb_elem_max),
      m_tab_values(nb_elem_max)
{

}

DictDynCharDouble::DictDynCharDouble(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition)
    : DictDyn(nb_elem_max, add_with_multiple, number_addition),
      m_tab_keys(nb_elem_max, add_with_multiple, number_addition),
      m_tab_values(nb_elem_max, add_with_multiple, number_addition)
{

}

DictDynCharDouble::DictDynCharDouble(const DictDynCharDouble& dict_dyn_ref)
    : DictDyn(dict_dyn_ref),
      m_tab_keys(dict_dyn_ref.m_tab_keys),
      m_tab_values(dict_dyn_ref.m_tab_values)
{

}

DictDynCharDouble::~DictDynCharDouble()
{

}

void DictDynCharDouble::SetParam(bool add_with_multiple, unsigned int number_addition)
{
    m_tab_keys.SetParam(add_with_multiple, number_addition);
    m_tab_values.SetParam(add_with_multiple, number_addition);
}

void DictDynCharDouble::SetSecurity(bool security)
{
    m_tab_keys.SetSecurity(security);
    m_tab_values.SetSecurity(security);
}

unsigned int DictDynCharDouble::GetNbElem() const
{
  if (m_tab_keys.GetNbElem() < m_tab_values.GetNbElem())
    {
        return m_tab_keys.GetNbElem();
    }
  return m_tab_values.GetNbElem();
}

unsigned int DictDynCharDouble::GetNbElemMax() const
{
  if (m_tab_keys.GetNbElemMax() < m_tab_values.GetNbElemMax())
    {
    return m_tab_keys.GetNbElemMax();
  }
  return m_tab_values.GetNbElemMax();
}

void DictDynCharDouble::Copy(DictDynCharDouble &dict_dyn_ref){
    m_tab_keys.Copy(dict_dyn_ref.m_tab_keys);
    m_tab_values.Copy(dict_dyn_ref.m_tab_values);
}

void DictDynCharDouble::Add(char key, double value)
{
    Add(key, value, true);
}

void DictDynCharDouble::Add(char key, double value, bool add_with_multiple)
{
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
    m_tab_keys.Add(key, add_with_multiple);
    m_tab_values.Add(value, add_with_multiple);

}

double DictDynCharDouble::Get(char key) const
{
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            return m_tab_values.Get(i);
        }
    }
    return '\0';
}

TabDynChar& DictDynCharDouble::GetTabKeys()
{
    return m_tab_keys;
}

TabDynDouble& DictDynCharDouble::GetTabValues()
{
    return m_tab_values;
}

void DictDynCharDouble::Set(char key, double value)
{
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_values.Set(i, value);
            return;
        }
    }
}

bool DictDynCharDouble::IfValue(char key, std::string condition, double value_id)
{
    return comparaison(Get(key), condition, value_id);
}

bool DictDynCharDouble::IfKey(char key, std::string condition, char value)
{
    return comparaison(key, condition, value);
}

DictDynCharDouble DictDynCharDouble::FiltreValue(std::string condition, double value)
{
    DictDynCharDouble dict_dyn_result;
    for (unsigned int i = 0; i < GetNbElem(); i++){
      if(comparaison(m_tab_values.Get(i), condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynCharDouble DictDynCharDouble::FiltreValue(const TabDynString& condition, const TabDynDouble& value, const TabDynString& OrAnd)
{
    for (unsigned int i = 0; i < condition.GetNbElem(); i++)
        std::cout << "condition : '" << condition.Get(i) << "'" << std::endl;

    DictDynCharDouble dict_dyn_result;
    bool test;
    unsigned int index;
    for (unsigned int i = 0; i < GetNbElem(); i++) {
        index = 0;
        test = comparaison(m_tab_values.Get(i), condition.Get(0), value.Get(0));
        while (index < OrAnd.GetNbElem())
        {
            if (OrAnd.Get(index) == "or" and !test) {
                index++;
                test = comparaison(m_tab_values.Get(i), condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "and" and test)
            {
                index++;
                test = comparaison(m_tab_values.Get(i), condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "or" or OrAnd.Get(index) == "and")
            {
                index++;
            }

            else
            {
                std::cerr << "Error : comparator forbidden : '"<< OrAnd.Get(index) << "' , only 'and' and 'or' are allowed" << std::endl;
                std::cerr << "index :" << index;
                return DictDynCharDouble();
            }
        }
        if(test)
        {
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
            test = false;
        }
    }
    return dict_dyn_result;
}

DictDynCharDouble DictDynCharDouble::FiltreKey(const TabDynString& condition, const TabDynChar& value, const TabDynString& OrAnd)
{
    DictDynCharDouble dict_dyn_result;
    bool test;
    unsigned int index = 0;
    for (unsigned int i = 0; i < GetNbElem(); i++)
    {
        test = comparaison(m_tab_keys.Get(i), condition.Get(0), value.Get(0));
        while (index < OrAnd.GetNbElem())
        {
            if (OrAnd.Get(index) == "or" and !test)
            {
                index++;
                test = comparaison(m_tab_keys.Get(i), condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "and" and test)
            {
                index++;
                test = comparaison(m_tab_keys.Get(i), condition.Get(index), value.Get(index));
            }

            else if (OrAnd.Get(index) == "or" or OrAnd.Get(index) == "and")
            {
                index++;
            }

            else
            {
                std::cerr << "Error : comparator forbidden, only 'and' and 'or' are allowed" << std::endl;
                return DictDynCharDouble();
            }
        }
        index = 0;
        if(test)
        {
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
            test = false;
        }
    }
    return dict_dyn_result;
}

DictDynCharDouble DictDynCharDouble::FiltreAndValue(const TabDynString& condition, const TabDynDouble& value)
{
    DictDynCharDouble dict_dyn_result;
    bool test = true;
    for(unsigned int i = 0; i < GetNbElem(); i++)
    {
        for(unsigned int j = 0; j < condition.GetNbElem(); j++){
            if(!comparaison(m_tab_values.Get(i), condition.Get(j), value.Get(j)))
            {
                test = false;
                break;
            }
        }
        if(test)
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        test = true;
    }
    return dict_dyn_result;
}

DictDynCharDouble DictDynCharDouble::FiltreOrValue(const TabDynString& condition, const TabDynDouble& value)
{
    DictDynCharDouble dict_dyn_result;
    bool test = false;
    for(unsigned int i = 0; i < GetNbElem(); i++)
    {
        for(unsigned int j = 0; j < condition.GetNbElem(); j++){
            if(comparaison(m_tab_values.Get(i), condition.Get(j), value.Get(j)))
            {
                test = true;
                break;
            }
        }
        if(test)
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        test = false;
    }
    return dict_dyn_result;
}

DictDynCharDouble DictDynCharDouble::FiltreKey(std::string condition, char value)
{
    DictDynCharDouble dict_dyn_result;
    for (unsigned int i = 0; i < GetNbElem(); i++){
        if(comparaison(m_tab_keys.Get(i), condition, value)){
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        }
    }
    return dict_dyn_result;
}

DictDynCharDouble DictDynCharDouble::FiltreAndKey(const TabDynString& condition, const TabDynChar& value)
{
    DictDynCharDouble dict_dyn_result;
    bool test = true;
    for (unsigned int i = 0; i < GetNbElem(); i++)
    {
        for (unsigned int j = 0; j < condition.GetNbElem(); j++)
        {
            if(!comparaison(m_tab_keys.Get(i), condition.Get(j), value.Get(j))){
                test = false;
                break;
            }
        }
        if(test)
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        test = true;
    }
    return dict_dyn_result;
}

DictDynCharDouble DictDynCharDouble::FiltreOrKey(const TabDynString& condition, const TabDynChar& value)
{
    DictDynCharDouble dict_dyn_result;
    bool test = false;
    for (unsigned int i = 0; i < GetNbElem(); i++)
    {
        for (unsigned int j = 0; j < condition.GetNbElem(); j++)
        {
            if(comparaison(m_tab_keys.Get(i), condition.Get(j), value.Get(j))){
                test = true;
                break;
            }
        }
        if(test)
            dict_dyn_result.Add(m_tab_keys.Get(i), m_tab_values.Get(i));
        test = false;
    }
    return dict_dyn_result;
}

DictDynCharDouble fusion(DictDynCharDouble& dict_dyn_ref, DictDynCharDouble& dict_dyn_ref2)
{
    char key;
    DictDynCharDouble dict_dyn_result;
    
    for (unsigned int i = 0; i < dict_dyn_ref2.GetNbElem(); i++) {
        key = dict_dyn_ref2.GetTabKeys().Get(i);
        dict_dyn_result.Add(key, dict_dyn_ref2.Get(key));
        dict_dyn_ref.Pop(key);
    }
    for(unsigned int i = 0; i < dict_dyn_ref.GetNbElem(); i++)
    {
        key = dict_dyn_ref.GetTabKeys().Get(i);
        dict_dyn_result.Add(key, dict_dyn_ref.Get(key));
    }
    return dict_dyn_result;
}

double DictDynCharDouble::Pop(char key)
{
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_keys.Get(i) == key){
            m_tab_keys.Pop(i);
            return m_tab_values.Pop(i);
        }
    }
    return '\0';
}

void DictDynCharDouble::Remove(double value, int num)
{
    int count = 0;
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_values.Get(i) == value){
            count++;
            if(count == num){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
}

void DictDynCharDouble::Remove(double value)
{
    for (int i = 0; i < GetNbElem(); i++){
        if(m_tab_values.Get(i) == value){
            m_tab_keys.Pop(i);
            m_tab_values.Pop(i);
            i--;
        }
    }
}

void DictDynCharDouble::Remove(double value, bool is_first)
{
    if(is_first){
        for (int i = 0; i < GetNbElem(); i++){
            if(m_tab_values.Get(i) == value){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
    else{
        for (int i = GetNbElem() - 1; i >= 0 ; i--){
            if(m_tab_values.Get(i) == value){
                m_tab_keys.Pop(i);
                m_tab_values.Pop(i);
                return;
            }
        }
    }
}