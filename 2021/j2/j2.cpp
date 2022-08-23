#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 0;
    string name;
    int price = 0;

    int maxPrice = 0;
    string maxName;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> name;
        cin >> price;

        if (price > maxPrice){
            maxPrice = price;
            maxName = name;
        }
    }

    cout << maxName << "\n";
    return 0;
}
