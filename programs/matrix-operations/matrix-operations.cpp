#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


using Matrix = std::vector<std::vector<double>>;

void odczyt(const std::string& file, Matrix& out){
	std::ifstream s(file);
	double liczba;
	double dlugosc{0};
	std::string line;
	while (std::getline(s, line)) {
		std::vector<double> w;
		std::istringstream iss(line);
		while (iss >> liczba) {
			w.push_back(liczba);
		}
		if (w.size()>0){
			if (out.empty() || w.size() == dlugosc ) {
				out.push_back(w);
			}
		}
		dlugosc = w.size();
	}
}

void add(const Matrix& m1, const Matrix& m2, Matrix& out){
	out.clear(); // - bo out moze nie byc pusty


} 

void multiplyk(Matrix& m, double k){}
void transpose(Matrix* pm) { Matrix& m{ *pm }; } // zamiana wierszy z kolumnami
void multiply(const Matrix& m1, const Matrix&m2, Matrix& out){}
void save(const Matrix& m, std::string f){}

int main() {
	//typedef vector<vector<double>> Matrix;
	// using Matrix = vector<vector<double>>; - dziala lepiej z szablonami, nowosc w cpp
	 

	Matrix ma;
	odczyt("macierz.txt", ma);
	
	Matrix mb1;
	Matrix mb2;
	Matrix mbout;
	add(mb1, mb2, mbout);
	

	return 0;
}
