#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

int main(   )
{
    int T;
    cin >> T;

    while (T--)
    {
        int n ,m;
        int count = 0;
        bool flag = false;
        cin >> n >> m;

        queue <int> q;

        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            q.push(temp);
        }

        for (int  i = 0 ; !q.empty(); i++)
        {
            int big = 0;
            
            for (int j = 0 ;j < q.size(); j++)
            {
                big = max(big, q.front()); // 가장 중요도 높은 문서탐색
                
                int temp = q.front();
                q.pop();
                q.push(temp);
                
                if (m == 0) m += q.size() - 1; //찾고자 하는 문서위치
                else m--;
            }
            for (int j = 0 ; j < q.size(); j++)
            {
                
                if (q.front() == big) //가장 중요도 높은 문서 제거 
                {
                    if (m == 0) //가장 높은게 찾고자 하는 문서일경우 끝냄
                    {
                        cout << ++count << "\n";
                        flag = true;
                        break;
                    }

                    m--;
                    q.pop();
                    count++;
                    
                    break;
                }
                else
                {
                    int temp = q.front();
                    q.pop();
                    q.push(temp);
                
                    if (m == 0) m += q.size() - 1; //찾고자 하는 문서위치
                    else m--;
                }
            }
            if (flag) break;
        }
        
    }
    
    
}
