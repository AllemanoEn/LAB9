#include "recherche.h"

using namespace std;

size_t rechercheLineaire(const vector<string>& vDictionnaire, const string& strMotAChercher){

    int iPos = 1;

    for(const auto& i : vDictionnaire){
        if(i==strMotAChercher){
            return iPos;
        }
        iPos++;
    }

    return -1;
}

vector<string>::iterator rechercheLineaire(vector<string>::iterator itDebut, vector<string>::iterator itFin, const string& strMotAChercher){

    for (auto i = itDebut; i != itFin; ++i){
        if(*i == strMotAChercher){
            return i;
        }
    }

    return itFin;
}

size_t rechercheDichotomique(const vector<string>& vDictionnaire, const string& strMotAChercher){

}

