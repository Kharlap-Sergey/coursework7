const int NL = 100; // text length is in lines
const int NUMW = 100; // lines length is in words
const int NW = 200; // word lenght
const int TextMaxLen = NL * NUMW * NW+10;
const int LineMaxLen = NUMW * NW + 10;
const char IN[] = "input.txt";
const char OUT[] = "output.txt";

struct Sentences {
	int len = 0; // ������ �����������
	int complexity = 0; // ��������� �����������
	char *value; // ��������� �� ���� �����������
};

struct SeparatedText {
	Sentences sentences[NL]; // ������ �������� ��� �����������
	int sentencesNumber = 0; // ����������� ����������� � ������
};
