#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001];
vector<int> two;

int main(void) {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      two.push_back(a[i] + a[j]);
    }
  }
  sort(two.begin(), two.end());
  for(int i = n-1; i > 0; i--) {
    for(int j = 0; j < i; j++) {
      if(binary_search(two.begin(), two.end(), a[i] - a[j])) {
       cout << a[i] << "\n";
       return 0;
      }
    }
  }
}