#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <cctype>
#include <climits>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <exception>
#include <fstream>
#include <algorithm>
#include <ios>
#include <bitset>
#include <sstream>

#define test 0
#define pi acos(-1.0)
#define eps 1e-8
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(x) (((x) > 0) ? (x) : (-(x)))
using namespace std ;

typedef int I ;
typedef short int SI ;
typedef long L ;
typedef long long LL ;
typedef unsigned long long ULL ;
typedef float F ;
typedef double D ;
typedef long double LD ;
typedef char C ;
typedef bool B ;
typedef string S ;
typedef vector<I> VI ;
typedef vector<I>::iterator VIT ;
typedef vector<L> VL ;
typedef vector<L>::iterator VLT ;
typedef vector<LL> VLL ;
typedef vector<LL>::iterator VLLT ;
typedef vector<C> VC ;
typedef vector<C>::iterator VCT ;
template<typename a>
void SWAP(a &b, a &c)
{
    a d = b ;
    b = c ;
    c = d ;
}

LL power(LL a, LL b)
{
   LL result = 1 ;
   while(b)
   {
       if(b&1)
        result = a * result ;
       a *= a ;
       b >>= 1 ;
   }
   return result ;
}
LL gcd(LL a, LL b)
{
    while(b)
    {
        a = a % b;
        SWAP(a,b);
    }
    return a;

}

LL lcm(LL a, LL b)
{
    return (a * (b / gcd(a,b)));
}
LL result = 0;
void merge(LL a[], LL start, LL mid, LL end)
{
    LL p = start, q = mid+1;
    LL arr[end-start+1], k = 0;


    for(LL i = start ; i <= end ; i++)
    {
        if(p > mid)
            {

                arr[k++] = a[q++];
            }
        else if(q > end)
            {
                arr[k++] = a[p++];
            }
        else if(a[p] > a[q])
        {
            result += (mid - p + 1);
            arr[k++] = a[q++];
        }
        else
            arr[k++] = a[p++];
    }
    for(LL i = 0, j = start ; i < k ; i++, j++)
    {
        a[j] = arr[i];
    }
}
void merge_sort(LL a[], LL start, LL end)
{
    if(start < end)
    {
        LL mid = (start +end)/2;

        merge_sort(a, mid+1, end);
        merge_sort(a, start, mid);
        merge(a, start, mid, end);
    }
}
int main()
{
#if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LL n;
    cin >> n;
    LL a[n];
    for(LL i = 0 ; i < n ; i++)
        cin >> a[i];
    merge_sort(a, 0, n-1);
    cout << result << endl;
    return 0 ;
}


