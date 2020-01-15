/// \file recherche.cpp
/// \authors Enzo Allemano, Jonathan Stocchetti, Nicolas Viotti
/// \date 14.01.2020
///
/// Remarque :
///
/// Compilateur : MinGw-g++ 6.3.0
#include "recherche.h"

using namespace std;

/// \brief fonction qui va chercher de manière linéaire un mot donné dans un vecteur donné.
/// \param vDictionnaire : vecteur qui contient un ensemble de mots.
/// \param strMotAChercher : mot à chercher dans le vecteur.
/// \return retourne l'indice de l'élément trouvé si le mot est présent dans le vecteur et size_t(-1) sinon.
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

/// \brief fonction qui va chercher de manière linéaire un mot donné dans un intervalle de deux itérateurs.
/// \param itDebut : représente le début d'un vecteur (begin)
/// \param itFin : représente la fin d'un vecteur (end)
/// \param strMotAChercher : mot à chercher dans l'intervalle d'itérateur.
/// \return retourne l'itérateur pointant vers l'élément trouvé. Sinon, elle retourne dico.end().
vector<string>::iterator rechercheLineaire(const vector<string>::iterator& itDebut, const vector<string>::iterator& itFin, const string& strMotAChercher){

    for (auto i = itDebut; i != itFin; ++i){
        if(*i == strMotAChercher){
            return i;
        }
    }

    return itFin;
}

/// \brief fonction qui va chercher de manière dichotomique un mot donné dans un vecteur donné.
/// \param vDictionnaire : vecteur qui contient un ensemble de mots.
/// \param strMotAChercher : mot à chercher dans le vecteur.
/// \return retourne l'indice de l'élément trouvé si le mot est présent dans le vecteur et size_t(-1) sinon.
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

/// \brief fonction qui va chercher de manière dichotomique un mot donné dans un intervalle de deux itérateurs.
/// \param itDebut : représente le début d'un vecteur (begin)
/// \param itFin : représente la fin d'un vecteur (end)
/// \param strMotAChercher : mot à chercher dans l'intervalle d'itérateur.
/// \return retourne l'itérateur pointant vers l'élément trouvé. Sinon, elle retourne dico.end().
vector<string>::iterator rechercheDichotomique(vector<string>::iterator itDebut, vector<string>::iterator itFin, const string& strMotAChercher){

    auto resultatErreur = itFin;

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
            return resultatErreur;
        }

        if (strMotAChercher > *(itDebut + mid)) {
            itDebut += mid;
        } else {
            itFin -= mid;
        }
    }
    return resultatErreur;
}

/// \brief fonction recursive qui va chercher de manière dichotomique un mot donné dans un vecteur donné.
/// \param vDictionnaire : vecteur qui contient un ensemble de mots.
/// \param strMotAChercher : mot à chercher dans le vecteur.
/// \return retourne l'indice de l'élément trouvé si le mot est présent dans le vecteur et size_t(-1) sinon.
size_t rechercheDichotomiqueRecursive(const vector<string>& vDictionnaire, const string& strMotAChercher){

    return rechercheDichotomiqueRecursive(vDictionnaire,strMotAChercher,0,vDictionnaire.size());

}

/// \brief fonction recursive qui va chercher de manière dichotomique un mot donné dans un vecteur donné.
/// \brief la recherche se fait dans un intervalle qui est définit dans les paramètres.
/// \param vDictionnaire : vecteur qui contient un ensemble de mots.
/// \param strMotAChercher : mot à chercher dans le vecteur.
/// \param first : debut de l'intervalle (compris)
/// \param last : fin de l'intervalle (non-compris)
/// \return retourne l'indice de l'élément trouvé si le mot est présent dans le vecteur et size_t(-1) sinon.
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

/// \brief fonction recursive qui va chercher de manière dichotomique un mot donné dans un intervalle de deux itérateurs.
/// \param itDebut : représente le début d'un vecteur (begin)
/// \param itFin : représente la fin d'un vecteur (end)
/// \param strMotAChercher : mot à chercher dans l'intervalle d'itérateur.
/// \return retourne 1 si le mot est trouvé et 0 sinon.
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
