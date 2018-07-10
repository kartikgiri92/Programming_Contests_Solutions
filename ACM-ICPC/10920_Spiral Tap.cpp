// Question - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1861

#include<bits/stdc++.h>
using namespace std;

#define frb(i,a,b) for(int i=a;i<b;i++)

int row[] =    {1,  0, -1, 0};
int column[] = {0, -1,  0, 1};

int main(){   
    int SZ, p;
    int n, x, y, temp, a;
    bool out;
    while(scanf("%d %d", &SZ, &p),(SZ || p)){   
        x = (SZ + 1) / 2 ; 
        y = (SZ + 1) / 2 ;
        n = 1; temp = 1 ; a = 0;
        out = false;

        if(p == 1){
           printf("Line = %d, column = %d.\n", x, y);
           continue; 
        }
        
        frb(i,0,4){
            frb(j,0,temp){
                x += row[i];
                y += column[i];
                n++;
                if(n == p){
                    out = true;
                    break;
                }
            }
            if(out)
                break;
            if(++a == 2){
                a = 0;
                temp += 1;
            }
            if(i == 3)
                i = -1;
        }
        printf("Line = %d, column = %d.\n", x, y);
    }
    return(0);
}
