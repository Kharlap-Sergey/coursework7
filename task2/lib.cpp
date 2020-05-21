#include "lib.h"

Matrix* read(const char* filename) {
	Matrix* matr = new Matrix;

	ifstream in;
	in.open(filename);
	in >> matr->n;
	in >> matr->m;
	double* mass = new double[matr->n * matr->m + 1];
	for (int i = 0; i < matr->n; i++) {
		for (int j = 0; j < matr->m; j++) {
			in >> *(mass + i * matr->m + j);
		}
	}
	in.close();

	matr->values = mass;
	return matr;
}


void print(const char* filename, bool f, Matrix* matr, Element* elem) {
	fstream out;
	out.open(filename);
	out << matr->n << ' ';
	out << matr->m << endl;;
	for (int i = 0; i < matr->n; i++) {
		for (int j = 0; j < matr->m; j++) {
			out << *(matr->values + i * matr->m + j) << ' ';
		}
		out << endl;
	}
	if (f) out << "������������ ������� - " << elem->value << "\n���������� ������������� �������� " << elem->n << ' ' << elem->m << endl;
	out << '/';
	out.close();
}

bool isRowIncrease(Matrix* matr, int rwoNumber, int rowLength) { // �������� ���� �� �����������
	bool ans = true;
	for (int i = 0; i < rowLength - 1; i++) {
		if (*(matr->values + rwoNumber * rowLength + i) > * (matr->values + rwoNumber * rowLength + i + 1)) {
			ans = false;
			break;
		}
	}
	return ans;
}

bool isRowDecrease(Matrix* matr, int rwoNumber, int rowLength) {// �������� ���� �� ���������
	bool ans = true;
	for (int i = 0; i < rowLength - 1; i++) {
		if (*(matr->values + rwoNumber * rowLength + i) < *(matr->values + rwoNumber * rowLength + i + 1)) {
			ans = false;
			break;
		}
	}
	return ans;
}
bool isRowOdered(Matrix* matr, int rwoNumber, int rowLength) {// �������� ���� �� ���������������
	return isRowDecrease(matr, rwoNumber, rowLength) || isRowIncrease(matr, rwoNumber, rowLength);
}

Element* findMaxSpecificelement(Matrix* matr) {
	Element* element = new Element;

	element->value = -1111111111;
	for (int i = 0; i <= matr->n; i++) {
		double mx = -1111111111;
		int jj = 0;
		if (isRowOdered(matr, i, matr->m)) {
			for (int j = 0; j < matr->m; j++) {
				if (mx < *(matr->values + i * matr->m + j)) {
					mx = *(matr->values + i * matr->m + j);
					jj = j;
				}
			}
			if (element->value < mx) {
				element->n = i;
				element->m = jj;
				element->value = mx;
			}
		}
	}
	return element;
}

void ansver() {
	Matrix* matrix = read("input.txt");
	Element* maxelem = findMaxSpecificelement(matrix);
	print("output.txt", true, matrix, maxelem);
}
