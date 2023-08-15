//
//  PersonProfile.hpp
//  CS32_4
//
//  Created by Snigdha Kansal on 3/7/22.
//

#ifndef PersonProfile_h
#define PersonProfile_h
#include "RadixTree.h"
#include "provided.h"
#include <vector>
#include <set>

using namespace std;

class PersonProfile
{
public:
    PersonProfile(string name, string email);
    ~PersonProfile(){};
    string GetName() const;
    string GetEmail() const;

    void AddAttValPair(const AttValPair &attval);
    int GetNumAttValPairs() const;
    bool GetAttVal(int attribute_num, AttValPair &attval) const;

private:
    string m_name;
    string m_email;
    // Maps attributes to set of values
    RadixTree<set<string>> m_radixtree;
    // Vector of all distinct AttValPairs
    vector<AttValPair> m_attval;
};

#endif /* PersonProfile_h */
