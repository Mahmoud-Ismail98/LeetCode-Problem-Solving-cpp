#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &it:nums)
        {
           
            if(st.find(it)!=st.end())  //or if(st.count(it)!=0)  // Found a duplicate
            {
                return true; 
            }
            st.insert(it); // Insert the number into the set
        }
        return false; // No duplicates found
    }
};
/* another slolution but that solution Exceeded Time Limit 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int>vec;
        for(auto &it:nums)
        {
            auto local_it=find(vec.begin(),vec.end(),it);
            if(local_it!=vec.end())
            {
                return true;
            }
            vec.push_back(it);
        }
        return false;
    }
};
*/
int main() {
    // Test cases
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    Solution solution;
    bool result1 = solution.containsDuplicate(nums1);
    cout <<"reult1 "<<result1<<endl;
    bool result2 = solution.containsDuplicate(nums2);
    cout <<"reult2 "<<result2<<endl;
    bool result3 = solution.containsDuplicate(nums3);
    cout <<"reult3 "<<result3<<endl;

    return 0;
}
