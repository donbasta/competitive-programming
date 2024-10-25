#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ptr = 0;
    while (ptr < n && s[ptr] == '0') ptr++;
    if (ptr == n) {
        cout << 0 << '\n';
        return;
    }
    string ret = s.substr(ptr, n - ptr);
    int p1 = ptr;
    while (ptr < n && s[ptr] == '1') ptr++;
    if (ptr == n) {
        cout << ret << '\n';
        return;
    }
    int p0 = ptr;

    vector<int> pos_nol, cp;
    for (int i = 0; i < n - p1; i++) {
        if (ret[i] == '0') pos_nol.push_back(i + p1);
    }
    cp = pos_nol;
    assert(!pos_nol.empty());

    int mx_pref = 0;
    vector<int> lmao(pos_nol.size(), '0');
    for (int i = p0 - 1; i >= p1; i--) {
        for (auto& e : pos_nol) {
            e--;
        }
        int x = 0;
        while (x < pos_nol.size() && s[pos_nol[x]] == '1') x++;
        if (x < mx_pref) {
            continue;
        } else if (x > mx_pref) {
            mx_pref = x;
            for (int j = 0; j < pos_nol.size(); j++) {
                lmao[j] = s[pos_nol[j]];
            }
        } else {
            int st = x;
            while (st < pos_nol.size() && lmao[st] == s[pos_nol[st]]) {
                st++;
            }
            if (st == pos_nol.size() || lmao[st] > s[pos_nol[st]]) continue;
            for (int j = 0; j < pos_nol.size(); j++) {
                lmao[j] = s[pos_nol[j]];
            }
        }
    }

    for (int i = 0; i < pos_nol.size(); i++) {
        ret[cp[i] - p1] = lmao[i];
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