#include <string>
#include <vector>

using namespace std;

string target = "";
string d = "AEIOU";

int cnt = 0;
int answer = 0;

void dfs(string word) {
    if(target == word) answer = cnt;
    else if(word.size() > 5) return;
    cnt++;
    for(int i = 0; i < 5; i++) dfs(word + d[i]);
}

int solution(string word) {
    target = word;
    dfs("");
    return answer;
}