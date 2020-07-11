#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int tc;
    cin >> tc;
    while(tc--){
        int x,n,m;
        cin >> x >> n >> m;
        while(x>0 && n>0 && x>(x/2+10)){
            x = x/2+10;
            n--;
        }
        while(x>0 && m>0){
            x -= 10;
            m--;
        }
        cout << ((x<=0) ? "YES" : "NO");
        cout << "\n";
    }
    

}