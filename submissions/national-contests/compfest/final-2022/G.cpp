#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

int ask(int x) {
    cout << "? " << x << endl;
    int y;
    cin >> y;
    return y;
}

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        int a = ask(1);
        int b = ask(2);
        int k = 1;
        if (a == 0 && b == 0)
            k = 0;
        else if (a == 1 && b == 1)
            k = 2;
        cout << "! " << k << endl;
        return;
    }
    int p1 = ask(1);
    int p2 = ask(2);
    int p3 = ask(3);
    int a = p2 - p1;
    int b = p3 - p2;
    int k = (b - a) / 2;
    cout << "! " << k << endl;
    return;
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}