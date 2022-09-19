#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

void print_vi(vi a)
{
	for(auto i : a)
	{
		cout << i << "\t";
	}
	cout << "\n";
}

void print_vvi(vvi a)
{
	for(auto i : a)
	{
		print_vi(i);
	}
}

void print_vvvi(vvvi a)
{
	for(auto i : a) {
		cout << i.size() << ":\n";
		print_vvi(i);
	}
}

int main()
{
	int T;	// the team to chose
	int G;	// number of games already played

	vi points(4,0);	// points of each team

	// all possible matches ( 6 in total )
	int matches[6][3] = {
		{1,2, 0},  /* team 1 Vs team 2, not done yet */
		{1,3, 0},
		{1,4, 0},
		{2,3, 0},
		{2,4, 0},
		{3,4, 0},
	};

	cin >> T;
	cin >> G;
	for(int i=0; i<G; i++){
		int A, B, Sa, Sb;
		cin >> A >> B >> Sa >> Sb;
		for(int i=0; i<6; i++){
			if(matches[i][0] == A and matches[i][1] == B){
				matches[i][2] = 1;
			}
		}
		if(Sa == Sb){
			points[A-1] += 1;
			points[B-1] += 1;
		}else if(Sa > Sb){
			points[A-1] += 3;
		}else{
			points[B-1] += 3;
		}
	}

	vector<vector<vector<int>>> todo_games;

	// possible games to play. e.g.
	/*
	 * {
	 *		// team 1 vs. 2
	 *		{
	 *			{ 1,1,0,0},
	 *			{ 3,0,0,0},
	 *			{ 0,3,0,0},
	 *
	 *		},
	 *		// team 3 vs. 4
	 *		{
	 *			{ 0,0,1,1},
	 *			{ 0,0,3,0},
	 *			{ 0,0,0,3},
	 *		}
	 * }
	 *
	 */
	for(int i=0; i<6; i++){
		// for every not-yet-played game, there are 3 possible results
		if(matches[i][2] == 0){
			// e.g. delta = {0,0,1,1}
			vector<vector<int>> deltas;

			int A = matches[i][0];
			int B = matches[i][1];

			vector<int> delta1(4,0);
			delta1[A-1] = 1;
			delta1[B-1] = 1;
			deltas.push_back(delta1);

			vector<int> delta2(4,0);
			delta2[A-1] = 3;
			deltas.push_back(delta2);

			vector<int> delta3(4,0);
			delta3[B-1] = 3;
			deltas.push_back(delta3);
			
			todo_games.push_back(deltas);
		}
	}

	//print_vvvi(todo_games);

	vvi R = todo_games[0];
	if(todo_games.size() > 1){
		vvi preR = R;
		for(int g=1; g<(int)todo_games.size(); g++){
			R.clear();
			for(auto delta : todo_games[g]){
				for(auto prer : preR){
					vector<int> r(4,0);	
					for(int i=0; i<4; i++){
						r[i] = prer[i] + delta[i];
					}
					R.push_back(r);
				}
			}
			preR = R;
		}
	}

	int P = 0;
	for(auto r : R){
		vi finalPoints(4,0);
		for(int i=0; i<4; i++){
			finalPoints[i] = points[i] +  r[i];	
		}
		bool win = true;
		for(int i=0; i<4; i++){
			if(i == T-1) continue;
			if(finalPoints[T-1] <= finalPoints[i]){
				win = false;
				break;
			}
		}
		if(win){
			P++;
		}
	}

	cout << P << "\n";
	return 0;
}
