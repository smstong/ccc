#include <iostream>
#include <vector>
using namespace std;

vector<int>::iterator binary_search(vector<int>::iterator begin, vector<int>::iterator end, int t){
    auto s=begin;
    auto e=end;
    while(true){
	cout << "[";
	for(auto x=s; x!=e; ++x){
	    cout << *x << ",";
	}
	cout << "]" << endl;

	if (e <= s){
	    return end;
	}
	auto m = s + (e - s)/2; 
	if(*m == t){
	    return m;
	} else if(t > *m){
	    s = m+1;
	}else{
	    e = m;
	} 
    }
}
int main(int argc, char** argv){
    vector<int> v{1,2,3,5,8,9,11,14,53,};
    auto found = binary_search(v.begin(), v.end(), 20);
    if(found == v.end()){
	cout << "not found.";
    }else{
	cout << *found;
    }
    cout << endl;
}
