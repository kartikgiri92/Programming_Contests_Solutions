//This code did not AC in UVA Compiler. The logic, according to me, is correct.
// Probably it is failing for some specific test cases.
// Please do comment or fork if you find the bug.
//Link for the problem - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400

#include<bits/stdc++.h>
using namespace std;

#define frb(i,a,b) for(int i=a;i<b;i++)

vector <int > visited;
vector< vector <int > > v;

int tc,i,ans;
char ch1,ch2;

void dfs(int j){
	visited[j]=1;
	for(auto x:v[j])
		if(!visited[x])
			dfs(x);
}

int main(){
	bool temp1,temp2;

	cin>>tc;
	while(tc--){

		i=0,ans=0;
		visited.assign(100,0);
		v.assign(100,vector<int> () );
		map<char,int> m;
		
		cin>>ch1;
		m[ch1]=i; i+=1;
		while(1){
			scanf("%c",&ch1);
			scanf("%c",&ch1);
			if(ch1=='\n')
				break;
			cin>>ch2;

			temp1=false;temp2=false;
			for(auto x:m){
				if(x.first==ch1)
					temp1=true;
				if(x.first==ch2)
					temp2=true;
			}
			if(!temp1){
				m[ch1]=i;
				i+=1;
			}
			if(!temp2){
				m[ch2]=i;
				i+=1;
			}

			v[m[ch1]].push_back(m[ch2]);
			v[m[ch2]].push_back(m[ch1]);

		}

		frb(j,0,i)
			if(!visited[j]){
				dfs(j);
				ans+=1;
			}
		if(tc!=0)
			printf("%d\n\n",ans);
		else
			printf("%d\n",ans);
	}
	return(0);
}
