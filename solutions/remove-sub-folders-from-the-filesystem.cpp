#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
public:
  bool is_word;
  unordered_map<string, TrieNode *> children;
};

class Trie {
public:
  TrieNode *root = new TrieNode();

  void add_folder(vector<string> words) {
    TrieNode *cur = root;
    for (auto &w : words) {
      if (!cur->children.contains(w)) {
        cur->children[w] = new TrieNode();
      }

      cur = cur->children[w];
    }

    cur->is_word = true;
  }
};

class Solution {
public:
  vector<string> removeSubfolders(vector<string> &folder) {
    vector<string> res{};
    Trie trie{};

    for (string &f : folder) {
      vector<string> path{};
      stringstream ss(f);
      string token{};

      while (getline(ss, token, '/')) {
        if (token != "") {
          path.push_back(token);
        }
      }

      trie.add_folder(path);
    }

    recur(trie.root, "", res);

    return res;
  }

  void recur(TrieNode *node, string path, vector<string> &res) {
    if (node == nullptr)
      return;

    for (auto &[word, child] : node->children) {
      string new_path = path + "/" + word;

      // Add to the paths
      if (child->is_word) {
        res.push_back(new_path);
      }
      // Go down tree
      else {
        recur(child, new_path, res);
      }
    }
  }
};

int main() {
  Solution sol;

  vector<string> folders;
  vector<string> res;

  cout << "testcase 1 :" << endl;
  folders = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
  res = sol.removeSubfolders(folders);

  for (auto &f : res) {
    std::cout << f << std::endl;
  }
  cout << endl;

  cout << "testcase 2 : " << endl;
  folders = {"/a", "/a/b/c", "/a/b/d"};
  res = sol.removeSubfolders(folders);

  for (auto &f : res) {
    cout << f << endl;
  }
  cout << endl;

  return 0;
}