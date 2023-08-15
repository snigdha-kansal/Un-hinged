//
//  PersonProfile.cpp
//  CS32_4
//
//  Created by Snigdha Kansal on 3/7/22.
//

#include "PersonProfile.h"

PersonProfile::PersonProfile(string name, string email)
    : m_name(name), m_email(email) {}

string PersonProfile::GetName() const
{
    return m_name;
}

string PersonProfile::GetEmail() const
{
    return m_email;
}

void PersonProfile::AddAttValPair(const AttValPair &attval)
{
    set<string> *att_set = m_radixtree.search(attval.attribute);

    if (att_set == nullptr)
    {
        set<string> value_to_add = {attval.value};
        m_radixtree.insert(attval.attribute, value_to_add);
        m_attval.push_back(attval);
        return;
    }

    bool res = att_set->insert(attval.value).second;

    att_set->insert(attval.value);

    if (res)
    {
        m_attval.push_back(attval);
    }
    return;
}

int PersonProfile::GetNumAttValPairs() const
{
    return int(m_attval.size());
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair &attval) const
{
    if (0 <= attribute_num && attribute_num < int(m_attval.size()))
    {
        attval = m_attval[attribute_num];
        return true;
    }
    return false;
}
