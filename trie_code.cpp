#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// structure of each node in Trie
struct TrieNode {
  struct TrieNode *child[26];	// array of pointers
  bool isEndOfWord;
};

struct TrieNode *newNode() {
  struct TrieNode *root = new TrieNode;
  root->isEndOfWord = false;
  for (int i = 0; i < 26; i++) {
    root->child[i] = NULL;
  }
  return root;
}

void insert(TrieNode *root, string str) {
  struct TrieNode *node = root;
  for (int i = 0; i < str.size(); i++) {
    int indx = str[i] - 'a';
    if (!node->child[indx]) {
      node->child[indx] = newNode();
    }
    node = node->child[indx];
  }
  node->isEndOfWord = true;
}

bool search(TrieNode *root, string str) {
  struct TrieNode *node = root;
  for (int i = 0; i < str.size(); i++) {
    int indx = str[i] - 'a';
    if (!node->child[indx]) {
      return false;
    }
    node = node->child[indx];
  }
  if (node != NULL && node->isEndOfWord) {
    return true;
  }
  return false;
}

int main() {

  int n;
  cin >> n;
  vector <string> keys;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    keys.push_back(str);
  }
  struct TrieNode *root = newNode();
  
  // insert operation
  for (int i = 0; i < keys.size(); i++) {
    insert(root, keys[i]);
  }

  // search operation
  string str;
  cin >> str;
  if (search(root, str)) {
    cout << "Found !" << endl;
  } else {
    cout << "Not Found !" << endl;
  }

  return 0;
}
