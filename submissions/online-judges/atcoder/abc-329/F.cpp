#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        --c[i];
    }
    vector<int> label(n);
    iota(label.begin(), label.end(), 0);
    vector<map<int, int>> cont(n);
    for (int i = 0; i < n; i++) {
        cont[i][c[i]]++;
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (cont[label[a]].size() > cont[label[b]].size()) {
            swap(label[a], label[b]);
        }
        for (auto c : cont[label[a]]) {
            cont[label[b]][c.first] += c.second;
        }
        cont[label[a]].clear();
        cout << cont[label[b]].size() << '\n';
    }
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