#include <iostream>
#include <map>
using namespace std;

// RFC 3986 defines Reserved and Unreserved Characters
// A reserved character with "reserved" purpose  must be urlencoded if it is used as a literal meaning. 
// But it MAY not be urlencoded if it doesn't have "reserved" purpose in the context.
string reserved = "!*'();:@&=+$,/?#[]%";

// unreserved characters SHOULD NOT be urlencoded
string unreserved = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_-+.~";

char hex(int codePoint){
	if(codePoint <= 9 && codePoint >= 0){
		return codePoint + '0';
	}
	if(codePoint <=15 && codePoint >= 10){
		return codePoint - 10 + 'A';
	}
	return 'X';
}	

int unhex(char c){
	if(c >= '0' && c <= '9'){
		return c - '0';
	}
	if(c >= 'A' && c <= 'F'){
		return c - 'A' + 10;
	}
	return -1;
}

string url_encode_char(char c){
	// if c is "unreserved", return it right away
	for(char ci : unreserved){
		if(ci == c){
			return string(1,c);
		}
	}
	// else 
	int low = c & 0x0F;
	int high = (c >> 4) & 0x0F;
	return "%" + string(1, hex(high)) + string(1, hex(low)) ;
}

string url_encode(string s){
	string r;
	for(char c : s){
		r += url_encode_char(c);
	}
	return r;
}

// a=1&b=2
string query_string_encode(const map<string, string>& m){
	string r;
	for(auto it=m.begin(), end=m.end(); it != end; ++it){
		string k = it->first;
		string v = it->second;
		r += url_encode(k) + "=" + url_encode(v) + "&";
	}
	return r.substr(0, r.size()-1); // remove last &
}

// 
string url_decode(string s){
	string r;
	char p;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '%'){
			int high = unhex(s[i+1]);
			int low = unhex(s[i+2]);
			p = (char)((high << 4) + low);
			i += 2;
		}else{
			p = s[i];
		}
		r += p;
	}
	return r;
}
// decode query string
map<string,string> query_string_decode(string s){
	map<string,string> m;
	int start = 0;
	int end = 0;
	for(int i=0, n=s.size(); i<n; i++){
		if(s[i] == '&' || i == n-1){
			end = (i == n-1 ? i : i-1);
			// handle current pair
			int kvd = s.find("=", start);
			string k = url_decode(s.substr(start, kvd-start));
			string v = url_decode(s.substr(kvd+1, end-kvd));
			m[k] = v;
			// prepare for next pair
			start = i+1;
		}
	}

	return m;
}

void print_map(map<string,string> m){
	for(auto& i : m){
		cout << i.first << ":" << i.second << endl;
	}
}

int main(){
	map<string, string> m;
	m["home address"] = "1833 Bayview Ave";
	m["name"] = "Jonathan Zhao";
	m["web"] = "https://linuxexam.net/";
	cout << "data:\n";
	print_map(m);

	// encode
	string s = query_string_encode(m);
	cout << "\nquery string: \n" << s << endl;

	// decode
	map<string,string> map_decoded = query_string_decode(s);
	cout << "\ndecoded:" << endl;
	print_map(map_decoded);

	return 0;
}
