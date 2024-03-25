#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& pricees) {
        int max_profit = 0;
        int min_buy =  0; 
        int max_sell=0;
        min_buy = pricees[0];
        for (int i = 1; i < pricees.size() ; i++) {

            max_sell= pricees[i];  
            if(max_sell<min_buy)
            {
                min_buy=max_sell;
            } 
            if((max_sell-min_buy)>max_profit)
            {
                max_profit=max_sell-min_buy;
            }            
        }
        return max_profit;
    }
};

int main() {
    //std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::vector<int> prices = {3,1, 4};
    Solution sol;
    int maxProfit = sol.maxProfit(prices);
    std::cout << "Max Profit: " << maxProfit << std::endl;
    return 0;
}
