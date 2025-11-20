class Solution {
  public:
    vector<vector<long long>> dijkstraAllPairs(vector<vector<pair<int,long long>>>& adj) {
        const long long INF = 1e15;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        for(int src = 0; src < 26; src++) {
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
            dist[src][src] = 0;
            pq.push({0, src});

            while(!pq.empty()) {
                auto [cost, u] = pq.top();
                pq.pop();

                if(cost > dist[src][u]) continue;

                for(auto &p : adj[u]) {
                    int v = p.first;
                    long long w = p.second;

                    if(dist[src][v] > cost + w) {
                        dist[src][v] = cost + w;
                        pq.push({dist[src][v], v});
                    }
                }
            }
        }
        return dist;
    }

    long long minCost(string s, string t, vector<vector<char>>& transform, vector<int>& cost) {
        int n = s.size();
        vector<vector<pair<int,long long>>> adj(26);
        for(int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            adj[u].push_back({v, cost[i]});
        }
        auto dist = dijkstraAllPairs(adj);

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            if(a == b) continue;

            long long best = 1e15;

            for(int c = 0; c < 26; c++) {
                if(dist[a][c] == 1e15 || dist[b][c] == 1e15) continue;
                best = min(best, dist[a][c] + dist[b][c]);
            }

            if(best == 1e15) return -1;

            ans += best;
        }

        return ans;
    }
};
//GFG POTD solution for 20 November
