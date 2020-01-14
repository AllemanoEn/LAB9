#include "recherche.h"

using namespace std;

/// \name
/// \brief
/// \param vDictionnaire
/// \param strMotAChercher
/// \return
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
    return -1;
}

vector<string>::iterator rechercheDichotomique(vector<string>::iterator itDebut, vector<string>::iterator itFin, const string& strMotAChercher){

    while (itDebut <= itFin) {
        int mid = distance(itDebut,itFin) / 2;
        int res = 0;

        if (strMotAChercher == *(itDebut + mid)){
            res = 1;
        }

        if (res == 1) {
            return itDebut + mid -1;
        }

        if(mid == 0){
            return itFin;
        }

        if (strMotAChercher > *(itDebut + mid)) {
            itDebut += mid;
        } else {
            itFin -= mid;
        }
    }
    return itFin;
}

size_t rechercheDichotomiqueRecursive(const vector<string>& vDictionnaire, const string& strMotAChercher){

    return rechercheDichotomiqueRecursive(vDictionnaire,strMotAChercher,0,vDictionnaire.size());

}

size_t rechercheDichotomiqueRecursive(const vector<string>& vDictionnaire, const string& strMotAChercher, size_t first, size_t last){

    if(first <= last) {
        size_t mid = first + (last - first) / 2;
        int res = 0;
        if (mid != last && strMotAChercher == vDictionnaire.at(mid)) {
            res = 1;
        }

        if (res == 1) {
            return mid;
        }

        if(mid == 0 || mid == last-1){
            return -1;
        }

        if (strMotAChercher > vDictionnaire.at(mid)) {
            first = mid;
        } else {
            last = mid;
        }

        return rechercheDichotomiqueRecursive(vDictionnaire,strMotAChercher,first,last);

    }
    return -1;
}

bool rechercheDichotomiqueRecursive(vector<string>::iterator itDebut, vector<string>::iterator itFin, const string& strMotAChercher){

    while (itDebut <= itFin) {
        int mid = distance(itDebut,itFin) / 2;
        int res = 0;

        if (strMotAChercher == *(itDebut + mid)){
            res = 1;
        }

        if (res == 1) {
            return true;
        }

        if(mid == 0){
            return false;
        }

        if (strMotAChercher > *(itDebut + mid)) {
            itDebut += mid;
        } else {
            itFin -= mid;
        }

        return rechercheDichotomiqueRecursive(itDebut,itFin,strMotAChercher);
    }
    return false;
}
