#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int tree[100][2];

void preoder(int node)
{
    if (node < 0 || node > 'Z' - 'A') return;

    cout << (char)(node + 'A');
    preoder(tree[node][0]);
    preoder(tree[node][1]);
}

void inorder(char node)
{
    if (node < 0 || node > 'Z' - 'A') return;
    inorder(tree[node][0]);
    cout << (char)(node + 'A');
    inorder(tree[node][1]);
}

void postorder(char node)
{
    if (node < 0 || node > 'Z' - 'A') return;

    postorder(tree[node][0]);
    postorder(tree[node][1]);
    cout << (char)(node + 'A');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        char parent, l_child, r_child;
        cin >> parent >> l_child >> r_child;
        tree[parent - 'A'][0] = l_child - 'A';
        tree[parent  - 'A'][1] = r_child - 'A';
    }

    preoder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";

    return 0;
}