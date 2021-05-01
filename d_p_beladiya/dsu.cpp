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