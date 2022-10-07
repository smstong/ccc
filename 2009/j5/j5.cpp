#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int id;
	vector<int> friends;
	bool visited;
};

vector<Node> nodes = {
	{1, {6}, false},
	{2, {6}, false},
	{3, {4,5,6,15}, false},
	{4, {3,5,6}, false},
	{5, {3,4,6}, false},
	{6, {1,2,3,4,5,7}, false},
	{7, {6,8}, false},
	{8, {7,9}, false},
	{9, {8,10,12}, false},
	{10, {9,11}, false},
	{11, {10,12}, false},
	{12, {9,11,13}, false},
	{13, {12,14,15}, false},
	{14, {13}, false},
	{15, {3,13}, false},
	{16, {17,18}, false},
	{17, {16,18}, false},
	{18, {16,17}, false},
};

void print_node(const Node& node)
{
	cout << "{" << node.id << ", [";
	for(int f : node.friends){
		cout << f << ",";
	}
	cout << "], ";
	cout << node.visited << " }" << endl;
}

void print_nodes()
{
	for(auto& node : nodes){
		print_node(node);
	}
}

int indexOfNode(int id)
{
	int ix = -1;
	for(int i=0; i<(int)nodes.size(); i++){
		if(nodes[i].id == id){
			ix = i;
			break;
		}
	}
	return ix;	
}

bool areFriends(int x, int y)
{
	int ix = indexOfNode(x);
	bool found = false;
	for(int f : nodes[ix].friends){
		if(f == y){
			found = true;
			break;
		}
	}
	return found;
}

void add_friendship(int x, int y){
	int ix = indexOfNode(x);
	if(ix < 0){
		nodes.push_back({x, {}, false});
		ix = nodes.size()-1;
	}
	int iy = indexOfNode(y);
	if(iy < 0){
		nodes.push_back({y, {}, false});
		iy = nodes.size()-1;
	}

	bool exist = false;
	for(auto f : nodes[ix].friends){
		if(y == f){
			exist = true;
			break;
		}
	}
	if(!exist){
		nodes[ix].friends.push_back(y);
	}

	for(auto f : nodes[iy].friends){
		if(x == f){
			exist = true;
			break;
		}
	}
	if(!exist){
		nodes[iy].friends.push_back(x);
	}
}

vector<int> direct_friends(int x)
{
	int i = indexOfNode(x);
	if(i<0){
		return vector<int>();
	}
	return nodes[i].friends;
}

vector<int> ff(int x)
{
	vector<int> vff;
	int ix = indexOfNode(x);
	for(auto f : nodes[ix].friends){
		int index = indexOfNode(f);
		for(auto ff : nodes[index].friends){
			bool ok = true;
			// can not be himself
			if(ff == x) {
				ok = false;
			}
			// can not be direct friends
			for(auto f1 : nodes[ix].friends){
				if(f1 == ff){
					ok = false;
					break;
				}
			}
			if(ok){
				vff.push_back(ff);
			}
		}
	}
	return vff;
}

void visit(int id)
{
	int i = indexOfNode(id);
	nodes[i].visited = true;
}

bool isVisited(int id)
{
	int i = indexOfNode(id);
	return nodes[i].visited;
}

bool isIn(vector<int>& v, int i)
{
	bool found = false;
	for(auto e : v){
		if(e==i){
			found = true;
			break;
		}
	}
	return found;
}

int separation(int x, int y)
{
	for(auto& node : nodes){
		node.visited = false;
	}
	vector<int> cur = {x};;
	vector<int> next;

	int steps = 0;
	int connected = false;
	while(true){
		next.clear();
		if(cur.size() == 0){
			break;
		}
		for(auto i : cur){
			visit(i);
			if(i == y){
				connected = true;
				break;
			}
			for(auto f : direct_friends(i)){
				if(!isVisited(f)){
					if(!isIn(next, f)){
						next.push_back(f);
					}
				}
			}
		}
		if(connected){
			break;
		}
		cur = next;
		steps ++;
	}
	if(!connected){
		return -1;
	}
	return steps;				
}

void del_friendship(int x, int y)
{
	int ix = indexOfNode(x);
	int iy = indexOfNode(y);
	if(ix < 0 || iy < 0){
		return;
	}

	vector<int> f;
	for(auto e : nodes[ix].friends){
		if(e != y){
			f.push_back(e);
		}
	}
	nodes[ix].friends = f;

	vector<int> f2;
	for(auto e : nodes[iy].friends){
		if(e != x){
			f2.push_back(e);
		}
	}
	nodes[iy].friends = f2;
}

int main()
{
	char c;
	while(true){
		cin >> c;
		int x,y;
		switch(c){
			case 'p':
				print_nodes();
				break;
			case 'q':
				return 0;
			case 'i':
				cin >> x >> y;
				add_friendship(x,y);
				break;
			case 'd':
				cin >> x >> y;
				del_friendship(x,y);
				break;
			case 'n':
				cin >> x;
				cout << direct_friends(x).size() << endl;
				break;
			case 'f':
				cin >> x;
				cout << ff(x).size() << endl;
				break;
			case 's':
				{
					cin >> x >> y;
					int s = separation(x,y);
					if(s<0){
						cout << "Not connected";
					}else{
						cout << s;
					}
					cout << endl;
				}
				break;
			default:
				break;
		}
	}
	return 0;
}
