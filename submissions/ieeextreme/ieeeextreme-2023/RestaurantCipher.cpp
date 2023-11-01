#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

vector<string> process_line_remove_space(string s) {
    vector<string> words;
    string tmp;
    for (auto c : s) {
        if (c == ' ') {
            words.push_back(tmp);
            tmp = "";
        } else {
            tmp.push_back(c);
        }
    }
    words.push_back(tmp);
    return words;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    string buf;
    getline(cin, buf);
    for (int i = 0; i < n; i++) {
        getline(cin, buf);
        int t = 0;
        int len = 0;
        for (auto x : buf) {
            if (x == ' ') continue;
            t = (t + x) % 7;
            len = (len + 1) % 7;
        }
        cout << t << ' ' << len << '\n';
        // vector<int> words = process_line_remove_space(buf);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}