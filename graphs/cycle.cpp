#include <iostream>
#include <vector>
#include <Queue>
#include <list>
#include <string>
using namespace std;

class graph{
    int V;
    list<int> *l;
    bool isUndir;
    public:
    graph(int v,bool isUndir=true){
        this->V=v;
        l=new list<int>[V];
        this->isUndir=isUndir;
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isUndir)
            l[v].push_back(u);
    }
    void print(){
        for(int u=0;u<V;u++){
            list<int> neighbours=l[u];
            cout<<u<<" : ";
            for(int v:neighbours){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    bool isCycleHelper(int src,int par,vector<bool>& vis){
        vis[src]=true;
        list<int> neighbours=l[src];
        for(int v:neighbours){
            if(!vis[v]){
                if(isCycleHelper(v,src,vis)){
                    return true;
                }
            }else{
                if(par!=v){
                    return true;
                }
            }
        }
        return false;
        
    }

    bool isCycle(){
        vector<bool> vis(V,false);
        return isCycleHelper(0,-1,vis);
    }
    bool cycleDirectedhelper(int src,vector<bool> &vis,vector<bool>& recPath){
        vis[src]=true;
        recPath[src]=true;
        list<int> neighbours=l[src];

        for(int v:neighbours){
            if(!vis[v]){
                if(cycleDirectedhelper(v,vis,recPath)){
                    return true;
                }
            }else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }
    bool cycleDirected(){
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycleDirectedhelper(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false;
        
    }
    bool isBipartite(){
        queue<int> q;
        vector<bool> vis(V,false);//this can be skipped instead of this color vector can tell that node is visited or not , if it is 0 or 1 in color than it is visited if -1 then u
        vector<int> color(V,-1);
        q.push(0);
        color[0]=0;
        vis[0]=0;
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            list<int> neighbours=l[curr];

            for(int v:neighbours){
                if(!vis[v]){
                    vis[v]=true;
                    color[v]=!color[curr];
                    q.push(v);
                }else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
            
        }
        return true;
    }
};

int main(){
    int v=5;
    graph g(v,false);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.addEdge(0,3);
    
    //bool ans=g.cycleDirected();
    bool ans=g.isBipartite();
    cout<<ans;
    return 0;
}
