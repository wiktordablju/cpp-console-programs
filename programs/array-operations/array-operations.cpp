#include <iostream>
#include <random>

int main()
{

    std::cout <<"Losowa tablica" << std::endl;
    const int N = 3;
    double tab[N];
    std::default_random_engine eng;
    std::uniform_real_distribution <double> dist(0, 1);

    for (int i = 0; i < N; i++) {
        double x = dist(eng);
        tab[i] = x;
    }
    
    for (int i = 0; i < N; i++) {
       std::cout << tab[i] << std::endl;
    }

    std::cout << "-------------------" << std::endl;
   

    std::cout << "Minimum tablicy" << std::endl;
    double min = tab[0];
    for (int i = 0; i < N; i++) {
       double liczba = tab[i];
       if (min == 0.0) {
           min = liczba;
       }else if (liczba < min) {
           min = liczba;
       }
    }
    std::cout << "najmniejsza liczba to: "<< min <<std::endl;

    std::cout << "-------------------" << std::endl;
    std::cout << "Odwrocona kolejnosc" << std::endl;

    for (int i = 0; i < N/2;i++) {
        double temp = tab[i];   
        tab[i] = tab[N - i - 1]; 
        tab[N - i - 1] = temp;
    }

        for (int i = 0; i < N; i++)
        {
            std::cout << tab[i] << std::endl;
        }
    std::cout << "-------------------" << std::endl;


    std::cout<<"Tabliczka mnozenia" << std::endl;
   const int N4 = 10;
    int tab2[N4][N4];
    for (int i = 0; i < N4; i++) {
        for (int j = 0; j < N4; j++) {
            tab2[i][j] = (i + 1) * (j + 1);
        }
    }

    for (int i = 0; i < N4; i++) {
        for (int j = 0; j < N4; j++) {
            std::cout << tab2[i][j] << "\t";
        }
        std::cout << std::endl;
    }
   std::cout << "-------------------" << std::endl;

    

    std::cout << "Macierz spiralna" << std::endl;
    const int N6 = 2;
    int tab6[N6][N6];

    int value = 1;
    int top = 0,left = 0, bottom = N6 - 1, right = N6 - 1;

    while (value <= N6 * N6) {
        for (int i = left; i <= right; i++) {
            tab6[top][i] = value++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            tab6[i][right] = value++;
        }
        right--;
        for (int i = right; i >= left; i--) {
            tab6[bottom][i] = value++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--) {
            tab6[i][left] = value++;
        }
        left++;
    }

    for (int i = 0; i < N6; i++) {
        for (int j = 0; j < N6; j++) {
            std::cout << tab6[i][j] << "\t";
        }
        std::cout << std::endl;
    }


    std::cout << "-------------------" << std::endl;    

}

