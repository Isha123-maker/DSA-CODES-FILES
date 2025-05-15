#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Helper function to explore the maze
void helper(vector<vector<int>>& mat, int row, int col, string path, vector<string>& ans) {
    int n = mat.size();

    // Base cases: out of bounds or encountering a blocked/visited cell
    if (row < 0 || col < 0 || row >= n || col >= n || mat[row][col] != 1) {
        return;
    }

    // If the destination is reached, store the path and return
    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark the current cell as visited
    mat[row][col] = -1;

    // Explore all possible directions: Down, Up, Left, Right
    helper(mat, row + 1, col, path + "D", ans);
    helper(mat, row - 1, col, path + "U", ans);
    helper(mat, row, col - 1, path + "L", ans);
    helper(mat, row, col + 1, path + "R", ans);

    // Unmark the current cell (backtrack)
    mat[row][col] = 1;
}

// Function to find all paths in the maze
vector<string> findPath(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<string> ans;

    // Check if the maze is empty or if start/end cells are blocked
    if (n == 0 || mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
        return ans;
    }

    // Call the helper function starting from (0, 0)
    string path = "";
    helper(mat, 0, 0, path, ans);

    return ans;
}

int main() {
    // Input maze
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    // Find all paths
    vector<string> ans = findPath(mat);

    // Print all paths
    if (ans.empty()) {
        cout << "No paths found." << endl;
    } else {
        for (const string& path : ans) {
            cout << path << endl;
        }
    }

    return 0;
}
