Link - https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1348
#include<bits/stdc++.h>
using namespace std;

// typedef vector<int > vi;
// #define frb(i,a,b) for(int i = a; i <b; i++ )

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main(){
    ll arr[1002],n,ans;
    while(1){
        cin>>arr[0];
        if(!arr[0])     break;
        for(ll i=1;;i++){
            cin>>arr[i]; 
            if(!arr[i]){n = i;break;}
        }
        for(ll i=1;i<n;i++)  arr[i] -= arr[0];
        ans = arr[1];
        for(ll i=2;i<n;i++)  ans=gcd(ans,arr[i]);
        printf("%lld\n",ans);
    }

    
    return(0);
}
