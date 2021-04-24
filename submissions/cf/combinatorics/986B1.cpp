#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6 + 5;

int ar[N + 5];
bool vis[N + 5];
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        count++;
        vis[i] = true;
        int next = ar[i];
        while (next != i) {
            vis[next] = true;
            next = ar[next];
        }
    }
    int count_swap = n - count;
    if ((count_swap + 3 * n) % 2 == 0) {
        cout << "Petr";
    } else {
        cout << "Um_nik";
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