#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; // Vector to store triplets summing up to zero
        sort(nums.begin(), nums.end()); // Sort the input array
        int n = nums.size(); // Length of the input array

        for (int i = 0; i < n - 2; ++i) { // Iterate through the array until the third last element
            if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicates
                continue;

            int left = i + 1; // Left pointer
            int right = n - 1; // Right pointer

            while (left < right) { // Continue until the pointers meet
                int sum = nums[i] + nums[left] + nums[right]; // Calculate the sum of the current triplet
                if (sum == 0) { // If the sum is zero, it's a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]}); // Add the triplet to the result vector
                    while (left < right && nums[left] == nums[left + 1]) // Skip duplicates
                        left++;
                    while (left < right && nums[right] == nums[right - 1]) // Skip duplicates
                        right--;
                    left++; // Move the left pointer to the right
                    right--; // Move the right pointer to the left
                } else if (sum < 0) { // If the sum is less than zero, move the left pointer to the right
                    left++;
                } else { // If the sum is greater than zero, move the right pointer to the left
                    right--;
                }
            }
        }

        return result; // Return the vector containing all valid triplets
    }
};

int main() {
    vector<int> vec{-1, 0, 1, 2, -1, -4}; // Example input array
    Solution solution; // Create an instance of the Solution class
    vector<vector<int>> vec2D = solution.threeSum(vec); // Find all triplets summing up to zero
    for (const auto& row : vec2D) { // Loop through each triplet in the result vector
        for (int num : row) { // Loop through each element in the triplet
            cout << num << " "; // Print the element
        }
        cout << endl; // Move to the next line for the next triplet
    }
    return 0; // Exit the program
}
