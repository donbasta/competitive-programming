#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    string t;
    cin >> n >> t;
    vector<int> id;

    int nt = t.length();
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int ns = s.length();
        if (ns < nt - 1 || ns > nt + 1) continue;
        int ptr = 0;
        while (ptr < min(ns, nt) && s[ptr] == t[ptr]) ptr++;
        if (ptr == min(ns, nt)) {
            id.push_back(i + 1);
            continue;
        }
        if (ns == nt) {
            ptr++;
            while (ptr < ns && s[ptr] == t[ptr]) ptr++;
        } else if (ns > nt) {
            while (ptr < nt && s[ptr + 1] == t[ptr]) ptr++;
        } else if (ns < nt) {
            while (ptr < ns && t[ptr + 1] == s[ptr]) ptr++;
        }
        if (ptr == min(ns, nt)) {
            id.push_back(i + 1);
        }
    }
    cout << id.size() << '\n';
    for (auto e : id) {
        cout << e << ' ';
    }
    cout << '\n';
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