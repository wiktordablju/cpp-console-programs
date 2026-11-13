#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <vector>

/**
 * @brief Droga między klientami A oraz B.
 */
struct Road {
    int clientA; ///< Klienta A
    int clientB; ///< Klienta B
    double distance; ///< Odległość między klientami A oraz B
    bool isOneWay; ///< Czy droga jest jednokierunkowa?
};

/**
 * @brief Mapa przechowująca wszystkie drogi między klientami.
 */
struct Map {
    std::vector<Road> roads; ///< Wektor przechowujący wszystkie drogi
};

#endif
