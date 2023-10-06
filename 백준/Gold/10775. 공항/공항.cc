#include <bits/stdc++.h>
using namespace std;

int tree[100001];

int find(int n){
    if(n == tree[n]) return n;
    return tree[n] = find(tree[n]);
}

int main(void) {
    int cnt = 0;
    int g,p;
    cin >> g >> p;
    for(int i = 1; i <= g; i++) {
        tree[i] = i;
    }
    for(int i = 0; i < p; i++) {
        int tmp;
        cin >> tmp;
        if(!find(tmp)) break;
        else {
            cnt++;
            tree[find(tmp)] = find(find(tmp) - 1);
        }
    }
    cout << cnt;
}
