#include<bits/stdc++.h>
using namespace std;

#define frb(i,a,b) for(int i = a; i < b; i++ )

typedef vector<int> vi;

bitset<100001> bs;

int main(){
    int tc, n, temp;
    string s;
    char c;
    cin >> tc;
    cin.ignore();
    while(tc--){
        cin >> n;
        cin >> s;
        if(n&1)     temp = n - 1;
        else        temp  = n;
        for(int i = 0; i < temp; i +=2 ){
            c = s[i];
            s[i] = s[i+1];
            s[i+1] = c;
        }
        frb(i,0,n)
            s[i] = 122 - s[i] + 97;
        cout << s << endl;
    }
    return(0);
}
