#include "menu.h"

using namespace std;

void callMenu() {
	cout << "введите 1 - для перезаписи информации\n\
введите 2 - для показа информации о введенной матрице;\n\
введите 3 - для нахождение максемального элемента, среди упорядоченных по убыванию или возрастанию строк;\n\
введите 4 - для пока результатов;\nиначе программа будет завершнена\n";
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
		cout << "Вычисление ответа\n";
		ansver();
		cout << "Ответ подсчитан успешно\n";
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
	cout << "введенная матрица...\n";
	cout << echo("input.txt");
	cout << "\n";
}
void showOutput() {
	cout << "результат...\n";
	cout << echo("output.txt");
	cout << "\n";
}
void rewriteInputData() {
	cout << "введите n и m - размерность матрицы\n";
	Matrix* matrix = new Matrix;
	cin >> matrix->n >> matrix->m;
	cout << "введите " << matrix->n * matrix->m << " елементов\n";
	matrix->values = new double[matrix->n * matrix->m];
	for (int i = 0; i < matrix->n; i++) {
		for (int j = 0; j < matrix->m; j++) {
			cin >> *(matrix->values + i * matrix->m + j);
		}
	}
	print("input.txt", false, matrix, NULL);
	cout << "\nперезапись выполнена успешно";
}

char* echo(const char* file) {
	char* text = new char[10000];
	ifstream in;
	in.open(file);
	in.get(text, 10000, '/');
	in.close();
	return text;
}