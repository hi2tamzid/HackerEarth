#include <bits/stdc++.h>
#define test 0
using namespace std;
typedef long long int LL ;
void max_heapify (LL Arr[ ], LL i, LL N)
{
    LL left = 2*i;              //left child
    LL right = 2*i +1;         //right child
    LL largest;
     if(left<= N and Arr[left] > Arr[i] )
         largest = left;
    else
        largest = i;
    if(right <= N and Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        swap (Arr[i] , Arr[largest]);
        max_heapify (Arr, largest,N);
    }
}

class priorityqueue
{

public:
    LL a[110005], length = 0;
    LL maximum(LL Arr[ ])
    {
        return Arr[ 1 ];  //as the maximum element is the root element in the max heap.
    }
    LL extract_maximum (LL Arr[ ])
    {
        if(length == 0)
        {
            cout<< "Can’t remove element as queue is empty";
            return -1;
        }
        LL max = Arr[1];
        Arr[1] = Arr[length];
        length = length -1;
        max_heapify(Arr, 1, length);
        return max;
    }
    void increase_value (LL Arr[ ], LL i, LL val)
    {
        if(val < Arr[ i ])
        {
            cout<<"New value is less than current value, can’t be inserted" <<endl;
            return;
        }
        Arr[ i ] = val;
        while( i > 1 and Arr[ i/2 ] < Arr[ i ])
        {
            swap(Arr[ i/2 ], Arr[ i ]);
            i = i/2;
        }
    }
    void insert_value (LL Arr[ ], LL val)
    {
        length = length + 1;
        Arr[ length ] = -1;  //assuming all the numbers greater than 0 are to be inserted in queue.
        increase_value(Arr, length, val);
    }
};

int main()
{
    #if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LL n;
    scanf("%lld", &n);
    priorityqueue ob;
    for(LL i = 0 ; i < n ; i++)
    {
        LL input;
        scanf("%lld", &input);
        ob.insert_value(ob.a, input);
    }

    LL q ;
    scanf("%lld", &q);
    for(LL i = 0 ; i < q ; i++)
    {
        LL first, second;
        scanf("%lld", &first);
        if(first == 1)
        {
            scanf("%lld", &second);
            ob.insert_value(ob.a, second);
        }
        else
        {
            LL result = ob.maximum(ob.a);
            printf("%lld\n", result);
        }
    }
    return 0;
}
