/// \file lecture.h
/// \authors Enzo Allemano, Jonathan Stochetti, Nicolas Viotti
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
    const string STRMOT = "bbababa";
    const string STRNOMDUFICHIER = "../dico_test.txt";
    vector<string> vDico = lecture(STRNOMDUFICHIER);

    if(!vDico.empty()){

        cout << "Mot a chercher : " << STRMOT << endl;

        cout << "rechercheLineaire(vDico,strMot)" << endl;
        cout << rechercheLineaire(vDico, STRMOT) << endl << endl;

        //Attention, le resultat de la fonction va changer au cours du programme car on va par
        //la suite trier le dico. Donc le résultat de l'itérateur va changer et modifier la variable resultat.
        rechercheLineaire(vDico.begin(), vDico.end(), STRMOT);

        //Affichage du dico
        affichageVecteur(vDico);

        //Trie le vecteur vDico pour la recherche dichotomique
        cout << endl << "trie du dictionnaire" << endl;
        trier(vDico);

        cout << endl << "rechercheDichotomique(vDico,strMot)" << endl;

        cout << rechercheDichotomique(vDico, STRMOT) << endl << endl;
        rechercheDichotomique(vDico.begin(), vDico.end(), STRMOT);

        //Affichage du dico
        affichageVecteur(vDico);

        cout << "rechercheDichotomiqueRecursive(vDico,strMot,first,last)" << endl;
        cout << rechercheDichotomiqueRecursive(vDico, STRMOT, 0, 7) << endl << endl;

        //Affichage du dico
        affichageVecteur(vDico);

        cout << "rechercheDichotomiqueRecursive(begin,end,strMot)" << endl;
        cout << rechercheDichotomiqueRecursive(vDico.begin(), vDico.end(), STRMOT) << endl << endl;

        //Affichage du dico
        affichageVecteur(vDico);

        //Test de la fonction inverser
        inverser(vDico);

        cout << endl << "Dico inverse" << endl << endl;

        //Affichage du dico
        affichageVecteur(vDico);
    }
    else{
        cout << "Fichier texte vide ou inexistant !" << endl;
    }

    return 0;
}
