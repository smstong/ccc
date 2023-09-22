// example for bit operators
// key points:
// - Big endian VS little endian
// - Split string
// - pointer type convertion

#include <iostream>
using namespace std;

bool isBigEndian(){
	int n = 0x12345678;
	unsigned char * p = (unsigned char*)&n;
	return *p == 0x12;
}
unsigned int ip2int(string ip){
	int start = 0;
	int pos;
	unsigned char c[4];
	int i=0;
	while ((pos = ip.find(".", start)) != string::npos){
		c[i++] = (unsigned char)stoi(ip.substr(start, pos-start));
		start = pos + 1;
	}
	c[i] = (unsigned char)stoi(ip.substr(start));

	if(!isBigEndian()){
		unsigned char t;
		t = c[0];
		c[0] = c[3];
		c[3] = t;

		t = c[1];
		c[1] = c[2];
		c[2] = t;
	}
	
	unsigned int n = *((unsigned int*)&c);
	return n;
}

bool isSameNetwork(string ip1, string ip2, string mask){

	unsigned int m = ip2int(mask);
	unsigned int network1 = ip2int(ip1) & m;
	unsigned int network2 = ip2int(ip2) & m;
	return network1 == network2;
}

int main(){
	string ip1, ip2, mask;
	cin >> ip1 >> ip2 >> mask;
	cout << (isSameNetwork(ip1, ip2, mask) ? "yes" : "no") << endl;
	return 0;
}
