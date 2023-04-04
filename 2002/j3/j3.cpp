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
	int minCount = 0;
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

						int count = i+j+k+m;
						// init
						if(minCount == 0){
							minCount = count;
						}
						minCount = minCount > count ? count : minCount;
					}
				}
			}
		}
	}
	cout << "Minimum number of tickets to print is " << minCount << endl;

	return 0;
}
