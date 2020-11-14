#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll a, b;
string sa, sb;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    {
        cin >> sa >> sb;
        assert(sa.size() <= 17 && sb.size() <= 17);
        // cin >> a >> b;
        a = stoll(sa);
        b = stoll(sb);
        assert(a > 0 && b > 0);
    }
    ll ans = 0;
    bool allb = 1;
    for (auto x : sb){
        if (x != '9') allb = 0;
    }
    if (!allb) ans = a * ((int)sb.size() - 1);
    else ans = a * ((int)sb.size());
    cout << ans << el;

    return 0;
}