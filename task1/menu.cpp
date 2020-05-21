#include "menu.h"

using namespace std;

void callMenu() {
	cout << "введите 1 - для перезаписи информации\n\
введите 2 - для показа информации о введенном тексете;\n\
введите 3 - для подсчета вхождения букв в текст;\n\
введите 4 - для пока результатов;\nиначе программа будет завершнена\n";
	cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
	int t ;
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
	case 3:{
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
	char* inf = read("input.txt");
	cout << "введенный текст...\n";
	cout << inf << endl;
}
void showOutput() {
	char* inf = read("output.txt");
	cout << "результат...\n";
	cout << inf << endl;
}
void rewriteInputData() {
	cout << "введите текст на руском языке заканчивающийся символом '/'\n";
	char* text = new char[MAX];
	cin.get(text, MAX - 10, '/');
	cout << text;
	cin.get();
	print("input.txt", text);
	cout << "\nперезапись выполнена успешно";
}