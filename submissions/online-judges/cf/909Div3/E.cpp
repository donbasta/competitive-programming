#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    int mn = *min_element(ve.begin(), ve.end());
    int ptr = 0;
    while (ve[ptr] != mn) ptr++;
    vector<int> tmp, ctmp;
    for (int i = ptr; i < n; i++) {
        tmp.push_back(ve[i]);
    }
    ctmp = tmp;
    sort(ctmp.begin(), ctmp.end());
    if (ctmp != tmp) {
        cout << -1 << '\n';
        return;
    }
    cout << ptr << '\n';
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