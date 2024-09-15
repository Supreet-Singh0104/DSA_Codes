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
//https://docs.google.com/document/d/1or47S_ufu982J8cF-0FYNo4AfbZzY_B0XLZMIbo2fLI/edit

int max(int a,int b,int c){ return max(a,max(b,c));}

int maxcalculator(vector<int>& easy, vector<int>& medium, vector<int>& hard,int n){
    if(n==0) return 0;

    vector<int> dp_easy(n+1,0);
    vector<int> dp_med(n+1,0);
    vector<int> dp_hard(n+1,0);

    //starting first few indexes

    //index1
    dp_easy[1]=easy[1];
    dp_med[1]=medium[1];
    dp_hard[1]=hard[1];

    //index2
    dp_easy[2]=easy[2]+max(easy[1],medium[1],hard[1]);
    dp_med[2]=medium[2]+max(easy[1],medium[1],hard[1]);// considerint the edge case is given that given condition is not valid till index2
    dp_hard[2]=hard[2]+max(easy[1],medium[1],hard[1]);

    //index3
    dp_easy[3]=easy[3]+max(dp_easy[2],dp_med[2],dp_hard[2]);
    dp_med[3]=medium[3]+easy[2]+medium[1];
    dp_hard[3]=hard[3]+easy[1]+max(easy[2],medium[2],hard[2]);  

    for(int i=4;i<=n;i++){
        dp_easy[i]=easy[i]+max(dp_easy[i-1],max(dp_med[i-1],dp_hard[i-1]));
        dp_med[i]=medium[i]+easy[i-1]+dp_med[i-2];
        // hard will have 3 options
        int opt1=hard[i]+easy[i-1]+dp_easy[i-2];
        int opt2=hard[i]+medium[i-1]+easy[i-2]+dp_med[i-3];
        int opt3=hard[i]+hard[i-1]+easy[i-2]+dp_easy[i-3];
        dp_hard[i]=max(opt1,max(opt2,opt3));
    }
    return max(dp_easy[n],dp_hard[n],dp_med[n]);
}

int main() {
    // code here
    int n; cin>>n;
    vector<int> easy(n+1),medium(n+1),hard(n+1);

    for(int i=1;i<=n;i++){
        cin>>easy[i];
    }
    for(int i=1;i<=n;i++){
        cin>>medium[i];
    }
    for(int i=1;i<=n;i++){
        cin>>hard[i];
    }
    cout<<"Maximum points "<<maxcalculator(easy,medium,hard,n);
    return 0;
}