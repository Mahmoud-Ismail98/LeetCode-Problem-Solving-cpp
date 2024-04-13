#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        // Count the frequency of each character in s
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        // Decrease the frequency of each character in t
        for (char ch : t) {
            if (--freq[ch] < 0) {
                return false; // If the frequency becomes negative, it means t contains a character not present in s
            }
        }

        return true;
    }
};

int main() {
    // Test cases
    string s1 = "anagram";
    string t1 = "nagaram";

    string s2 = "rat";
    string t2 = "car";

    Solution solution;
    bool result1 = solution.isAnagram(s1, t1);
    cout << "Result 1: " << (result1 ? "true" : "false") << endl;

    bool result2 = solution.isAnagram(s2, t2);
    cout << "Result 2: " << (result2 ? "true" : "false") << endl;

    return 0;
}
