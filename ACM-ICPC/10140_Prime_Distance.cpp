#include<bits/stdc++.h>
using namespace std;

#define frb(i,a,b) for(ll i = a; i <= b; i++ )

typedef vector<int> vi;
typedef long long ll;

bitset<10000010> bs;
vi primes;
ll _sieve_size;

void sieve(ll upperbound){
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]){
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);
    } 
}

bool isPrime(ll N) {
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

int main(){
    ll L,U,C1,C2,D1,D2,x,y,maxd,mind;
    sieve(10000000);
    while(cin >> L >> U){
        bool firstprime = true;
        C1 = C2 = D1 = D2 = x = y = 0;
        maxd=0;mind=1000000;
        frb(i,L,U)
            if(isPrime(i)){
                if(firstprime)  {firstprime = false; y = i; continue;}
                x = y; y = i;
                if((y - x) < mind ){mind=y-x;C1=x;C2=y;}
                if((y - x) > maxd ){maxd=y-x;D1=x;D2=y;}
            }
        if(C1)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",C1,C2,D1,D2);
        else
            printf("There are no adjacent primes.\n");
    }
    return(0);
}
