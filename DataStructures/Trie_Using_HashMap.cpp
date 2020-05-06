// 1. Initialization of Trie
// 2. Insert a word
// 3. Search a word
// 4. Delete a word
// 5. Show all Words (PreOrder Travesal of Trie)
// 6. Count All words(PreOrder Travesal of Trie)

#include <bits/stdc++.h>
using namespace std;

// Trie Using HashMap //
struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool EndOfWord;

    TrieNode(){
        EndOfWord = false;
    }
};

// Insert Implementation Start //
void insert(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++){
        int index = key[i];
        if(!(pCrawl->children.count(index)))
            pCrawl->children[index] = new TrieNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->EndOfWord = true; 
} 
// Insert Implementation End //

// Search Implementation Start //
bool search(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++){
        int index = key[i];
        if(!(pCrawl->children.count(index)))
            return false;

        pCrawl = pCrawl->children[index];
    }

    return(pCrawl != NULL && pCrawl->EndOfWord);
}
// Search Implementation End //

// Delete Implementation Start //
bool isEmpty(TrieNode* root){
    if(!(root->children.empty()))
        return(false);
    return true;
}
  
TrieNode* remove(TrieNode* root, string key, int depth){
    if (!root)
        return NULL;

    if(depth == key.size()){
  
        if(root->EndOfWord)
            root->EndOfWord = false;

        if(isEmpty(root)){
            delete (root);
            root = NULL;
        }

        return root;
    } 
  
    int index = key[depth]; 
    root->children[index] = remove(root->children[index], key, depth + 1);
  
    if(isEmpty(root) && root->EndOfWord == false){
        delete(root);
        root = NULL;
    }
    return root; 
}
// Delete Implementation End //

// ShowAllWords Implementation Start //
void ShowAllWords(TrieNode *root, string curr){ //Also Known as Preorder Traversal
    if(root->EndOfWord)
        cout<<curr<<endl;

    for(int i = 0; i < 128; i++){
        if(root->children.count(i) && root->children[i]){
            ShowAllWords(root->children[i], curr + char(i));
        }
    }
}
// ShowAllWords Implementation End //

// CountAllWords Implementation Start //
void CountAllWords(TrieNode *root, string curr, int &count){ 
    if(root->EndOfWord)
        count++;

    for(int i = 0; i < 128; i++){
        if(root->children.count(i) && root->children[i]){
            CountAllWords(root->children[i], curr + char(i), count);
        }
    }
}
// CountAllWords Implementation End //

int main(){
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their", ";;.." };
    int n = sizeof(keys)/sizeof(keys[0]);

    struct TrieNode *root = new TrieNode();

    // Inserting
    for(int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Searching
    search(root, "the")? cout << "Query - Yes\n" : cout << "Query - No\n";
    search(root, "these")? cout << "Query - Yes\n" : cout << "Query - No\n";
    search(root, ";;..")? cout << "Query - Yes\n" : cout << "Query - No\n";

    // Deleting
    remove(root, "the", 0);
    search(root, "the") ? cout << "Query - Yes\n" : cout << "Query - No\n";
    remove(root, ";;..", 0);
    search(root, ";;..")? cout << "Query - Yes\n" : cout << "Query - No\n";

    // Display All Words
    /* Also Known as Preorder Traversal; 
       Used to display all keys lexographically */
    ShowAllWords(root, "");

    // Count All Words
    int count = 0;
    CountAllWords(root, "", count);
    cout<<count<<endl;


    return 0;
} 
