class Solution {
public:
    vector<vector<int>> directions {{1, 1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        if(m == 0 || n == 0 || grid[0][0] != 0) {
            return -1;
        }

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int level = 0;

        while(!q.empty()) {

            int N = q.size();

            while(N--) {

                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                if(x == m-1 && y == n-1) {
                    return level + 1;
                }

                for(auto& dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_, y_) && grid[x_][y_] == 0) {
                        q.push({x_, y_});
                        grid[x_][y_] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};