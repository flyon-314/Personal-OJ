#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double counts[26] = {0};
    string str;
    getline(std::cin, str);

    for (char c : str)
    {
        if (c >= 'A' && c <= 'Z')
        {
            counts[c - 'A']++;
        }
    }

    long long pH = static_cast<long long>(counts['H' - 'A'] + counts['A' - 'A'] + counts['P' - 'A'] + counts['Y' - 'A']);
    long long pS = static_cast<long long>(counts['S' - 'A'] + counts['A' - 'A'] + counts['D' - 'A']);

    if (pH == 0 && pS == 0) {
        printf("50.00\n");
    } else {
        long long happiness_index = (pH * 100000) / (pH + pS);

        if (happiness_index % 10 >= 5) {
            happiness_index /= 10;
            happiness_index += 1;
        } else {
            happiness_index /= 10;
        }
        
        printf("%lld.%02lld\n", happiness_index / 100, happiness_index % 100);
    }
    
    return 0;
}
