#include <iostream>
#include <vector>
using namespace std;

class PriroityQueue
{
    vector<int> pq;

public:
    PriroityQueue()
    {
    }
    bool is_empty()
    {
        return pq.size() == 0;
    }
    int get_size()
    {
        return pq.size();
    }
    int get_min()
    {
        if (is_empty())
        {
            return 0;
        }
        return pq[0];
    }
    void insert(int num)
    {
        pq.push_back(num);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] > pq[childIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }
    int remove()
    {
        if (is_empty())
        {
            return INT8_MIN;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int leftIndex = parentIndex * 2 + 1;
        int rightIndex = parentIndex * 2 + 2;

        while (leftIndex < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftIndex])
            {
                minIndex = leftIndex;
            }
            if ((rightIndex < pq.size()) && pq[rightIndex] < pq[minIndex])
            {
                minIndex = rightIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            int parentIndex = minIndex;
            int leftIndex = parentIndex * 2 + 1;
            int rightIndex = parentIndex * 2 + 2;
        }
        return ans;
    }
};