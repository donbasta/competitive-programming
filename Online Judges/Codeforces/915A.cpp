#include <bits/stdc++.h>

using namespace std;

int main(){

    map<int,int> mp;
    string a,b,ans;
    int top, cur;
    bool var, less;

    cin>>a>>b;

    if(a.length()<b.length()){
        sort(a.rbegin(),a.rend());
        cout << a;
    } else {
        for(auto i : a){
            mp[i-'0']++;
        }
        for(auto i : b){
            top = i-'0';
            var = false;
            less = false;
            if(mp[top]){
                mp[top]--;
                var = true;
                ans += (char) (top+48);
            } else {
                for(int j = top-1; j >= 0; j--){
                    if(mp[j]){
                        mp[j]--;
                        var = true;
                        less = true;
                        ans += (char) (j+48);
                        break;
                    }
                }
            }
            if(less){
                break;
            }
            if(!var){
                cur = (int) ans.length();
                mp[ans[cur-1]-'0']++;
                ans = ans.substr(0,cur-1);
                break;
            }
        }

        if(!var){
            bool found = false;
            while(cur>=1 && !found){
                top = b[cur-1]-'0';
                for(int j = top-1; j >= 0; j--){
                    if(mp[j]){
                        mp[j]--;
                        var = true;
                        ans += (char) (j+48);
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cur--;
                    mp[ans[cur-1]-'0']++;
                    ans = ans.substr(0,cur-1);
                }
            }
        }

        for(int i=9; i>=0; i--){
            if(mp[i]){
                for(int j=0; j<mp[i]; j++){
                    ans += (char) (i+48);
                }
            }
        }
        
        cout << ans;
    }
}