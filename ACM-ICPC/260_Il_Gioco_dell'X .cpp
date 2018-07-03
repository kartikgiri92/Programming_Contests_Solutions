//Link for the problem - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=196

#include<bits/stdc++.h>
using namespace std;

#define frb(i,a,b) for(int i=a;i<b;i++)

int matr[201][201];
int visited[201][201];

int row[]={-1,-1,0,0,1,1};
int column[]={-1,0,-1,1,0,1};

int n,var1,var2,temp;

void dfs(int rrw,int cllm){
	visited[rrw][cllm] = 1;
	frb(i,0,6){
		var1=rrw+row[i];
		var2=cllm+column[i];
		if((var1>=0)&&(var1<n)&&(var2>=0)&&(var2<n))
			if((matr[var1][var2]==0) && (visited[var1][var2]==0)){
				if((var1)==(n-1))
					temp=1;
				else
					dfs(var1,var2);
			}
	}
}

int main(){
	char ch;
	int cont=1;
	while(scanf("%d",&n) && n){
		frb(i,0,n)
			frb(j,0,n){
				visited[i][j]=0;
				scanf("%c",&ch);
				if(ch=='\n')
					j-=1;
				else if(ch=='b')
					matr[i][j]=0;		// 0 for black
				else
					matr[i][j]=1;		// 1 for white
			}
		temp=0;
		frb(i,0,n)
			if((matr[0][i]==0) && (visited[0][i]==0) && !temp)
				dfs(0,i);

		printf("%d ",cont);
		cont++;
		if(temp)
			printf("B\n");
		else
			printf("W\n");
	}
	return(0);
}
