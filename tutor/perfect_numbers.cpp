#include <iostream>
using namespace std;

// perfect square
bool is_perfect_square(int n){
    if(n < 0){
	return false;
    }
    int i,v;
    bool perfect = false;
    for(i=0; v=i*i, v<=n; i++){
	if(v == n){
	    perfect = true;
	    break;
	}
    }
    return perfect;
}

// perfect cube
bool is_perfect_cube(int n){
    if(n < 0){
	n = -n;
    }
    int i, v;
    bool perfect = false;
    for(i=0; v=i*i*i, v<=n; i++){
	if(v == n){
	    perfect = true;
	}
    }
    return perfect;
}

int main(){
    cout << "perfect squares:\n";
    for(int i=1; i<=1000; i++){
	if(is_perfect_square(i)){
	    cout << i << endl;
	}
    }
    cout << "perfect cubes:\n";
    for(int i=0; i<=1000; i++){
	if(is_perfect_cube(i)){
	    cout << i << endl;
	}
    }
    return 0;
}
