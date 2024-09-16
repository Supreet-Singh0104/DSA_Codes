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
 //   graph.bfs();
    return 0;
}