#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

float C[3][2];

void matrix() {
	int A[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} };
	float B[4][2] = { {1.2, 0.5}, {2.8, 0.4}, {5, 1}, {2, 1.5} };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			C[i][j] = 0;
			C[i][j] += A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j] + A[i][3] * B[3][j];
		}
	}
	cout << setw(15) << "C = AxB\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << setw(8) << C[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int gain(bool max) {
	int out = 0;
	if (max) {
		float cmp = 0;
		for (int i = 0; i < 3; i++) {
			if (C[0][i] - C[1][i] > cmp) {
				cmp = C[i][0];
				out = i + 1;
			}
		}
	}
	else {
		float cmp = 1024;
		for (int i = 0; i < 3; i++) {
			if (C[0][i] - C[1][i] < cmp) {
				cmp = C[i][0];
				out = i + 1;
			}
		}
	}
	return(out);
}

int comm(bool max) {
	int out = 0;
	if (max) {
		float cmp = 0;
		for (int i = 0; i < 3; i++) {
			if (C[1][i] > cmp) {
				cmp = C[i][0];
				out = i + 1;
			}
		}
	}
	else {
		float cmp = 1024;
		for (int i = 0; i < 3; i++) {
			if (C[1][i] < cmp) {
				cmp = C[i][0];
				out = i + 1;
			}
		}
	}
	return(out);
}

float msumm() {
	float out = 0;
	for (int i = 0; i < 3; i++) {
		out += C[i][0] - C[i][1];
	}
	return(out);
}

float csumm() {
	float out = 0;
	for (int i = 0; i < 3; i++) {
		out += C[i][1];
	}
	return(out);
}