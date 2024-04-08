#include <vector>
#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars; // Vector to store pairs of position and time
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], ((target - position[i]) / (float)speed[i])}); // Calculate time and add to vector
        }
        sort(cars.begin(), cars.end(), greater<pair<int, float>>()); // Sort cars based on their positions in descending order

        int fleet_count = 0; // Counter for the number of car fleets
        float prev_time = -1; // Variable to store the previous car's time
        for (const auto& car : cars) { // Loop through the cars
            if (car.second > prev_time) { // If the current car's time is greater than the previous car's time
                fleet_count++; // Increment fleet count
                prev_time = car.second; // Update previous time
            }
        }
        return fleet_count; // Return the total number of car fleets
    }
};

int main() {
    // Test case 1
    int target1 = 12;
    vector<int> position1 = {10, 8, 0, 5, 3};
    vector<int> speed1 = {2, 4, 1, 1, 3};
    Solution solution1;
    int result1 = solution1.carFleet(target1, position1, speed1);
    cout<<result1<<endl;
    // Test case 2
    int target2 = 20;
    vector<int> position2 = {10, 8, 5, 15, 18};
    vector<int> speed2 = {2, 3, 1, 4, 2};
    Solution solution2;
    int result2 = solution2.carFleet(target2, position2, speed2);
    cout<<result2<<endl;

    return 0;
}
