/*
 * Description:
 * Implementation for Trie data structure.
 *
 * Created on: 18/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

class TrieNode {
  public:
  TrieNode *data[26];
  bool wordEnd;

  explicit TrieNode()
  {
    wordEnd = false;
    for (auto &i : data) {
      i = nullptr;
    }
  }

  bool IsEmpty()
  {
    for (auto &i : data) {
      if (i != nullptr) {
        return false;
      }
    }
    return true;
  }
};

class Trie {
  public:
  TrieNode *root;
  Trie()
  {
    root = new TrieNode();
  }

  void Insert(const std::string& word)
  {
    TrieNode *cur = root;
    //Process character by character in string word.
    for (auto &c : word) {
      if (cur->data[c - 'a'] == nullptr) {
        cur->data[c - 'a'] = new TrieNode();
      }
      cur = cur->data[c - 'a'];
    }
    //When the word completes, set flag to indicate its end.
    cur->wordEnd = true;
  }

  bool Delete(std::string& word)
  {
    TrieNode* res = Delete(root, word, 0);
    if (res == nullptr) {
      return false;
    }
    return true;
  }

  TrieNode* Delete(TrieNode* node, std::string& word, int index)
  {
    if (node == nullptr) {
      return nullptr;
    }

    if (index ==  word.length()) {
      //If word is found.
      if (node->wordEnd == true) {
        //set end node to false.
        node->wordEnd = false;
      }

      //Check if any child nodes are present.
      if (node->IsEmpty()) {
        delete node;
        node = nullptr;
      }
      return node;
    }

    //If end node is not reached, move to next character node.
    char c = word[index];
    node->data[c - 'a'] = Delete(node->data[c - 'a'], word, index + 1);

    //While traversing back, if node has no child (cause it got deleted), delete it.
    if ((node->wordEnd == false)  && (node->IsEmpty())) {
      delete node;
      node = nullptr;
    }
    return node;
  }

  bool Search(const std::string& word)
  {
    TrieNode *cur = root;
    for (auto &c : word) {
      if (cur->data[c - 'a'] == nullptr) {
        return false;
      }
      cur = cur->data[c - 'a'];
    }
    //If the last character is not the marked end, return false.
    //Eg if we have inserted only word as AND.
    //But if we search word 'an' in database, it will be found.
    //But because at character 'n' the node is not marked 'end', it should return false.
    return cur->wordEnd;
  }
};

void Test_Trie()
{
  Trie trie;

  //Insert words into trie.
  trie.Insert("and");
  trie.Insert("ant");
  trie.Insert("jaspreet");
  trie.Insert("antartica");
  trie.Insert("andaman");
  trie.Insert("done");

  //Test word search.
  std::vector<std::string> sWords = {
    "ant", "an", "jaspreet", "do", "don", "done",  "abcd"
  };
  for (auto &word : sWords) {
    if (trie.Search(word)) {
      std::cout << "Word: '" << word << "' is present in the database!!!" << std::endl;
    } else {
      std::cout << "Word: '" << word << "' is not present in the database!!!" << std::endl;
    }
  }

  //Test delete
  std::vector<std::string> dWords = {"ant", "an"};
  for (auto &word : dWords) {
    std::cout << "Deleting word : '" << word << "'." << std::endl;
    if (trie.Delete(word) == false) {
      std::cout << "Delete failed!!!\n";
    } else {
      std::cout << "Delete successful or deletion skipped for word that was not present in DB!!!\n";
    }
  }

  //We have attempted to delete words 'ant' and 'an'. Check 'and' is safe in DB.
  sWords = { "ant", "an", "and"};
  for (auto &word : sWords) {
    if (trie.Search(word)) {
      std::cout << "Word: '" << word << "' is present in the database!!!" << std::endl;
    } else {
      std::cout << "Word: '" << word << "' is not present in the database!!!" << std::endl;
    }
  }
}
