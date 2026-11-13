#include <iostream>

void my_swap(int* a, int* b) {
	int z = *a;
	*a = *b;
	*b = z;
}

struct Punkt {
	double x;
	double y;
};

void movex(Punkt* a, double x) {
	a->x += x; // a->x == (*a).x = x;
}

void fill_table(double* T, int n, double x) {
	for (double* p = T; p < T + n; p++) {
		*p = x;
	}
}

double* alloc(int n) {
	//double* T = new 
}
int main() {
	int i = 3;
	int* pi = &i;     // pobierz adres i, pointer - wskaznik, wskazuje adres i
	int& ri = i; // trzeba zainicjowac, de facto alias zmiennej i
	*pi = 5;     // wchodzimy we wskaznik pi, pobieramy jego adres i na ten adres wpisujemy 5
	//& dodaje tak jakby gwiazdke, * przed zmienna ja odejmuje, typy musza sie zgadzac
	int** ppi;
	ppi = &pi;
	**ppi = 6;
	int j = 12;
	*ppi = &j;

	int a = 2;
	int b = 3;
	my_swap(&a, &b);

	Punkt P1{ 1.2, 3.4 }; // tworzona na stosie
	Punkt* pP2 = new Punkt{ 10.1, 12.3 }; // tworzona dynamicznie, na stercie
	//delete pP2; // zwolnienie z pamieci;

	std::cout << P1.x << " " << pP2->x << std::endl;
	movex(&P1, 5);
	movex(pP2, 10.1);
	std::cout << P1.x << " " << pP2->x << std::endl;
	delete pP2;

	int n;
	//std::cout << "wielkosc T: ";
	//std::cin >> n;
	n = 5;
	std::cout << std::endl;
	double* T = new double[n];

	fill_table(T, n, 123);
	/*for (int i = 0; i < n; i++) {
		std::cout << T[i] << std::endl;
	}*/
	delete[] T;


	// double** T = new double*[m];
	// double * raw = new double[m*n];
	// for()
	// t[i]  = raw + i*n
	// delete T
	// delete raw
	// 
	// tablica wskaznikow o rozmiarze m i kazdy wiersz jest osobno alokowany
	// najpierw tworzymy ogromna tablice m*n elementow, zeby w pamieci byly blisko siebie
	// tablica pomocnicza z wskaznikami
	// funkcja musi zwracac dwie tablice void alloc2D(double**& T, double*& raw)
}
