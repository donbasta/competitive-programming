#include <bits/stdc++.h>
using namespace std;

int n, a, b, a1, b1, a2, b2;

void ask(int t){
    cout << "+ " << t << endl;
}

int get(int inc){
    int x = (sqrt(8*inc+1)+1)/2;
    return x;
}

int main(){

    cin >> n >> a >> b;
    vector<int> v1, v2;
    vector<int> ans(n+1, -1);

    if(n==4){
  
    }

    for(int i = 2; i <= n; i += 3){
        ask(i);
        cin >> a1 >> b1;
        ask(i);
        cin >> a2 >> b2;
        if(b1==0 && b2==0){
            ans[i] = 0;
        } else {
            ans[i] = get(b1-b);
        }
        v1.push_back(a2-a1);
        a = a2;
        b = b2;
    }

    ask(1);
    cin >> a1 >> b1;
    ans[3] = (a1-a)/(ans[2]+2);
    a = a1; b = b1;

    for(int i = 4; i <= n-2; i += 3){
        ask(i);
        cin >> a1 >> b1;
        ans[i+2] = (a1-a-(ans[i-2]+ans[i+1]+4)*(ans[i-1]+1))/(ans[i+1]+2);
        a = a1; b = b1;
    }

    if(n % 3 == 1){
        ask(3);
        cin >> a1 >> b1;
        int temp = v1[0]/ans[3];
        int inc = a1-a;
        inc -= (2*ans[2]+ans[5]+6);
        inc -= (ans[2]+2) * temp;
        ans[4] = inc/(ans[5]+2);
        ans[1] = temp - ans[4];
        for(auto )
    } else if(n % 3 == 2) {
        
    } else if(n % 3 == 0) {

    }




    

}