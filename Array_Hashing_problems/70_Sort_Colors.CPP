#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
class Solution {
public:
    void sortColors(vector<int>& nums) {    // 2 0 2 1 1 0
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }  
        
    }
    // another solution 
    void sortColors2(vector<int>&nums)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for (auto i : mp)
        {
            if(i.first==0)
            {
                for(int j=0;j<i.second;j++)
                {
                    nums[j]=0;
                }
            }
            else if(i.first==1)
            {
                for(int j=i.second;j<i.second+i.second;j++)
                {
                    nums[j]=1;
                }
            }
            else
            {
                for(int j=i.second+i.second;j<nums.size();j++)
                {
                    nums[j]=2;
                }
            }   
        }

        
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,0,2,1,1,0};
    solution.sortColors2(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}


/* analysis:
First Solution (sortColors function)
Time Complexity
The algorithm iterates through the array once with a while loop, performing constant-time operations (swaps and increments).
Overall time complexity: O(n), where n is the number of elements in nums.

Space Complexity
The algorithm uses a constant amount of extra space for the variables low, mid, and high.
Overall space complexity: O(1).

Second Solution (sortColors2 function)
Time Complexity
Building the frequency map (mp): O(n), where n is the number of elements in nums.
Iterating through the map and updating nums: O(n), since each element in the map is processed and placed back into nums.
Overall time complexity: O(n).

Space Complexity
Frequency map (mp): O(k), where k is the number of unique elements in nums (in this case, k is at most 3 since the elements are 0, 1, and 2).
No additional space used apart from the map.
Overall space complexity: O(k), which simplifies to O(1) since k is a small constant (3).

*/