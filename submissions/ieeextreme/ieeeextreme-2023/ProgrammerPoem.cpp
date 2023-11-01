#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

char lowercase(char c) {
    if (c >= 'a' && c <= 'z') return c;
    return c - 'A' + 'a';
}

vector<string> process_line(string s) {
    vector<string> words;
    string tmp;
    for (auto c : s) {
        if (c == ' ') {
            words.push_back(tmp);
            tmp = "";
        } else {
            tmp.push_back(lowercase(c));
        }
    }
    words.push_back(tmp);
    return words;
}

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> ump;
    string st;
    getline(cin, st);
    for (int i = 0; i < n; i++) {
        getline(cin, st);
        vector<string> words = process_line(st);
        for (auto word : words) {
            ump[word] = i;
        }
    }

    string buf;
    getline(cin, buf);
    string ret(m, 'X');
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < m; i++) {
        getline(cin, buf);
        vector<string> words = process_line(buf);
        assert(!words.empty());
        string w = words.back();
        if (!ump.count(w)) continue;
        pos[ump[w]].push_back(i);
    }
    vector<vector<int>> ve;
    for (auto e : pos) {
        ve.push_back(e.second);
    }
    sort(ve.begin(), ve.end(), [&](const vector<int>& a, const vector<int>& b) -> bool {
        return a[0] < b[0];
    });
    int cur = 0;
    for (auto e : ve) {
        if (e.size() == 1) continue;
        for (auto x : e) {
            ret[x] = cur + 'A';
        }
        cur = (cur + 1) % 26;
        if (cur == 23) {
            cur = (cur + 1) % 26;
        }
    }
    cout << ret << '\n';
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