#include <fstream>
#include <iostream>
const int NL = 10; // text lenght in liness
const int NS = 100; // lines length
const int NW = 200; // word lenght
const int MAX = NL * NS + 10;

using namespace std;

struct List {
	char* value;
	List* next = NULL;
};

char* read(const char* filename); // ������ ������ �� �����
char toLower(char c); // ������� ������� 'c' � ������ ������
List* extractWords(char* text); // �������� ����� �� ������, ������� ������ �� ������ ���� � ��������� ��������� �� 0 ������� �����
List* insertElement(List* current, char* value);// ��������� � ������ �������
bool isAlpha(char c); // ���������, ������ �� ������ � ������� �������
bool isWordGood(char* word, char letter);// ��������� ����� �� ���������� ������ � ��������� ����� � ��������
void print(const char* filename, char* inf);// ������� ���������� � ����
void ansver();// ������� ����������� ������� ������ (���������� ���� ���� ���������. �������) � ��������� ����� � �������� ����