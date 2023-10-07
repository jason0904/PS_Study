#include <bits/stdc++.h>
using namespace std;

int tree[10000];

void postorder(int start, int end) {
  if(start >= end) return;
  else if(start == end - 1) {
    cout << tree[start] << "\n";
    return;
  }
  int idx = start + 1;
  while(idx < end) {
    if(tree[start] < tree[idx]) break;
    idx++;
  }
  postorder(start + 1, idx);
  postorder(idx, end);
  cout << tree[start] << "\n";
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  int idx;
  while(cin >> n) {
    tree[idx++] = n;
  }
  postorder(0, idx);
  return 0;
}