#include <iostream>
#include <fstream>
#include <iomanip>

#include "funzioni.hpp"

int main() {
    std::ifstream inFile("data.txt");
    std::ofstream outFile("result.txt");

    if (inFile.fail()) {
        std::cerr << "Errore di apertura data.txt" << std::endl;
        return 2;
    }
    if (outFile.fail()) {
        std::cerr << "Errore di apertura result.txt" << std::endl;
        return 1;
    }
	double value;
	double sum = 0;
	int counter = 0;
	

    while (inFile >> value) {
		
		counter++;
		sum += mapValue(value);
        outFile << counter << " " << std::scientific << std::setprecision(16)<< sum/counter << std::endl;
    }

    inFile.close();
    outFile.close();

    std::cout << "Processo completato, risultato in result.txt\n";
    return 0;
}

