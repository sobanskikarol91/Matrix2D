#include <iostream>
#include <fstream> // zapis/odczyt do/z pliku
#include <windows.h> // kolorowanie skladni
#include <string> // dla getline()
using namespace std;

#define MAX_SIZE 20

enum FILL { DOWN, UP }; // enumerator do okreslenia jak wypelniamy  macierz (gora czy dol zerami)

int choose_matrix_size()
{
	int size;
	cout << "Choose matrix size: ";
	cin >> size;
	return size;
}

bool matrix_up_condition(int row, int column)
{
	return row < column;
}

bool matrix_down_condition(int row, int column)
{
	return row > column;
}

void fill_matrix(const int * size, float matrix[MAX_SIZE][MAX_SIZE], FILL fill)
{
	bool(*condition)(int, int);		// wskaznik na funkcje

	if (fill == FILL::UP) condition = matrix_up_condition;
	else  condition = matrix_down_condition;

	for (size_t r = 0; r < *size; r++)  // row
	{
		for (size_t c = 0; c < *size; c++) // column
		{
			if (condition(r, c)) matrix[r][c] = 0;
			else matrix[r][c] = c + r;
		}
	}
}

FILL choose_matrix_fill()
{
	int wybor;
	system("cls");
	cout << "1)     zeros under diagonal" << endl;
	cout << "other) zeros above diagonal" << endl;

	cin >> wybor;
	system("cls");

	if (wybor == 1) return FILL::DOWN;
	else return FILL::UP;
}

void display_matrix(const int * size, float matrix[MAX_SIZE][MAX_SIZE])
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // koloruj na zolty
	for (size_t r = 0; r < *size; r++)  // row
	{
		for (size_t c = 0; c < *size; c++) // column
		{
			cout << "[" << matrix[r][c] << "]";
		}
		cout << endl;
	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // koloruj na szary
}

int choose_matrix_element(const int * size)
{
	int choice;
	cin >> choice;
	if (choice < 0 || choice >= *size)
	{
		cout << "Error, element doesn't exist!" << endl;
		getchar();
		getchar();
		exit(0);
	}

	return choice;
}

void change_matrix_element(const int * size, float matrix[MAX_SIZE][MAX_SIZE])
{
	cout << "Choose element to change" << endl;

	cout << "Select row: ";
	int row = choose_matrix_element(size);

	cout << "Select column: ";
	int column = choose_matrix_element(size);

	cout << "Enter new value: ";
	cin >> matrix[row][column];
}

int line_counter() // zliczamy ilosc lini aby dowiedziec sie jaki rozmiar ma macierz
{
	string line;
	fstream file;
	file.open("matrix.txt", ios::in);

	int lineAmount = 0;
	while (getline(file, line)) lineAmount++;
	file.close();
	return lineAmount;
}


void load_matrix(int * size, float matrix[MAX_SIZE][MAX_SIZE])
{
	string line;
	fstream file;

	*size = line_counter();

	file.open("matrix.txt", ios::in);

	if (file.good() == true)
	{
		for (int r = 0; r < *size; r++)
			for (int c = 0; c < *size; c++)
				file >> matrix[r][c];

		file.close();
	}
}


void save_matrix(const int * size, float matrix[MAX_SIZE][MAX_SIZE])
{
	string line;
	fstream file;

	file.open("matrix.txt", ios::out | ios::trunc);

	if (file.good() == true)
	{
		for (size_t r = 0; r < *size; r++)
		{
			for (size_t c = 0; c < *size; c++)
				file << matrix[r][c] << " ";

			file << endl;
		}
	}
	else
		cout << "File error!" << endl;

	cout << "save successful!" << endl;
	getchar();
	file.close();
}

void create_new_matrix(int * size, float matrix[MAX_SIZE][MAX_SIZE])
{
	*size = choose_matrix_size();
	FILL fill = choose_matrix_fill();
	fill_matrix(size, matrix, fill);
}

void main_menu(int * size, float matrix[MAX_SIZE][MAX_SIZE])
{
	int choice;

	display_matrix(size,matrix);
	cout << "1) Create new Matrix" << endl;
	cout << "2) Change matrix element" << endl;
	cout << "3) Load Matrix" << endl;
	cout << "other) Save and Exit" << endl;

	cin >> choice;
	system("cls");

	switch (choice)
	{
	case 1:
		create_new_matrix(size, matrix);
		break;
	case 2:
		change_matrix_element(size, matrix);
		break;
	case 3:
		load_matrix(size, matrix);
		break;
	default:
	{
		save_matrix(size, matrix);
		exit(0);
	}
	}

	main_menu(size, matrix);
}

int main()
{
	float matrix[MAX_SIZE][MAX_SIZE];
	int size;

	load_matrix(&size, matrix);
	main_menu(&size, matrix);
	getchar();
	getchar();
	return 0;
}

/*
1)	U¿ytkownik podaje rozmiar utworzonej macierzy kwadratowej, macierz jest tworzona dynamicznie
2)	Wybiera czy pod diagonalna czy nad chce mieæ wypelniona zerami macierz
3)	Reszta danych wype³niona przez wzór z pêtli.
4)	Tworzy na ekranie macierz kwadratowa, z zerami nad lub pod przekatna.
5)	Program ma mieæ mo¿liwoœæ zmiany danego elementu kwadratowej macierzy na element podany przez u¿ytkownika w konsoli.Uzytkownik podaje numer wiersza i kolumny oraz nowy element
6)	Program powinien mieæ opcje zapisu do pliku
7)	Program powinien mieæ opcje wczytania danych z pliku*/