#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin >> c[i];
    }
    int ans = 0;
    for(int i=n-1; i>0; i--){
        if(c[i]!=c[0]){
            ans = max(ans, i);
            break;
        }
    }
    for(int i=0; i<n-1; i++){
        if(c[i]!=c[n-1]){
            ans = max(ans, n-1-i);
            break;
        }
    }
    cout << ans;
}