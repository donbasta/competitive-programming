#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;
bool dp[N + 5];

vector<int> sq = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};

void solve() {
    int n;
    cin >> n;
    if (n == 2 || n == 3 || n == 5) {
        cout << 4 << '\n';
    } else {
        cout << 3 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}