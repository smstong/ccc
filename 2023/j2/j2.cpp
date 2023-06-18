#include <iostream>
using namespace std;

int shu(string pepper_name){
	int r = 0;
	if(pepper_name == "Poblano"){
		r = 1500;
	}else if(pepper_name == "Mirasol"){
		r = 6000;
	}else if(pepper_name == "Serrano"){
		r = 15500;
	}else if(pepper_name == "Cayenne"){
		r = 40000;
	}else if(pepper_name == "Thai"){
		r = 75000;
	}else if(pepper_name == "Habanero"){
		r = 125000;
	}else{
		r = -1;
		cout << "unknown\n";
	}
	return r;
}
int main(){
	int N;
	cin >> N;

	int T=0;
	for(int i=0; i<N; i++){
		string name;
		cin >> name;
		T += shu(name);
	}

	cout << T << endl;
	return 0;
}
