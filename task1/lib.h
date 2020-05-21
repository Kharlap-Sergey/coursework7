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

char* read(const char* filename); // чтение текста из файла
char toLower(char c); // перевод символа 'c' в нижний регист
List* extractWords(char* text); // выдел€ет слова из текста, создает список из данных слов и возращает указатель на 0 элемент спика
List* insertElement(List* current, char* value);// вставл€ет в список элемент
bool isAlpha(char c); // провер€ет, входит ли символ в русский алфовит
bool isWordGood(char* word, char letter);// провер€ет слово на совпадение первой и последней буквы с заданной
void print(const char* filename, char* inf);// выводит информацию в файл
void ansver();// функци€ выполн€бща€ подсчет ответа (нахождение всех слов удолетвор. условию) и вывод€ща€ ответ в выходной файл