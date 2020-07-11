#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n,m;
    cin >> n >> m;
    int a[n+5];

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    int ans = 1e9;
    for(int i=1; i<=n-m+1; i++){
        ans = min(ans, a[i+m-1]-a[i]);
    }

    cout << ans << '\n';
}