# class 1
## g++ compiler installation
## C++ template code
```cpp
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    cout << "hello cpp!\n";
    return 0;
}
```
## template Makefile
```Makefile
j1: j1.cpp
	g++ -std=c++11 -O2 -Wall -static -o $@ $<
```

## template test.sh
```bash
	cat TestData/j1.sample.1.in | ./j1
```
