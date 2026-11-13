#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

/**
 * @brief Wypisuje użytkownikowi krótką instrukcję w przypadku braku podania parametrów.
 */
void instruction() {
    std::cout << "Instrukcja: ./main -i input.txt -d output.txt" << std::endl;
}

/**
 * @brief Wczytuje drogi z pliku wejściowego.
 * 
 * @param filename Nazwa pliku wejściowego.
 * @param map Mapa dróg do wypełnienia.
 */
void loadRoads(const std::string& filename, Map& map) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Nie można otworzyć pliku" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int clientA, clientB;
        double distance;
        char separator1, separator2;
        iss >> clientA >> separator1;
        
        if (separator1 == '-') {
            iss >> separator2;
            Road road;  
            road.clientA = clientA;  
            if (separator2 == '>') {
                iss >> clientB >> separator1 >> distance;
                road.clientB = clientB;
                road.distance = distance;
                road.isOneWay = true; 
            } else {
                iss.putback(separator2); 
                iss >> clientB >> separator1 >> distance;
                road.clientB = clientB;
                road.distance = distance;
                road.isOneWay = false; 
            }
            
            addRoad(map, road); 
        }
    }

    inputFile.close();
}

/**
 * @brief Znajduje najkrótszą drogę kuriera odwiedzającego wszystkich klientów.
 * 
 * @param map Mapa dróg.
 * @return std::pair<std::vector<int>, double> Kolejność odwiedzania klientów i długość drogi.
 */
std::pair<std::vector<int>, double> findShortestPath(const Map& map) {
    std::vector<int> clients;
    for (const auto& road : map.roads) {
        if (std::find(clients.begin(), clients.end(), road.clientA) == clients.end()) {
            clients.push_back(road.clientA);
        }
        if (std::find(clients.begin(), clients.end(), road.clientB) == clients.end()) {
            clients.push_back(road.clientB);
        }
    }

    std::vector<int> bestPath;
    double minDistance = 1e9; // Ogromna liczba, aby zapewnić, że pierwsza znaleziona droga będzie krótsza
    std::sort(clients.begin(), clients.end());
    do {
        double currentDistance = 0.0;
        bool validPath = true;
        for (int i = 0; i < clients.size() - 1; ++i) {
            bool found = false;
            for (const auto& road : map.roads) {
                if ((road.clientA == clients[i] && road.clientB == clients[i + 1]) ||
                    (road.clientA == clients[i + 1] && road.clientB == clients[i])) {
                    currentDistance += road.distance;
                    found = true;
                    break;
                }
            }
            if (!found) {
                validPath = false;
                break;
            }
        }
        // Sprawdzenie powrotu do punktu początkowego
        if (validPath) {
            bool found = false;
            for (const auto& road : map.roads) {
                if ((road.clientA == clients.back() && road.clientB == clients.front()) ||
                    (road.clientA == clients.front() && road.clientB == clients.back())) {
                    currentDistance += road.distance;
                    found = true;
                    break;
                }
            }
            if (!found) {
                validPath = false;
            }
        }
        if (validPath && currentDistance < minDistance) {
            minDistance = currentDistance;
            bestPath = clients;
        }
    } while (std::next_permutation(clients.begin(), clients.end())); // Generuje następną permutację klientów

    return {bestPath, minDistance};
}

/**
 * @brief Przetwarza plik wejściowy i zapisuje wynik do pliku wyjściowego.
 * 
 * @param inputFile Nazwa pliku wejściowego.
 * @param outputFile Nazwa pliku wyjściowego.
 */
void processFile(const std::string& inputFile, const std::string& outputFile) {
    Map map;
    loadRoads(inputFile, map);
    std::pair<std::vector<int>, double> result = findShortestPath(map);
    std::vector<int> bestPath = result.first;
    double minDistance = result.second;

    std::ofstream outputFileStream(outputFile);
    if (bestPath.empty()) {
        outputFileStream << "Nie można wyznaczyć drogi" << std::endl;
    } else {
        outputFileStream << "Najkrótsza droga: ";
        for (int client : bestPath) {
            outputFileStream << client << " ";
        }
        outputFileStream << bestPath.front() << std::endl; // Powrót do punktu początkowego
        outputFileStream << "Długość drogi: " << minDistance << std::endl;
    }
    outputFileStream.close();
}

/**
 * @brief Dodaje drogę do mapy.
 * 
 * @param map Mapa dróg.
 * @param road Droga do dodania.
 */
void addRoad(Map& map, const Road& road) {
    map.roads.push_back(road);
}
