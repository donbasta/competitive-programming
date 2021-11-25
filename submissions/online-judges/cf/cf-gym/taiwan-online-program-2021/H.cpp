#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct query {
    int t, u, i, v, j;
};

bool is_possible(vector<int>& vals, vector<pair<int, int>>& edges, vector<query>& restriction) {
    int n = vals.size();
    int m = edges.size();
    // check
    
}

void solve() {
    int x = 60091;
    int y = 51514;
    cout << x ^ y << '\n';
    bitset<16> u(x);
    bitset<16> v(y);
    cout << u << ' ' << v << '\n';
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