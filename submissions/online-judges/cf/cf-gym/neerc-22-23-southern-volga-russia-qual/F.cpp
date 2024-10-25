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

    int ret = 0;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    int la = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            if (la == -1) la = i;
        } else {
            if (la != -1) {
                vector<int> tmp;
                for (int j = la; j >= i; j--) {
                    ret += ve[j];
                    tmp.push_back(ve[j]);
                }
                ret -= *min_element(tmp.begin(), tmp.end());
                la = -1;
            }
        }
    }
    if (la != -1) {
        for (int i = 0; i <= la; i++) {
            ret += ve[i];
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