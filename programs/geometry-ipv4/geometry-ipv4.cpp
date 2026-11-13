#include <iostream>
#include <math.h>
#include <cstdint> // include cstdint for uint8_t and uint32_t
#include <string>

struct Punkt {
    double x;
    double y;
}; //B, mozna tak utworzyc zmienna globalna

struct Prostokat {
    Punkt A;
    Punkt B;
};

struct Okrag {
    Punkt S;
    double r;
};

enum class Polozenie_Okregow {
    Rozlaczne_Zewnetrznie, Styczne_Zewnetrznie, Przecinajace_sie, Styczne_wewnetrznie, Rozlaczne_wewnetrznie, Wspolsrodkowe 
};

double odleglosc(const Punkt& P1, const Punkt& P2) {
    //root((Xb - Xa)^2 + (Yb-Ya)^2)
    double odlX = P2.x - P1.x;
    double odlY = P2.y - P1.y;
    return sqrt(odlX*odlX + odlY*odlY);
}

double pole(const Prostokat& P1) {
    double a = P1.B.x - P1.A.x;
    double b = P1.B.y - P1.A.y;
    return abs(a) * abs(b);
}

double pole(const Okrag& O) {
    return M_PI * O.r * O.r;
}

Polozenie_Okregow polozenieOkregow(const Okrag& O1, const Okrag& O2) {
    double d = odleglosc(O1.S, O2.S);
    double r1 = O1.r;
    double r2 = O2.r;

    if (d > r1 + r2) {
        return Polozenie_Okregow::Rozlaczne_Zewnetrznie;
    } else if (d == r1 + r2) {
        return Polozenie_Okregow::Styczne_Zewnetrznie;
    } else if (d < r1 + r2 && d > abs(r1 - r2)) {
        return Polozenie_Okregow::Przecinajace_sie;
    } else if (d == abs(r1 - r2)) {
        return Polozenie_Okregow::Styczne_wewnetrznie;
    } else if (d < abs(r1 - r2)) {
        return Polozenie_Okregow::Rozlaczne_wewnetrznie;
    } else {
        return Polozenie_Okregow::Wspolsrodkowe;
    }
}

std::string polozenieOkregowToString(Polozenie_Okregow polozenie) {
    switch (polozenie) {
        case Polozenie_Okregow::Rozlaczne_Zewnetrznie:
            return "Rozlaczne_Zewnetrznie";
        case Polozenie_Okregow::Styczne_Zewnetrznie:
            return "Styczne_Zewnetrznie";
        case Polozenie_Okregow::Przecinajace_sie:
            return "Przecinajace_sie";
        case Polozenie_Okregow::Styczne_wewnetrznie:
            return "Styczne_wewnetrznie";
        case Polozenie_Okregow::Rozlaczne_wewnetrznie:
            return "Rozlaczne_wewnetrznie";
        case Polozenie_Okregow::Wspolsrodkowe:
            return "Wspolsrodkowe";
        default:
            return "Nieznane";
    }
}

const Prostokat& wiekszy(const Prostokat& P1, const Prostokat& P2 ) {
    if (pole(P1) > pole(P2)) {
        return P1;
    }
    else {
        return P2;
    }
}

Prostokat& wiekszy(Prostokat& P1, Prostokat& P2) {
    // to samo, ino teraz nie sa constami, w cpp mozna tworzyc dwie funkcje o tych samych nazwach jesli zwracaja/uzywaja inne/ych typow
    if (pole(P1) > pole(P2)) {
        return P1;
    }
    else {
        return P2;
    }
}

union IP {
    uint32_t entire;
    uint8_t parts[4];
};

std::string ipToString(const IP& ip) {
    return std::to_string(ip.parts[0]) + "." + std::to_string(ip.parts[1]) + "." + std::to_string(ip.parts[2]) + "." + std::to_string(ip.parts[3]);
}

std::string areIPsEqual(const IP& ip1, const IP& ip2) {
    if (ip1.entire == ip2.entire) {
        return "tak";
    } else {
        return "nie";
    }
}

int main() {
    Punkt Pkt1{ 3.5, 4.7 };
    Prostokat Pros1{ {1.2, 2.1}, {4.3, 3.4}};
    //std::cout << Pros1.A.x; 
    Okrag O1{ {5.7, 4.3}, 2.13 };

    /*
    enum Color{
    Red, Green, Blue
    }
    Color c;
    c = Green; - to sa inty (Red - 0, Green - 1, Blue - 2)
    TO JEST PRZESTARZALE
    
    enum class Color2{
    Red, Green, Blue
    }
    Color2 c;
    c = Color2:: Green
    int i = (int) Red
    To jest zgodne z nowszym standardem
    */
    Polozenie_Okregow x;
    x = Polozenie_Okregow::Styczne_wewnetrznie;

    Punkt Pkt31 { 2.0, 3.0 };
    Punkt Pkt32{ 4.0, 5.0 };
    std::cout << odleglosc(Pkt31, Pkt32) << std::endl;

    Prostokat Pros3{ {1.2, 2.3}, {3.4, 4.5} };
    std::cout << pole(Pros3) << std::endl;

    Prostokat Pros4{ {3.0, 4.0}, {100.0, 600.0} };
    Prostokat Pros42 = wiekszy(Pros3, Pros4);
    std::cout << Pros42.A.x << std::endl;

    Okrag O2{ {1.0, 1.0}, 3.0 };
    std::cout << "Pole O1: " << pole(O1) << std::endl;
    std::cout << "Pole O2: " << pole(O2) << std::endl;

    Polozenie_Okregow polozenie = polozenieOkregow(O1, O2);
    std::cout << "Polozenie okregow: " << polozenieOkregowToString(polozenie) << std::endl;

    IP ip;
    ip.parts[0] = 192;
    ip.parts[1] = 168;
    ip.parts[2] = 0;
    ip.parts[3] = 1;
    std::cout << "IP jako uint8_t: " << (int)ip.parts[0] << "." << (int)ip.parts[1] << "." << (int)ip.parts[2] << "." << (int)ip.parts[3] << std::endl;
    std::cout << "IP jako uint32_t: " << ip.entire << std::endl;

    IP ip2{ .parts = {192, 168, 0, 1} };
    IP ip3{ .parts = {192, 168, 0, 10} };
    if (ip2.entire == ip3.entire) {
        std::cout << "ip sa takie same" << std::endl;
    } else {
        std::cout << "ip sa rozne" << std::endl;
    }

    IP ip4{ .parts = {192, 168, 1, 11} };
    IP ip5{ .parts = {192, 168, 1, 12} };

    std::cout << "IP4: " << ipToString(ip4) << std::endl;
    std::cout << "IP5: " << ipToString(ip5) << std::endl;

    std::cout << areIPsEqual(ip4, ip5) << std::endl;
}
