#include <iostream>
using namespace std;

#define MAX_SIZE 10

int choose_matrix_size()
{
	int size;
	cout << "Choose matrix size: ";
	//cin >> size;
	size = 4;
	return size;
}

void fill_matrix(const int * size, float matrix[MAX_SIZE][MAX_SIZE])
{
	for (size_t r = 0; r < *size; r++)  // row
	{
		for (size_t c = 0; c < *size; c++) // column
		{
			if (r > c) matrix[r][c] = 0;
			else matrix[r][c] = c + r;
		}
	}
}

int choose_matrix_fill()
{
	int wybor;
	cout << "1) wyplenij zerami pola pod diagonalna";
	cout << "2) wypelnij zerami pola nad diagonalna";
	wybor = 0;

	if (wybor == 0)
	{

	}
	return wybor;
}

void display_matrix(const int * size, float matrix[MAX_SIZE][MAX_SIZE])
{
	cout << endl;
	for (size_t r = 0; r < *size; r++)  // row
	{
		for (size_t c = 0; c < *size; c++) // column
		{
			cout << "[" << matrix[r][c] << "]";
		}
		cout << endl;
	}
}

int choose_matrix_element(const int * size)
{
	int choice;
	cin >> choice;
	if (choice < 0 || choice >= *size)
	{
		cout << "Error, element doesn't exist!" << endl;
		getchar();
		exit(0);
	}

	return choice;
}

void change_matrix_element(const int * size, float matrix[MAX_SIZE][MAX_SIZE])
{
	cout << "Choose element to change" << endl;

	cout << "Select row:";
	int row = choose_matrix_element(size);
	
	cout << "Select column:";
	int column = choose_matrix_element(size);

	cout << "Enter new value: ";
	cin >> matrix[row][column];
}

void create_new_matrix()
{
	float matrix[MAX_SIZE][MAX_SIZE];

	int size = choose_matrix_size();

	choose_matrix_fill();
	fill_matrix(&size, matrix);
	display_matrix(&size, matrix);
	change_matrix_element(&size, matrix);
	display_matrix(&size, matrix);
}

void load_matrix()
{

}

void save_matrix()
{

}

void menu()
{
	int choice;

	cout << "1) Create Matrix" << endl;
	cout << "2) Load Matrix" << endl;
	cout << "default) Exit" << endl;

	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:
		create_new_matrix();
		break;
	case 2:
		load_matrix();
		break;
	default:
		exit(0);
	}

	menu();
}

int main()
{
	menu();

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