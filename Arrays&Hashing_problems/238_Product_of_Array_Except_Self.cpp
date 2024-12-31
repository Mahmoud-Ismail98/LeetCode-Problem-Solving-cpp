#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int total_sum = 1;
//         vector<int> result(nums.size(), 0);
//         int zero_flag = -1;
//         int zero_count = 0;       
//         // First pass to calculate total product and count zeros
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] == 0) {
//                 zero_flag = i;
//                 zero_count++;
//                 if (zero_count > 1) break; // If more than one zero, no need to continue
//                 continue;
//             }
//             total_sum *= nums[i];
//         }
        
//         if (zero_count > 1) return result; // If more than one zero, return all zeros
        
//         // Second pass to calculate product except itself
//         for (int i = 0; i < nums.size(); ++i) {
//             if (zero_count == 1) {
//                 if (i == zero_flag) result[i] = total_sum; // If one zero, set the product except itself
//             } else {
//                 result[i] = total_sum / nums[i]; // Calculate product except itself
//             }
//         }
        
//         return result;
//     }
// };
// another solution
class Solution{
    public:
    vector<int> productExceptSelf(vector<int>&nums){
        vector<int>result(nums.size(),1);
        int prefix=1;
        for (int i = 0; i <nums.size() ; i++)
        {   
            result[i]=prefix;
            prefix*=nums[i];
        }
        int postfix=1;
        for (int i = nums.size()-1; i >0 ; i--)
        {
            result[i]*=postfix;
            postfix*=nums[i];
        }
        
     return result;   
    }
};
int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 4},    // Output: [24,12,8,6]
        {-1, 1, 0, -3, 3} // Output: [0,0,9,0,0]
    };
    
    Solution solution;
    for (auto& nums : testCases) {
        vector<int> result = solution.productExceptSelf(nums);
        cout << "Output: [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
