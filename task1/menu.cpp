#include "menu.h"

using namespace std;

void callMenu() {
	cout << "������� 1 - ��� ���������� ����������\n\
������� 2 - ��� ������ ���������� � ��������� �������;\n\
������� 3 - ��� �������� ��������� ���� � �����;\n\
������� 4 - ��� ���� �����������;\n����� ��������� ����� ����������\n";
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
	char* inf = read("input.txt");
	cout << "��������� �����...\n";
	cout << inf << endl;
}
void showOutput() {
	char* inf = read("output.txt");
	cout << "���������...\n";
	cout << inf << endl;
}
void rewriteInputData() {
	cout << "������� ����� �� ������ ����� ��������������� �������� '/'\n";
	char* text = new char[MAX];
	cin.get(text, MAX - 10, '/');
	cout << text;
	cin.get();
	print("input.txt", text);
	cout << "\n���������� ��������� �������";
}