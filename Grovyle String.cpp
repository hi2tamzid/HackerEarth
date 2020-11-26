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
int partition(S &a, I low, I high, I turn)
{
    I pivot = low + (rand()% (high - low + 1));
    I i = low+1;
    swap(a[pivot], a[low]);
    if(turn == 1)
    {
        for(I j = low+1; j <= high ; j++)
        {
            if(a[j] < a[low])
            {
                swap(a[j], a[i]);
                i++;
            }
        }
    }
    else
    {
        for(I j = low+1; j <= high ; j++)
        {
            if(a[j] > a[low])
            {
                swap(a[j], a[i]);
                i++;
            }
        }
    }
    swap(a[low], a[i-1]);
    return i-1;
}
void quick_sort(S &a, I low, I high, I turn)
{
    if(low < high)
    {
        I pivot = partition(a, low, high, turn);
        quick_sort(a, low, pivot-1, turn);
        quick_sort(a, pivot+1, high, turn);
    }
}
int main()
{
#if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
        S s;
        cin >> s;
        I mid = (I)s.size() / 2;
        quick_sort(s, 0, (I)s.size()-1, 1);
        swap(s[mid], s[(I)s.size()-1]);
        for(int i = 1, j = s.size()-1 ; i <= mid/2 ; i++, j-=2)
        {
            swap(s[mid-i], s[j]);
            swap(s[mid+i], s[j-1]);
        }
//        quick_sort(s, mid, ((I)s.size()-1), 2);
//        for(I i = mid-1, j = mid+2 ; i > 0 ; i--, j++)
//        {
//            swap(s[i], s[j]);
//        }
        cout << s << endl;
    }
    return 0 ;
}


