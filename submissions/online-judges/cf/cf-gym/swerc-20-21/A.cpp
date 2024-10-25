#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    map<string, int> cnt, last;
    string tmp;
    getline(cin, tmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            string s;
            getline(cin, s);
            cnt[s]++;
            last[s] = i * 3 + j;
        }
    }
    vector<string> ret;
    for (auto e : cnt) {
        ret.push_back(e.first);
    }
    sort(ret.begin(), ret.end(), [&](const string& p, const string& q) -> bool {
        if (cnt[p] == cnt[q]) {
            return last[p] > last[q];
        }
        return cnt[p] > cnt[q];
    });
    for (int i = 0; i < min(k, (int)ret.size()); i++) {
        cout << ret[i] << '\n';
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