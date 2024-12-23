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
        while(parI>=0 && vec[x]>vec[parI]){ //vec[x]>vec[parI] for max heap , for min heap < is used in the condition vec[x]<vec[parI]
            swap(vec[x],vec[parI]);
            x=parI;
            parI=(x-1)/2;
        }
    }
    void heapify(int i){ //i=Par_Idx
        if(i >= vec.size()){ //this case if the no element eas ledt after deleting the element
            return ;
        }

        int l=2*i+1;
        int r=2*i+2;

        int MaxIdx=i;

        if(l<vec.size() && vec[l]>vec[MaxIdx]){ // for min heap vec[l]<vec[MaxIdx]
            MaxIdx=l;
        }
        if(r<vec.size() && vec[r]>vec[MaxIdx]){ // for min heap vec[r]<vec[MaxIdx]
            MaxIdx=r;
        }

        swap(vec[i],vec[MaxIdx]);

        if(MaxIdx!=i){  //swapping with child node
            heapify(MaxIdx);
        }

    }
    void pop(){
        //step 1
        swap(vec[0],vec[vec.size()-1]);

        //step2
        vec.pop_back();

        //step 3
        heapify(0);
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
    heap.pop();
    cout<<"top = "<<heap.top()<<endl;
    return 0;
}
