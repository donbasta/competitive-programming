#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

class Node {
   public:
    Node* left;
    Node* right;
    int val;
};

string serialize(Node* node) {
    // if node is empty or null, we serialize it as a string consisting of a special character ‘?’
    if (!node) {
        return "?";
    }

    return to_string(node->val) + ',' + serialize(node->left) + ',' + serialize(node->right);
}

Node* deserialize(std::string bytes) {
    int current_pos = 0;
    const function<Node*(void)> recurse = [&]() -> Node* {
        if (current_pos >= bytes.length()) {
            return nullptr;
        }

        int next_separator_pos = bytes.find_first_of(',', current_pos);
        if (next_separator_pos == std::string::npos) {
            next_separator_pos = bytes.length();
        }
        std::string root_val = bytes.substr(current_pos, next_separator_pos - current_pos);
        current_pos = next_separator_pos + 1;
        if (root_val == "?") {
            return nullptr;
        }

        // create the resulting Node, recurse for its left and right children.
        // after every call to the recurse function, the current_pos will be positioned to the next unprocessed bytes.
        int val = stoi(root_val);
        Node* root = new Node();
        root->val = val;
        root->left = recurse();
        root->right = recurse();
        return root;
    };

    return recurse();
}

void solve() {
    string test = "4,18,?,29,35,?,?,6,?,?,11,?,15,?,?";
    bool hehe = serialize(deserialize(test)) == test;
    cout << hehe << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}