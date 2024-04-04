#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Vector to store the result
        vector<int> result(temperatures.size(), 0);
        // Stack to store the indices of temperatures
        stack<int> st;
        
        // Loop through each temperature
        for (int i = 0; i < temperatures.size(); ++i) {
            // Check if the current temperature is warmer than temperatures at indices stored in the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                // If warmer, update the result for the corresponding index in the result vector
                int prevIndex = st.top(); // Index of the previous temperature
                st.pop(); // Remove the previous temperature index from the stack
                result[prevIndex] = i - prevIndex; // Update the result for the previous index
            }
            // Push the current index to the stack
            st.push(i);
        }
        // Return the result vector
        return result;
    }
};

int main() {
    // Test case 1
    vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution solution1;
    vector<int> result1 = solution1.dailyTemperatures(temperatures1);
    cout << "Test case 1 Output: ";
    for (auto &it : result1) {
        cout << it << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> temperatures2 = {30, 40, 50, 60};
    Solution solution2;
    vector<int> result2 = solution2.dailyTemperatures(temperatures2);
    cout << "Test case 2 Output: ";
    for (auto &it : result2) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
