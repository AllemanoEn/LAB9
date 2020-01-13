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
    string strMot = "HES";

    vector<string> vDico = lecture("../dico_test.txt");

    cout << "Mot a chercher : " << strMot << endl;

    cout << "rechercheLineaire(vDico,strMot)" << endl;
    cout << rechercheLineaire(vDico,strMot) << endl << endl;

    //Attention, le resultat de la fonction va changer au cours du programme car on va par
    //la suite trier le dico. Donc le résultat de l'itérateur va changer et modifier la varaible resultat.
    auto resultat = rechercheLineaire(vDico.begin(),vDico.end(),strMot);

    //Affichage du dico
    affichageVecteur(vDico);

    //Trie le vecteur vDico pour la recherche dichotomique
    cout << endl << "trie du dictionnaire" << endl;
    trier(vDico);

    cout << endl << "rechercheDichotomique(vDico,strMot)" << endl;

    cout << rechercheDichotomique(vDico,strMot) << endl << endl;
    //auto resultat2 = rechercheDichotomique(vDico.begin(),vDico.end(),strMot);

    //Affichage du dico
    affichageVecteur(vDico);

    /*
    cout << "rechercheDichotomiqueRecursive(vDico,strMot,first,last)" << endl;
    cout << rechercheDichotomiqueRecursive(vDico,strMot,0,6) << endl << endl;

    //Affichage du dico
    affichageVecteur(vDico);

    //Test de la fonction inverser
    inverser(vDico);

    cout << endl << "Dico inverse"<< endl << endl;

    //Affichage du dico
    affichageVecteur(vDico);
     */

    return 0;
}
