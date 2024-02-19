#include <bits/stdc++.h>
using namespace std;

int tree[500001];
int n, m;

int Xor (int i) {
    int ans = 0;
    while (i > 0) {
        ans ^= tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, int num) {
    while(i <= n) {
        tree[i] ^= num;
        i += (i & -i);
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        update(i + 1, tmp);
        update(i + 2, tmp);
    }
    cin >> m;
    for(int tmp = 0; tmp < m; tmp++) {
        int query;
        cin >> query;
        if(query == 1) {
            int i,j,k;
            cin >> i >> j >> k;
            update(i + 1,k);
            update(j + 2,k);
        }
        else {
            int x;
            cin >> x;
            cout << Xor(x + 1) << "\n";
        }
    }
}