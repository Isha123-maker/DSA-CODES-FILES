#include <iostream>
#include <vector>

using namespace std;

// Function to check if the current move is valid
bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
    // Boundary checks and checking if the current cell matches the expected value
    if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) {
        return false;
    }

    // Base case: if we have reached the last expected value
    if (expVal == n * n - 1) {
        return true;
    }

    // Recursive calls for all possible knight's moves
    if (isValid(grid, r - 2, c + 1, n, expVal + 1)) return true;
    if (isValid(grid, r - 1, c + 2, n, expVal + 1)) return true;
    if (isValid(grid, r + 1, c + 2, n, expVal + 1)) return true;
    if (isValid(grid, r + 2, c + 1, n, expVal + 1)) return true;
    if (isValid(grid, r + 2, c - 1, n, expVal + 1)) return true;
    if (isValid(grid, r + 1, c - 2, n, expVal + 1)) return true;
    if (isValid(grid, r - 1, c - 2, n, expVal + 1)) return true;
    if (isValid(grid, r - 2, c - 1, n, expVal + 1)) return true;

    return false;
}

int main() {
    
    //Grid when path dosen't exist
    vector<vector<int>> grid = {
        {0, 1, 2, 3, 4},
        {19, 18, 17, 16, 5},
        {20, 25, 24, 15, 6},
        {21, 22, 23, 14, 7},
        {22, 23, 24, 13, 8}
    };
    //Grid when path exist
    // vector<vector<int>> grid = {
    //   {0, 17, 4, 19, 2},
    //   {5, 24, 1, 16, 3},
    //   {18, 7, 22, 9, 20},
    //   {23, 6, 15, 8, 13},
    //   {10, 21, 12, 14, 11}
    // };


    // Start from the top-left corner with the first expected value (0)
    bool ans = isValid(grid, 0, 0, grid.size(), 0);
    cout << (ans ? "Path exists" : "Path doesn't exist") << endl;

    return 0;
}
