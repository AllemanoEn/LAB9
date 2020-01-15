/// \file lecture.h
/// \authors Enzo Allemano, Jonathan Stocchetti, Nicolas Viotti
/// \date 14.01.2020
///
/// \brief \b Laboratoire \b 09
/// \brief Ce programme permet de chercher un mot avec plusieurs méthodes (voir recherche.h \brief ) dans un fichier.txt
///
/// Remarque(s) : Modifier la variable STRMOT pour changer le mot à chercher
/// Modifier STRNOMDUFICHIER pour changer le fichier dans lequel exécuter la recherche
///
/// Compilateur : MinGw-g++ 6.3.0
#include <iostream>
#include "recherche.cpp"
#include "lecture.cpp"

#include <vector>

using namespace std;


void affichageVecteur(const vector<string>& v){
    for(const auto& i : v){
        cout << i << endl;
    }
    cout << endl;
}

int main() {
    const string STRMOT = "echo";
    const string STRNOMDUFICHIER = "../dictionnaire-UNIX/dictionary.txt";
    const string STRTEXTE = "../livre/input_sh.txt";
    vector<string> vDico = lecture(STRNOMDUFICHIER);

    if(!vDico.empty()){

    }
    else{
        cout << "Fichier texte vide ou inexistant !" << endl;
    }

    return 0;
}
