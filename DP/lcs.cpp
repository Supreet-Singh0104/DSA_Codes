#include<iostream>
#include<vector>

using namespace std;

int lcsMem(string str1,string str2, vector<vector<int> > dp){//O(n*m)
    if(str1.size()==0 || str2.size()==0){
        return 0;
    }
    int n = str1.size();
    int m = str2.size();

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(str1[n-1]==str2[m-1]){
        dp[n][m]= 1+lcsMem(str1.substr(0,n-1),str2.substr(0,m-1),dp);
    }else{
        int ans1=lcsMem(str1.substr(0,n-1),str2,dp);
        int ans2=lcsMem(str1,str2.substr(0,m-1),dp);
        dp[n][m]= max(ans1,ans2);
    }
    return dp[n][m];
}

int main() {
    // code here
    string str1="abcdge";
    string str2="abedg";
    int n=str1.length();
    int m=str2.length();

    vector<vector<int> > dp(n+1,vector<int>(m+1,-1));

    cout<<lcsMem(str1,str2,dp)<<endl;
    return 0;
}