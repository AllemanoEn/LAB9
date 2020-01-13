#include <iostream>
#include "recherche.cpp"
#include "lecture.cpp"

#include <vector>

using namespace std;

int main() {
    string strMot = "bbaaaa";

    vector<string> vDico = lecture("../dico_test.txt");

    cout << rechercheLineaire(vDico,strMot) << endl << endl;

    //Attention, le resultat de la fonction va changer au cours du programme car on va par
    //la suite trier le dico. Donc le résultat de l'itérateur va changer et modifier la varaible resultat.
    auto resultat = rechercheLineaire(vDico.begin(),vDico.end(),strMot);

    //Affichage du dico
    for(const auto& i : vDico){
        cout << i << endl;
    }

    //Trie le vecteur vDico pour la recherche dichotomique
    trier(vDico);


    cout << rechercheDichotomique(vDico,strMot) << endl << endl;;

    auto resultat2 = rechercheDichotomique(vDico.begin(),vDico.end(),strMot);

    //Affichage du dico
    for(const auto& i : vDico){
        cout << i << endl;
    }

    //Test de la fonction inverser
    inverser(vDico);

    cout << endl << "Dico inverse"<< endl;

    //Affichage du dico
    for(const auto& i : vDico){
        cout << i << endl;
    }

    return 0;
}
