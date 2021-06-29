//best rank with path compression

//we attach the tree with the lower rank to the one with the bigger rank.
class Solution {
public:
vector<int> parent;
    vector<int> rank;
    
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
         if((n-1)>connections.size())
            return -1;
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
        rank.resize(n+1,0);
        for(auto i:connections)
        {
            union_sets(i[0],i[1]);
        }
            
        map<int,int> m;
        for(int i=0;i<n;i++)cout<<parent[i]<<" ";
        for(int i=0;i<n;i++)
            m[find_set(i)]++;
        
        return m.size()-1;
        
    }
};



/////////////

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








///////////////////
class Solution {
public:
    
   
int find(int x,vector<int> & par)
    {
        if(par[x]==-1)
            return x;
        
        par[x]=find(par[x],par);
        return par[x];
    }
    
    void unio(int x,int y,vector<int> &par)
    {
        int xp=find(x,par);
        int yp=find(y,par);
        
        if(xp!=yp)
            par[yp]=xp;
            
    }
    int findCircleNum(vector<vector<int>>& M) {
        
        int n=M.size();
         vector<int> par(n,-1);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(M[i][j])
                unio(i,j,par);
        int x=0;
        map<int,int> m;
        for(int i=0;i<n;i++)   
        {
            int ty=find(i,par);
               
            m[ty]++;
        }cout<<m.size()<<endl;
        
        return m.size();
    }
};

////////pathcompression


class Solution {
    public int makeConnected(int n, int[][] connections) {
        DSU dsu = new DSU(n);
        for (int[] c : connections)
             dsu.union(c[0],c[1]);
        if( connections.length < n-1)
        return -1;
        return dsu.operation-1;
    }
    public class DSU {
    int [] parent;
    int [] rank;
    int operation;

    public DSU(int n){
      parent = new int[n];
      rank =   new int [n];
      for (int i=0;i < n;i++)
          parent[i]=i;
      operation =n;
    }

    public void union(int x,int y){
    int par_x = find(x);
    int par_y = find(y);

    if (par_x != par_y){

        if (par_x > par_y){
            parent[par_y] = par_x;
            rank[par_x]++;
        }
        else{
            parent[par_x] = par_y;
            rank[par_y]++;
        }
        operation--;
    }  
    }
    public int find (int i){
    if (parent[i] != i){
     parent[i] = parent[ parent[i]];
     return find (parent[i]);
    }
    else
    return i;
    }
    }

    }