#include <iosfwd>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string str;
int dat[5001];
int nxt[5001] ;
int pre[5001] ;
int unused = 1;
void insert(int c, int addr)
{
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}
void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(dat, dat + 5001 , -1);
    fill(pre, pre + 5001, -1);
    fill(nxt, nxt + 5001, -1);
    
    int N, K;
    cin >> N >> K;

    int cursor = 0;
    for (int i = 1 ; i <= N ; i++)
    {
        insert(i, cursor);
        cursor++;
    }
    
    nxt[unused - 1] = 1;
    pre[1] = unused -1;
    cursor = 0;
    cout << "<";
    for (int cnt = 0 ; cnt < N ; cnt++) {
        for (int i = 0 ; i < K ; i++)
        {
            cursor = nxt[cursor];
        }
        cout << dat[cursor];
         if (cnt != N - 1) cout << ", ";
        erase(cursor);
        cursor = pre[cursor];
    }
    cout << ">" << "\n";
}