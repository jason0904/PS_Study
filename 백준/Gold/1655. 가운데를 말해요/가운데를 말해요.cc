#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> maxHeap;
priority_queue<int, vector<int>, greater<>> minHeap;
int n;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(maxHeap.size() <= minHeap.size()) {
            maxHeap.push(tmp);
        }
        else minHeap.push(tmp);
        if(!minHeap.empty() and maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.top() << "\n";
    }
}