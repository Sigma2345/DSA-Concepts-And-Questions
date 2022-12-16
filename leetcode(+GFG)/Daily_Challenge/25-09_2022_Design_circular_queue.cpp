// https://leetcode.com/problems/design-circular-queue/
/*
    size -> size of circular queue
    cnt -> num of elements in queue

    we have to refer to previous index when refer to
    rear as in circular queue we always point to the next
    empty space for element to insert
*/

class MyCircularQueue
{
public:
    int *arr;
    int s, e, cnt;
    int size;
    MyCircularQueue(int k)
    {
        arr = new int[k];
        s = 0, e = 0, cnt = 0;
        size = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        arr[e] = value;
        e = (e + 1) % size;
        cnt++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        s = (s + 1) % size;
        cnt--;
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : arr[s];
    }

    int Rear()
    {
        return isEmpty() ? -1 : arr[(e + size - 1) % size];
    }

    bool isEmpty()
    {
        return cnt == 0;
    }

    bool isFull()
    {
        return cnt == size;
    }
};

