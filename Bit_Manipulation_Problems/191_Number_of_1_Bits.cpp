#include <iostream>
using namespace std;

class Solution {
public:
    // Function to calculate the number of set bits in the binary representation of a positive integer
    int hammingWeight(int n) {
        int result = 0; // Initialize the result counter
        int i = 0; // Initialize the bit position counter
        // Iterate over each bit of the integer
        while (i < (sizeof(int) * 8)) {
            // Add 1 to the result if the current bit is set (equal to 1)
            result += (n >> i) & 1;
            i++; // Move to the next bit position
        }
        return result; // Return the total count of set bits
    }
};

int main() {
    Solution sol; // Create an instance of the Solution class

    // Test case 1
    int n1 = 11;
    int result1 = sol.hammingWeight(n1); // Calculate the number of set bits for input n1
    // Output the test case information and result
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 3" << endl;
    cout << endl;

    // Test case 2
    int n2 = 128;
    int result2 = sol.hammingWeight(n2); // Calculate the number of set bits for input n2
    // Output the test case information and result
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 1" << endl;

    return 0;
}
