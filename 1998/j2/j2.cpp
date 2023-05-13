#include <iostream>
using namespace std;


bool is_perfect(int n)
{
    int d;
    int sum = 0;
    for(d=1; d<n; d++){
	if(n % d == 0){
	    sum += d;
	}
    }
    return sum == n;
}


void q1(){
    for(int n=1000; n<=9999; n++){
	if(is_perfect(n)){
	    cout << n << endl;
	}
    }
}

bool is_armstrong(int n)
{
   int old = n;
   int digit; 
   int sum = 0;
   while(n != 0){
       digit = n % 10;
       n = n / 10;
       sum += digit * digit * digit;
   }
   return sum == old;
}

void q2()
{
    for(int n=100; n<=999; n++){
	if(is_armstrong(n)){
	    cout << n << endl;
	}
    }
}

void q3()
{
    //find perfect square
    cout << "perfect squares: \n";
    for(int n=8000; n<9000; n++){
	bool ps = false;
	for(int i=1; i<n; i++){
	    if(i*i == n){
		ps = true;
		break;
	    }
	}	    
	if(ps){
	    cout << n << endl;
	}
    }

    // answers
    cout << "8 1 2 8" <<endl;
    cout << "x 1 x 2" <<endl;
    cout << "8 1 1 8" <<endl;
    cout << "x 3 7 1" <<endl;
}


int main(){
    cout << "answer to question 1:\n";
    q1();
    cout << "answer to question 2:\n";
    q2();
    cout << "answer to question 3:\n";
    q3();
    return 0;
}
