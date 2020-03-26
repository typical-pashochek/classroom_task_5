#include <stdio.h>
#include <time.h>
#include <Windows.h>
#define SIZE 40



int length(char str[]) {
	int n = 0;
	while (str[n] != '\0') {
		n = n + 1;
	}
	return n;
}

void StrCopy(char** mass1, char** mass2) {
	int len2 = length(*mass2);
	free(*mass1);
	*mass1 = (char*)malloc((len2 + 1) * sizeof(char));
	(*mass1)[len2] = 0;
	for (int i = 0; i < len2; i++) {
		(*mass1)[i] = (*mass2)[i];
	}


}

void Output(char*** mass) {
	for (int i = 0; i < SIZE; i++) {
		puts((*mass)[i]);
	}
}

int main() {
	srand((unsigned int)time(0));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	COORD position = { 0,0};
	SetConsoleCursorPosition(hConsole, position);
	char** mass = (char**)malloc(sizeof(char*) * SIZE);
	for (int i = 0; i < SIZE; i++) {
		mass[i] = (char*)malloc(sizeof(char) * SIZE);
		mass[i][0] = 0;
	}
	while (0 != 1) {
		for (int j = 0; j < SIZE; j++) {
			mass[SIZE-1][j] = (char)(rand() % 10 + 48);
			if (rand() % 5 == 0) {
				mass[SIZE - 1][j] = ' ';
			}
		}
		mass[SIZE-1][SIZE - 1] = 0;
		Output(&mass);
		SetConsoleCursorPosition(hConsole, position);
		for (int j = 0; j < SIZE - 1; j++) {
			StrCopy(&(mass[j]), &(mass[j+1]));
		}
		Sleep(25);	
	}
	return 0;
}
