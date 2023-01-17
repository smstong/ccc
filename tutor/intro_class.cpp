#include <iostream>
using namespace std;

namespace myspace {
	class A{
		private:
			string name;
			double score;

		public:
			A(){
				cout << "constructor\n";
			}
			~A(){
				cout << "destructor\n";
			}
		public:
			// copy constructor
			A(const A& old){
				cout << "copy constructor\n";
			}
		public:
			// assignment operator
			A& operator =(const A& o){
				cout << "assignment operator\n";
				return *this;
			}
	};
}

int main(){
	myspace::A a; // constructor
	myspace::A b; // constructor
	cout << &b << endl;
	b = a; // assignment operator
	cout << &b << endl;

	// a destructor
	// b destructor
	return 0;
}

