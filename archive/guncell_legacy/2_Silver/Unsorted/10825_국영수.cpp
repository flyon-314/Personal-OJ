#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct STUDENT{
    string name;
    int korean,english,math;
};
bool comp(STUDENT a,STUDENT b)
{
    if(a.english==b.english &&a.math==b.math && a.korean==b.korean )
        return a.name<b.name;
    else if(a.korean==b.korean && a.english==b.english )
        return a.math>b.math;
    else if(a.korean==b.korean)
        return a.english<b.english;
    else
        return a.korean>b.korean;
}
int main() {
    int num;
    vector<STUDENT> sol;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        STUDENT st;
        cin>>st.name>>st.korean>>st.english>>st.math;
        sol.push_back(st);
    }
    stable_sort(sol.begin(),sol.end(),comp);
    for(int i = 0; i < num; i++)
        cout << sol[i].name<< '\n';
}