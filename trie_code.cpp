# include <vector>
# include <string>
using namespace std;

class TrieNode {
  public:
    vector<TrieNode*> child;
    bool isEndOfWord;

    TrieNode() {
      child.assign(26, NULL);
      isEndOfWord = false;
    }
};

class Trie {
  private:
    TrieNode* root;

  public:
    Trie(const vector<string> &words) {
      root = new TrieNode();
      for (int i = 0; i < words.size(); i++) {
        insertWord(words[i]);
      }
    }

    TrieNode* getRoot() {
      return root;
    }

    void insertWord(const string &word) {
      TrieNode* currNode = root;
      for (int i = 0; i < word.size(); i++) {
        int indx = word[i] - 'a';
        if (currNode->child[indx] == NULL) {
          currNode->child[indx] = new TrieNode();
        }
        currNode = currNode->child[indx];
      }
      currNode->isEndOfWord = true;
    }

    bool search(TrieNode *root, string &word) {
      TrieNode *currNode = root;
      for (int i = 0; i < word.size(); i++) {
        int indx = word[i] - 'a';
        if (currNode->child[indx] == NULL) {
          return false;
        }
        currNode = currNode->child[indx];
      }
      return (currNode != NULL && currNode->isEndOfWord);
    }
};

