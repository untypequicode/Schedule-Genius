#include "tab_dyn.hpp"

TabDynInt::TabDynInt()
	: TabDyn()
{

}

TabDynInt::TabDynInt(unsigned int nbElemMax)
	: TabDyn(nbElemMax),
	m_tab(new int[nbElemMax])
{

}

TabDynInt::TabDynInt(unsigned int nbElemMax, bool add_with_multiple, unsigned int addition)
	: TabDyn(nbElemMax, add_with_multiple, addition),
	m_tab(new int[nbElemMax])
{

}

TabDynInt::TabDynInt(const TabDynInt& tabDynInt)
	: TabDyn(tabDynInt),
	m_tab(new int[tabDynInt.m_nbElemMax])
{
	for (unsigned int i = 0; i < tabDynInt.m_nbElem; i++)
	{
		m_tab[i] = tabDynInt.m_tab[i];
	}
}

TabDynInt::~TabDynInt()
{
	delete[] m_tab;
}

void TabDynInt::Append(int i)
{
	AddAppend(i, true);
}

void TabDynInt::Add(int i)
{
	AddAppend(i, false);
}

int TabDynInt::Get(unsigned int index) const
{
	if (index < m_nbElem)
	{
		return m_tab[index];
	}
	else
	{
		return 0;
	}
}

int* TabDynInt::GetTab() const
{
	return m_tab;
}

void TabDynInt::Set(unsigned int index, int i)
{
	if (index < m_nbElem)
	{
		m_tab[index] = i;
	}
}

void TabDynInt::AddAppend(int i, bool addition)
{
	if (m_nbElemMax == 0)
	{
		if (addition)
		{
			m_tab = new int[m_addition];
			m_nbElemMax = m_addition;
		}
		else
		{
			m_tab = new int[1];
			m_nbElemMax = 1;
		}
		m_tab[0] = i;
		m_nbElem = 1;
	}
	else if (m_nbElem < m_nbElemMax)
	{
		m_tab[m_nbElem] = i;
		m_nbElem++;
	}
	else if (m_nbElem == m_nbElemMax)
	{
		int* new_tab;
		if (addition)
		{
			if (m_add_with_multiple)
			{
				new_tab = new int[m_nbElemMax * m_addition];
			}
			else
			{
				new_tab = new int[m_nbElemMax + m_addition];
			}
		}
		else
		{
			new_tab = new int[m_nbElemMax +1];
		}
		for (unsigned int i = 0; i < m_nbElem; i++)
		{
			new_tab[i] = m_tab[i];
		}
		delete[] m_tab;
		new_tab[m_nbElem] = i;
		if (addition)
		{
			if (m_add_with_multiple)
			{
				m_nbElemMax *= m_addition;
			}
			else
			{
				m_nbElemMax += m_addition;
			}
		}
		else
		{
			m_nbElemMax++;
		}
		m_nbElem++;
		m_tab = new_tab;
	}
}