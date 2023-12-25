#include <iostream>
using namespace std;
#include <vector>

bool isThere(vector<vector<int>> &arr, int n, int i, int j)
{
    for (int o = j - 1; o >= 0; o--)
    {
        if (arr[i][o] == 1)
        {
            return true;
        }
    }
    for (int o = j + 1; o < n; o++)
    {
        if (arr[i][o] == 1)
        {
            return true;
        }
    }
    for (int o = i - 1; o >= 0; o--)
    {
        if (arr[o][j] == 1)
        {
            return true;
        }
    }
    for (int o = i + 1; o < n; o++)
    {
        if (arr[o][j] == 1)
        {
            return true;
        }
    }
    for (int o = i - 1, k = j - 1; (o >= 0 && k >= 0); o--, k--)
    {
        if (arr[o][k] == 1)
        {
            return true;
        }
    }
    for (int o = i - 1, k = j + 1; (o >= 0 && k < n); o--, k++)
    {
        if (arr[o][k] == 1)
        {
            return true;
        }
    }
    for (int o = i + 1, k = j - 1; (o < n && k >= 0); o++, k--)
    {
        if (arr[o][k] == 1)
        {
            return true;
        }
    }
    for (int o = i + 1, k = j + 1; (o < n && k < n); o++, k++)
    {
        if (arr[o][k] == 1)
        {
            return true;
        }
    }
    return false;
}

void printMat(vector<vector<int>> &arr)
{
    for (const auto &i : arr)
    {
        for (const int &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool helper(vector<vector<int>> &arr, int n, int size)
{
    int i;
    if (n == 0)
    {
        printMat(arr);
        return false;
    }
    for (i = 0; i < size; i++)
    {
        if (isThere(arr, size, n - 1, i) == false)
        {
            arr[n - 1][i] = 1;
            if (helper(arr, n - 1, size) == false)
            {
                arr[n - 1][i] = 0;
            }
        }
    }
    return false;
}

void kween(const int n)
{
    vector<vector<int>> arr(n, vector<int>(n, 0));
    helper(arr, n, n);
}

/*
{0,0,1,0},
{1,0,0,0},
{0,0,0,1},
{0,1,0,0}
*/

int main()
{
    kween(4);
}
