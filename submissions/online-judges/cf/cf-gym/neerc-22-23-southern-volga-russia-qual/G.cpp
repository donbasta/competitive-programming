#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    multiset<int> se;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        se.insert(x);
    }
    for (int i = 0; i < n - 1; i++) {
        int a = *se.begin();
        int b = *(--se.end());
        se.erase(se.begin());
        se.erase((--se.end()));
        se.insert((a + b) / 2);
    }
    assert(se.size() == 1);
    cout << (*se.begin()) << '\n';
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