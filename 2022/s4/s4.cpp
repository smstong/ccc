#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N=8;
int C=10;

bool isBetween(double p1, double p2, double p){
	//cout << "inBetween: " << p << "("<<p1<<","<<p2<<")\n";
	if(p1<p2){
		return p>p1 && p<p2;
	}else{
		return p>p1 || p<p2;
	}

}
double diffAB(double p1, double p2){
	if(p1 < p2){
		return p2-p1;
	}else{
		return C-(p1-p2);
	}
}
// p3 must be in range (p1', p2')
bool isGood(int p1, int p2, int p3){
	if(fabs(p1-p2)==C/2.0 || p1==p2){
		return false;
	}
	double p1_o = (p1 + C/2.0);
	if(p1_o >= C){
		p1_o -= C;
	}
	double p2_o = (p2 + C/2.0);
	if(p2_o >= C){
		p2_o -= C;
	}

	if(diffAB(p1,p2)>C/2.0){
		return isBetween(p2_o, p1_o, p3);
	}else{
		return isBetween(p1_o, p2_o, p3);
	}
}

int main(){
	cin >> N >> C;
	vector<int> P(N);
	for(int i=0; i<N; i++){
		cin >> P[i];
	}

	// P[i], P[j], P[k] to form a triangle
	int count = 0;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			for(int k=j+1; k<N; k++){
				if(isGood(P[i], P[j], P[k])){
					//cout <<i+1 << j+1 << k+1 <<endl;
					count++;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
