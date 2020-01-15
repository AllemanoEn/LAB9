/// \file recherche.h
/// \authors Enzo Allemano, Jonathan Stocchetti, Nicolas Viotti
/// \date 14.01.2020
///
/// \brief \b Laboratoire \b 09
/// \brief Contient les fonctions de recherche linéaire(avec/sans itérateur, dichotomiques (avec/sans itérateur,
/// récursion et surchage)
///
/// Remarque :
///
/// Compilateur : MinGw-g++ 6.3.0

#ifndef LAB9_RECHERCHE_H
#define LAB9_RECHERCHE_H

#include <vector>

using namespace std;
size_t rechercheLineaire(const vector<string>& vDictionnaire, const string& strMotAChercher);

vector<string>::iterator rechercheLineaire(const vector<string>::iterator& itDebut, const vector<string>::iterator& itFin, const string& strMotAChercher);

size_t rechercheDichotomique(const vector<string>& vDictionnaire, const string& strMotAChercher);

vector<string>::iterator rechercheDichotomique(vector<string>::iterator itDebut, vector<string>::iterator itFin, const string& strMotAChercher);

size_t rechercheDichotomiqueRecursive(const vector<string>& vDictionnaire, const string& strMotAChercher);

size_t rechercheDichotomiqueRecursive(const vector<string>& vDictionnaire, const string& strMotAChercher, size_t first, size_t last);

bool rechercheDichotomiqueRecursive(vector<string>::iterator itDebut, vector<string>::iterator itFin, const string& strMotAChercher);

#endif //LAB9_RECHERCHE_H
