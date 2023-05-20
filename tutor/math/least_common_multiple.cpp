#include <iostream>
using namespace std;

// least common multiple of a and b
int lcm(int a, int b) 
{
    int small, big;
    if(a < b){
	small = a;
	big = b;
    }else{
	small = b;
	big = a;
    }

    int m = big;
    while(true){
	if(m % small == 0){
	    break;
	}
	m += big;
    }	
    return m;
}

bool test_lcm(){
    return 
	(12 == lcm(3,4)) &&
	(30 == lcm(5,6));
}

int main(){
    if(test_lcm()){
	cout << "ok";
    }else{
	cout << "failed";
    }
    cout << endl;
    return 0;
}
