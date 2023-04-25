#include <iostream>
#include <vector>
using namespace std;

bool isHighCard(string card){
    string highCards[] = {
	"jack", "queen", "king", "ace",
    };
    for(string hc : highCards){
	if(hc == card){
	    return true;
	}
    }
    return false;
}
int main(){
    vector<string> cards;
    for(int i=0; i<52; i++){
	string card;
	cin >> card;
	cards.push_back(card);
    }
    string player;
    int i;
    int scoreA = 0;
    int scoreB = 0;
    for(i=0, player="A"; i<52; i++){
	int left = 51 - i;  // cards left
	string card = cards[i];
	int score = 0;
	if(card == "ace" && left >= 4 && 
		!isHighCard(cards[i+1]) &&
		!isHighCard(cards[i+2]) &&
		!isHighCard(cards[i+3]) &&
		!isHighCard(cards[i+4])){ 
	    score = 4;
	    cout << "Player " << player << " scores 4 point(s)." << endl;
	}else if(card == "king" && left >= 3 && 
		!isHighCard(cards[i+1]) &&
		!isHighCard(cards[i+2]) &&
		!isHighCard(cards[i+3])){ 
	    score = 3;
	    cout << "Player " << player << " scores 3 point(s)." << endl;
	}else if(card == "queen" && left >= 2 && 
		!isHighCard(cards[i+1]) &&
		!isHighCard(cards[i+2])){ 
	    score = 2;
	    cout << "Player " << player << " scores 2 point(s)." << endl;
	}else if(card == "jack" && left >= 1 && 
		!isHighCard(cards[i+1])){ 
	    score = 1;
	    cout << "Player " << player << " scores 1 point(s)." << endl;
	}else{
	    ;
	}


	//cout << player << ":" << card << endl;
	if(player == "A"){
	    scoreA += score;
	    player = "B";
	}else{
	    scoreB += score;
	    player = "A";
	}
    }

    cout << "Player A: " << scoreA << " point(s)." << endl;
    cout << "Player B: " << scoreB << " point(s)." << endl;
    return 0;
}
