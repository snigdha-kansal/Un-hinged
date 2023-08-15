//
//  MemberDatabase.hpp
//  CS32_4
//
//  Created by Snigdha Kansal on 3/8/22.
//

#ifndef MemberDatabase_h
#define MemberDatabase_h
#include "provided.h"
#include "PersonProfile.h"
#include "RadixTree.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class MemberDatabase
{
public:
    MemberDatabase(){};
    ~MemberDatabase();
    bool LoadDatabase(string filename);
    vector<string> FindMatchingMembers(const AttValPair &input) const;
    const PersonProfile *GetMemberByEmail(string email) const;

private:
    // Maps attval string to vector of emails
    RadixTree<vector<string>> m_radixtree1;
    // Maps email string to PersonProfile*
    RadixTree<PersonProfile *> m_radixtree2;
    // Vector of PersonProfile*
    vector<PersonProfile *> m_members;
};

#endif /* MemberDatabase_h */
