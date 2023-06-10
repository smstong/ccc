#include <iostream>
using namespace std;

// '3' -> 3
int c2i(char c){
	return c - '0';
}

// 3 -> '3'
char i2c(int i){
	return i + '0';
}

// getBit("123", 0) = 3
int getBit(const string s, int i){
	int n = s.length();
	if(i < n){
		return c2i(s[n-1-i]);
	}else{
		return 0;
	}
}

// "100" - "2" = "98"
// preconditions:
// - a and b are both positive numbers
// - a > b
string do_hi_sub_pos(string a, string b){
	int len_a = a.length();
	int maxLen = len_a;

	string r;
	int borrow = 0;
	for(int i=0; i<maxLen; i++){
		int bit_a = getBit(a, i);
		int bit_b = getBit(b, i);

		bit_a = bit_a - borrow;
		if(bit_a < bit_b){
			bit_a += 10;
			borrow = 1;
		}
		else{
			borrow = 0;
		}
		int bit_r = bit_a - bit_b;
		r = i2c(bit_r) + r;
	}

	int i;
	for(i=0; i<r.length(); i++){
		if(r[i] != '0'){
			break;
		}
	}

	return r.substr(i);
}

// '123' > '12'
// preconditions:
// - a and b are positive numbers
int hi_cmp_pos(string a, string b){
	int len_a = a.length();
	int len_b = b.length();
	if(len_a > len_b){
		return 1;
	}else if(len_a < len_b){
		return -1;
	}else{
		for(int i=0; i<len_a; i++){
			if(a[i] > b[i]){
				return 1;
			}else if(a[i] < b[i]){
				return -1;
			}else{
				continue;
			}
		}
	}
	return 0;
}

// substraction
// precondistions:
// - a and b are positive int
string hi_sub_pos(string a, string b){
	int cmp = hi_cmp_pos(a,b);
	if(cmp == 0){
		return "0";
	}else if(cmp > 0){
		return do_hi_sub_pos(a,b);
	}else{
		return "-" + do_hi_sub_pos(b,a);
	}
}


// huge integer addition
// e.g. 123456789123456789123456789 + 88888888888
// preconditions:
// - a and b are both positive int
//
string hi_add_pos(string a, string b){
	int len_a = a.length();
	int len_b = b.length();
	int maxLen = len_a > len_b ? len_a : len_b;
	int minLen = len_a < len_b ? len_a : len_b;

	string r;
	int carry = 0;
	for(int i=0; i<maxLen; i++){
		int bit_a = getBit(a, i);
		int bit_b = getBit(b, i);
		int sum = bit_a + bit_b + carry;
		int bit_r = sum % 10;
		carry = sum / 10;
		r = i2c(bit_r) + r;
	}
	if(carry != 0){
		r = i2c(carry) + r;
	}
	return r;
}

bool is_negative(string s){
	return s[0] == '-';
}

//
// a and b are positive or negative
//
string hi_add(string a, string b){
	if(is_negative(a) && is_negative(b)){
		return "-" + hi_add_pos(a.substr(1), b.substr(1));
	}else if(is_negative(a) && !is_negative(b)){
		return hi_sub_pos(b, a.substr(1));
	}else if(is_negative(b) && !is_negative(a)){
		return hi_sub_pos(a, b.substr(1));
	}else{
		return hi_add_pos(a,b);
	}	
}


int main(){
	cout << hi_add("-9999999999999999999999999999999999999", "1") << endl;
	return 0;
}

