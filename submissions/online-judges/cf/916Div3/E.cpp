#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ll score = 0;
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    map<int, vector<int>> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] != 0 && B[i] != 0) {
            mp[-(A[i] + B[i])].emplace_back(A[i]);
            cnt++;
        }
        score += A[i] - B[i];
    }
    for (auto& e : mp) {
        sort(e.second.begin(), e.second.end());
    }
    int turn = 1;
    for (auto e : mp) {
        int sz = e.second.size();
        int l = 0, r = sz - 1;
        while (l <= r) {
            if (turn == 1) {
                int b = (-e.first) - e.second[l];
                score += (b - 1);
                l++;
            } else {
                int a = e.second[r];
                score -= (a - 1);
                r--;
            }
            turn ^= 1;
        }
    }
    cout << score << '\n';
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