#include <bits/stdc++.h>
using namespace std;
int leftrotatearray(vector<int> &a, int n)
{
    int temp = a[0];
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1];
    }
    a[n - 1] = temp;
    return a;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    leftrotatearray(arr[], n);
    return 0;
}
