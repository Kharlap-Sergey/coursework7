#include "menu.h"

using namespace std;

void callMenu() {
	cout << "������� 1 - ��� ���������� ����������\n\
������� 2 - ��� ������ ���������� � ��������� �������;\n\
������� 3 - ��� ���������� ������������� ��������, ����� ������������� �� �������� ��� ����������� �����;\n\
������� 4 - ��� ���� �����������;\n����� ��������� ����� ����������\n";
	cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
	int t;
	cin >> t;
	switch (t) {
	case 1: {
		rewriteInputData();
		cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
		break;
	}
	case 2: {
		showInput();
		cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
		break;
	}
	case 3: {
		cout << "���������� ������\n";
		ansver();
		cout << "����� ��������� �������\n";
		cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
		break;
	}
	case 4: {
		showOutput();
		cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";

		break;
	}
	default: {
		return;
	}
	}

	callMenu();
}

void showInput() {
	cout << "��������� �������...\n";
	cout << echo("input.txt");
	cout << "\n";
}
void showOutput() {
	cout << "���������...\n";
	cout << echo("output.txt");
	cout << "\n";
}
void rewriteInputData() {
	cout << "������� n � m - ����������� �������\n";
	Matrix* matrix = new Matrix;
	cin >> matrix->n >> matrix->m;
	cout << "������� " << matrix->n * matrix->m << " ���������\n";
	matrix->values = new double[matrix->n * matrix->m];
	for (int i = 0; i < matrix->n; i++) {
		for (int j = 0; j < matrix->m; j++) {
			cin >> *(matrix->values + i * matrix->m + j);
		}
	}
	print("input.txt", false, matrix, NULL);
	cout << "\n���������� ��������� �������";
}

char* echo(const char* file) {
	char* text = new char[10000];
	ifstream in;
	in.open(file);
	in.get(text, 10000, '/');
	in.close();
	return text;
}