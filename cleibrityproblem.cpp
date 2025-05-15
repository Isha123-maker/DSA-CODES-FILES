#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int getCelebrity(vector<vector<int>> &arr)
{
    int n = arr.size();
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();

        if (arr[i][j] == 1)
        {
            s.push(j);
        }
        else
        {
            s.push(i);
        }
    }

    int celib = s.top();

    for (int i = 0; i < n; i++)
    {
        if ((i != celib) && (arr[i][celib] == 0 || arr[celib][i] == 1))
        {
            return -1;
        }
    }
    return celib;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int ans = getCelebrity(arr);

    cout << ans << endl;

    return 0;
}