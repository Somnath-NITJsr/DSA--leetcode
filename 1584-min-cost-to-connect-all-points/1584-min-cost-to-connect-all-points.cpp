class Solution {
public:
    typedef pair<int, int> P;
    
    int PrimsAlgo(vector<vector<P>>& adj, int& V) {

        priority_queue<P, vector<P>, greater<P> >pq;

        pq.push({0, 0});
        // wt, node
        int sum = 0;

        vector<bool> inMST(V, false);

        while(!pq.empty()) {
            auto& it = pq.top();
            int dist = it.first;
            int node = it.second;
            pq.pop();

            
            if(inMST[node]) continue;

            inMST[node] = true;
            sum += dist;

            for(auto& v: adj[node]) {
                int neigh_wt  = v.first;
                int neighbour = v.second;

                if(!inMST[neighbour]) {
                    pq.push({neigh_wt, neighbour});
                }
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        // create the adj list

        vector<vector<P> >adj(V);

        for(int i=0; i<V; i++) {
            for(int j=i+1; j<V; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});

            }
        }

        return PrimsAlgo(adj, V);
    }
};