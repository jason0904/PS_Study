#include <bits/stdc++.h>
using namespace std;

int n, m, k;

void update(vector<long long> &tree, int i, long long num) {
    while(i <= tree.size()) {
        tree[i] += num;
        i += (i & -i);
    }
}

long long sum(vector<long long> &tree, int i) {
    long long ans = 0;
    while(i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

int main(void) {
    cin >> n >> m >> k;
    vector<long long> a(n+1);
    vector<long long> tree(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(tree, i, a[i]);
    }
    for(int i = 0; i < m+k; i++) {
        int tmp1, tmp2;
        long long tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        if(tmp1 == 1) {
            long long diff = tmp3 - a[tmp2];
            a[tmp2] = tmp3;
            update(tree, tmp2, diff);
        }
        else if(tmp1 == 2) {
            cout << sum(tree, (int)tmp3) - sum(tree, tmp2-1) << "\n";
        }
    }
}