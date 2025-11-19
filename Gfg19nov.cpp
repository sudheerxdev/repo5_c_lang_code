class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        vector<vector<pair<int,int>>>adj(mat.size()*mat[0].size());
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i-1>=0)
                {
                    int node1=i*mat[0].size()+j;
                    int node2=(i-1)*mat[0].size()+j;
                    int d=abs(mat[i][j]-mat[i-1][j]);
                    adj[node1].push_back({node2,d});
                }
                if(j-1>=0)
                {
                    int node1=i*mat[0].size()+j;
                    int node2=i*mat[0].size()+j-1;
                    
                    int d=abs(mat[i][j]-mat[i][j-1]);
                    adj[node1].push_back({node2,d});
                }
                if(i+1<mat.size())
                {
                    int node1=i*mat[0].size()+j;
                    int node2=(i+1)*mat[0].size()+j;
                    int d=abs(mat[i][j]-mat[i+1][j]);
                    adj[node1].push_back({node2,d});
                }
                if(j+1<mat[0].size())
                {
                    int node1=i*mat[0].size()+j;
                    int node2=i*mat[0].size()+j+1;
                    int d=abs(mat[i][j]-mat[i][j+1]);
                    adj[node1].push_back({node2,d});
                }
            }
        }
        vector<int>dist(mat.size()*mat[0].size(),INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            int d=pq.top().first,node1=pq.top().second;
            pq.pop();
            if(d!=dist[node1])
            continue;
            if(node1==mat.size()*mat[0].size()-1)
            break;
            for(auto &item:adj[node1]){
                int node2=item.first,wt=item.second;
                if(dist[node2]>dist[node1] && dist[node2]>wt)
                {
                    
                    dist[node2]=max(dist[node1],wt);
                    pq.push({dist[node2],node2});
                }
            }
        }
        return dist[mat.size()*mat[0].size()-1];
    }
};

//GFG POTD solution for 19 November
