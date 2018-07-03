// Link to the problem - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3972

#include<bits/stdc++.h>
using namespace std;

vector<int> visit(10,0);            // a lookup array to see whether the digit is visited or not.

bool check(int n){
    int temp1,temp2 = n,cond=0;
    while(temp2){
        temp1 = temp2 % 10;
        temp2 /= 10;
        if(!visit[temp1])
            visit[temp1] = 1 ;     // if the digit is visited first time we set its index value
        else{
            cond = 1;              // if the digit is visited second time i.e. repeated value
            break;                 // we break the loop and set the cond variable .
        }
    }
    while(n){                      // loop to reset all the digits visited
        temp1 = n % 10;
        n /= 10;
        visit[temp1] = 0 ;
    }
    if(cond)
        return(false);
    else
        return(true);
}

int main(){
    int n , m ,count;
    while(cin>>n>>m){             // numbers will be read till EOF
        count = 0;
        for(int i=n;i<=m;i++){
            if(check(i))          // The range is short so we will check the
                count += 1;       // condition for every number in the range.
        }
        cout<<count<<endl;
    }
    return 0;
}