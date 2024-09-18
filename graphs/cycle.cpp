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
};
int main(){
    return 0;
}
