class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
         vector<int> front(n, 0);
         vector<int> cur(n, 0);

        // Initialize the last row of dp with triangle values
        for (int j = 0; j < n; j++) {
           front[j] = triangle[n - 1][j];
        }

        // Traverse from second-last row to the top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                // Calculate sum from down and diagonal paths
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j + 1];

                // Store the minimum of the two paths
                cur[j] = min(down, diag);
            }
            front = cur;
        }

        // Return the minimum path sum from top
        return front[0];
    }
};