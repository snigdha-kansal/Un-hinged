//
//  MemberDatabase.cpp
//  CS32_4
//
//  Created by Snigdha Kansal on 3/8/22.
//

#include "MemberDatabase.h"

MemberDatabase::~MemberDatabase()
{
    vector<PersonProfile *>::iterator it = m_members.begin();
    while (it != m_members.end())
    {
        PersonProfile *temp = *it;
        delete temp;
        it = m_members.erase(it);
    }
}

bool MemberDatabase::LoadDatabase(string filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        return false;
    }

    while (infile)
    {
        string name, email, pairs;
        if (getline(infile, name) && !name.empty())
        {
            getline(infile, email);
            if (m_radixtree2.search(email) != nullptr)
            {
                return false;
            }
            PersonProfile *member = new PersonProfile(name, email);
            getline(infile, pairs);
            stringstream pair(pairs);
            int attval_count = 0;
            pair >> attval_count;
            for (int i = 0; i < attval_count; i++)
            {
                string line;
                getline(infile, line);
                istringstream iss(line);
                string att, val;
                getline(iss, att, ',');
                getline(iss, val, '\n');
                AttValPair to_add(att, val);
                member->AddAttValPair(to_add);
                string attval = att + val;
                vector<string> *emails_with_attval = m_radixtree1.search(attval);
                if (emails_with_attval == nullptr)
                {
                    vector<string> new_attvals = {email};
                    m_radixtree1.insert(attval, new_attvals);
                }
                else
                {
                    emails_with_attval->push_back(email);
                }
            }
            m_radixtree2.insert(email, member);
            m_members.push_back(member);
        }
    }
    return true;
}

vector<string> MemberDatabase::FindMatchingMembers(const AttValPair &input) const
{
    string attval = input.attribute + input.value;
    vector<string> *matching_members = m_radixtree1.search(attval);
    if (matching_members == nullptr)
    {
        return vector<string>();
    }
    return *matching_members;
}

const PersonProfile *MemberDatabase::GetMemberByEmail(string email) const
{
    PersonProfile **pp = m_radixtree2.search(email);
    if (pp == nullptr)
    {
        return nullptr;
    }
    return *pp;
}
