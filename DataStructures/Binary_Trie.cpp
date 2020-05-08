// Question - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-and-insert-92b9b529/

#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    int EndOfWord;
    struct TrieNode *children[2];

    TrieNode(){
        for(int i = 0; i < 2; i++)
            children[i] = NULL;
        EndOfWord = -1;
    }
};

void Insert(struct TrieNode *root, int key){
    TrieNode *temp = root;
    for(int i = 30; i >= 0; i--){
        int mst_bit = ((key) & (1 << i)) ? 1 : 0;
        if(!temp->children[mst_bit]){
            temp->children[mst_bit] = new TrieNode();
        }

        temp = temp->children[mst_bit];
    }

    temp->EndOfWord = key;
}

int GetMinimum(struct TrieNode *root, int curr_xor){
    TrieNode *temp = root;
    int ans = 0;
    for(int i = 30; i >= 0; i--){
        int mst_bit = ((curr_xor) & (1 << i)) ? 1 : 0;
        if(!temp->children[mst_bit]){
            ans = ans | (1 << i);
            temp = temp->children[!mst_bit];
        }
        else{
            temp = temp->children[mst_bit];
        }
    }
    return(ans);
}

int main(){
    int n, curr_xor = 0, query, query_value;
    struct TrieNode *root = new TrieNode();

    cin>>n;
    Insert(root, 0);
    while(n--){
        cin>>query;
        if(query == 1){
            cin>>query_value;
            Insert(root, query_value ^ curr_xor);
        }
        else if(query == 2){
            cin>>query_value;
            curr_xor ^= query_value;
        }
        else{
            cout<<GetMinimum(root, curr_xor)<<endl;
        }
    }

    return 0;
}
