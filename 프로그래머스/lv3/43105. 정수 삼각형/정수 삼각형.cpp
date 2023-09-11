#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int board[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i = 0; i < triangle.size(); i++) {
        for(int j = 0; j < i+1; j++) board[i][j] = triangle[i][j];
    }
    for(int i = 1; i < triangle.size(); i++) {
        for(int j = 0; j < i+1; j++) {
            if(j == 0) board[i][j] += board[i-1][j];
            else board[i][j] += max(board[i-1][j], board[i-1][j-1]);
            }
    }
        for(int i = 0; i < triangle.size(); i++) {
            for(int j = 0; j < i+1; j++) answer = max(answer, board[i][j]);
    }
    return answer;
}