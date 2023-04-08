#include <iostream>
using namespace std;

int main(){
    int a[] {23, 25,26,27,29,40,45,54,54,58,58,66,66,66,66,66,70};

    // mean
    double sum = 0;
    for(const int& e : a){
	sum += e;
    }
    int n = sizeof(a) / sizeof(a[0]);
    double mean = sum / n;
    cout << "Mean: " << mean << endl;

    // median
    double median;
    if(n % 2 == 0){
	int middle1 = n / 2;
	int middle2 = middle1 - 1;
	median = (a[middle1] + a[middle2])/2;
    }else{
	int middle1 = n / 2;
	median = a[middle1];
    }
    cout << "Median: " << median << endl;

    // mode
    int maxRep = 0;
    int mode = a[0];
    int rep = 1;
    for(int i=1; i<n; i++){
	if(a[i] == a[i-1]) {
	    rep++;
	    if(rep > maxRep){
		maxRep = rep;
		mode = a[i];
	    }
	}else{
	    rep = 1;
	}
    }
    cout << "Mode: " << mode << endl;

    return 0;
} 
