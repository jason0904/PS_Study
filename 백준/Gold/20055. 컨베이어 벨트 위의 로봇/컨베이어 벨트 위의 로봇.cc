#include <bits/stdc++.h>
using namespace std;

deque<int> durability;
deque<bool> isRobot;

int n, k;
int rnd = 1;

void rotate() {
    durability.push_front(durability.back());
    durability.pop_back();
    isRobot.push_front(isRobot.back());
    isRobot.pop_back();
    isRobot[n-1] = false;
}

void move() {
    for(int i = n - 2; i >= 0; i--) {
        if(isRobot[i] and !isRobot[i+1] and durability[i+1] > 0) {
            isRobot[i] = false;
            isRobot[i+1] = true;
            durability[i+1] -= 1;
        }
    }
    isRobot[n-1] = false;
}

void update() {
    if(durability[0] > 0) {
        isRobot[0] = true;
        durability[0] -= 1;
    }
}

int cnt() {
    int tmp = 0;
    for(int i = 0; i < 2*n; i++) {
        if(durability[i] == 0) tmp++;
    }
    return tmp;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < 2*n; i++) {
        int tmp;
        cin >> tmp;
        isRobot.push_back(false);
        durability.push_back(tmp);
    }

    while (true) {
        rotate();
        move();
        update();
        if(cnt() >= k) break;
        rnd++;
    }
    cout << rnd << "\n";

}