#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
void printv(vector<T> v){
	cout << "vector("<<v.size()<<")[";
	for(auto elem : v){
		cout << elem << ",";
	}
	cout << "]\n";
}
int main(){
	vector<int> v{2,5,6,1,7,8};

	printv(v);
	// sort reverse
	sort(v.begin(), v.end(), 
			[](auto x, auto y){
				return x > y;
			});
	printv(v);

	// find_if
	auto pos = find_if(v.begin(), v.end(), 
			[](auto x){
				return x == 2;
			});
	if(pos != v.end()){
		*pos = *pos * 2;
	}
	printv(v);

	// for_each
	int m = 10; // closure
	for_each(v.begin(), v.end(), 
			[=](auto& x){
				x = x*m;	
			});
	printv(v);
}
