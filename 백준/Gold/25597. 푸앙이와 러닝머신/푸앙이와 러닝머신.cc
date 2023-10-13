#include <bits/stdc++.h>
using namespace std;

const int speeds[] = {8, 4, 1};
#define SPEED_COUNT 3

int buttonPressCount(int *periods)
{
    int result = 0;
    for (int i = 0; i < SPEED_COUNT; i++)
        if (periods[i] != 0)
            result++;
    return result;
}

int sum(int *periods)
{
    int result = 0;
    for (int i = 0; i < SPEED_COUNT; i++)
        result += periods[i];
    return result;
}

bool run(int *periods, int t)
{
    if (sum(periods) > t)
        return false;

    int count = buttonPressCount(periods);
    cout << count << "\n";

    int passed = t - sum(periods);

    for (int i = 0; i < SPEED_COUNT; i++)
    {
        if (periods[i] == 0)
            continue;
        cout << passed << " " << speeds[i] << "\n";
        passed += periods[i];
    }

    return true;
}

void movePeriod(int *periods, int from, int to)
{
    periods[to] += periods[from] * speeds[from] / speeds[to];
    periods[from] = 0;
}

int main()
{
    int x, t;
    cin >> x >> t;

    int minPeriods[SPEED_COUNT];
    int periods[SPEED_COUNT];
    for (int i = 0; i < SPEED_COUNT; i++)
    {
        minPeriods[i] = x / speeds[i];
        x %= speeds[i];
    }

    int periodSum = sum(minPeriods);

    if (periodSum > t)
    {
        cout << -1 << "\n";
        return 0;
    }

    int pressCount = buttonPressCount(minPeriods);


    if (pressCount == 1)
    {
        run(minPeriods, t);
        return 0;
    }

 
    else if (pressCount == 2)
    {
        memcpy(periods, minPeriods, sizeof(int) * 3);


        if (periods[2] == 0)
        {
            movePeriod(periods, 0, 1);
            if (run(periods, t))
                return 0;
        }


        else
        {
            movePeriod(periods, 0, 2);
            movePeriod(periods, 1, 2);
            if (run(periods, t))
                return 0;
        }

 
        memcpy(periods, minPeriods, sizeof(int) * 3);
        if (run(periods, t))
            return 0;
        else
        {
            cout << -1 << "\n";
            return -1;
        }
    }


    else
    {

        memcpy(periods, minPeriods, sizeof(int) * 3);
        movePeriod(periods, 0, 2);
        movePeriod(periods, 1, 2);
        if (run(periods, t))
            return 0;


        memcpy(periods, minPeriods, sizeof(int) * 3);
        movePeriod(periods, 0, 1);
        if (run(periods, t))
            return 0;


        memcpy(periods, minPeriods, sizeof(int) * 3);
        movePeriod(periods, 1, 2);
        if (run(periods, t))
            return 0;

        memcpy(periods, minPeriods, sizeof(int) * 3);
        movePeriod(periods, 0, 2);
        if (run(periods, t))
            return 0;


        memcpy(periods, minPeriods, sizeof(int) * 3);
        if (run(periods, t))
            return 0;
        else
        {
            cout << -1 << "\n";
            return -1;
        }
    }
}