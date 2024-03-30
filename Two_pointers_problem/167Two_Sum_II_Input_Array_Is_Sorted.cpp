#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

      unordered_map<int,int>mp;
      int complement;
      vector<int>vec;
      for(int i=0;i<numbers.size();i++)
      {
      complement=target-numbers[i];  
      /*
      Returns:
      Iterator pointing to sought-after element, or end() if not found. This function takes a key and tries to locate the element 
      with which the key matches. If successful the function returns an iterator pointing to the sought after element. If unsuccessful it returns the past-the-end ( end() ) iterator.
      */
      auto it=mp.find(complement); 
      if(it!=mp.end())
      {

        vec.push_back(mp[complement]+1);
        vec.push_back(i+1);
        return vec;
      } 
      else 
      {
        mp.insert(make_pair(numbers[i],i));
      }   
    }
        return vec;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Create a hash map to store the numbers and their indices
        unordered_map<int,int> mp;
        // Declare variables to store complement and result vector
        int complement;
        vector<int> vec;
        
        // Iterate through the numbers array
        for(int i = 0; i < numbers.size(); i++) {
            // Calculate the complement for the current number
            complement = target - numbers[i]; 
            
            // Find if the complement exists in the map
            auto it = mp.find(complement); 
       /*
      Returns:
      Iterator pointing to sought-after element, or end() if not found. This function takes a key and tries to locate the element 
      with which the key matches. If successful the function returns an iterator pointing to the sought after element. If unsuccessful it returns the past-the-end ( end() ) iterator.
      */           
            // If the complement exists, return the indices
            if(it != mp.end()) {
                // Push the indices of the complement and current number into the result vector
                vec.push_back(mp[complement] + 1); // Indices are 1-indexed
                vec.push_back(i + 1); // Indices are 1-indexed
                return vec;
            } 
            // If the complement does not exist, insert the current number into the map
            else {
                mp.insert(make_pair(numbers[i], i)); // Store the number and its index in the map
            }   
        }
        // If no pair is found, return an empty vector
        return vec;
    }
};

int main() {
    Solution sol; // Create an instance of the Solution class

    // Test case
    vector<int> numbers = {1, 7,2, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(numbers, target); // Calculate the indices of the two numbers

    // Output the test case information and result
    cout << "Input: numbers = [";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i < numbers.size() - 1) {
            cout << ", ";
        }
    }
    cout << "], target = " << target << endl;
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}

/* another solution is
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0; // Pointer for the leftmost element
        int right = numbers.size() - 1; // Pointer for the rightmost element

        // Loop until left pointer is less than right pointer
        while (left < right) {
            int sum = numbers[left] + numbers[right]; // Calculate sum of current pair
            // If the sum is equal to the target, return the indices
            if (sum == target) {
                return {left + 1, right + 1}; // Return indices (1-indexed)
            } else if (sum < target) {
                left++; // Move left pointer to the right
            } else {
                right--; // Move right pointer to the left
            }
        }
        return {}; // Return an empty vector if no solution is found
    }
};*/
