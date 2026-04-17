#include<iostream>
#include<string>
#include<stack>
 
using namespace std;
 
int main()
{
    int T;        //테스트 케이스
    string sentence;    //문장 (길이 최대 1000) 단어길이: 20
    stack <char> st;    //단어를 뒤집기 위한 스택
 
    cin >> T;
    cin.ignore();    //버퍼 비우기
    while (T--)
    {
        getline(cin, sentence);
        sentence += ' ';
 
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }cout << ' ';
            }
            else 
                st.push(sentence[i]);
        }cout << "\n";
    }
 
}
