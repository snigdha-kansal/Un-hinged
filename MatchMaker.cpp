//
//  MatchMaker.cpp
//  CS32_4
//
//  Created by Snigdha Kansal on 3/8/22.
//

#include "MatchMaker.h"

using namespace std;

bool sortbysecdesc(const EmailCount &a, const EmailCount &b)
{
    if (a.count == b.count)
    {
        return a.email < b.email;
    }
    return a.count > b.count;
}

bool operator<(const AttValPair &a, const AttValPair &b)
{
    if (a.attribute < b.attribute)
    {
        return true;
    }
    else if (a.attribute == b.attribute && a.value < b.value)
    {
        return true;
    }
    return false;
}

MatchMaker::MatchMaker(const MemberDatabase &mdb, const AttributeTranslator &at)
    : m_memberdatabase(&mdb), m_attributetranslator(&at)
{
}

vector<EmailCount> MatchMaker::IdentifyRankedMatches(string email, int threshold) const
{
    // Finds PersonProfile associated with Email
    const PersonProfile *ppf = m_memberdatabase->GetMemberByEmail(email);

    // Exit if input Email is not in MemberDatabase
    if (ppf == nullptr)
    {
        return vector<EmailCount>();
    }

    // Finds all compatible AttValPairs corresponding to each of PersonProfile's own
    // Set to ensure no duplicates
    set<AttValPair> desired_pairs;
    for (int i = 0; i < ppf->GetNumAttValPairs(); i++)
    {
        AttValPair av;
        ppf->GetAttVal(i, av);
        vector<AttValPair> compatible_pairs = m_attributetranslator->FindCompatibleAttValPairs(av);
        for (auto it = compatible_pairs.begin(); it != compatible_pairs.end(); it++)
        {
            desired_pairs.insert(*it);
        }
    }

    map<string, int> email_to_count;
    for (auto it = desired_pairs.begin(); it != desired_pairs.end(); it++)
    {
        vector<string> matching_emails = m_memberdatabase->FindMatchingMembers(*it);
        for (auto it1 = matching_emails.begin(); it1 != matching_emails.end(); it1++)
        {
            if (*it1 != ppf->GetEmail())
                email_to_count[*it1]++;
        }
    }

    vector<EmailCount> sorted_matches;
    for (auto it = email_to_count.begin(); it != email_to_count.end(); it++)
    {
        if (it->second >= threshold)
        {
            sorted_matches.push_back(EmailCount(it->first, it->second));
        }
    }
    sort(sorted_matches.begin(), sorted_matches.end(), sortbysecdesc);
    return sorted_matches;
}
