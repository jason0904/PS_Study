#include <bits/stdc++.h>
using namespace std;

int parent[201];

int n, m;
int start;

int find(int x) {
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(x < y) parent[y] = x;
    else parent[x] = y;
}


int main(void) {
    for(int i=1; i<=200; i++) parent[i] = i;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int tmp;
            cin >> tmp;
            if(tmp == 1) Union(i, j);
        }
    }
    cin >> start;
    start = find(start);
    for(int i = 1; i < m; i++) {
        int tmp;
        cin >> tmp;
        if(find(tmp) != start) {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    return 0;
}