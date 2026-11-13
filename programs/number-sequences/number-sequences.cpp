#include <iostream>
#include <random>

int main()
{

	int n;
	std::cout << "podaj liczbe n: ";
	std::cin >> n;
	for (int i = 1; i < n+1; i++) {
		std::cout << i;
	}
	


	
	int n;
	std::cout << "podaj liczbe n: ";
	std::cin >> n;
	
	while (n>0) {
		std::cout << n;
		n--;
	}
	


int liczba, min, max;
int suma = 0;
int liczby = 0;
char kontynuuj;

do
{
	std::cout << "Podaj liczbe: ";
	std::cin >> liczba;

	if (liczby==0) {
		min = liczba;
		max = liczba;
	}

	if(liczba<min) {
		min = liczba;
	}

	if (liczba>max) {
		max = liczba;
	}

	suma += liczba;
	liczby += 1;
	std::cout << "Podajesz dalej? (T/N)";
	std::cin >> kontynuuj;

} while (kontynuuj == 't');

double srednia = suma / liczby;
std::cout << "Wartosc minimalna: " << min << std::endl;
std::cout << "Wartosc maksymalna: " << max << std::endl;
std::cout << "Srednia: " << srednia << std::endl;



	
	int min, max, n;
	char odp;
	std::cout << "podaj liczbe n: ";
	std::cin >> n;
	std::cout << "Podaj zakres liczbowy: ";
	std::cin >> min >> max;
	float sr = (max + min) / 2;
	
	do {
		std::cout << "Czy liczba jest mniejsza od " << sr << std::endl;;
		std::cin >> odp;
		if (odp == 'n') {
			min = sr;
			sr = (max + min) / 2;
			
			
		}
		else if (odp == 't') {
			max = sr;
			sr = (max + min) / 2;
			
		}
	} while (sr!=n);
	std::cout << "twoja liczba to: " << sr;
	



	
	int n;
	double a, q;
	
	
	std::cout << "Ile wyrazow ciagu? " << std::endl;
	std::cin >> n;
	std::cout << "jaki a1 i q? " << std::endl;
	std::cin >> a >> q;
	double sum = 0;
	std::cout << "Ciag geometryczny to: ";
	for (int i = 1; i <= n; i++ ) {
		std::cout << a << std::endl;
		sum = sum + a;
		a = a * q;
		

	}
	std::cout << "Suma to: " << sum;
	





// int n;
// std::cout << "Podaj n: ";
// std::cin >> n;
// std::cout << "0" << "1";
// for (int i = 1; i <= n; i++) {
// 	std::cout << 
// }

int x;
int binarna = 0;
int miejsce = 1; 
std::cout << "Podaj liczbe do przekonwertowania na dwojkowy: ";
std::cin >> x;



do {
    binarna += (x % 2) * miejsce;
    x /= 2;
    miejsce *= 10; 
} while (x != 0);

std::cout << binarna << std::endl;



int x;
int dziesietna = 0;
int potega = 1;

std::cout << "Podaj liczbe do przekonwertowania na dziesietny: ";
std::cin >> x;

while (x>0) {
	int miejsce = x % 10;
	dziesietna += miejsce * potega;
	potega *= 2;
	x /= 10;

}
std::cout << dziesietna;
}


