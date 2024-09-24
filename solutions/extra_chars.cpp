#include <bitset>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    int n = s.length();

    TrieNode *root = make_tree(dictionary);

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = n - 1; i >= 0; i--) {
      dp[i] = dp[i + 1] + 1;
      TrieNode *cur = root;

      for (int j = i; j < n; j++) {
        int pos = s[j] - 'a';
        if (!cur->children.contains(pos)) {
          break;
        }

        cur = cur->children[pos];

        if (cur->is_word) {
          dp[i] = min(dp[i], dp[j + 1]);
        }
      }
    }

    return dp[0];
  }

  TrieNode *make_tree(vector<string> &dict) {
    TrieNode *root = new TrieNode();

    for (string &word : dict) {
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

    return root;
  }
};

int main() {
  Solution sol;

  string s = "leetscode";
  vector<string> dict = {"leet", "code", "leetcode"};

  int res = sol.minExtraChar(s, dict);
  cout << "testcase 1 : " << res << endl;

  s = "sayhelloworld";
  dict.clear();
  dict = {"hello", "world"};
  res = sol.minExtraChar(s, dict);
  cout << "testcase 2 : " << res << endl;

  return 0;
}