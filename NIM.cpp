#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a[26];
stack<int> Stack;
bool visited[26];

void topologicalSortUtil(int v, bool visited[], stack<int> &Stack){
    visited[v] = true;
    for (int i = 0; i != a[v].size(); ++i){
        if (!visited[a[v][i]])
            topologicalSortUtil(a[v][i], visited, Stack);}
    Stack.push(v);
}

void topologicalSort(){
    for (int i = 0; i < 26; i++){
      if (!visited[i]){
        topologicalSortUtil(i, visited, Stack);}}
}

int main(){
    cin >> n;
    string s[n];

    for(int i=0; i<n; ++i){
        cin >> s[i];}

    for(int i=0; i<n; ++i){
        visited[i] = false;}

    for(int i=0; i<n-1; ++i){
        int j=0;
        while((s[i][j] == s[i+1][j]) && (j-1 < min(s[i].length(), s[i+1].length())) ){
            j++;
        }
        int p = s[i][j] - 'a';
        int q = s[i+1][j] - 'a';
        a[p].push_back(q);
    }

        topologicalSort();

        while (!Stack.empty()){
            char s = char(Stack.top() + 97);
            cout << s;
            Stack.pop();
        }
    }
