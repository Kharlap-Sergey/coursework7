#include <fstream>
#include <iostream>
using namespace std;

struct Matrix {
	int n, m; // ����������� �������
	double* values; // ������ �� �������� ������� 
};

struct Element {
	int n, m; // ������� ��������
	double value; // �������� ��������
};
void ansver();// ������� ����������� ������� ������ (���������� ���� ���� ���������. �������) � ��������� ����� � �������� ����
Matrix* read(const char* filename); // �������, �������� ������� �� �����.
void print(const char* filename, bool f, Matrix* matr, Element* elem);// �������, ��������� �����.
Element* findMaxSpecificelement(Matrix* matr); // �������, ��������� ������������ ������� ����� ���� �������������� �����.