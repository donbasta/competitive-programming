#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    long long n,m;
    cin >> n >> m;

    long long ans = 8*(m+n-4)+2*(m-2)*(m-3)+2*(n-2)*(n-3);
    cout << ans << '\n';
}