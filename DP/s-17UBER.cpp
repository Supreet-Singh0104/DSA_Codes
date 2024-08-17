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
// https://docs.google.com/document/d/1qSv9hJcj1nNsvMOdbGx1HFbJLWcIX7Plt2I_vKOz8pA/edit

void countJourneys(vector<int>& arr, vector<int>& brr){
    int n=arr.size();

    // creating 3 d dp array with 1 based indexing 
     vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(2, vector<int>(2, 0)));
    int a=0;
    int b=1;
    int e=0;//even
    int o=1;//odd
    
// haandling the edge case
    if(arr[1]%2==0){
        dp[1][a][e]=1;
        dp[1][a][o]=0;
    }else{
        dp[1][a][e]=0;
        dp[1][a][o]=1;
    }
    if(brr[1]%2==0){
        dp[1][b][e]=1;
        dp[1][b][o]=0;
    }else{
        dp[1][b][e]=0;
        dp[1][b][o]=1;
    }

    for(int i=2;i<=n;i++){
        // this updation was made for the arr array
        if(arr[i]%2==0){
            dp[i][a][e] =dp[i-1][a][e]+dp[i-1][b][e];
        }else{
            dp[i][a][e] =dp[i-1][a][o]+dp[i-1][b][o];
        }
        if(arr[i]%2==0){
            dp[i][a][o] =dp[i-1][a][o]+dp[i-1][b][o];
        }else{
            dp[i][a][o] =dp[i-1][a][e]+dp[i-1][b][e];
        }
        // now this updation is being made for brr array
        if(brr[i]%2==0){
            dp[i][b][e] =dp[i-1][a][e]+dp[i-1][b][e];
        }else{
            dp[i][b][e] =dp[i-1][a][o]+dp[i-1][b][o];
        }
        if(brr[i]%2==0){
            dp[i][b][o] =dp[i-1][a][o]+dp[i-1][b][o];
        }else{
            dp[i][b][o] =dp[i-1][a][e]+dp[i-1][b][e];
        }
    }
    int evenjourneys=(dp[n][a][e]+dp[n][b][e]);
    int oddjourneys=(dp[n][a][o]+dp[n][a][o]);
    cout << "Even journey count is " << evenjourneys << endl;
    cout << "Odd journey count is " << oddjourneys << endl;
}

int main() {
    // code here
    vector<int> a(3); //= {1, 2, 1};
    vector<int> b(3);// = {3, 1, 1};
    for(int i=0;i<3;i++) cin>>a[i];
    for(int i=0;i<3;i++) cin>>b[i];
    
    countJourneys(a,b);
    return 0;
}