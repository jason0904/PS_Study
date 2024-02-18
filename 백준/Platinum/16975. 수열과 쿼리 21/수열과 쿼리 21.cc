#include <bits/stdc++.h>
using namespace std;

long long tree[100001];
long long arr[100001];
int n, m;

long long sum(int i) {
    long long ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, long long num) {
    while(i <= n) {
        tree[i] += num;
        i += (i & -i);
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    cin >> arr[1];
    update(1, arr[1]);
    for(int i = 2; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i] - arr[i-1]);
    }
    cin >> m;
    for(int tmp = 0; tmp < m; tmp++) {
        int query;
        cin >> query;
        if(query == 1) {
            int i,j;
            long long k;
            cin >> i >> j >> k;
            update(i,k);
            update(j+1,-k);
        }
        else {
            int x;
            cin >> x;
            cout << sum(x) << "\n";
        }
    }
}