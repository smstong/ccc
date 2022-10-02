#include <iostream>
#include <vector>
using namespace std;

struct Point{
	int x;
	int y;
};

typedef vector<Point> vp;

vp next_points(const vp& Pc)
{
	vp Pn;
	for(auto p : Pc){
		int x = p.x;
		int y = p.y;
		if(x+2 <= 8){
			if(y+1<=8){
				Pn.push_back({x+2, y+1});
			}
			if(y-1>=1){
				Pn.push_back({x+2, y-1});
			}
		}
		if(x-2 >= 1){
			if(y+1<=8){
				Pn.push_back({x-2, y+1});
			}
			if(y-1>=1){
				Pn.push_back({x-2, y-1});
			}
		}
		if(y+2 <= 8){
			if(x+1<=8){
				Pn.push_back({x+1, y+2});
			}
			if(x-1>=1){
				Pn.push_back({x-1, y+2});
			}
		}
		if(y-2 >= 1){
			if(x+1<=8){
				Pn.push_back({x+1, y-2});
			}
			if(x-1>=1){
				Pn.push_back({x-1, y-2});
			}
		}
	}
	return Pn;
}

bool isPointIn(Point point, const vp& v)
{
	for(auto p: v){
		if(p.x==point.x && p.y == point.y) {
			return true;
			break;
		}
	}
	return false;
}
int main()
{
	Point start;
	Point end;

	cin >> start.x >> start.y;
	cin >> end.x >> end.y;

	int moves = 0;
	vp v(1, start);
	while(true){
		if(isPointIn(end, v)){
			break;
		}
		auto vn = next_points(v);
		v = vn;
		moves ++;
	}

	cout << moves << endl;

	return 0;
}
