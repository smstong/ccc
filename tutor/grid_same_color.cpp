/**
 * g++ -std=c++20
 */

#include <iostream>
#include <set>
#include <utility>

using namespace std;

char G[8][8] = {
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,0,1,1,0,0},
	{0,0,0,1,1,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
};
typedef pair<int,int> Point;

void print_set(const set<Point>& s){
	cout << s.size() << ":";
	for(Point p : s){
		cout << "(" << p.first << "," << p.second << "),";
	}
	cout << endl;
}

int main(){

	set<Point> all;
	set<Point> s;
	s.insert(Point(2,3));
	while(!s.empty()){
		set<Point> sn;
		for(Point p : s){
			int i = p.first;
			int j = p.second;
			if(i>=0 && i<8 && j>=0 && j<8 && G[i][j] == 1){
				all.insert(Point(i,j));

				Point adj[] = { 
					Point(i-1,j), 
					Point(i+1,j), 
					Point(i,j-1), 
					Point(i,j+1), 
				};
				for(Point q : adj){
					if(!all.contains(q)){ // C++20
						sn.insert(q);
					}
				}
			}
		}
		s = sn;
	}

	print_set(all);
	return 0;
}
