#include <bits/stdc++.h> // Include necessary headers
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp; // Create a map to store characters and their last seen indices
        int mx = 0; // Initialize the maximum length of substring without repeating characters
        int l = 0, r = 0; // Initialize pointers for the current substring

        for(int i = 0; i < s.size(); i++) { // Loop through the string
            if(mp[s[i]] != 0) { // Check if the current character has been seen before
                while(mp[s[i]] != 0) { // Loop until the current character is not repeated
                    mp[s[l]] = 0; // Reset the count for characters in the substring
                    l++; // Move the left pointer to the right
                }
            }

            mp[s[i]]++; // Update the count of the current character in the map
            r++; // Move the right pointer to the right
            mx = max(mx, (r - l)); // Update the maximum length of the substring
        }
            for (const auto& pair : mp) {
                std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
            }        
        return mx; // Return the maximum length of substring without repeating characters
    }
};

int main() {
    std::string s = "abcabcbb"; // Input string
    Solution solution; // Create an instance of the Solution class
    int result = solution.lengthOfLongestSubstring(s); // Call the lengthOfLongestSubstring function
    std::cout << "Input: " << s << std::endl; // Print the input string
    std::cout << "Output: " << result << std::endl;  // Print the output (maximum length of substring) 
    return 0; // Return 0 to indicate successful termination
}
