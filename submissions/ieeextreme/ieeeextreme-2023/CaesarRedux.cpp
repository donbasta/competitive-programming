#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    auto shift = [&](vector<string>& words, int sh) {
        for (auto w : words) {
            for (auto c : w) {
                int cur = (c - 'a' + sh) % 26;
                cout << (char)(cur + 'a');
            }
            cout << ' ';
        }
    };

    for (int i = 0; i < n; i++) {
        int sh;
        cin >> sh;
        string st;
        getline(cin, st);
        getline(cin, st);
        bool is_plaintext = false;
        vector<string> words;
        string tmp;
        for (auto c : st) {
            if (c == ' ') {
                words.push_back(tmp);
                tmp = "";
            } else {
                tmp.push_back(c);
            }
        }
        words.push_back(tmp);
        for (auto w : words) {
            if (w == "the") {
                is_plaintext = true;
            }
        }
        if (is_plaintext) {
            shift(words, 26 - sh);
        } else {
            shift(words, sh);
        }
        cout << '\n';
    }
}