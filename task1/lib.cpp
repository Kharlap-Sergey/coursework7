#include "lib.h"

using namespace std;

ifstream in;
ofstream out;

char* information;

bool isWordGood(char* word, char letter) {
	return word[0] == word[strlen(word) - 1] && word[0] == letter;
} 

char toLower(char c) {
	if (c >= 'А' && c <= 'Я') {
		c = c + 32;
	}
	return c;
} 

bool isAlpha(char c) {
	bool ans = 'А' <= c && c <= 'я';
	return ans;
}

void ansver() {
	information = read("input.txt");
	char alpha;

	List* zero = extractWords(information);
	List* curent = zero->next;

	out.open("output.txt");
	out << information << endl;
	out << "\nсостояние списка:\n";
	while (curent != NULL) {
		out << (curent->value) << ' ';
		if (curent->next == NULL) {
			alpha = curent->value[strlen(curent->value) - 1];
		}
		curent = curent->next;
	}
	out << endl;
	curent = zero->next;
	out << "слова начинающиеся и заканчивающиеся на букву " << alpha << ":\n";
	while (curent != NULL) {
		if (isWordGood(curent->value, alpha))
			out << curent->value << ' ';
		curent = curent->next;
	}
	out << '/';
	out.close();
}

List* insertElement(List* current, char* value) {
	List* buf = current->next;
	current->next = new List;
	current = current->next;
	current->value = value;
	current->next = buf;
	return current;
}

List* extractWords(char* text) {
	List* first = new List;
	List* current = first;
	bool isWordStart = false;
	char* buf = new char[NW + 1];
	int len = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		if (isAlpha(text[i])) {
			buf[len] = toLower(text[i]);
			len++;
			isWordStart = true;
		}
		else {
			if (isWordStart) {
				buf[len] = '\0';
				current = insertElement(current, buf);
				isWordStart = false;
				len = 0;
				buf = new char[NW + 1];
			}
		}
	}
	buf[len] = '\0';
	if (len != 0) current = insertElement(current, buf);
	return first;
}

char* read(const char* filename) {
	in.open(filename);
	char* inform = new char[MAX];
	in.get(inform, MAX - 10, '/');
	in.close();
	return inform;
}

void print(const char* filename, char* inf) {
	out.open(filename);
	out << inf << '/';
	out.close();
}