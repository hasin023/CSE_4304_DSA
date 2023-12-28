#include <iostream>

using namespace std;

int getMax(int stones[], int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (stones[i] > max)
            max = stones[i];
    }
    return max;
}

int getSecondMax(int stones[], int size)
{
    int max = getMax(stones, size);
    int secondMax = 0;
    for (int i = 0; i < size; i++)
    {
        if (stones[i] > secondMax && stones[i] != max)
            secondMax = stones[i];
    }
    return secondMax;
}

int lastStoneWeight(int stones[], int size)
{
    int max = getMax(stones, size);
    int secondMax = getSecondMax(stones, size);
    int diff = max - secondMax;

    if (size > 1 && secondMax == 0)
    {
        diff = 0;
    }

    if (size == 1 && secondMax == 0)
    {
        diff = max;
    }

    if (diff == 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (stones[i] == max)
                stones[i] = 0;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (stones[i] == max)
                stones[i] = diff;
        }
    }
    if (secondMax != 0 && diff == 0)
        return lastStoneWeight(stones, size);
    else
        return diff;
}

int main()
{
    int stones[] = {1, 7, 5, 4, 2, 2, 1, 4, 8};
    int size = sizeof(stones) / sizeof(stones[0]);
    cout << lastStoneWeight(stones, size) << endl;
}