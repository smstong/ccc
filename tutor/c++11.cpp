///////////////////////////
//C++ 11 best features
///////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// uniform initialization and initializer list
// TYPE VARNAME{ initializaiter list };

void demo_1(){
	int a{1};
	double x{1.2};
	string s{"hello, world"};
	int A[]{1,2,3};
	vector<int> v{1,2,3,4,5};

	cout << a << endl;
	cout << x << endl;
	cout << s << endl;

	for(int i=0; i<sizeof(A)/sizeof(A[0]); i++){
		cout << A[i] << ",";
	}
	cout << endl;

	for(int i=0; i<v.size(); i++){
		cout << v[i] << ",";
	}
	cout << endl;
}

// keyword "auto"
// C++ compiler deduces the datatype for you.
// This can simplify code significantly when using templates
// where a type name can be very tedious.

void demo_2(){
	vector<int> v{1,2,3};

	// Without auto
	//for(vector<int>::iterator pos = v.begin(), end = v.end(); pos != end; ++pos){
	
	// With "auto"
	for(auto pos=v.begin(), end=v.end(); pos!=end; ++pos){
		cout << *pos << ",";
	}
	cout << endl;
}

// for-each
// for-each is valid for any containers including array.
// under the hood it uses iterator, but the syntax looks much better
// Java 8 JCF(Java Collections Framework) steals this from C++11

void demo_3(){
	vector<int> v{1,2,3};
	for(const auto& elem : v){
		cout << elem << ",";
	}
	cout << endl;
}

// lambda
// The closure can be very useful
void demo_4(){
	vector<int> v{1,2,3,4,5,6,7,8,9,10};
	int M = 4;
	auto pos = find_if(v.begin(), v.end(), 
			[=](int elem){
				return elem % M == 0;
			});
	if(pos != v.end()){
		cout << *pos << endl;
	}

	sort(v.begin(), v.end(),
			[](int x,int y){
				return x > y;
			});

	for(auto& elem : v){
		cout << elem << ",";
	}
	cout << endl;
}

int main(){
	demo_1();
	demo_2();
	demo_3();
	demo_4();

	return 0;
}

