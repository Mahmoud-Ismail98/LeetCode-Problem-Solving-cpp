#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; // Create a stack to store operands
        int operend1, operend2, result; // Variables to store operands and result
        for (auto &it : tokens) { // Iterate over each token in the input vector
            if ((it != "-") && (it != "/") && (it != "*") && (it != "+")) { // Check if the token is an operand
                st.push(stoi(it)); // Push the operand onto the stack after converting it to an integer
            } else { // If the token is an operator
                // Pop the top two operands from the stack
                operend1 = st.top();
                st.pop();
                operend2 = st.top();
                st.pop();
                // Perform the operation based on the operator
                if (it == "+") {
                    result = operend1 + operend2;
                } else if (it == "/") {
                    result = operend2 / operend1;
                } else if (it == "-") {
                    result = operend2 - operend1;
                } else if (it == "*") {
                    result = operend2 * operend1;
                }
                // Push the result back onto the stack
                st.push(result);
            }
        }
        // Return the top element of the stack, which is the final result
        return st.top();
    }
};

int main() {
    // Test cases
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    Solution solution1;
    cout << "Example 1 Output: " << solution1.evalRPN(tokens1) << endl;

    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    Solution solution2;
    cout << "Example 2 Output: " << solution2.evalRPN(tokens2) << endl;

    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution solution3;
    cout << "Example 3 Output: " << solution3.evalRPN(tokens3) << endl;

    return 0;
}


/* convert a string to an integer without using stoi
int strToInt(const string& s) {
    int result = 0;
    bool negative = false;
    int i = 0;

    // Check if the number is negative
    if (s[0] == '-') {
        negative = true;
        i++;
    }

    // Iterate over the characters of the string
    while (i < s.size()) {
        result = result * 10 + (s[i] - '0'); // Convert character to integer
        i++;
    }

    // If the number is negative, make it negative
    if (negative) {
        result = -result;
    }

    return result;
}


*/