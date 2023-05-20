/*
 * fraction addition
 * e.g. 1/4 + 7/12 = 3/12 + 7/12 = 10/12 = 5/6
 *
 */
#include <iostream>
using namespace std;

// greatest common factor
// e.g. gcf(4,6) = 2
int gcf(int a, int b){
    int small, big;
    if(a<b){
	small = a;
	big = b;
    }else{
	small = b;
	big = a;
    }

    int f;
    for(int i=1; f=small/i, f>0; i++){
	if((small % f == 0) && (big % f == 0)){
	    return f;
	}
    }
    return 1;
}

// least common multiple
// e.g. lcm(4,6) = 12
int lcm(int a, int b){
    int small, big;
    if(a<b){
	small = a;
	big = b;
    }else{
	small = b;
	big = a;
    }
    int m;
    for(m=big; m%small !=0 ;m+=big){
	;
    }
    return m;
}

// n/d = ns/ds
// e.g. 4/6 = 2/3
void fraction_simplify(int n, int d, int& ns, int& ds){
    int f = gcf(n, d);
    ns = n / f;
    ds = d / f;
}

// e.g. 3/2 = (1 and 1/2)
void fraction_mix(int n, int d, int& q, int& ns, int& ds){
    q = n / d;
    ns = n % d;
    ds = d;
}

// n1/d1 + n2/d2 = n / d
// e.g. 1/2 + 1/3 = 5/6
void fraction_add(int n1, int d1, int n2, int d2, int& ns, int& ds){
    int m = lcm(d1, d2);
    int n = (n1*m/d1) + (n2*m/d2);
    int d = m;
    //cout << n << "/" << d << endl;
    fraction_simplify(n,d,ns,ds);
}

int main(int argc, char** argv){
    if(argc != 5){
	cout << "Usage: " << argv[0] << " n1 d1 n2 d2" << endl;
	return 0;
    }	
    int n1 = atoi(argv[1]);
    int d1 = atoi(argv[2]);
    int n2 = atoi(argv[3]);
    int d2 = atoi(argv[4]);

    int ns, ds;
    //fraction_add(1, 4, 7, 12, ns, ds);
    fraction_add(n1, d1, n2, d2, ns, ds);
    cout << ns << "/" << ds << endl;
    int q, m_n, m_d;
    fraction_mix(ns, ds, q, m_n, m_d);
    cout << q << " and " << m_n << "/" << m_d << endl;
    return 0;
}
