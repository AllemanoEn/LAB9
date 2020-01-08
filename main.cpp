#include <iostream>
#include "recherche.cpp"
#include "lecture.cpp"

#include <vector>

using namespace std;

int main() {
    string strMot = "Coding";

    vector<string> vDico = lecture("../dico_test.txt");

    cout << rechercheLineaire(vDico,strMot) << endl << endl;

    auto resultat = rechercheLineaire(vDico.begin(),vDico.end(),strMot);

    inverser(vDico);

    trier(vDico);

    for(const auto& i : vDico){
        cout << i << endl;
    }

    return 0;
}
