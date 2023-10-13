#include <cstdio>
#include <cstring>
int N;
char CMD[10000 + 2];
int px, py;

int W;
int wall[25 + 2][25 + 2];
int Z;

struct _st
{
    int x, y;
    int type;
    char dir;
    int speed;
};
_st ZOMBI[625 + 2];
int zpos[25 + 2][25 + 2];
int D;
int dead_day;


// dir
// 상 우 하 좌
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };
int dir_op[4] = { 2, 3, 0, 1 };


void input()
{
    scanf("%d", &N);
    scanf("%s", &CMD);
    scanf("%d %d", &px, &py);
    scanf("%d", &W);
    for (int i = 0; i < W; i++) {
        int wx = 0, wy = 0;
        scanf("%d %d", &wx, &wy);
        wall[wx][wy] = 1;
    }
    scanf("%d", &Z);
    for (int i = 1; i <= Z; i++) {	// 사실 이거 처음에 숫자로 바꿔주면 char -> int, int -> char 할 필요 없음
        scanf("%d %d %d %c %d", &ZOMBI[i].x, &ZOMBI[i].y, &ZOMBI[i].type, &ZOMBI[i].dir, &ZOMBI[i].speed);
    }
    scanf("%d", &D);
}

void move_player(char dir)
{
    int ndir = -1;

    if (dir == 'U') ndir = 0;
    else if (dir == 'R') ndir = 1;
    else if (dir == 'D') ndir = 2;
    else if (dir == 'L') ndir = 3;
    else if (dir == 'S') return;	// 제자리, 이동하지 않음

    int nx = px + dir_x[ndir];
    int ny = py + dir_y[ndir];
    if (nx < 1 || nx > N || ny < 1 || ny > N || wall[nx][ny] == 1) return;	// 이동하지 않음
    px = nx, py = ny;
    return;
}


int cnt_wall(int x, int y, int p)
{
    int cnt = 0;
    int nx = x;
    int ny = y;

    while (1) {
        if (nx + dir_x[p] < 1 || nx + dir_x[p] > N || ny + dir_y[p] < 1 || ny + dir_y[p] > N) break;
        if (wall[nx + dir_x[p]][ny + dir_y[p]] == 1) cnt++;
        nx += dir_x[p];
        ny += dir_y[p];
    }

    return cnt;
}


void move_zombies()
{
    // init
    memset(zpos, 0, sizeof(zpos));

    for (int i = 1; i <= Z; i++) {
        int type = ZOMBI[i].type;
        char dir = ZOMBI[i].dir;
        int ndir = -1;
        int speed = ZOMBI[i].speed;

        if (dir == 'U') ndir = 0;
        else if (dir == 'R') ndir = 1;
        else if (dir == 'D') ndir = 2;
        else if (dir == 'L') ndir = 3;

        if (type == 0) {	// 하급좀비
            int nx = ZOMBI[i].x;
            int ny = ZOMBI[i].y;

            for (int s = 1; s <= speed; s++){
                if (nx + dir_x[ndir] < 1 || nx + dir_x[ndir] > N || ny + dir_y[ndir] < 1 || ny + dir_y[ndir] > N) {
                    ndir = dir_op[ndir];
                    break;
                }
                if (wall[nx + dir_x[ndir]][ny + dir_y[ndir]] == 1) {
                    ndir = dir_op[ndir];
                    break;
                }
                nx += dir_x[ndir];
                ny += dir_y[ndir];
            }

            if (ndir == 0) dir = 'U';
            else if (ndir == 1) dir = 'R';
            else if (ndir == 2) dir = 'D';
            else if (ndir == 3) dir = 'L';

            ZOMBI[i] = { nx, ny, type, dir, speed };
            zpos[nx][ny] = 1;
        }
        else if (type == 1) {	// 상급좀비
            int nx = ZOMBI[i].x;
            int ny = ZOMBI[i].y;

            // 이동하기
            for (int h = 1; h <= speed; h++) {
                if (nx + dir_x[ndir] < 1 || nx + dir_x[ndir] > N || ny + dir_y[ndir] < 1 || ny + dir_y[ndir] > N) break;
                if (wall[nx + dir_x[ndir]][ny + dir_y[ndir]] == 1) {
                    wall[nx + dir_x[ndir]][ny + dir_y[ndir]] = 0;	// 그 앞의 벽을 부순다
                    break;
                }
                nx += dir_x[ndir];
                ny += dir_y[ndir];
            }
            // 방향 틀기
            int max_cnt = -1;
            int opt_dir = -1;
            for (int p = 0; p < 4; p++) {
                int res = cnt_wall(nx, ny, p);
                if (res > max_cnt) {
                    max_cnt = res;
                    opt_dir = p;
                }
            }

            char nopt_dir = '-1';
            if (opt_dir == 0) nopt_dir = 'U';
            else if (opt_dir == 1) nopt_dir = 'R';
            else if (opt_dir == 2) nopt_dir = 'D';
            else if (opt_dir == 3) nopt_dir = 'L';


            ZOMBI[i] = { nx, ny, type, nopt_dir, speed };
            zpos[nx][ny] = 1;
        }
    }
}






bool simulation()
{
    for (int day = 1; day <= D; day++) {
        if (CMD[day - 1] == '\0') break;
        move_player(CMD[day - 1]);
        move_zombies();
        if (zpos[px][py] == 1) {
            dead_day = day;
            return false;
        }
    }
    return true;
}


int main()
{
    input();
    bool res = simulation();
    if (res == false) {
        printf("%d\n", dead_day);
        printf("DEAD...\n");
    }
    else printf("ALIVE!\n");
    return 0;
}