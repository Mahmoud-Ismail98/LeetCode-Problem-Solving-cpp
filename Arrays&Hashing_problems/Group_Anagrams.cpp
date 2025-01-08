#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm> // for sorting
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for (int i = 0; i < strs.size(); i++)
        {
            string sorted_string =strs[i];
            sort(sorted_string.begin(),sorted_string.end());
            mp[sorted_string].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto &pair:mp)
        {
            result.push_back(pair.second);
        }
        
        return result;
    }
};     
// Utility function to check if two 2D vectors contain the same elements
bool compare2DVector(vector<vector<string>>& a, vector<vector<string>>& b) {
    for (auto& vec : a) {
        sort(vec.begin(), vec.end());  // Sort each group
    }
    for (auto& vec : b) {
        sort(vec.begin(), vec.end());  // Sort each group
    }
    sort(a.begin(), a.end());  // Sort the list of groups
    sort(b.begin(), b.end());  // Sort the list of groups

    return a == b;
}

void runTests() {
    Solution solution;

    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    solution.groupAnagrams(strs1);
    vector<vector<string>> expected1 = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
    assert(compare2DVector(solution.groupAnagrams(strs1), expected1));
    
    // // Test case 2
    // vector<string> strs2 = {""};
    // vector<vector<string>> expected2 = {{""}};
    // assert(compare2DVector(solution.groupAnagrams(strs2), expected2));

    // // Test case 3
    // vector<string> strs3 = {"a"};
    // vector<vector<string>> expected3 = {{"a"}};
    // assert(compare2DVector(solution.groupAnagrams(strs3), expected3));

    // cout << "All test cases passed!" << endl;
}

int main() {
    runTests();
    return 0;
}
