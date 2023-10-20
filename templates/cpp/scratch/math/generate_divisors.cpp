#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void generateDivisors(int curIdx, int curDiv, const vector<pair<int, int>>& ar, vector<int>& div) {
    if (curIdx == ar.size()) {
        div.emplace_back(curDiv);
        return;
    }
    for (int i = 0; i <= ar[curIdx].second; i++) {
        generateDivisors(curIdx + 1, curDiv, ar, div);
        curDiv *= ar[curIdx].first;
    }
}

void solve() {
    vector<pair<int, int>> p = {{2, 3}, {3, 2}, {7, 1}};
    vector<int> d;
    generateDivisors(0, 1, p, d);
    for (auto& e : d) cout << e << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}