#include <bits/stdc++.h>
using namespace std;

// Bottom-Up Approach
void Construct(int st_node, vector <int> &st, int start, int end, vector <int> &arr){
    if(start == end){
        st[st_node] = arr[start];
        return ;
    }

    int mid = start + (end - start)/2;
    int left_node = (2 * st_node) + 1;
    int right_node = (2 * st_node) + 2;
    // int parent_node = (st_node - 1)/2;

    Construct(left_node, st, start, mid, arr);
    Construct(right_node, st, mid + 1, end, arr);
    st[st_node] = st[left_node] + st[right_node];
}

// Bottom-Up Approach
int Query(int st_node, vector <int> &st, int start, int end, int left, int right){
    if(right < start || end < left){
        return(0);
    }

    if(left <= start && end <= right)
        return(st[st_node]);

    int mid = start + (end - start)/2;
    int left_node = (2 * st_node) + 1;
    int right_node = (2 * st_node) + 2;
    // int parent_node = (st_node - 1)/2;

    return(Query(left_node, st, start, mid, left, right) + Query(right_node, st, mid + 1, end, left, right));
}

// Top-Down Approach
void Update(int st_node, vector <int> &st, int start, int end, int index, int diff){
    st[st_node] += diff;
    if(start == end)
        return ;

    int mid = start + (end - start)/2;
    int left_node = (2 * st_node) + 1;
    int right_node = (2 * st_node) + 2;
    // int parent_node = (st_node - 1)/2;

    if(start <= index && index <= mid)
        Update(left_node, st, start, mid, index, diff);
    else if((mid + 1) <= index && index <= end)
        Update(right_node, st, mid + 1, end, index, diff);
}


int main(){
    vector <int> arr{1, 3, 5, 7, 9, 11};
    int n = arr.size();

    int height_st = (int)ceil(log2(n));
    int size_st = (2 * pow(2, height_st)) - 1;
    int start = 0, end = n - 1, st_node = 0;

    vector <int> st(size_st);
    Construct(st_node, st, start, end, arr);

    cout<<Query(st_node, st, start, end, 0, 5)<<endl;

    int index = 2, new_val = 7;
    Update(st_node, st, start, end, index, new_val - arr[index]);

    cout<<Query(st_node, st, start, end, 0, 5)<<endl;
    return 0;
} 
