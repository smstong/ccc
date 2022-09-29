#include <iostream>
#include <vector>

using namespace std;
typedef struct _Point{
	int x;
	int y;
}Point;

int main()
{
	vector<Point> V;
	V.push_back({0, -1});
	V.push_back({0, -2});
	V.push_back({0, -3});
	V.push_back({1, -3});
	V.push_back({2, -3});
	V.push_back({3, -3});
	V.push_back({3, -4});
	V.push_back({3, -5});
	V.push_back({4, -5});
	V.push_back({5, -5});
	V.push_back({5, -4});
	V.push_back({5, -3});
	V.push_back({6, -3});
	V.push_back({7, -3});
	V.push_back({7, -4});
	V.push_back({7, -5});
	V.push_back({7, -6});
	V.push_back({7, -7});
	V.push_back({6, -7});
	V.push_back({5, -7});
	V.push_back({4, -7});
	V.push_back({3, -7});
	V.push_back({2, -7});
	V.push_back({1, -7});
	V.push_back({0, -7});
	V.push_back({-1, -7});
	V.push_back({-1, -6});
	V.push_back({-1, -5});

	while(true){
		char direction;
		int u;
		cin >> direction >> u;
		if(direction == 'q'){
			return 0;
		}
		bool danger = false;
		for(int i=0; i<u; i++){
			Point pLast = V[V.size()-1];
			Point pNew = pLast;
			switch(direction){
				case 'l':
					pNew.x = pLast.x - 1;
					pNew.y = pLast.y;
					break;
				case 'r':
					pNew.x = pLast.x + 1;
					pNew.y = pLast.y;
					break;
				case 'u':
					pNew.x = pLast.x;
					pNew.y = pLast.y + 1;
					break;
				case 'd':
					pNew.x = pLast.x;
					pNew.y = pLast.y - 1;
					break;
			}
			for(const auto& e:V){
				if(e.x == pNew.x && e.y == pNew.y){
					danger = true;
					break;
				}
			}
			V.push_back(pNew);
		}

		Point pLast = V[V.size()-1];
		cout << pLast.x << " " << pLast.y << " ";
		if(danger){
			cout << "DANGER\n";
			return 1;
		}else{
			cout << "safe\n";
		}
	}

	return 0;
}
