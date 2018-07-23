Link - https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1335

#include<bits/stdc++.h>
using namespace std;

#define frb(i,a,b) for(ll i = a; i <b; i++ )

typedef long long ll;
typedef vector<ll> vi;

bitset<20005012> bs;
vi primes;
ll _sieve_size;

void sieve(ll upperbound){
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]){
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((ll)i);
    } 
}

int main(){
    ll arr[100002][2],pos=1;
    sieve(20000010);
    frb(i,0,primes.size()-1){
        if((primes[i+1]-primes[i]) == 2)    {arr[pos][0]=primes[i];arr[pos][1]=primes[i+1];pos+=1;}
        if(pos>100000)  break;
    }
    while(cin>>pos)
        printf("(%lld, %lld)\n",arr[pos][0],arr[pos][1]);
    return(0);
}
