#include<bits/stdc++.h>
using namespace std;

#define frb(i,a,b) for(int i=a;i<=b;i++)

int main(){   
    int n, q, l, r, c, count;
    char p, s[100001][21];
    scanf("%d", &n);
    frb(i, 1, n){
        cin >> s[i];
    }
    scanf("%d", &q);
    while(q--){
        count = 0;
        scanf("%d %d %d %c", &l, &r, &c, &p);
        frb(i, l, r)
            if(s[i][c-1] == p)
                count += 1;
        printf("%d\n", count);
    }
    return(0);
}
