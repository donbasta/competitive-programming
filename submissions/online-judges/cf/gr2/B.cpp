#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n,h;
    cin >> n >> h;
    vector<int> ve(n);
    for(int i=0; i<n; i++){
        cin >> ve[i];
    }
    int cur = h;
    int ans;
    for(int i=0; i<n; i+=2){
        if(i<n-1){
            if(max(ve[i],ve[i+1])<=cur){
                ans = i+1;
                cur -= max(ve[i],ve[i+1]);
            } else if(ve[i]<=cur){
                ans = i;
                break;
            } else break;
        } else {
            if(ve[i]<=cur){
                ans = i; break;
            }
        }
    }
    cout << ans+1;

}