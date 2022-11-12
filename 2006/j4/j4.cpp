#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _Node{
	int id;
	vector<int> ins;
	bool done;
}Node;

vector<Node> nodes;

void addConstraint(int x, int y){
	nodes[y-1].ins.push_back(x);
}

int main(){
	for(int i=0; i<7; i++){
		Node node;
		node.id = i+1;
		node.done = false;
		nodes.push_back(node);
	}
	addConstraint(1,7);
	addConstraint(1,4);
	addConstraint(2,1);
	addConstraint(3,4);
	addConstraint(3,5);

	while(true){
		int x,y;
		cin >> x >> y;
		if(x == 0){
			break;
		}else{
			addConstraint(x,y);
		}
	}

	vector<int> doneIds;
	while(true){
		// find ready nodes
		vector<int> readyNodes;
		for(size_t i=0; i<nodes.size(); i++){
			bool ready = true;
			for(int in : nodes[i].ins){
				if(!nodes[in-1].done){
					ready = false;
					break;
				}
			}
			if(ready && !nodes[i].done){
				readyNodes.push_back(i);
			}
		}
		if(readyNodes.size() == 0){
			break;
		}
		sort(readyNodes.begin(), readyNodes.end());
		int todo = readyNodes[0];
		nodes[todo].done = true;
		doneIds.push_back(nodes[todo].id);
	}

	// check if all nodes are done
	if(doneIds.size() == nodes.size()){
		for(size_t i=0; i<doneIds.size()-1; i++){
			cout << doneIds[i] << " ";
		}
		cout << doneIds[doneIds.size()-1] << endl;
	}else{
		cout << "Cannot complete these tasks.  Going to bed." << endl;
	}
	return 0;
}
