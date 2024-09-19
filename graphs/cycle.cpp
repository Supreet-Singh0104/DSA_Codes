#include <iostream>
#include <vector>
#include <Queue>
#include <list>
#include <string>
using namespace std;

class graph{
    int V;
    list<int> *l;
    public:
    graph(int v){
        this->V=v;
        l=new list<int>[V];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
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
};

int main(){
    int v=5;
    graph g(v);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    bool ans=g.isCycle();
    cout<<ans;
    return 0;
}
