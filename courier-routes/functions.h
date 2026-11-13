#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include "structs.h"
#include <utility>

/**
 * @brief Wypisuje użytkownikowi krótką instrukcję w przypadku braku podania parametrów.
 */
void instruction();

/**
 * @brief Przetwarza plik wejściowy i zapisuje wynik do pliku wyjściowego.
 * 
 * @param inputFile Nazwa pliku wejściowego.
 * @param outputFile Nazwa pliku wyjściowego.
 */
void processFile(const std::string& inputFile, const std::string& outputFile);

/**
 * @brief Dodaje drogę do mapy.
 * 
 * @param map Mapa dróg.
 * @param road Droga do dodania.
 */
void addRoad(Map& map, const Road& road);

/**
 * @brief Wczytuje drogi z pliku wejściowego.
 * 
 * @param filename Nazwa pliku wejściowego.
 * @param map Mapa dróg do wypełnienia.
 */
void loadRoads(const std::string& filename, Map& map);

/**
 * @brief Znajduje najkrótszą drogę kuriera odwiedzającego wszystkich klientów.
 * 
 * @param map Mapa dróg.
 * @return std::pair<std::vector<int>, double> Kolejność odwiedzania klientów i długość drogi.
 */
std::pair<std::vector<int>, double> findShortestPath(const Map& map);

#endif