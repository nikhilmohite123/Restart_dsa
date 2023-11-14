#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int maze[][4], int &n, vector<vector<int>> &ans, int row, int col) {
    if (row < 0 || row >= n)
        return false;
    if (col < 0 || col >= n)
        return false;
    
    if (ans[row][col] == 1)
        return false;
    if (maze[row][col] == 0)
        return false;
    

    return true;
}

void printvisited(vector<vector<int>> &ans, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
       
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void path(int maze[][4], int &n, vector<vector<int>> &ans, int row, int col) {
    if (row == n - 1 && col == n - 1) {
        
        printvisited(ans, n);
        cout<<endl;
        return;
    }

    // d
    if (isSafe(maze, n, ans, row + 1, col)) {
        ans[row + 1][col] = 1;
        path(maze, n, ans, row + 1, col);
        ans[row + 1][col] = 0;
    }
    // l
    if (isSafe(maze, n, ans, row, col - 1)) {
        ans[row][col - 1] = 1;
        path(maze, n, ans, row, col - 1);
        ans[row][col - 1] = 0;
    }

    // r
    if (isSafe(maze, n, ans, row, col + 1)) {
        ans[row][col + 1] = 1;
        path(maze, n, ans, row, col + 1);
        ans[row][col + 1] = 0;
    }

    // U
    if (isSafe(maze, n, ans, row - 1, col)) {
        ans[row - 1][col] = 1;
        path(maze, n, ans, row - 1, col);
        ans[row - 1][col] = 0;
    }
}

int main() {
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    int n = 4;

    vector<vector<int>> ans(n, vector<int>(n, 0)); // Initialize ans with size n x n and all values set to 0
    ans[0][0] = 1;

    path(maze, n, ans, 0, 0);

    return 0;
}
