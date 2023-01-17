#include <iostream>
using namespace std;

namespace myspace {
	class Animal
	{
		private:
			string name;
			int age;

		public:
			Animal(){
				this->age = 0;
				this->name = "Unknown";

				cout << "Animal::Animal()\n";
			}
			~Animal(){
				cout << "Animal::~Animal()\n";
			}
		public:
			virtual void say(){
				cout << "Animal::say()\n";
			}
	};

	class Dog : public Animal
	{
		public:
			Dog(){
				cout << "Dog::Dog()\n";
			}
			~Dog(){
				cout << "Dog::~Dog()\n";
			}
		public:
			 void say() override{
				this-> Animal::say();
				cout << "wong!\n";
			}
	};
	class Cat : public Animal
	{
		public:
			Cat(){
				cout << "Cat::Cat()\n";
			}
			~Cat(){
				cout << "Cat::~Cat()\n";
			}
		public:
			 void say() override{
				this-> Animal::say();
				cout << "Mew!\n";
			}
	};

}

using namespace myspace;
int main(){
	Cat cat;
	Dog dog;

	Animal* animalps[] = { &cat, &dog};
	for(auto a : animalps){
		a->say(); // runtime binding (call virtual functions)
	}

	Animal animals[] = {cat, dog};
	for(auto a : animals){
		a.say(); // compile time binding
	}

	return 0;
}
