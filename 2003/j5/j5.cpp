#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
	int x;
	int y;
};

int N;
int r, c;
vector<vector<char>> grid;
vector<vector<Pos>> rooms;

int room_owner(int x, int y){
	for(int i=0; i<rooms.size(); i++){
		for(auto p : rooms[i]){
			if(p.x == x && p.y == y){
				return i;	
			}
		}
	}
	return -1;
}

void print_grid(){
	for(auto row : grid){
		for(auto cell : row){
			cout << cell;
		}
		cout << endl;
	}
}

void print_rooms(){
	for(int i=0; i<rooms.size(); i++){
		cout << "room(" << rooms[i].size() << "):";
		for(int j=0; j<rooms[i].size(); j++){
			cout << "(" << rooms[i][j].x << "," << rooms[i][j].y << ")";
		}
		cout << endl;
	}
}

bool compare_room(vector<Pos> r1, vector<Pos> r2){
	return r1.size() > r2.size();
}

void mark_room(int i, int j){
	if(i<0 || i>=r || j<0 || j>=c){
		return;
	}

	if(grid[i][j] == '.'){
		grid[i][j] = '+';
		mark_room(i-1, j);
		mark_room(i+1, j);
		mark_room(i, j-1);
		mark_room(i, j+1);
	}
}
void get_room(int i, int j){
	mark_room(i,j);
	vector<Pos> room;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(grid[i][j] == '+'){
				grid[i][j] = 'I';
				room.push_back(Pos{i,j});
			}
		}
	}
	if(room.size() > 0){
		rooms.push_back(room);
	}
}


int main(){
	cin >> N >> r >> c;

	for(int i=0; i<r; i++){
		string line;
		cin >> line;
		vector<char> row;
		for(int j=0; j<c; j++){
			row.push_back(line[j]);
		}
		grid.push_back(row);
	}

	//print_grid();
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			get_room(i, j);
		}
	}

	sort(rooms.begin(), rooms.end(), compare_room);
	//print_rooms();
	
	int left = N;
	int doneRooms = 0;
	for(auto& room : rooms){
		left -= room.size();
		if(left < 0){
			left += room.size();
			break;
		}
		doneRooms ++;
	}

	cout << doneRooms << " rooms, " << left << " square metre(s) left over" << endl;

	return 0;
}
