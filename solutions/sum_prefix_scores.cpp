#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
public:
  int count{0};
  TrieNode *children[26] = {};
};

class Trie {
public:
  TrieNode *root = new TrieNode();

  void add_word(string word) {
    TrieNode *cur = root;
    for (char &ch : word) {
      int i = (ch - 'a');

      if (!cur->children[i]) {
        cur->children[i] = new TrieNode();
      }

      cur = cur->children[i];
      cur->count++;
    }
  }

  int has_word(string word) {
    TrieNode *cur = root;
    int res = 0;

    for (char &ch : word) {
      int i = ch - 'a';
      if (!cur->children[i]) {
        break;
      }

      cur = cur->children[i];
      res += cur->count;
    }

    return res;
  }
};

class Solution {
public:
  vector<int> sumPrefixScores(vector<string> &words) {

    Trie *trie = new Trie();

    for (auto &w : words) {
      trie->add_word(w);
    }

    vector<int> res(words.size());

    for (int i = 0; i < words.size(); i++) {
      res[i] = trie->has_word(words[i]);
    }

    return res;
  }
};

void print_vec(vector<int> arr) {
  cout << "[";

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << ((i != arr.size() - 1) ? ", " : "");
  }

  cout << "]" << endl;
}

int main() {
  Solution sol;

  vector<string> words;
  vector<int> res;

  words = {"abc", "ab", "bc", "b"};
  res = sol.sumPrefixScores(words);
  print_vec(res);

  return 0;
}