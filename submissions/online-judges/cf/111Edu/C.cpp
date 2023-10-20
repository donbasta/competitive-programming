#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            ans++;
        else if (i == n - 2)
            ans += 2;
        else if (ar[i] == ar[i + 1])
            ans += 2;
        else if (ar[i] > ar[i + 1]) {
            if (ar[i + 1] >= ar[i + 2])
                ans += 2;
            else if (ar[i + 1] < ar[i + 2] && ar[i + 2] <= ar[i])
                ans += 3;
            else if (ar[i + 2] > ar[i]) {
                if (i + 3 >= n)
                    ans += 3;
                else if (ar[i + 3] >= ar[i + 2] || ar[i + 3] <= ar[i + 1])
                    ans += 3;
                else
                    ans += 4;
            }
        } else if (ar[i] < ar[i + 1]) {
            if (ar[i + 1] <= ar[i + 2])
                ans += 2;
            else if (ar[i + 1] > ar[i + 2] && ar[i + 2] >= ar[i])
                ans += 3;
            else if (ar[i + 2] < ar[i]) {
                if (i + 3 >= n)
                    ans += 3;
                else if (ar[i + 3] <= ar[i + 2] || ar[i + 3] >= ar[i + 1])
                    ans += 3;
                else
                    ans += 4;
            }
        }
    }
    cout << ans << '\n';
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