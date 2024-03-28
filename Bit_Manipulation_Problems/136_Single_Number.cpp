#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = 0; // Initialize result variable to store the single number

    // Function to find the single number using XOR operation
    int singleNumber(vector<int>& nums) {
        for(auto it : nums) {
            result ^= it; // XOR operation to find the single number
        }
        return result; // Return the single number
    }
};

// Test case
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 2, 1};
    int result1 = sol.singleNumber(nums1);

    // Test case 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    int result2 = sol.singleNumber(nums2);

    // Output results
    cout << "Result 1: " << result1 << endl; // Output the result of test case 1
    cout << "Result 2: " << result2 << endl; // Output the result of test case 2

    return 0;
}
/*
// another solutions 
class Solution {
public:
    // Function to find the single number in the array
    int singleNumber(vector<int>& nums) {
        // Sort the input array
        sort(nums.begin(), nums.end());

        // Get the size of the array
        int n = nums.size();
        
        // Initialize the answer variable
        int ans = 0;

        // Iterate through the sorted array
        for(int i = 1; i < n; i += 2) {
            // Check if the current element is not equal to the previous element
            if(nums[i] != nums[i - 1]) {
                // If true, return the previous element
                return nums[i - 1];
            }
        }

        // If no single number found, return the last element
        return nums[n - 1];
    }
};*/