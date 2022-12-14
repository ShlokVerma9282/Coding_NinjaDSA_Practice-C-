#include <iostream>
#include <queue>
using namespace std;
void median(int arr[], int n)
{
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            max.push(arr[i]);
        }
        else
        {
            if (arr[i] < max.top())
            {
                max.push(arr[i]);
            }
            else
            {
                min.push(arr[i]);
            }
        }
        if (int(min.size() - max.size()) > 1)
        {
            int temp = min.top();
            min.pop();
            max.push(temp);
        }
        else if (int(max.size() - min.size()) > 1)
        {
            int temp = max.top();
            max.pop();
            min.push(temp);
        }

        int size = min.size() + max.size();

        if (size % 2 == 0)
        {
            cout << (min.top() + max.top())/2 << endl;
        }
        else
        {
            if (min.size() > max.size())
            {
                cout << min.top()<<endl;
            }
            else
            {
                cout<<max.top()<<endl;
            }
        }
    }
}
int main()
{
    int arr[6]={6,2,1,3,7,5};
    median(arr,6);
}
