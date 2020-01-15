/// \file lecture.h
/// \authors Enzo Allemano, Jonathan Stochetti, Nicolas Viotti
/// \date 14.01.2020
///
/// \brief \b Laboratoire \b 09
/// \brief Contient les fonctions permettant de remplir un vecteur à partir d'un fichier texte, d'inverser le sens
/// des éléments d'un vecteur, et de trier le vecteur de manière croissante par comparaison
///
/// Remarque :
///
/// Compilateur : MinGw-g++ 6.3.0

#ifndef LAB9_LECTURE_H
#define LAB9_LECTURE_H

#include <vector>

vector<string> lecture(const string& strNomDuFichier);

void inverser(vector<string>& vDictionnaire);

void trier(vector<string>& vDictionnaire);

vector<string> lireTexte(const string& fichier);

vector<string> separerMots(const string& ligne);

#endif //LAB9_LECTURE_H
