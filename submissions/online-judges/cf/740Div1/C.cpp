#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2021;
int ar[N + 10], pos[N + 10];
int n;

void swap(int pr) {
    for (int i = 1; i < pr + 1 - i; i++) {
        swap(ar[i], ar[pr + 1 - i]);
    }
    for (int j = 1; j <= n; j++) {
        pos[ar[j]] = j;
    }
}

void solve() {
    cin >> n;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        ok &= ((ar[i] % 2) == (i % 2));
    }
    if (!ok) {
        cout << -1 << '\n';
        return;
    }
    vector<int> moves;
    for (int i = n; i > 1; i -= 2) {
        for (int j = 1; j <= i; j++) {
            pos[ar[j]] = j;
        }
        moves.emplace_back(pos[i]);
        swap(pos[i]);
        if (ar[2] == i - 1) {
            swap(i);
            moves.emplace_back(i);
            continue;
        }
        moves.emplace_back(pos[i - 1] - 1);
        swap(pos[i - 1] - 1);
        moves.emplace_back(pos[i - 1] + 1);
        swap(pos[i - 1] + 1);
        moves.emplace_back(3);
        swap(3);
        moves.emplace_back(i);
        swap(i);
    }
    cout << (int) moves.size() << '\n';
    for (auto e : moves) {
        cout << e << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}