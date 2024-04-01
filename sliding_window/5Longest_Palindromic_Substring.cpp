#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    // Function to expand from the middle and find the length of the palindrome
    int expand_from_middle(string s, int left, int right) {
        int local_max = 0;
        // Expand from the middle while the characters match and the indices are within bounds
        while (left >= 0 && right < s.size()) {
            if (s[left] == s[right]) {
                local_max = right - left + 1; // Update local_max to reflect the length of the palindrome
                left--; // Move left pointer to the left
                right++; // Move right pointer to the right
            } else {
                break; // Exit the loop if characters don't match
            }
        }
        return local_max; // Return the length of the palindrome found
    }

public:
    // Function to find the longest palindrome substring
    string longestPalindrome(string s) {
        int max_length = 0; // Initialize the maximum palindrome length
        int start = 0; // Initialize the starting index of the longest palindrome
        // Iterate through each character in the string
        for (int i = 0; i < s.size(); ++i) {
            // Find the length of the palindrome with current character as the middle (for odd-length palindromes)
            int len1 = expand_from_middle(s, i, i);
            // Find the length of the palindrome with current character and the next character as middle (for even-length palindromes)
            int len2 = expand_from_middle(s, i, i + 1);
            // Get the maximum length of the palindromes found
            int len = max(len1, len2);
            // Update the maximum length and starting index if a longer palindrome is found
            if (len > max_length) {
                max_length = len;
                start = i - (len - 1) / 2; // Update start index based on the length of the palindrome
            }
        }
        // Return the longest palindrome substring
        return s.substr(start, max_length);
    }
};

int main() {
    std::string s = "babad"; // Input string
    Solution solution; // Create an instance of the Solution class
    string result = solution.longestPalindrome(s); // Call the longestPalindrome function
    std::cout << "Input: " << s << std::endl; // Print the input string
    std::cout << "Output: " << result << std::endl;  // Print the output (longest palindrome substring) 
    return 0; // Return 0 to indicate successful termination
}
