#include "lecture.h"

#include <fstream>

using namespace std;

vector<string> lecture(const string& strNomDuFichier){
    vector<string> vDictionnaire;

    string line;
    ifstream inputFile;
    inputFile.open(strNomDuFichier);

    while (!inputFile.eof()){
        getline(inputFile,line);
        vDictionnaire.push_back(line);
    }

    inputFile.close();

    return vDictionnaire;
}