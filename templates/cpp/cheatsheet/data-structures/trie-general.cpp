#include <bits/stdc++.h>
using namespace std;

struct Trie {
    bool isLeaf;
    unordered_map<char, Trie*> map;
};

// Function that returns a new Trie node
Trie* getNewTrieNode() {
    Trie* node = new Trie;
    node->isLeaf = false;

    return node;
}

void insert(Trie*& head, char* str) {
    if (head == nullptr)
        head = getNewTrieNode();

    Trie* curr = head;
    while (*str) {
        if (curr->map.find(*str) == curr->map.end())
            curr->map[*str] = getNewTrieNode();
        curr = curr->map[*str];
        str++;
    }
    curr->isLeaf = true;
}

bool haveChildren(Trie const* curr) {
    for (auto it : curr->map)
        if (it.second != nullptr)
            return true;
    return false;
}

bool search(Trie* head, char* str) {
    if (head == nullptr)
        return false;

    Trie* curr = head;
    while (*str) {
        curr = curr->map[*str];

        if (curr == nullptr)
            return false;

        str++;
    }

    return curr->isLeaf;
}