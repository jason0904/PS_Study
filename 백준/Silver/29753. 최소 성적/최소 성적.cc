#include <bits/stdc++.h>
using namespace std;

int n, ans;
string tmp;
int tmp2;
int tmp6;
int tmpans;

map<string,int> m;
string arr[9] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};

int main(void) {
    m.insert({"A+", 450});
    m.insert({"A0", 400});
    m.insert({"B+", 350});
    m.insert({"B0", 300});
    m.insert({"C+", 250});
    m.insert({"C0", 200});
    m.insert({"D+", 150});
    m.insert({"D0", 100});
    m.insert({"F", 0});
    cin >> n >> tmp;
    tmp.erase(1, 1);
    ans = stoi(tmp);
    for(int i = 0; i < n-1; i++) {
        int tmp3;
        string tmp4;
        cin >> tmp3 >> tmp4;
        tmp2 += tmp3;
        tmp6 += tmp3 * m[tmp4];
    }
    int tmp5;
    cin >> tmp5;
    tmp2 += tmp5;
    for(int i = 8; i >= 0; i--) {
        int tmp7 = (tmp6 + tmp5 * m[arr[i]]) / tmp2;
        string tmpstr2 = to_string(tmp7);
        tmpstr2 = tmpstr2.substr(0,3);
        tmp7 = stoi(tmpstr2);
        if(ans < tmp7) {
            cout << arr[i] << "\n";
            return 0;
        }
    }
    cout << "impossible" << "\n";
}