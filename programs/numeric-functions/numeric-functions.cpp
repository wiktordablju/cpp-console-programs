#include <iostream>
#include <random>
#include <string>

double szescian(double liczba) {
    return liczba * liczba * liczba;
}

double potega(double liczba, int n) {
    for (int i = 0; i < n; i++) {
        liczba *= liczba;
    }
    return liczba;
}

double odleglosc(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void zamiana(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int licz_a(const std::string& s) {
    return s.length();
}

void fill(double t[], int n, double a, double b) {
    std::default_random_engine eng;
    std::uniform_real_distribution <double> dist(a, b);
    for (int i = 0; i < n; i++) {
        double x = dist(eng);
        t[i] = x;
    }
}

void display(double t[], int n) {
    if (n <= 0) {
        return;
    }
    std::cout << t[n - 1] << " ";
    display(t, n - 1);
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int fib_iter(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

bool solve(double a, double b, double c, double d, double e, double f, double& x, double& y) {
    double w = (a * e) - (b * d);
    double wx = (c * e) - (f * b);
    double wy = (a*f) - (d*c);
    if (w != 0 && wx!=0 && wy!=0) {
        x = wx / w;
        y = wy / w;
        return true;
    }
    else {
        return false;
    }

}

std::string rev_copy(const std::string& s) {

    return s;
}

void rev(std::string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        std::swap(s[i], s[n - i - 1]);
    }
}

void pobierzDane(std::string& imie, std::string& nazwisko, int& wiek) {
    std::cout << "Podaj imię: ";
    std::cin >> imie;
    std::cout << "Podaj nazwisko: ";
    std::cin >> nazwisko;
    std::cout << "Podaj wiek: ";
    std::cin >> wiek;
}

int main(){
    std::cout << "Szescian" << std::endl;
    std::cout << szescian(2.17) << std::endl;
    std::cout << "--------------" << std::endl;

    std::cout << "Potegowanie" << std::endl;
    std::cout << potega(2.17, 3) << std::endl;
    std::cout << "--------------" << std::endl;

    std::cout<< "Odleglosc punktow" << std::endl;
    std::cout << odleglosc(2, 5, -2, 7) << std::endl;
    std::cout << "--------------" << std::endl;

    std::cout << "Zamiana wartosci" << std::endl;
    int a = 3;
    int b = 4;
    std::cout << a << b << std::endl;
    zamiana(a, b);
    std::cout << a << b << std::endl;
    std::cout << "--------------" << std::endl;

    std::cout << "Dlugosc tekstu" << std::endl;
    std::cout << licz_a("abc") << std::endl;
    std::cout << "--------------" << std::endl;

    std::cout << "Losowanie wartosci" << std::endl;
    double t[2];
    fill(t, 2, 5, 10);
    std::cout << "--------------" << std::endl;

    std::cout << "Wypisywanie od konca" << std::endl;
    display(t, 2);
    std::cout << std::endl;
    std::cout << "--------------" << std::endl;

    std::cout << "Ciag Fibonacciego" << std::endl;
    std::cout << fib(11) << std::endl;
    std::cout << fib_iter(7) << std::endl;
    std::cout << "--------------" << std::endl;

    
    std::cout << "Uklad rownan" << std::endl;
    double x;
    double y;
    std::cout << solve(2, 4, 6, 8, 10, 12, x, y)<<std::endl;
    std::cout << x << y<< std::endl;
    std::cout << "--------------" << std::endl;


    std::cout << "Kopia tekstu" << std::endl;
    std::cout << rev_copy("abcd") << std::endl;
    std::cout << "--------------" << std::endl;

    std::cout << "Odwrocenie tekstu" << std::endl;
    std::string s = "abcd";
    rev(s);
    std::cout << s << std::endl;
    std::cout << "--------------" << std::endl;

    std::cout << "Dane osoby" << std::endl;
    std::string imie, nazwisko;
    int wiek;
    pobierzDane(imie, nazwisko, wiek);
    std::cout << imie << " " << nazwisko << " " << wiek << std::endl;
    std::cout << "--------------" << std::endl;

    // metoda pushback

    return 0;

}

