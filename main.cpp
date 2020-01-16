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
#include <algorithm>

using namespace std;


void affichageVecteur(const vector<string>& v){
    for(const auto& i : v){
        cout << i << endl;
    }
}

int main() {
    const string STRNOMDUFICHIER = "../dictionnaire-UNIX/dictionary.txt";
    const string STRLIVRE = "../livre/input_sh.txt";
    vector<string> vDico = lecture(STRNOMDUFICHIER);
    vector<string> vLivre = lireTexte(STRLIVRE);
    vector<string> vLivreFormate;
    vector<string> vMotAMot;

    //Trie le dictionnaire avec sort
    sort(vDico.begin(),vDico.end());

    //Le dictionnaire doit existé et être rempli, pareil pour le livre
    if(!vDico.empty() && !vLivre.empty()){

        for(const auto& strLigne : vLivre){
            vMotAMot = separerMots(strLigne);
            vLivreFormate.insert(vLivreFormate.end(),vMotAMot.begin(),vMotAMot.end());
        }

        for(const auto& mot : vLivreFormate) {
            //Le mot n'a pas été trouvé si rechercheDichotomique retourne size_t -1 (size_t -1 = 4294967295) donc si le résultat est plus grand que la taille de vDico.
            if (vDico.size() < rechercheDichotomique(vDico, normaliserMot(mot))) {
                cout << recherchePhrase(vLivre, mot) << " : " << mot << endl;
            }
        }
    }
    else{
        cout << "Fichier texte vide ou inexistant !" << endl;
    }

    return 0;
}
