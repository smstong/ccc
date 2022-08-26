#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string line;
	cin >> line;
	int n = line.length();
	char* R = new char[n+1];
	strcpy(R, line.c_str());

	int swaps = 0;

	int L = 0;
	int M = 0;
	int S = 0;

	// How many Ls, Ms, Ss?
	for (int i=0; i<n; i++){
		if(R[i] == 'L'){
			L++;
		}
		else if(R[i] == 'M'){
			M++;
		}
		else if(R[i] == 'S'){
			S++;
		}
	}

	// swap MS out of L zone
	for(int l=0; l<L; l++){
		if(R[l] == 'M'){
		// first swap 'L' in M zone, then in S zone
			for(int m=L; m<n; m++){
				if(R[m] == 'L'){
					char t = R[l];
					R[l] = R[m];
					R[m] = t;
					swaps ++;
					break;
				}
			}
		} else if(R[l] == 'S'){
			// first swap 'L' in S zone, then in M zone
			for(int s=(n-1); s>=L; s--){
				if(R[s] == 'L'){
					char t = R[l];
					R[l] = R[s];
					R[s] = t;
					swaps ++;
					break;
				}
			}
		}else{
		}
	}

	// swap Ss out of M zone
	for(int m=L; m<L+M; m++){
		if(R[m] == 'S'){
			for(int s=L+M; s<n; s++){
				if(R[s] == 'M'){
					char t = R[m];
					R[m] = R[s];
					R[s] = t;
					swaps ++;
					break;
				}
			}
		}
	}

	cout << swaps << "\n";
}
