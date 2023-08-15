//
//  MatchMaker.hpp
//  CS32_4
//
//  Created by Snigdha Kansal on 3/8/22.
//

#ifndef MatchMaker_h
#define MatchMaker_h
#include "MemberDatabase.h"
#include "AttributeTranslator.h"
#include "provided.h"
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool sortbysecdesc(const EmailCount &a, const EmailCount &b);

bool operator<(const AttValPair &a, const AttValPair &b);

class MatchMaker
{
public:
    MatchMaker(const MemberDatabase &mdb, const AttributeTranslator &at);
    ~MatchMaker(){};
    vector<EmailCount> IdentifyRankedMatches(string email, int threshold) const;

private:
    const MemberDatabase *m_memberdatabase;
    const AttributeTranslator *m_attributetranslator;
};

#endif /* MatchMaker_h */