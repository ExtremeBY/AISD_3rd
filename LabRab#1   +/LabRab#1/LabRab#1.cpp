#include "Macros.h"
void hanoi(int N, int from_rod, int aux_rod, int end_rod) {
	if (N == 0)
	{
		ret;
	}
	hanoi(N - 1, from_rod, end_rod, aux_rod);
	vi "Transfer disk " << N << " from " << from_rod << " to " << end_rod << " rod"; nl
	hanoi(N - 1, aux_rod, from_rod, end_rod);
}

int main() {
	SCOCP1251
	SCCP1251
	vi "Enter the number of disks - "; 
	unsigned int N = 3;
	vv N;
	while (N < 0) {
		vi "There can't be a negative number of disks. Correct your mistake plz."; nl
			vi "Enter the number of disks - ";
		vv N;
	}
	if (N == 0) {
		vi "If N = 0, then you don't need to do anything. Goodbye!"; nl
		vi "Shutting down..."; nl
		pause
		ret 0;
	}
	unsigned int num_rods = 3;

	vi "Enter the end rod number - ";
	unsigned int end_rod = 3;
	vv end_rod;
	while (end_rod > num_rods) {
		vi "End rod cant be in the air. There are only " << num_rods << "rods. Correct your mistake plz.";  nl
		vi "Enter the end rod number - ";
		vv end_rod;
	}
	if (end_rod == 1) {
		vi "You don't need to do anything. Goodbye!"; nl
		vi "Shutting down..."; nl
		pause
		ret 0;
	}
	else {
		unsigned int aux_rod = 0;
		unsigned int counter_of_rods = 0;
		for (int i = num_rods; i > 0; i--) {
			counter_of_rods += i;
		}
		aux_rod = counter_of_rods - end_rod - 1;
		unsigned int from_rod = 1;
		hanoi(N, from_rod, aux_rod, end_rod);
	}
	pause
	ret 0;
}