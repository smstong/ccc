#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _Entry{
	char k;	/* R, S */
	int v;	/* friend id */
	int when;	/* timestamp (second) */
}E;

void show(const vector<E>& v)
{
	for(auto e : v){
		cout << e.k << " " << e.v << " " << e.when << "\n";
	}
}

int main()
{
	int M;
	cin >> M;

	vector<E> v;
	// save all inputed entries
	for(int i=0; i<M; i++){
		E e;
		cin >> e.k;
		cin >> e.v; 
		e.when = 0;
		v.push_back(e);
	}

	// calculate timestamp for each entry
	v[0].when = 0;
	int ts = 0;
	for(int i=1; i<M; i++){
		if(v[i].k == 'W'){
			ts += 0;
		}else {
			if(v[i-1].k == 'W'){
				ts += v[i-1].v;
			}else{
				ts += 1;
			}
		}
		v[i].when = ts;
	}

	// find distinct friend ids
	vector<int>	ids;
	for(int i=0; i<M; i++){
		if(v[i].k == 'W'){
			continue;
		}

		bool found = false;
		for(auto id : ids){
			if(id == v[i].v){
				found = true;
				break;	
			}
		}
		if(!found){
			ids.push_back(v[i].v);
		}
	}
	sort(ids.begin(), ids.end());

	// calculate wait times
	for(int id : ids){
		cout << id << " ";
		vector<int> whens;
		for(auto e : v){
			if(e.v == id){
				whens.push_back(e.when);
			}
		}
		// no S back for that last R
		if(whens.size() % 2 != 0){
			cout << "-1\n";
			continue;
		}
		int sum = 0;
		for(int i=1; i<(int)whens.size(); i+=2){
			sum += (whens[i]-whens[i-1]);
		}
		cout << sum << "\n";
	}

	return 0;
}
