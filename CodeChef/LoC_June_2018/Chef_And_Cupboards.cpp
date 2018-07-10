#include<bits/stdc++.h>
using namespace std;

#define frb(i,a,b) for(int i=a;i<b;i++)

int main(){   
    int tc;
    long long x, vol, a, b;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        x = llround(((a+b)-sqrt(a*a + b*b -a*b))/3);
        vol=(x)*(a-x)*(b-x);
        printf("%lld %lld \n", x, vol);
    }
    return(0);
}
