#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V; 
    list<int> *l;
    public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }
    void addEdge(int u,int v){ //u--v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(){
        queue<int> q;
        vector<bool> vis(V,false);
        q.push(0);
        vis[0]=true;

        while(q.size()>0){
            int u=q.front();// curr vertex
            q.pop();
            cout<<u<<" ";

            list<int> neighbours=l[u];
            for(int v:neighbours){// visiting all neighbours of the current vertex
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }

    void dfsHelper(int u,vector<bool>& vis){
    vis[u]=true;
    cout<<u<<" ";
    list<int> neighbours=l[u];
    for(int v:neighbours){
        if(!vis[v]){
            dfsHelper(v,vis);
        }
    }
    }
    void dfs(){
        vector<bool> vis(V,false);
        dfsHelper(0,vis);
        cout<<endl;
    }

    bool haspathHelper(int src,int dest,vector<int>& vis){
        if(dest==src){
            return true;
        }
        vis[src]=true;
        list<int> neighbours=l[src];
        for(int v:neighbours){
            if(!vis[v]){
                if(haspathHelper(v,dest,vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool haspath(int src,int dest){
        vector<int> vis(V,false);
        return haspathHelper(src,dest,vis);
    }


};





int main(){
    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    graph.bfs();
    cout<<endl;
    graph.dfs();
    cout<<endl;
    cout<<graph.haspath(5,9);
    return 0;
}