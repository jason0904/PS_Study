#include <bits/stdc++.h>
using namespace std;

int t;

int parent[200001];
int s[200001];

map<string, int> m;

int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}


void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(s[a] < s[b]) swap(a, b);
    s[a] += s[b]; //개수
    parent[b] = a;
}

void reset() {
    for(int i = 0; i <= 200000; i++) {
        s[i] = 1;
        parent[i] = i;
    }
    m.clear();
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        reset();
        int p;
        cin >> p;
        int node = 1;
        for(int i = 0; i < p; i++) {
            string name, name2;
            cin >> name >> name2;
            if(m.count(name) == 0) m[name] = node++;
            if(m.count(name2) == 0) m[name2] = node++;
            merge(m[name], m[name2]);
            int p1 = find(m[name]);
            int p2 = find(m[name2]);
            cout << max(s[p1], s[p2]) << "\n";

        }
    }
}