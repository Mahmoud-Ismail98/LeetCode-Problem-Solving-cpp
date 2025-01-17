#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int>row[9],col[9],box[9];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(row[i][board[i][j]]++>0)
                    {
                        return false;
                    }
                    if(col[j][board[i][j]]++>0)
                    {
                        return false;
                    }
                    if(box[(i/3)*3+j/3][board[i][j]]++>0) // box number = (i/3)*3+j/3  and i=0,1,2,3,4,5,6,7,8 and j=0,1,2,3,4,5,6,7,8 
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    bool result = solution.isValidSudoku(board);
    cout << result << endl;
    return 0;
}

/* analysis:
Time Complexity
Iterating through the board: O(1), since the board size is fixed at 9x9.
Checking and updating the maps: O(1) for each cell, since the operations on the unordered_map are O(1).
Overall time complexity: O(1).

Space Complexity
Row maps (row): O(9 * 9) = O(81), since there are 9 rows and each can have up to 9 entries.
Column maps (col): O(9 * 9) = O(81), since there are 9 columns and each can have up to 9 entries.
Box maps (box): O(9 * 9) = O(81), since there are 9 boxes and each can have up to 9 entries.
Overall space complexity: O(1), since the space used is constant and does not depend on the input size.

*/