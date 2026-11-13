#include <iostream>
#include<map>
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>

void liczba_slow(std::map<std::string, int> mapa, const std::string plik) {
    std::ifstream powiesc(plik);
    if (powiesc) {
        std::string slowo;
        while (powiesc >> slowo) {
            mapa[slowo]++;

        }
        for (const auto& n : mapa) {
            std::cout << n.first << " = " << n.second << "; \n";
        }
    }
}

void liczba_par(std::map<std::string, int> mapa, const std::string plik) {
    std::ifstream powiesc(plik);

    if (powiesc) {
        std::string pierwsze_slowo, drugie_slowo;
        if (powiesc >> pierwsze_slowo) {
            while (powiesc >> drugie_slowo) {
                std::string para = pierwsze_slowo + " " + drugie_slowo;
                mapa[para]++;
                pierwsze_slowo = drugie_slowo;
            }
        }

        for (const auto& n : mapa) {
            std::cout << n.first << " = " << n.second << "; \n";
        }
    }
}

void indeksy(std::map < std::string, std::vector<int>> mapa, std::string plik) {
    // zmienna z numerem linii
    // jesli slowo jest to dodaje do wektora z numerami tych linii
    std::ifstream powiesc(plik);
    if (powiesc) {
        int linia = 0;
        std::string slowo;
        while (powiesc >> slowo) {

        }
    }


}

int main() {
    std::string powiesc = "werter.txt";

    std::map<std::string, int> slowa;
    liczba_slow(slowa, powiesc);


    std::cout << "========================================================================================\n";
    // pary slow - Ala ma asa, czyli pierwsza: ala ma druga: ma asa
    std::map<std::string, int> mapa_par;
    liczba_par(mapa_par, powiesc);

    std::map<std::string, std::vector<int>> mapa_indeksy;
    indeksy(mapa_indeksy, powiesc);

    // map<string, pair<vector<string> vecotr<int>>>
    // ala: ma 5, kocha 1, to 3 
    //5/9 na ma, 1/9 na kocha 3/9 na to
    // wylosowuje sie ma
    // potem para ma: 
    // i tak dalej i tak dalej
    //std discrete distribution
}

