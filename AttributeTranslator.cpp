//
//  AttributeTranslator.cpp
//  CS32_4
//
//  Created by Snigdha Kansal on 3/8/22.
//

#include "AttributeTranslator.h"

using namespace std;

bool AttributeTranslator::Load(string filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        return false;
    }

    while (infile)
    {
        string line;
        getline(infile, line);
        if (line == "")
        {
            break;
        }
        istringstream iss(line);

        string s_att, s_val, c_att, c_val;

        getline(iss, s_att, ',');
        getline(iss, s_val, ',');
        getline(iss, c_att, ',');
        getline(iss, c_val, '\n');

        string s_attval = s_att + s_val;
        AttValPair c_attval(c_att, c_val);

        vector<AttValPair> *compatible_pairs = m_radixtree.search(s_attval);
        if (compatible_pairs == nullptr)
        {
            vector<AttValPair> new_compatible_pairs = {c_attval};
            m_radixtree.insert(s_attval, new_compatible_pairs);
        }
        else
        {
            compatible_pairs->push_back(c_attval);
        }
    }
    return true;
}

vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair &source) const
{
    string s_attval = source.attribute + source.value;
    vector<AttValPair> *compatible_pairs = m_radixtree.search(s_attval);
    if (compatible_pairs == nullptr)
    {
        return vector<AttValPair>();
    }
    return *compatible_pairs;
}