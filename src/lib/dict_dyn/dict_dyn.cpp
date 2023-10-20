#include "dict_dyn.h"

DictDynIntString::DictDynIntString()
    : TabDyn()
{

}

DictDynIntString::DictDynIntString(unsigned int nbElemMax)
    : TabDyn(nbElemMax),
      m_keys(nbElemMax),
      m_values(nbElemMax)
{

}

DictDynIntString::DictDynIntString(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
    : TabDyn(nbElemMax, add_with_multiple, addition),
      m_keys(nbElemMax),
      m_values(nbElemMax)
{

}

DictDynIntString::DictDynIntString(const DictDynIntString &dictDynIntString)
    : TabDyn(dictDynIntString),
        m_keys(dictDynIntString.GetKeys()),
        m_values(dictDynIntString.GetValues())
{

}

DictDynIntString::~DictDynIntString()
{

}

void DictDynIntString::Append(int key, std::string value)
{
    AddAppend(key, value, false);
}

void DictDynIntString::Add(int key, std::string value)
{
    AddAppend(key, value, true);
}

std::string DictDynIntString::Get(int key) const
{
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        if (m_keys.Get(i) == key)
        {
            return m_values.Get(i);
        }
    }
    return "/0";
}

TabDynInt DictDynIntString::GetKeys() const
{
    return m_keys;
}

TabDynString DictDynIntString::GetValues() const
{
    return m_values;
}

void DictDynIntString::Set(int key, std::string value)
{
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        if (m_keys.Get(i) == key)
        {
            m_values.Set(i, value);
            return;
        }
    }
}

std::string DictDynIntString::Pop(int key)
{
    for (int i = 0; i < m_nb_elem; i++)
    {
        if (m_keys.Get(i) == key)
        {
            m_keys.Pop(i);
            return m_values.Pop(i);
        }
    }
    return "/0";
}

void DictDynIntString::Remove(std::string value, int num)
{
    if (num < m_nb_elem)
    {
        int count = 0;
        for (int i = 0; i < m_nb_elem; i++) {
            if (m_values.Get(i) == value) {
                count++;
                if (count == num) {
                    m_keys.Pop(i);
                    m_values.Pop(i);
                    return;
                }
            }
        }
    }
}

void DictDynIntString::Remove(std::string value)
{
    for (int i = 0; i < m_nb_elem; i++)
    {
        if (m_values.Get(i) == value)
        {
            m_keys.Pop(i);
            m_values.Pop(i);
            i--;
        }
    }
}

void DictDynIntString::Remove(std::string value, bool first)
{
    if (first)
    {
        for (int i = 0; i < m_nb_elem; i++)
        {
            if (m_values.Get(i) == value)
            {
                m_keys.Pop(i);
                return;
            }
        }
    }
    else
    {
        for (int i = m_nb_elem - 1; i >= 0; i--)
        {
            if (m_values.Get(i) == value)
            {
                m_keys.Pop(i);
                return;
            }
        }
    }
}

void DictDynIntString::AddAppend(int key, std::string value, bool addition)
{
    for (unsigned int i = 0; i < m_nb_elem; i++)
    {
        if (m_keys.Get(i) == key)
        {
            m_values.Set(i, value);
            return;
        }
    }
    if (m_nb_elem < m_nb_elem_max)
    {
        m_values.Set(m_nb_elem, value);
        m_keys.Set(m_nb_elem, key);
        m_nb_elem++;
    }
    else if (m_nb_elem == m_nb_elem_max)
    {
        if (addition)
        {
            m_keys.Add(key);
            m_values.Add(value);
        }
        else
        {
            m_keys.Add(key, false);
            m_values.Add(value, false);
        }
        m_nb_elem++;
        m_nb_elem_max = m_keys.GetNbElemMax();
    }
}