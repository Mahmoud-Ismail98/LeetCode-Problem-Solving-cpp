#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if s1 is a permutation of any substring of s2
    bool checkInclusion(string s1, string s2) {
        // If the length of s1 is greater than the length of s2, s1 cannot be a substring of s2
        if(s1.size() > s2.size()) {
            return false;
        }
        
        // Create frequency maps for characters in s1 and the current window in s2
        map<char, int> map_s1;
        map<char, int> map_s2;
        
        // Populate the frequency map for s1
        for(char c : s1) {
            map_s1[c]++;
        }        
        
        int right = 0, left = 0;
        // Iterate through s2 to find the window where s1 may be a permutation
        for(left = 0; left <= (s2.size() - s1.size()); left++) {
            // Expand the window to the right until it matches the size of s1
            while (right - left < s1.size()) {
                map_s2[s2[right++]]++; // Increment frequency of characters in the window
            }
            
            // If the frequency maps for s1 and the current window are equal, s1 is a permutation of the current window
            if (map_s1 == map_s2) {
                return true;
            }   
            else {
                // Update the frequency map for the next window by removing the leftmost character and updating its frequency
                if(map_s2[s2[left]] == 1)
                    map_s2.erase(s2[left]);
                else    
                    map_s2[s2[left]]--;
            }         
        }
        
        // If no permutation of s1 is found in s2, return false
        return false; 
    }
};

// Test the implementation
int main() {
    Solution sol;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << "Result: " << boolalpha << sol.checkInclusion(s1, s2) << endl;
    return 0;
}

/*another solution but more runtime and complexity*/
/* 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        {
            return false;
        }
        vector<char>sub_s1(s1.begin(),s1.end());
        sort(sub_s1.begin(),sub_s1.end());
        
        //for(char c:s1)
        //{
        //    sub_s1.push_back(c);
        //}
       
        vector<char>sub_s2;
        int right=0,left=0;
        char last_element;
        for(left=0;left<=(s2.size()-s1.size());left++)
        {
            while (right-left<s1.size())
            {
                sub_s2.push_back(s2[right++]); 
            }
            sort(sub_s2.begin(),sub_s2.end());
            if (sub_s1==sub_s2)
            {
                return true;
            }   
            else
            {
                auto it=find(sub_s2.begin(),sub_s2.end(),s2[left]);
                sub_s2.erase(it);
            }         
        }
        return false; 
    }
}; */

