class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        if (grid.empty() || grid[0].empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n-1 || j == m-1)
                {
                     if (grid[i][j] == 1)
                     {
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                     
                }
                
            }
            
        }

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        while (!q.empty())
        {
            auto [row,col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                   vis[nrow][ncol] = 1;
                   q.push({nrow,ncol});
                }
                
            }
        }


         int cnt = 0;
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < m; j++)
           {
             if (vis[i][j] == 0 && grid[i][j] == 1)
             {
                cnt++;
             }
             
           }
           
        }
        
       return cnt; 
    }
};
