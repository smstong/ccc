#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double mean(vector<int> v)
{
    double sum = 0;
    for(int e : v){
	sum += e; 
    }
    double mean = sum / v.size();
    return mean;
}

int mode(vector<int> v)
{
    sort(v.begin(), v.end());
    int value = v[0];
    int count = 0;

    int mode = v[0];
    int countMax = 0;

    for(int e : v){
	if(value == e){
	    count++;
	    if(count > countMax){
		countMax = count;
		mode = value;
	    }
	}else{
	    value = e;
	    count = 0;
	}
    }
    return mode;
}

double median(vector<int> v)
{
    sort(v.begin(), v.end());
    double median;
    int n = v.size();
    if(n % 2 == 0){
	median = (v[n/2 - 1] + v[n/2]) / 2.0;
    }else{
	median = v[n/2];
    }
    return median;
}

int range(vector<int> v)
{
    int max = v[0];
    int min = v[0];
    for(int e : v){
	if(e < min){
	    min = e;
	}
	if(e > max){
	    max = e;
	}
    }
    return max-min;
}

int main(){
    int n;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n; i++){
	int a;
	cin >> a;
	v.push_back(a);
    }

    cout << "Mean: " << mean(v) << endl;
    cout << "Median: " << median(v) << endl;
    cout << "Mode: " << mode(v) << endl;
    cout << "Range: " << range(v) << endl;

    return 0;
}
