#include<iostream>
#include <time.h>
#include <vector>

using namespace std;



int main() {
	setlocale(LC_ALL, "Ru");

	vector <int> A;

	int num;

	while (true) {
		cin >> num;
		if (num == 0) {
			break;
		}
		if (num > 0) {
			A.push_back(num);
		}
		else {
			cout << "Отрицательные числа игнорируются.\n";
		}
	}

	int N = A.size();

	if (N == 0) {
		cout << "Последовательность пустая. Завершение программы.\n";
		return 0;
	}

	vector<int> D(N, 1);
	vector<int> route(N, -1);

	for (int i = 1; i < A.size(); i++) {

		for (int j = i - 1; j >= 0; j--) {
			if (A[j] < A[i] && D[i] <= D[j]) {
				D[i] = D[j] + 1;
				route[i] = j;

			}


		}

	}
	cout << "\nA:\n";

	for (int i = 0; i < N; i++) {
		cout << "A[" << i << "]: " << A[i] << "; ";
	}



	cout << "\nD:\n";

	for (int i = 0; i < N; i++) {
		cout << "D[" << i << "]: " << D[i] << "; ";

	}



	cout << "\n\nroute:\n";

	for (int i = 0; i < N; i++) {
		cout << "route[" << i << "]: " << route[i] << "; ";
	}

	int max = 0;


	for (int i = 0; i < N; i++) {
		if (D[i] > D[max])
			max = i;
	}




	cout << "\n\nПоследовательность:\n";

	vector<int> subSeq;
	for (int i = max; i != -1; i = route[i]) {
		subSeq.push_back(A[i]);
	}

	for (int i = subSeq.size() - 1; i >= 0; i--) {
		cout << subSeq[i] << "; ";
	}

	
}