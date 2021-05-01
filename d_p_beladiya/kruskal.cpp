//https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/843958/C%2B%2B-Classic-Minimum-Spanning-Tree-or-Prim's-%2B-Kruskal(TLE-idk-why)-or-Mini-Tutorial







class Solution {
public:
    int find(vector<int> &par, int i) {
        if (par[i] != i) {
            par[i] = find(par, par[i]);
        }
        return par[i];
    }
    void uniondsu(vector<int> &par, vector<int> &sz, int &x, int &y, int &w, int &ans, int &E) {
        int p1 = find(par, x);
        int p2 = find(par, y);
        if (p1 == p2) return;
        ans += w;
        E--;
        if (sz[p1] > sz[p2]) {
            sz[p1] += sz[p2];
            par[p2] = p1;
        } else {
            sz[p2] += sz[p1];
            par[p1] = p2;
        }
        return;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edge;
        int n = points.size();
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int sz = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edge.push_back({sz, i, j});
            }
        }
        sort(edge.begin(), edge.end());
        vector<int> par(n);
        vector<int> size(n, 1);
        for(int i=0; i<n; i++) par[i] = i;
        int E = n-1;
        int ans = 0;
        for(auto &i: edge) {
            int w, x, y;
            w = i[0];
            x = i[1];
            y = i[2];
            uniondsu(par, size, x, y, w, ans, E);
            if (!E) break;
        }
        return ans;
    }
};




----------------------

//https://leetcode.com/contest/weekly-contest-206/problems/min-cost-to-connect-all-points/


#define pii pair<int,int>
#define fr first
#define sc second
class Solution {
public:
  
    int minCostConnectPoints(vector<vector<int>>& points) {
       int n=points.size();
        
        set<pii> vis,unvis;  
        for(int i=0;i<n;i++) unvis.insert({points[i][0],points[i][1]});  

         priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> q;

        int ans=0; q.push({0,{points[0][0],points[0][1]}});  
        while(!q.empty() && vis.size()<n)
        {
            pair<int,pii> pi=q.top(); q.pop();  
            if(vis.find(pi.sc)!=vis.end()) continue; 
            vis.insert(pi.sc); unvis.erase(pi.sc); 

            for(auto itr:unvis)   
            {
                int dist=abs(pi.sc.fr-itr.fr)+abs(pi.sc.sc-itr.sc);
                q.push({dist,{itr.fr,itr.sc}});
            }
            
            ans=ans+pi.fr;
        }
        return ans;
    }
};