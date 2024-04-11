
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        // Iterate through each bar in the histogram
        for (int i = 0; i <= n; ++i) {
            // Calculate the height of the current bar (0 for the last one)
            int h = (i == n) ? 0 : heights[i];
            
            // If the current bar's height is smaller than the previous one(s), calculate the area
            while (!st.empty() && h < heights[st.top()]) {
                // Get the height of the top bar in the stack
                int height = heights[st.top()];
                st.pop();
                
                // Calculate the width of the rectangle using the index of the previous smaller bar
                int width = st.empty() ? i : i - st.top() - 1;
                
                // Update the maximum area
                maxArea = max(maxArea, height * width);
            }
            
            // Push the index of the current bar into the stack
            st.push(i);
        }
        
        return maxArea;
    }
};
/*another solution
// Function to expand from the middle of the histogram and calculate the area of the largest rectangle
int expand_from_middle(int middle, vector<int>& heights) {
    // Initialize variables to keep track of the right and left indices, count of bars, and end flags
    int right = middle + 1;
    int left = middle - 1;
    int count = 1;
    int end_left = 1;
    int end_right = 1;
    
    // Continue expanding from the middle while there are still bars to the left or right
    while (end_right || end_left) {
        // Expand to the left if possible and increment the count if the left bar is taller or equal
        if (left >= 0 && (heights[left] >= heights[middle])) {
            count++;
            left--;
        } else {
            // Set end_left flag to 0 if no more bars to the left or the left bar is shorter
            end_left = 0;
        }
        
        // Expand to the right if possible and increment the count if the right bar is taller or equal
        if (right < heights.size() && (heights[right] >= heights[middle])) {
            count++;
            right++;
        } else {
            // Set end_right flag to 0 if no more bars to the right or the right bar is shorter
            end_right = 0;
        }
    }
    
    // Return the area of the largest rectangle formed around the middle bar
    return (count * heights[middle]);
}

class Solution {
public:
    // Function to find the largest rectangle area in the histogram
    int largestRectangleArea(vector<int>& heights) {
        // Initialize variables to store the final result and the result for the current iteration
        int result = 0;
        int local_result = 0;
        
        // Iterate through each bar in the histogram
        for (int i = 0; i < heights.size(); i++) {
            // Calculate the area of the largest rectangle for the current bar
            local_result = expand_from_middle(i, heights); 
            
            // Update the final result if the current result is larger
            if (local_result > result) {
                result = local_result;
            }
        }
        
        // Return the final result
        return result;
    }
};
*/
int main() {
    // Test cases
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    vector<int> heights2 = {0, 9};

    Solution solution;

    cout << "Test Case 1: " << solution.largestRectangleArea(heights1) << endl;
    cout << "Test Case 2: " << solution.largestRectangleArea(heights2) << endl;

    return 0;
}
