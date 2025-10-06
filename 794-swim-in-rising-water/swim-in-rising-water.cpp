class Solution {
public:
    bool dfs(int n, int r, int c, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int mid) {
        if(r<0 || r>=n || c<0 || c>=n || vis[r][c] || grid[r][c]>mid) 
            return false;
        if (r == n - 1 && c == n - 1)
            return true;

        if (grid[r][c] <= mid) {
            vis[r][c] = 1;
        }
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] <= mid) {

                if (dfs(n, nrow, ncol, grid, vis, mid))
                    return true;
            }
        }
        return false;
    }
    int binarySearch(int n, int low, int high, vector<vector<int>>& grid) {
        while (low <= high) {

            int mid = (low + high) / 2;
            vector<vector<int>> vis(n, vector<int>(n, 0));
            if (dfs(n, 0, 0, grid, vis, mid) == true) {

                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = grid[0][0];
        int high = grid[0][0];
        for (auto& row : grid) {
            low = min(low, *min_element(row.begin(), row.end()));
            high = max(high, *max_element(row.begin(), row.end()));
        }

        int ans = binarySearch(n, low, high, grid);
        return ans;
    }
};