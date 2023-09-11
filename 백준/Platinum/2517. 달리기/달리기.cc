#include <bits/stdc++.h>
using namespace std;


int tree[500005];
int n, x;
vector<pair<int, int>> v;

int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, int num) {
    while (i <= n) {
        tree[i] += num;
        i += (i & -i);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back({x, i+1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        v[i].first = i + 1;
        swap(v[i].first, v[i].second);
    }
    sort(v.begin(), v.end());
    fill(tree, tree + 500005, 0);
    for (int i = 0; i < n; i++) {
        int temp = v[i].second;

        cout << (i + 1) - sum(temp - 1) << "\n";
        update(temp, 1);
    }
}