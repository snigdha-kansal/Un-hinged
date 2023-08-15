//
//  AttributeTranslator.hpp
//  CS32_4
//
//  Created by Snigdha Kansal on 3/8/22.
//

#ifndef AttributeTranslator_h
#define AttributeTranslator_h
#include "provided.h"
#include "RadixTree.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class AttributeTranslator
{
public:
    AttributeTranslator(){};
    ~AttributeTranslator(){};
    bool Load(string filename);
    vector<AttValPair> FindCompatibleAttValPairs(const AttValPair &source) const;

private:
    // Maps attval strings to a vector of their compatible AttValPairs
    RadixTree<vector<AttValPair>> m_radixtree;
};

#endif /* AttributeTranslator_h */
