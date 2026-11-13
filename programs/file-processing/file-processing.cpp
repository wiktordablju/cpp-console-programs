#include <iostream>
#include <random>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>


//if (std::string(argv[i]) == "-i")

void rand(int n, const std::string& file) {
    std::ofstream s;
    s.open(file);
    std::default_random_engine eng;
    std::uniform_real_distribution <double> dist(1, n);
    
    if (s.is_open()){
        for (int i = 0; i < n; i++) {
            double x = dist(eng);
            s << x <<std::endl;
        }
        s.close();
    }
}

void vec(const std::string& file) {
    std::vector<double> wektor;
    std::ifstream s(file);
    if (s) {
        double x;
        while (s >> x) {
            wektor.push_back(x);
        }
        s.close();
    }
   
}

void wypisz(const std::string& file) {
    std::cout << std::endl;
    std::ifstream s(file);
    if (s) {
        std::string line;
        while (s){
            s >> line;
            if (s) {
                std::cout << line << std::endl;
            }
        }
    }
}

void czyt(const std::string& file) {
    std::ifstream s(file);
    if (s) {
        std::string name;
        int age;
        std::vector<std::string> oldest_names;
        int oldest_age = 0;
        std::vector<std::string> youngest_names;
        int youngest_age = 1000;

        while (s >> name >> age) {
            if (age > oldest_age) {
                oldest_age = age;
                oldest_names.clear();
                oldest_names.push_back(name);
            } else if (age == oldest_age) {
                oldest_names.push_back(name);
            }

            if (age < youngest_age) {
                youngest_age = age;
                youngest_names.clear();
                youngest_names.push_back(name);
            } else if (age == youngest_age) {
                youngest_names.push_back(name);
            }
        }

        std::cout << youngest_age << " ";
        for (const auto& n : youngest_names) {
            std::cout << n << " ";
        }
        std::cout << std::endl;

        std::cout << oldest_age << " ";
        for (const auto& n : oldest_names) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
}

//ifstream f(file, ios_base::binary)
// f.seekg(0, ios_base::end) - ustawianie sie w pliku bez odczytywania
// int size = f.tellg - powie nam rozmiar pliku
// f.seekg(0, ios_base::beg) - back to poczatek
//char* buf = new char[size]
//f.read(buf, size)
//delete() buf
void licz(const std::string& file, char letter) {
    std::ifstream s(file, std::ios_base::binary);
    if (s) {
        s.seekg(0, std::ios_base::end);
        int size = s.tellg();
        s.seekg(0, std::ios_base::beg);
        
        char* buf = new char[size];
        s.read(buf, size);
        
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (buf[i] == letter) {
                count++;
            }
        }
        
        delete[] buf;
        std::cout << letter << " " << count << " razy"<< std::endl;
    }
}



int main(int argc, char** argv)
{ 
    for (int i = 1; i < argc; ++i) {
        std::cout << std::string(argv[i]);
    }

    rand(4, "random.txt");

    vec("random.txt");

    wypisz("random.txt");

    czyt("ludzie.txt");

    licz("litery.txt", 'a');
    licz("litery.txt", 'b');
    licz("litery.txt", 'c');
    licz("litery.txt", 'd');

}

