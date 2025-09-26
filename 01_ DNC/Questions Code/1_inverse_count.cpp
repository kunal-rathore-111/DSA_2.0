#include <iostream>
#include <vector>

using namespace std;

int mergeFunc(vector<int> &vec, int start, int mid, int end)
{
    int count = 0;

    int i = start, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= end)
    {
        if (vec[i] <= vec[j])
        {
            temp.push_back(vec[i]);
            i++;
        }
        else
        {
            temp.push_back(vec[j]);
            count += mid + 1 - i;
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(vec[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(vec[j]);
        j++;
    }

    for (int i = start; i <= end; i++)
    {
        vec[i] = temp[i - start];
    }
    return count;
}

int mergeSort(vector<int> &vec, int start, int end)
{
    int count = 0;
    if (start >= end)
    {
        return 0;
    }
    int mid = start + (end - start) / 2;
    count += mergeSort(vec, start, mid);
    count += mergeSort(vec, mid + 1, end);
    count += mergeFunc(vec, start, mid, end);

    return count;
}

int main()
{
    vector<int> vec = {4, 5, 1, 2};

    int count = 0;
    int ans = mergeSort(vec, 0, 3);
    cout << ans;
    return 0;
}