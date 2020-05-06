// Disjoint Set Union (Union - Find)

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector <int> parent, size;

void initialize(int n){
    for(int i = 0; i < n + 1; i++){
        parent.push_back(i);
        size.push_back(1);
    }
}

int Root(int a){
    while(parent[a] != a){
        parent[a] = parent [parent[a]];
        a = parent[a];
    }
    return(a);
}

bool Find(int a, int b){
    if(Root(a) == Root(b))
        return(true);
    return(false);
}

void Union(int a, int b){
    int root_a = Root(a);
    int root_b = Root(b);

    if(root_a != root_b){
        if(size[root_a] < size[root_b]){
            parent[root_a] = parent[root_b];
            size[root_b] += size[root_a];
        }
        else{
            parent[root_b] = parent[root_a];
            size[root_a] += size[root_b];
        }
    }

}

int main(){
    int n = 8;
    initialize(n);

    Union(1, 3);
    Union(7, 5);
    Union(1, 7);

    Union(2, 4);
    Union(8, 6);
    Union(4, 8);

    cout<<"FIND\n";
    cout<<"Find(1, 3) = "<<Find(1, 3)<<endl;
    cout<<"Find(2, 3) = "<<Find(2, 3)<<endl;
    cout<<"Find(8, 4) = "<<Find(8, 4)<<endl;
    cout<<"Find(5, 7) = "<<Find(5, 7)<<endl;
    cout<<"Find(8, 1) = "<<Find(8, 1)<<endl;

    cout<<"Root\n";
    cout<<"Root(1) = "<<Root(1)<<endl;
    cout<<"Root(2) = "<<Root(2)<<endl;
    cout<<"Root(3) = "<<Root(3)<<endl;
    cout<<"Root(4) = "<<Root(4)<<endl;
    cout<<"Root(5) = "<<Root(5)<<endl;
    cout<<"Root(6) = "<<Root(6)<<endl;
    cout<<"Root(7) = "<<Root(7)<<endl;
    cout<<"Root(8) = "<<Root(8)<<endl;

    return 0;
}
