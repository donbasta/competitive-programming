#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    string s;
    cin >> s;
    vector<pair<int, char>> s1, s2;
    int idx = 0;
    for (auto c : s) {
        if (c == 'B') {
            if (!s1.empty()) s1.pop_back();
        } else if (c == 'b') {
            if (!s2.empty()) s2.pop_back();
        } else if (c >= 'A' && c <= 'Z') {
            s1.emplace_back(idx++, c);
        } else {
            s2.emplace_back(idx++, c);
        }
    }
    int i = 0, j = 0;
    string ret;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i].first < s2[j].first) {
            ret.push_back(s1[i].second);
            i++;
        } else {
            ret.push_back(s2[j].second);
            j++;
        }
    }
    while (i < s1.size()) {
        ret.push_back(s1[i].second);
        i++;
    }
    while (j < s2.size()) {
        ret.push_back(s2[j].second);
        j++;
    }
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}