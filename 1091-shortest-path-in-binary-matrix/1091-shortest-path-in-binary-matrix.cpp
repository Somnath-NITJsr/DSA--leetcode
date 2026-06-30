class Solution {
public:
    vector<vector<int>> directions {{1, 1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

    typedef pair<int, pair<int, int> > P;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 0 || n == 0 || grid[0][0] != 0) {
            return -1;
        }

        auto isSafe = [&](int x, int y) {
            return x >=0 && x < m && y >=0 && y < n;
        };


        /*
        // using BFS
        
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
        */

        // using priority_queue
        
        // define the result vector , as 2d
        vector<vector<int>> result(m, vector<int>(n, 1e9));

        // define the priority queue
        priority_queue<P, vector<P>, greater<P> > pq;

        // pq stores {distance, {x, y}}
        pq.push({0, {0, 0}});

        result[0][0] = 0;
        grid[0][0] = 1; // mark as visited

        while(!pq.empty()) {
            
            auto it = pq.top();
            int dist = it.first;
            int x = it.second.first;
            int y = it.second.second;

            pq.pop();

            for(auto& dir: directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                int dist_ = 1;

                if(isSafe(x_, y_) && grid[x_][y_] == 0 && dist + dist_ < result[x_][y_]) {
                    pq.push({dist + dist_, {x_, y_}});
                    result[x_][y_] = dist + dist_;
                }
            }
        }

        if(result[m-1][n-1] == 1e9) {
            return -1;
        }

        return result[m-1][n-1] + 1;
        
    }
};
