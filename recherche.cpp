#include "recherche.h"

using namespace std;

size_t rechercheLineaire(const vector<string>& vDictionnaire, const string& strMotAChercher){

    int iPos = 0;

    for(const auto& i : vDictionnaire){
        if(i==strMotAChercher){
            return iPos;
        }
        iPos++;
    }

    return -1;
}

vector<string>::iterator rechercheLineaire(const vector<string>::iterator& itDebut, const vector<string>::iterator& itFin, const string& strMotAChercher){

    for (auto i = itDebut; i != itFin; ++i){
        if(*i == strMotAChercher){
            return i;
        }
    }

    return itFin;
}

size_t rechercheDichotomique(const vector<string>& vDictionnaire, const string& strMotAChercher){

    size_t taille = vDictionnaire.size();

    if(taille) {
        int iLePlusPetit = 0;
        int iLePlusGrand = taille - 1;
        while (iLePlusPetit <= iLePlusGrand) {
            size_t mid = iLePlusPetit + (iLePlusGrand - iLePlusPetit) / 2;
            int res = 0;
            if (strMotAChercher == vDictionnaire.at(mid)) {
                res = 1;
            }

            if (res == 1) {
                return mid;
            }

            if (strMotAChercher > vDictionnaire.at(mid)) {
                iLePlusPetit = mid + 1;
            } else {
                iLePlusGrand = mid - 1;
            }
        }
    }
    return -1;
}

vector<string>::iterator rechercheDichotomique(vector<string>::iterator itDebut, vector<string>::iterator itFin, const string& strMotAChercher){


    if(!(itFin->empty())) {

        auto iLePlusPetit = 0;
        auto iLePlusGrand = distance(itDebut,itFin) -1;

        while (itDebut <= itFin) {
            int mid = iLePlusPetit + (iLePlusGrand - iLePlusPetit) / 2;
            int res = 0;
            auto i = itDebut;
            for (; i != itFin ; ++i) {
                if (strMotAChercher == *i && mid == distance(itDebut,i)) {
                    res = 1;
                    break;
                }
            }

            if (res == 1) {
                return i;
            }

            i = itDebut;

            for (; i != itFin ; ++i) {
                if (strMotAChercher > *i && mid == distance(itDebut,i)) {
                    iLePlusPetit = mid + 1;
                    itDebut + iLePlusPetit;
                    break;
                }
                if(strMotAChercher < *i && mid == distance(itDebut,i)) {
                    iLePlusGrand = mid - 1;
                    itFin - iLePlusGrand;
                    break;
                }
            }
        }
    }
    return itFin;
}

size_t rechercheDichotomiqueRecursive(const vector<string>& vDictionnaire, const string& strMotAChercher){
    return -1;
}

size_t rechercheDichotomiqueRecursive(const vector<string>& vDictionnaire, const string& strMotAChercher, size_t first, size_t last){

    size_t taille = vDictionnaire.size();

    if(taille) {

        if(first <= last) {
            size_t mid = first + (last - first) / 2;
            int res = 0;
            if (strMotAChercher == vDictionnaire.at(mid)) {
                res = 1;
            }

            if (res == 1) {
                return mid;
            }

            if (strMotAChercher > vDictionnaire.at(mid)) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }

            rechercheDichotomiqueRecursive(vDictionnaire,strMotAChercher,first,last);

        }
    }
    return -1;
}
