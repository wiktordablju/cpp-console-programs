# C++ Console Programs

Zestaw niezależnych programów konsolowych C++: operacje na liczbach, tablicach,
plikach, strukturach i wskaźnikach oraz przeszukiwanie tras pomiędzy punktami.
Każdy katalog zawiera osobny program z własnym `main`. Część implementacji jest
nieukończona; ograniczenia opisano poniżej.

## Zawartość

| Katalog | Działanie i ograniczenia |
| --- | --- |
| `courier-routes` | Przegląda permutacje punktów i wybiera najkrótszy znaleziony cykl. |
| `programs/console-output` | Wypisuje stały tekst. |
| `programs/calendar-input` | Pobiera numer dnia i sygnalizuje liczby poza zakresem 1–365; nie wyznacza daty. |
| `programs/number-sequences` | Zawiera operacje na ciągach i liczbach; obecnie nie kompiluje się z powodu ponownych deklaracji zmiennych. |
| `programs/array-operations` | Losuje tablicę, wyszukuje minimum, odwraca kolejność, wypisuje tabliczkę mnożenia i spiralę. |
| `programs/numeric-functions` | Uruchamia funkcje liczbowe i tekstowe, następnie odczytuje imię, nazwisko i wiek; część wyników jest niepoprawna. |
| `programs/file-processing` | Wypisuje argumenty, nadpisuje `random.txt`, czyta `ludzie.txt` i zlicza litery w `litery.txt`. |
| `programs/geometry-ipv4` | Obliczenia geometryczne i prezentacja adresów IPv4 na stałych danych. |
| `programs/pointer-operations` | Operacje na wskaźnikach, punktach i dynamicznej tablicy; funkcja `alloc` nie zwraca wyniku. |
| `programs/matrix-operations` | Wczytuje `macierz.txt`; pozostałe operacje macierzowe są nieukończone, program nie wypisuje wyników. |
| `programs/word-frequencies` | Zlicza słowa i sąsiednie pary słów; funkcja indeksowania jest nieukończona. |
| `programs/patient-ordering` | Sortuje rekordy z `patients.txt` według malejącego wieku, a przy remisie według nazwiska. |

## Budowanie i uruchamianie

Wymagany jest kompilator C++ z biblioteką standardową. Sprawdzone polecenia
korzystają z GCC 13.3.0 w Ubuntu/WSL. Nie ma dodatkowych bibliotek aplikacyjnych.
Programy należy uruchamiać z ich katalogów, ponieważ korzystają ze względnych
nazw plików. Polecenia poniżej są przeznaczone dla powłoki systemu Linux/WSL.

Program tras:

```sh
cd courier-routes
g++ -std=c++23 -O3 -pedantic-errors main.cpp functions.cpp -o main
./main -i input.txt -d output.txt
```

Pozostałe programy buduje się niezależnie, wskazując ich pojedynczy plik `.cpp`, np.:

```sh
cd programs/patient-ordering
g++ -std=c++23 -O0 patient-ordering.cpp -o main
./main
```

Każdy katalog w `programs` zawiera też rozwiązanie `.sln` dla Visual Studio 2022,
z toolsetem v143 i Windows SDK 10.0. Konfiguracje zachowują swoje wcześniejsze
ustawienia. Budowania MSVC nie zweryfikowano; pomyślny wynik GCC nie stanowi
potwierdzenia kompilacji tym narzędziem. `number-sequences` pozostaje niebudowalny.

## Format tras

Jeden wiersz opisuje parę całkowitych identyfikatorów i długość drogi:

```text
1 - 2 : 2.0
2 -> 3 : 3.0
3 - 1 : 4.0
```

Parser zapisuje rozróżnienie `-` i `->`, ale wyszukiwanie traktuje oba warianty
jak połączenia dwukierunkowe. Program wypisuje kolejność punktów wraz z powrotem
do początku i łączną długość do pliku wskazanego przez `-d`. Dla powyższych danych
wynik ma długość 9. Dla dołączonego `input.txt` długość wynosi 12.5.
Uruchomienie bez argumentów wyświetla instrukcję.

Przeszukiwanie ma koszt rosnący silniowo. Dla wielokrotnych połączeń tej samej
pary używane jest pierwsze pasujące połączenie. Początkowy limit wyniku to 1e9.
Walidacja wejścia i obsługa błędów plików są niepełne; puste lub błędne wejście
może prowadzić do niezdefiniowanego zachowania. Nie należy zakładać, że zerowy
kod zakończenia oznacza poprawne przetworzenie danych.

## Pliki danych

Dołączone rekordy osób są fikcyjne. `word-frequencies` odczytuje plik o stałej
nazwie `werter.txt` z bieżącego katalogu. Ten plik nie jest dołączony. Aby wykonać
analizę, umieść tam własny tekst, do którego masz prawa. Zmiana tekstu zmienia
wyniki zliczania. Bez pliku program wypisuje jedynie separator.

## Sprawdzenie działania

Repozytorium nie zawiera automatycznego zestawu testów. Po kompilacji można
uruchomić program tras z dołączonym wejściem i sprawdzić wynik:

```text
Najkrótsza droga: 1 2 3 4 5 6 7 1
Długość drogi: 12.5
```

Podczas przygotowania tej wersji porównano 28 przypadków uruchomienia dla
oryginalnych i przygotowanych źródeł, w tym brakujące pliki, dane graniczne,
remisy i grafy bez cyklu. W 26 przypadkach wyniki były identyczne. W dwóch programach jedyną zmianą
wyjścia są opisowe nagłówki sekcji; po uwzględnieniu tych zmian wyniki są zgodne.
11 z 12 programów skompilowało się przed i po zmianach; błędu `number-sequences`
nie poprawiano. Zgodność tych prób nie gwarantuje poprawności wszystkich wejść
ani stabilności zachowania niezdefiniowanego.

## Dokumentacja kodu

Opcjonalnie w `courier-routes` można wykonać `doxygen doxyfile` (konfiguracja
pochodzi z Doxygen 1.9.8). Generowanie dokumentacji nie zostało przetestowane.
Wygenerowane katalogi `html` i `latex` są pomijane przez `.gitignore`.
Oznaczenie autora programu tras zachowane w konfiguracji: Dziendziel.

Projekt nie zawiera pliku licencji.
