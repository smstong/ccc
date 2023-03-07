#include <iostream>
using namespace std;

int main(){
	int pink_price;
	int green_price;
	int red_price;
	int orange_price;

	cout << "Cost of PINK tickets:\n";
	cin >> pink_price;
	cout << "Cost of GREEN tickets:\n";
	cin >> green_price;
	cout << "Cost of RED tickets:\n";
	cin >> red_price;
	cout << "Cost of ORANGE tickets:\n";
	cin >> orange_price;

	int amount;
	cout << "How much must be raised with ticket sales?\n";
	cin >> amount;
	cout << "Combinations are\n";

	for(int i=0; i*pink_price <= amount; i++){
		for(int j=0;  i*pink_price + j*green_price <= amount; j++){
			for(int k=0; i*pink_price + j*green_price + k*red_price <= amount; k++){
				for(int m=0; i*pink_price + j*green_price + k*red_price + m*orange_price <= amount; m++){
					if(i*pink_price + j*green_price + k*red_price + m*orange_price == amount){
						cout << "# of PINK is " << i;
						cout << "\t# of GREEN is " << j;
						cout << "\t# of RED is " << j;
						cout << "\t# of ORANGE is " << j << endl;
					}
				}
			}
		}
	}

	return 0;
}
