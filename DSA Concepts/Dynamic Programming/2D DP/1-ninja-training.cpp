#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Ninja earns points on completing tasks, but he can't perform same
// task on consecutive days. Maximize the points gained.

// Recursion (req value to base case)
// f1 is the max points earned on day 'i' when last day task was 'last'
int f1(int day, int last, vector<vector<int>> &points)
{
    if(day == 0){
        int maxi = INT_MIN;

        for(int task=0; task<3; task++){
            if(task != last){
                maxi = max(maxi, points[0][task]);
            }
        }

        return maxi;
    }

    int maxi = INT_MIN;
    for(int task=0; task<3; task++){
        if(task != last){
            int point = points[day][task] + f1(day-1, task, points);
            maxi = max(maxi, point);
        }
    }

    return maxi;
}

// Memoization
int f2(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if(day == 0){
        int maxi = INT_MIN;

        for(int task=0; task<3; task++){
            if(task != last){
                maxi = max(maxi, points[0][task]);
            }
        }

        return maxi;
    }
    if(dp[day][last] != -1)
        return dp[day][last];

    int maxi = INT_MIN;
    for(int task=0; task<3; task++){
        if(task != last){
            int point = points[day][task] + f2(day-1, task, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}

// Tabulation
int f3(vector<vector<int>> &points)
{
    int days = points.size();

    vector<vector<int>> dp(days, vector<int> (4, 0)); // dp array (days, last task)
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][3]));

    for(int day=1; day<days; day++){
        
        for(int last=0; last<4; last++){
            dp[day][last] = 0;

            for(int task=0; task<3; task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[days-1][3];
}

// Space Optimization
int f4(vector<vector<int>> &points)
{
    int days = points.size();

    vector<int> prev(4, 0); // dp array (days, last task)
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][3]));

    for(int day=1; day<days; day++){
        vector<int> temp(4, 0);

        for(int last=0; last<4; last++){
            temp[last] = 0;

            for(int task=0; task<3; task++){
                if(task != last){
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}

int ninjaTraining(vector<vector<int>> &points)
{
    int days = points.size();
    int tasks = 3;  // 0-task0, 1-task1, 2-task2, 3-notaskdone

    // return f1(days-1, tasks, points);

    // vector<vector<int>> dp(days, vector<int>(tasks+1, -1));
    // return f2(days-1, tasks, points, dp);

    // return f3(points);
    return f4(points);
}

int main()
{
    vector<vector<int>> points = {{1,2,5},{3,1,1},{3,3,3}};
    cout << ninjaTraining(points);

    return 0;
}