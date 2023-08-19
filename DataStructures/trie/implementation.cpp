#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

// characters are only lowercase latin letters
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        for (int i=0;i<26;i++) this->children[i] = NULL;
        this->isTerminal = false;
    }

    bool isEmpty() {
        for (int i=0;i<26;i++) {
            if (this->children[i] != NULL) return false;
        }
        return true;
    }

};

class Trie {
private:
    void insertUtil(TrieNode* root, string& word, int i) {
        if (i==word.length()) {
            root->isTerminal = true;
            return;
        }
        // assumption => all characters are in CAPS
        int index = word[i] - 'A';
        TrieNode* child;
        if (root->children[index] != NULL) {
            // present
            child = root->children[index];
        }
        else {
            //absent
            child = new TrieNode(word[i]);
            root->children[index] = child;
        }
        insertUtil(child, word, i+1);
        return;
    }

    bool searchUtil(TrieNode* root, string& word, int i) {
        if (i==word.length()) {
            return root->isTerminal;
        }
        int index = word[i] - 'A';
        if (root->children[index] != NULL) {
            return searchUtil(root->children[index], word, i+1);
        }
        return false;
    }

    TrieNode* removeWordUtil(TrieNode* nd, string& word, int i) {
        if (nd == NULL) {
            // word is not in trie
            return NULL;
        }
        if (i==word.length()) {
            nd->isTerminal = false;
            if (nd->isEmpty()) {
                delete nd;
                nd = NULL;
            }
            return nd;
        }
        int index = word[i] - 'A';
        nd->children[index] = removeWordUtil(nd->children[index], word, i+1);
        // If its children are removed and it is note the end of some other word
        if (nd->isEmpty() and !(nd->isTerminal)) {
            delete nd;
            nd = NULL;
        }
        return nd;
    }

public:
    TrieNode* root;
    Trie() {
        // insert a null character in root node, because that is not an important node for storage of data
        root = new TrieNode('\0');
    }
    // O(length of word)
    void insertWord(string word) {
        insertUtil(this->root, word, 0);
    }
    // O(length of word)
    bool searchWord(string word) {
        return searchUtil(this->root, word, 0);
    }
    // O(length of word)
    void removeWord(string word) {
        removeWordUtil(this->root, word, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Implemented for using a dictionary (english dictionary)
    // Three operations -> addword, removeword, searchWord
    Trie* t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("ABC");
    cout << t->searchWord("ABCD") << endl;
    cout << t->searchWord("ABC") << endl;
    t->removeWord("ABCD");
    cout << t->searchWord("ABCD") << endl;
    cout << t->searchWord("ABC") << endl;
    return 0;
}