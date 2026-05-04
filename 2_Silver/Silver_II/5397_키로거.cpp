#include <iosfwd>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string str;
char dat[1000005];
int nxt[1000005] ;
int pre[1000005] ;
int unused = 1;
void insert(char c, int addr)
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
void traversal(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << "\n" ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int m;
    cin >> m;

    while (m--)
    {
        fill(nxt,nxt+1000005,-1);
        fill(pre,pre+1000005,-1);
        unused = 1;
        int cursor = 0;
        cin >> str;
        
        for (char c : str)
        {
            if (c ==  '>')
            {
                if (nxt[cursor] != -1) cursor = nxt[cursor];
            }
            else if (c ==  '<')
            {
                if (pre[cursor] != -1) cursor = pre[cursor];
            }
            else if ( c == '-'){
                if (pre[cursor] != -1)
                {
                    erase(cursor);
                    cursor = pre[cursor];
                }
            }
            else
            {
                
                insert(c, cursor);
                cursor = nxt[cursor];
            } 
        
        }
        traversal();
        
    }
    
}