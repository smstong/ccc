#include <iostream>
using namespace std;

// greatest common factor of a and b
int gcf(int a, int b) 
{
    int small, big;
    if(a < b){
	small = a;
	big = b;
    }else{
	small = b;
	big = a;
    }

    for(int i=small; i>=1; i--){
	if(small % i == 0 && big % i == 0){
	    return i;
	}
    }
    return 1;
}

bool test_gcf(){
    return 
	(6 == gcf(12,18)) &&
	(1 == gcf(12,13));
}

int main(){
    if(test_gcf()){
	cout << "ok";
    }else{
	cout << "failed";
    }
    cout << endl;
    return 0;
}
