#include <iostream>

using namespace std;

const int MAX = 100;
void print_answer(int goal, int coinnum, int* count, int* coin);

/* input:
 * coinnum: number of coin types
 * coin[]: values of each coin
 * goal: target value
 * output: number of coin; coin values.
 */
int main(){
	// count[i] store the least number of coin needed for value i
	int count[MAX];
	// coin[] store the value of each coin
	int coin[MAX];
	int goal, j, temp, coinnum;
	do{
		cin >> coinnum;
		if(coinnum <= 0){
			cout << "coin number is less than 1, please input again!" << endl;
		}
		if(coinnum > MAX){
			cout << "coin number is greater than "
					<< MAX << ", please input again!" << endl;
		}
	}while(coinnum <= 0 || coinnum > MAX);
	for(int k = 0; k < coinnum; k++){
		do {
			cin >> coin[k];
			if (coin[k] <= 0) {
				cout << "coin value is less than 1, please input again!" << endl;
			}
		} while (coin[k] <= 0);
	}
	do {
		cin >> goal;
		if (goal <= 0) {
			cout << "goal value is less than 1, please input again!" << endl;
		}
	} while (goal <= 0);

	/* the least number of coin to reach value i is
	 * to use i to minus the value of each coin, respectively
	 * and calculate an array of least number of coin to reach i - coin[j]
	 * (j = 0, 1, ... coinnum - 1)
	 * and pick out the smallest number and plus 1
	 */
	count[0] = 0;
	for(int i = 1; i <= goal; i++){
		temp = goal + 1;
		for(j = 0; j < coinnum; j++){
			if(i - coin[j] >= 0 && count[i - coin[j]] >= 0
					&& temp > count[i - coin[j]]){
				temp = count[i - coin[j]];
			}
		count[i] = temp + 1;
		}
	}
	if(count[goal] > goal) cout << "no answer" << endl;
	else{
		cout << "number of coin: " << count[goal] << endl;
		cout << "coin values: ";
		print_answer(goal, coinnum, count, coin);
	}
	return 0;
}

void print_answer(int goal, int coinnum, int* count, int* coin){
	if(goal == 0) return;
	int j, temp, cointemp = 0;
	temp = goal + 1;
	for (j = 0; j < coinnum; j++) {
		if (goal - coin[j] >= 0 && count[goal - coin[j]] >= 0
				&& temp >= count[goal - coin[j]]) {
			temp = count[goal - coin[j]];
			if(cointemp < coin[j]) cointemp = coin[j];
		}
	}
	if(temp == goal + 1){
		cout << "unknown error!" << endl;
		return;
	}
	cout << cointemp << " ";
	print_answer(goal - cointemp, coinnum, count, coin);
}

