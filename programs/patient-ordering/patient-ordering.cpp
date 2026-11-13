#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>

struct Patient{
    std::string surname;
    int age{};
};

void ProcessPatients(const std::string& file, std::vector<Patient>& vector) {
    std::ifstream inputFile(file);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            Patient patient;
            std::string s;
            int a;
            iss >> s >> a;
            patient.surname = s;
            patient.age = a;
            vector.push_back(patient);
        }
        std::sort(vector.begin(), vector.end(), [](const Patient& a, const Patient& b) {
            if (a.age == b.age) { 
                return a.surname < b.surname; } 
            else { return a.age > b.age; }
            });
    }
    else {
        std::cout << "Nie udalo sie prawidlowo otworzyc pliku" << std::endl;
    }  
}

int main(){

    
    std::string file = "patients.txt";
    std::vector<Patient> vector;


    ProcessPatients(file, vector);
    for (int i = 0; i < vector.size();++i) {
        std::cout << vector[i].surname << " " << vector[i].age << std::endl;
    }

    std::vector<int> vector2(100);
    std::default_random_engine eng;
    std::uniform_int_distribution<> dist(1, 10);
    int i = dist(eng);
    std::generate(vector2.begin(), vector2.end(), [&dist, &eng]() {return dist(eng);});
    std::remove(vector2.begin(), vector2.end(), 10);
    // remove usunie kazda 10, ale miejsca po niej wypelni czyms co juz bylo => nie zmieni wielkosci wektora, v.erase zmniejszy bo to metoda czysto wektora a nie funkcja do wielu typow struktur

    std::unique(vector2.begin(), vector2.end());


    return 0;
}

