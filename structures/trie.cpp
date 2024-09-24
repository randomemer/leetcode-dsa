#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
public:
  bool is_word;
  unordered_map<char, TrieNode *> children;
};

class Trie {
public:
  TrieNode *root = new TrieNode();

  void add_word(string word) {
    TrieNode *cur = root;
    for (char &ch : word) {
      int i = ch - 'a';

      if (!cur->children.contains(i)) {
        cur->children[i] = new TrieNode();
      }

      cur = cur->children[i];
    }

    cur->is_word = true;
  }

  bool has_word(string word) {
    TrieNode *cur = root;

    for (char &ch : word) {
      if (!cur->children.contains(ch - 'a')) {
        break;
      }

      cur = cur->children[ch - 'a'];
    }

    return (cur != nullptr && cur->is_word);
  }
};