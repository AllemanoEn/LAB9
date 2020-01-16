/// \file lecture.cpp
/// \authors Enzo Allemano, Jonathan Stocchetti, Nicolas Viotti
/// \date 14.01.2020
///
/// Remarque :
///
/// Compilateur : MinGw-g++ 6.3.0

#include "lecture.h"

#include <fstream>
#include <string>

using namespace std;

/// \brief Permet la lecture d'un fichier ligne par ligne, et les ajoute à la suite dans un vecteur de type string
/// \param strNomDuFichier : contient le nom du fichier à chercher avec son extension (ex: fichier.txt)
/// \return Retourne le vecteur contenant les lignes du fichier qui a été lu
vector<string> lecture(const string& strNomDuFichier){
    vector<string> vDictionnaire;

    string line;
    ifstream inputFile;
    inputFile.open(strNomDuFichier);

    if(inputFile.fail()){
        cerr << "Le fichier n'a pas pu s'ouvrir";
        inputFile.close();
        return vDictionnaire;
    }

    while (!inputFile.eof()){
        getline(inputFile,line);

        if(!line.empty()){
            vDictionnaire.push_back(normaliserMot(line));
        }
    }

    inputFile.close();

    return vDictionnaire;
}
/// \brief Inverse le sens de lecture du vecteur passé en paramètre ( ex: AB -> BA )
/// \param vDictionnaire : vecteur string dont le sens va être inversé
void inverser(vector<string>& vDictionnaire){
    vector<string> vDictionnaireReverse(vDictionnaire.rbegin(),vDictionnaire.rend());
    vDictionnaire = vDictionnaireReverse;
}

/// \brief Trie le vecteur passé en paramètre de manière alphabétique/croissante avec une comparaison char à char
/// \param vDictionnaire
void trier(vector<string>& vDictionnaire){

    int iTaille = vDictionnaire.size();

    string temp;

    for (int j=0; j<iTaille-1; j++)
    {
        for (int i=j+1; i<iTaille; i++)
        {
            if (vDictionnaire.at(j).compare(vDictionnaire.at(i)) > 0)
            {
                temp = vDictionnaire.at(j);
                vDictionnaire.at(j) = vDictionnaire.at(i);
                vDictionnaire.at(i) = temp;
            }
        }
    }
}

/// \brief lit un fichier texte
/// \param fichier : le nom du fichier à lire
/// \return le contenu du fichier sous forme d'un vector de string, chaque string correspondant à une ligne du fichier
vector<string> lireTexte(const string& fichier){
    vector<string> vLivre;

    string line;
    ifstream inputFile;
    inputFile.open(fichier);

    if(inputFile.fail()){
        cerr << "Le fichier n'a pas pu s'ouvrir";
        inputFile.close();
        return vLivre;
    }

    while (!inputFile.eof()){
        getline(inputFile,line);
        vLivre.push_back(line);
    }

    inputFile.close();

    return vLivre;
}

/// \brief coupe une ligne en mots. Un mot est
// défini comme une suite de caractères étant soit
// des lettres de 'a' à 'z' ou de 'A' à 'Z', soit
// l'apostrophe qui est utilisée en anglais dans les
// pluriels. Mais un groupe d'apostrophe(s) ne contenant
// aucune lettre n'est pas considéré comme un mot.
/// \param ligne : la ligne de texte à analyser
/// \return un vector de string, chaque string contenant un mot distinct.
vector<string> separerMots(const string& ligne){

    vector<string> vResultat;
    string strMot;

    for(auto str : ligne){
        if(!isalpha(str)){
            if(str != '\''){
                if(!strMot.empty()){
                    if(strMot.at(strMot.size()-1) == '\''){
                        strMot.erase(strMot.size()-1);
                    }
                    vResultat.push_back(strMot);
                    strMot.clear();
                }
            }else{
                if(!strMot.empty()){
                    strMot += '\'';
                }
            }

        } else{

            strMot += str;
        }
    }

    //Recupère le dernier mot si il n'est pas vide
    if(!strMot.empty()){
        vResultat.push_back(strMot);
    }

    return vResultat;

}

/// \brief Transforme toute les lettres d'un mot en minuscule
/// \param s mot à transformer
/// \return le mot transformer
string normaliserMot(string s){

    string strResultat;

    for(auto lettre : s){
        strResultat += static_cast<char>(tolower(lettre));
    }

    return strResultat;
}