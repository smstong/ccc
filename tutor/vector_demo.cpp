#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v1;

	cout << sizeof(v1) << endl;

	for(int i=0; i<1000; i++){
		v1.push_back(i);
	}

	cout << sizeof(v1) << endl;

	return 0;
}
