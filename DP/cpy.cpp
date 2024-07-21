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
ll max(ll a,ll b,ll c)
{
    return max(a,max(b,c)) ; 
}
ll min(ll a,ll b,ll c)
{
    return min(a,min(b,c)) ;
}

int main() {
    // code here
    ll t;
    cin>>t;
    while(t--){
        ll n;// no of quwries
        cin>>n;
        vector<ll> dpmax(n + 1);
        vector<ll> dpmin(n + 1);
        dpmax[0]=1;
        dpmin[0]=dpmax[0];// 1 energy is left initially
        for(int i=1;i<=n;i++){
            char sign;
            cin>>sign;
           // cout<<sign;
            if(sign=='+'){
                ll num; cin>>num;
                dpmax[i]=max(dpmax[i-1]+num,dpmax[i-1],dpmin[i-1]+num);
                dpmin[i]=min(dpmin[i-1]+num,dpmin[i-1],dpmax[i-1]+num);
            }else if(sign=='-'){
                ll num; cin>>num;
                dpmax[i]=max(dpmax[i-1]-num,dpmax[i-1],dpmin[i-1]-num);
                dpmin[i]=min(dpmin[i-1]-num,dpmin[i-1],dpmax[i-1]-num);
            }else if(sign=='*'){
                ll num; cin>>num;
                dpmax[i]=max(dpmax[i-1]*num,dpmax[i-1],dpmin[i-1]*num);
                dpmin[i]=min(dpmin[i-1]*num,dpmin[i-1],dpmax[i-1]*num);               
            }else if(sign =='/'){
                ll num; cin>>num;
                dpmax[i]=max(dpmax[i-1]/num,dpmax[i-1],dpmin[i-1]/num);
                dpmin[i]=min(dpmin[i-1]/num,dpmin[i-1],dpmax[i-1]/num);
            }else{
                
                dpmax[i]=max(-1*dpmin[i-1],-1*dpmax[i-1],dpmax[i-1]);
                dpmin[i]=min(-1*dpmax[i-1],-1*dpmin[i-1],dpmin[i-1]);                
            }
        }
        cout<<dpmax[n]<<"\n";

    }
    return 0;
}