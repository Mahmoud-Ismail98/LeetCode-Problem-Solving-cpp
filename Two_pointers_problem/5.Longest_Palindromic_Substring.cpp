#include <bits/stdc++.h>
using namespace std;


class Solution {
private: 
     pair<int,int> expand_from_middle(string str,int left, int right)
    {
        pair<int,int>p1;
        while(str[left]==str[right]&&left>=0&&right<str.size())
        {
            left--;
            right++;
        }
        p1=make_pair((right-left-1),left+1);
        return p1;
    }       
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;

        pair<int,int>max_len_even;
        pair<int,int>max_len_odd;
        int max_length=0;
       int start;
        for(int i=0; i<n; i++){
        //auto [len1, start1] = expand_from_middle(s, i, i);
        //auto [len2, start2] = expand_from_middle(s, i, i + 1);    
        max_len_even=expand_from_middle(s,i,i+1) ;    
        max_len_odd =expand_from_middle(s,i,i) ;    
        if(max_len_odd.first>max_length)
        {
           max_length=max_len_odd.first;
           start=max_len_odd.second; 

        }
        if(max_len_even.first>max_length)
        {
           max_length=max_len_even.first;
           start=max_len_even.second; 

        }
    }
    return s.substr(start, max_length);
    }
}; 

int main() {
  // std::string s = "bcabacd"; // Input string
    std::string s = "cbbd"; // Input string
    Solution solution; // Create an instance of the Solution class
    string result = solution.longestPalindrome(s); // Call the lengthOfLongestSubstring function
    std::cout << "Input: " << s << std::endl; // Print the input string
    std::cout << "Output: " << result << std::endl;  // Print the output (maximum length of substring) 
    return 0; // Return 0 to indicate successful termination
}
