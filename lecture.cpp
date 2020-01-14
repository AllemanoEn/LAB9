#include "lecture.h"

#include <fstream>

using namespace std;

vector<string> lecture(const string& strNomDuFichier){
    vector<string> vDictionnaire;
    vector<string> vError {"Impossible de lire le fichier"};

    string line;
    ifstream inputFile;
    inputFile.open(strNomDuFichier);

    if(inputFile.fail()){
        cerr << "Le fichier n'a pas pu s'ouvrir";
        inputFile.close();
        return vError;
    }

    while (!inputFile.eof()){
        getline(inputFile,line);

        if(!line.empty()){
            vDictionnaire.push_back(line);
        }
    }

    inputFile.close();

    return vDictionnaire;
}

void inverser(vector<string>& vDictionnaire){
    vector<string> vDictionnaireReverse(vDictionnaire.rbegin(),vDictionnaire.rend());
    vDictionnaire = vDictionnaireReverse;
}

void trier(vector<string>& vDictionnaire){

    int iTaille = vDictionnaire.size();

    string temp;

    for (int j=0; j<iTaille-1; j++)
    {
        for (int i=j+1; i<iTaille; i++)
        {
            if (vDictionnaire.at(j).compare(vDictionnaire.at(i)) > 0)
            {
                temp = vDictionnaire.at(j);
                vDictionnaire.at(j) = vDictionnaire.at(i);
                vDictionnaire.at(i) = temp;
            }
        }
    }
}