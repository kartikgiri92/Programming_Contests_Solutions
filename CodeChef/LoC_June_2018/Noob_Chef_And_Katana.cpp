#include<bits/stdc++.h>
using namespace std;

#define frb(i,a,b) for(int i=a;i<b;i++)

int main(){   
    int n, temp;
    set<int> s;
    scanf("%d", &n);
    frb(i,0,n){
        cin >> temp;
        s.insert(temp);
    }
    printf("%d\n", s.size());
    return(0);
}
