// Question - https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1796

#include<bits/stdc++.h>
using namespace std;

#define frb(i,a,b) for(int i=a;i<b;i++)

int n,N;
char X[500][500], Y[500][500], Z[500][500];

void rotate()       //function to rotate small square
{
    frb(i,0,n)
        frb(j,0,n)
            Z[j][n-1-i] = Y[i][j];
    frb(i,0,n)
        frb(j,0,n)
            Y[i][j] = Z[i][j];
}

bool same(int p, int q) 
{
    frb(i,0,n)
        frb(j,0,n)
            if(Y[i][j] != X[i + p][j + q])
                return(false);

    return(true);
}

int match()
{
    int temp = 0;
    frb(i,0,N-n+1)                  //from each table index the small square will be checked
        frb(j,0,N-n+1)
            if(same(i,j))
                temp++;

    return(temp);
}


int main()
{
    while(scanf("%d %d",&N,&n),(N || n))
    {
        frb(i,0,N)
            scanf("%s",&X[i]);
        frb(i,0,n)
            scanf("%s",&Y[i]);
        frb(i,0,4)
        {
            if(i)  rotate();
            printf("%d%c",match(),i < 3 ? ' ' : '\n');
        }
    }
    return(0);
}
