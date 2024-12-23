#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>

using namespace std;
typedef long long int ll;

void heapify(int i ,vector<int> &arr, int n){// n represents the size of the heap
    int left=2*i+1;
    int right=2*i+2;
    int maxi=i;

    if(left<n && arr[left]>arr[maxi]){ //max heap for ascending order
        maxi=left;
    }
    if(right<n && arr[right]>arr[maxi]){ //max heap for ascending order
        maxi=right;
    }

    if(maxi!=i){
        swap(arr[i],arr[maxi]);
        heapify(maxi,arr,n);
    }

}

void heapSort(vector<int> &arr){
    int n=arr.size();

    //step 1: Build maxHeap
    for(int i=n/2-1;i>=0;i--){//O(n*logn)
        heapify(i,arr,n);
    }

    //step 2: Taking elements to the correct position
    for(int i=n-1;i>=0;i--){//O(n*logn)
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}

int main() {
    // code here
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(7);

    heapSort(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}