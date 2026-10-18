class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        if (grid.empty() || grid[0].empty()) return 0;

        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        
            for(int i = 0; i < m; i++) {
                 for(int j = 0; j < n; j++) {
                      vis[i][j] = 0;
                  }
                }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
             if(i == 0 || j == 0 || i == m-1 || j == n-1){
                if(grid[i][j]){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,+1,0,-1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && ncol >=0 && nrow < m && ncol < n
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
        if(grid[i][j] == 1 && vis[i][j] == 0){
            cnt++;
        }
        }
    }
    return cnt;
    }
};
