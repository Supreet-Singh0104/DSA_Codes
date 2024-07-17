#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
typedef long long int ll;
using namespace std;
//Q) https://atcoder.jp/contests/dp/tasks/dp_c
//https://docs.google.com/document/d/155E_2S7FabNMwPyQT4qcPJYug8gLOJsu37UsUNMrOCE/edit

int main() {
    // code here
    ll n; cin>>n;
    vector<ll> a(n+1,0);
    vector<ll> b(n+1,0);
    vector<ll> c(n+1,0);
    
 
    vector<ll> dpa(n + 1, 0);
    vector<ll> dpb(n + 1, 0);
    vector<ll> dpc(n + 1, 0);

    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    dpa[1]=a[1];
    dpb[1]=b[1];
    dpc[1]=c[1];
    
    for(int i=2;i<=n;i++){
        dpa[i]=a[i]+max(dpb[i-1],dpc[i-1]);
        dpb[i]=b[i]+max(dpa[i-1],dpc[i-1]);
        dpc[i]=c[i]+max(dpa[i-1],dpb[i-1]);
    }

    cout<<max(dpa[n],max(dpb[n],dpc[n]));
    return 0;
}