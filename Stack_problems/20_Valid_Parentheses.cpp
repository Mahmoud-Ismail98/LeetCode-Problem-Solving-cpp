#include <bits/stdc++.h> // Include necessary header files

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if ((s.size() % 2) != 0) { // Check if the length of the string is odd
            return false; // Return false if the length is odd
        }
        stack<char> st; // Create a stack to store opening brackets
        for (auto c : s) { // Iterate through each character in the string
            if ((c == '(') || (c == '[') || (c == '{')) { // If the character is an opening bracket
                st.push(c); // Push it onto the stack
            } else { // If the character is a closing bracket
                if (st.empty() || // If the stack is empty or
                    (c == ')' && st.top() != '(') || // If the closing bracket doesn't match the top of the stack
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false; // Return false
                }
                st.pop(); // Pop the matching opening bracket from the stack
            }
        }
        return st.empty(); // Return true if the stack is empty (all brackets are matched)
    }
};

int main() {
    // Test cases
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";

    // Create an instance of the Solution class
    Solution solution;

    // Test case 1
    cout << "Test case 1: ";
    if (solution.isValid(s1))
        cout << "Output: true\n";
    else
        cout << "Output: false\n";

    // Test case 2
    cout << "Test case 2: ";
    if (solution.isValid(s2))
        cout << "Output: true\n";
    else
        cout << "Output: false\n";

    // Test case 3
    cout << "Test case 3: ";
    if (solution.isValid(s3))
        cout << "Output: true\n";
    else
        cout << "Output: false\n";

    return 0;
}


/* another solution 
class Solution {
public:
    bool isValid(string s) {
        if ((s.size() % 2) != 0) {
            return false;
        }
        stack<char> st1;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
                st1.push(s[i]);
            } else {
                // Check if stack is empty before accessing top element
                if (st1.empty()) {
                    return false;
                }
                char temp = st1.top();
                st1.pop(); // Remove the top element from the stack
                switch (temp) {
                    case '(':
                        if (s[i] != ')') {
                            return false;
                        }
                        break;
                    case '[':
                        if (s[i] != ']') {
                            return false;
                        }
                        break;
                    case '{':
                        if (s[i] != '}') {
                            return false;
                        }
                        break;
                }
            }
        }
        // Check if stack is empty after processing all characters
        return st1.empty();
    }
};

*/