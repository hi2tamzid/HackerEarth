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
#include <set>
#include <list>

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
#define pal pair<LL,LL>
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
S hashTable[100010];
LL  hashTableSize = 100000;
void insert(LL index, string s)
{
//    LL index = hashFunc(s);
    LL check_val = 0;
    while(hashTable[index] != "" && check_val < hashTableSize)
        index = (index+1) % hashTableSize, check_val++;

    if(hashTable[index] == "")
    hashTable[index] = s;
    else
        cout << "no space" << endl;
}
void search(LL index)
{
//    LL index = hashFunc(s);
    LL check_val = 0;
//    while(hashTable[index] != s and hashTable[index] != "" and check_val < hashTableSize)
//        index = (index + 1) % hashTableSize,check_val++;

//    if(hashTable[index] == s)
        cout <<  hashTable[index] << endl;
//        else
//            cout << s << " is not found!" << endl;
}
int main()
{
#if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LL n;
    scanf("%lld", &n);
//    scanf("%*c");
    S input2;
    LL input1;
    for(LL i = 0 ; i < n ; i++)
    {
        cin >> input1 >> input2 ;
        insert(input1, input2);
    }
    LL q;
    cin >> q;
    for(LL i = 0 ; i < q ; i++)
    {
        cin >> input1;
        search(input1);
    }
    return 0;
}


