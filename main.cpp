#include <iostream>
#include "recherche.cpp"
#include "lecture.cpp"

#include <vector>

using namespace std;

int main() {
    string strMot = "bbbbbbbbbbb";

    vector<string> vDico = lecture("../dico_test.txt");

    cout << rechercheLineaire(vDico,strMot) << endl << endl;

    //Affichage du dico
    for(const auto& i : vDico){
        cout << i << endl;
    }

    trier(vDico);

    cout << rechercheDichotomique(vDico,strMot) << endl << endl;;
    rechercheDichotomique(vDico.begin(),vDico.end(),strMot);

    //Affichage du dico
    for(const auto& i : vDico){
        cout << i << endl;
    }

    auto resultat = rechercheLineaire(vDico.begin(),vDico.end(),strMot);

    inverser(vDico);

    return 0;
}
