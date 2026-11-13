#include <iostream>

int main()
{
    /* int a, b;
    std::cout << "Podaj liczbe A i B: " << std::endl;
    std::cin >> a >> b;
    std::cout << "Suma: " << a + b << std::endl
        << "Roznica: " << a - b << std::endl
        << "Iloczyn: " << a * b << std::endl
        << "Suma bitowa: << a | b << std::endl "
        << "Iloczyn bitowy: << a & b << std::endl "
        << "Różnica symetryczna: << a ^ b << std::endl "
        << "Przesunięcie bitowe w lewo "
        << "Dzielenie z reszta: << a % b << std::endl ";
        */

    /*
    double a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    double w = (a * e) - (b * d);
    double wx = (c * e) - (f * b);
    double wy = (a*f) - (d*c);
   

    if (w == 0) {
        if (wx == 0 && wy == 0) {
            std::cout << "Uklad nieoznaczony" << std::endl;
        }
        else {
            std::cout << "Uklad sprzeczny" << std::endl;
        }
    } else {
        std::cout << "Niewiadoma x wynosi: " << wx/ w << std::endl << "Niewiadoma y wynosi: " << wy/w;
    }
    */
     
    
    /* double a, b, c;
    std::cout << "Podaj a, b, c " << std::endl;
    std::cin >> a >> b >> c;
    double delta = (b * b) - (4 * a * c);
    double x = -b/2*a;
    double x1 = -b - sqrt(delta) / 2*a;
    double x2 = -b + sqrt(delta) / 2*a; 

    
    if (a == 0) {
        std::cout << "Rownanie jest liniowe" << std::endl << "x wynosi: " << -c / b;
    }
    else  {
        if (delta < 0) {
            std::cout << "Brak rozwiazan" << std::endl;
        }
        else {
            if (delta > 0) {
                std::cout << "Rozwiazanie to: " << x1 << " lub: " << x2;

            }
            else {
                std::cout << "Rozwiazanie to: " << x;

            }
        }
        
    }
    */
    
    // styczen, luty, potem juz ify z reszta z dzielenia
    int dzien;
    std::cout << "Podaj numer dnia w roku: ";
    std::cin >> dzien;
    if (dzien > 0 && dzien < 366) {
        if (dzien < 60) {

        }
    }
    else {
        std::cout << "Podano niepoprawna liczbe ";
    }

}

