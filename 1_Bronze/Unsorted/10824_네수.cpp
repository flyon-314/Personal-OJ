#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    string number1=to_string(a)+to_string(b);
    string number2=to_string(c)+to_string(d);
    long long answer=stoll(number1)+stoll(number2);
    
    cout<<answer;
    
}