#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // Depth First Search (DFS) Function
    void dfs(int row, int col, vector<vector<int>> &vis, 
             vector<vector<char>> &mat, int delrow[], int delcol[]) {
        
        vis[row][col] = 1; // Mark current cell as visited
        int n = mat.size();
        int m = mat[0].size();

        // Check for top, right, bottom, left directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Boundary checks and condition for unvisited 'O'
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        
        // Direction vectors for moving Up, Right, Down, Left
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        // Visited matrix initialized with 0
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // 1. Traverse First Row and Last Row (Boundary O's)
        for (int j = 0; j < m; j++) {
            // First Row
            if (!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, vis, mat, delrow, delcol);
            }
            // Last Row
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, mat, delrow, delcol);
            }
        }

        // 2. Traverse First Column and Last Column (Boundary O's)
        for (int i = 0; i < n; i++) {
            // First Column
            if (!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat, delrow, delcol);
            }
            // Last Column
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, mat, delrow, delcol);
            }
        }

        // 3. Replace all remaining unvisited 'O's with 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};
