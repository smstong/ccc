#include <bits/stdc++.h>
using namespace std;

int main()
{
    int P,B;
    cin >> B;
    P = 5 * B - 400;
    cout << P << "\n";

    if (P > 100) {
        cout << -1;
    }else if (P == 100){
        cout << 0;
    }else{
        cout << 1;
    }
    cout << "\n";

    return 0;
}
