#include <vector>
#include <unordered_set>
using namespace std;
#include <bits/stdc++.h>

#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end()); //erase dublication
        int local_count = 1; // Start with 1 because at least one element is consecutive
        int max_count = 1;   // Initialize max_count to 1
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                local_count++; // Increment local_count if the current element is consecutive
            } else {
                // If the current element is not consecutive and not equal to the previous one,
                // reset local_count to 1
                max_count = std::max(max_count, local_count); // Update max_count if needed
                local_count = 1; // Reset local_count to 1
            }
        }
        
        return std::max(max_count, local_count); // Return the maximum of max_count and local_count
    }
};


int main() {
    Solution solution;
    
    // Test cases
    std::vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    std::vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 2, 1};
    // Expected output: 4
    int result1 = solution.longestConsecutive(nums1);
    cout<<"result1 "<<result1<<endl;
    // Expected output: 9
    int result2  = solution.longestConsecutive(nums2);
    cout<<"result2 "<<result2<<endl;
    
    return 0;
}
