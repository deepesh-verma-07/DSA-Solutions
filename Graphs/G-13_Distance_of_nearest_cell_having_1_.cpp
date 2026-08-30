#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Function to find distance of nearest 1 in the grid for each cell
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        
        // Queue stores: {{row, col}, steps}
        queue<pair<pair<int, int>, int>> q;
        
        // Step 1: Initialize visited matrix and push all cells with value 1 into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        
        // Delta arrays for 4-directional movement (Up, Right, Down, Left)
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        
        // Step 2: Multi-source BFS traversal
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            dist[row][col] = steps;
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                // Check for valid matrix boundaries and unvisited cells
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }
        
        return dist;
    }
};
