#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n), cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
    }
    vector<int> br;
    int mex = -1;
    for (int i = 0; i <= n; i++) {
        if (cnt[i] == 0) {
            mex = i;
            break;
        }
    }
    if (mex == 0) {
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }
    set<int> se;
    int tmp = mex;
    for (int i = 0; i < n; i++) {
        if (ar[i] < mex) {
            cnt[ar[i]]--;
            if (cnt[ar[i]] == 0) tmp = min(tmp, ar[i]);
            se.insert(ar[i]);
        }
        if (se.size() == mex) {
            br.push_back(mex);
            mex = tmp;
            se.clear();
        }
    }
    cout << br.size() << '\n';
    for (auto e : br) {
        cout << e << ' ';
    }
    cout << '\n';
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