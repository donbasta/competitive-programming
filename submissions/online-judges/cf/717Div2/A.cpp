#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 105;

int ar[N];
int n, k;

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int sum = 0;
    int idx = 0;
    while (idx < n - 1 && sum < k) {
        if (sum + ar[idx] < k) {
            sum += ar[idx];
            ar[idx] = 0;
            idx++;
        } else {
            ar[idx] -= (k - sum);
            sum = k;
        }
    }
    ar[n - 1] += sum;
    for (int i = 0; i < n; i++) {
        cout << ar[i] << ' ';
    }
    cout << '\n';
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