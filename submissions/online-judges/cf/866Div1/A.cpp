#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    set<int> se;
    map<int, int> fi, la;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        se.insert(ar[i]);
        if (!fi.count(ar[i])) {
            fi[ar[i]] = i;
        }
        la[ar[i]] = i;
    }
    int mex = 0;
    while (se.count(mex)) mex++;
    if (!se.count(mex + 1)) {
        if (mex == n) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
        return;
    }
    for (int i = 0; i < mex; i++) {
        if (fi[i] > fi[mex + 1] && la[i] < la[mex + 1]) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
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