#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _Point{
	int x;
	int y;
}Point;

typedef vector<Point> vp;

vp points;
void addPoint(int x, int y){
	Point p;
	p.x = x;
	p.y = y;
	points.push_back(p);
}

int main(void){
	int level;
	int width;
	int X;
	cin >> level >> width >> X;


	addPoint(0,1);
	addPoint(width, 1);

	for(int i=0; i<=level; i++){
	}

	// find points whose x is X
	vector<int> vy;
	for(const Point &p : points){
		if(p.x == X){
			vy.push_back(p.y);
		}
	}

	// print out results
	sort(vy.begin(), vy.end());

	string out;
	for(int y : vy){
		out += to_string(y) + " ";
	}

	if(out.length() > 0){
		out.pop_back();
	}
	cout << out << endl;

	return 0;
}
