#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freqMap; 
        priority_queue<pair<int,int>>max_heap;
        vector<int>output;
        for(int i=0;i<nums.size();i++)  // 1->3  2->2  3->1
        {
            freqMap[nums[i]]++;
        }
        for(auto pair:freqMap)
        {
           max_heap.push({pair.second,pair.first}); 
        }
        for(int i=0;i<k;i++)
        {
            output.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return output;
    }
};

int main() {
    // Test cases
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution solution;
    vector<int> result = solution.topKFrequent(nums, k);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}

/* analysis:
Time Complexity
Building the frequency map (freqMap): O(n), where n is the number of elements in nums.
Building the max heap (max_heap): O(n log n), since inserting into a heap takes O(log n) time and we do this for each element in freqMap.
Extracting the top k elements: O(k log n), since each extraction involves removing from the heap which takes O(log n) time.
Overall time complexity: O(n log n).

Space Complexity
Frequency map (freqMap): O(n), where n is the number of unique elements in nums.
Max heap (max_heap): O(n), where n is the number of unique elements in nums.
Output vector (output): O(k), where k is the number of top frequent elements.
Overall space complexity: O(n).

*/