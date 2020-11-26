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
bool bombastic(S a, S b)
{
//    LL first =  0, second = 0;
//    for(LL i = 0 ; i < a.size() ; i++)
//        first += (LL)a[i];
//    for(LL i = 0 ; i < b.size() ; i++)
//        second += (LL)b[i];


        return (a.size() < b.size());

}

void merging(S a[], LL start, LL mid, LL end)
{
    LL first = start, second = mid+1, index = 0;
    S b[end-start+1];
    for(LL i = start ; i <= end ; i++)
    {
        if(first > mid)
            b[index++] = a[second++];
        else if(second > end)
            b[index++] = a[first++];
        else if(a[first].size() > a[second].size())
            b[index++] = a[second++];
        else
            b[index++] = a[first++];
    }
//    printf("printf b:\n");
//    for(LL i = 0 ; i < index ; i++)
//        cout << b[i] << " ";
//    cout << endl;
    for(LL i = 0, j = start ; i < index ; i++, j++)
        a[j] = b[i];
}

void merge_sort(S a[], LL start, LL end)
{
    if(start < end)
    {
//        LL mid = start + ((end - start)/2);
        LL mid = (start + end) / 2;
        merge_sort(a, start, mid);
        merge_sort(a, mid+1, end);
        merging(a, start, mid, end);
    }
}
int main()
{
#if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LL t;
    cin >> t;
    scanf("%*c");
    while(t--)
    {
        S s[1001];
        S input;
        stringstream ss;
        getline(cin, input);
        ss << input;
        I i = 0;
        while(ss >> s[i])
            i++;
        LL len = i;

        merge_sort(s, 0, len-1);
        for(LL i = 0 ; i < len ; i++)
            cout << " " << s[i] ;
            cout << endl;
    }
    return 0 ;
}


