#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Heap{
    vector<int> vec;
    public:

    void push(int val){ //O(logn)
        // step1
        vec.push_back(val);

        //fix heap
        int x=vec.size()-1; // ChildI-->latest child added
        int parI=(x-1)/2;
        while(parI>=0 && vec[x]>vec[parI]){ //vec[x]>vec[parI] for max heap , for min heap < is used in the condition
            swap(vec[x],vec[parI]);
            x=parI;
            parI=(x-1)/2;
        }
    }
    void pop(){

    }
    int top(){
        return vec[0];
    }
    bool empty(){
        return vec.size()==0;
    }
};
int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);
    cout<<"top = "<<heap.top()<<endl;
    return 0;
}
