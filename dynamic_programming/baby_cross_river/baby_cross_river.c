#include <iostream>
#include <algorithm>
using namespace std;

int baby_cross_river(int *T, int n)
{
    if(n<=2) return T[n];
    if(n == 3) return T[1]+T[2]+T[3];
    int f_n2 = T[2]; //f(n-2)
    int f_n1 = T[1]+T[2]+T[3];//f(n-1)
    int f_n = 0;
    for(int i = 4; i <= n; ++i)
    {
        f_n = T[1] + 2*T[2] + T[i] + f_n2;
        f_n2 = f_n1;
        f_n1 = f_n;
    }
    return f_n;
}
int main()
{
    const int n = 5;
    int T[n+1]={0, 1, 2, 5, 10, 20};//start index = 1
    int fn = baby_cross_river(T, n);
    cout<<"total cost is "<<fn<<endl;
    return 0;
}
