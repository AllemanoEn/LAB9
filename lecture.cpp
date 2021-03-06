/// \file lecture.cpp
/// \authors Enzo Allemano, Jonathan Stochetti, Nicolas Viotti
/// \date 14.01.2020
///
/// Remarque :
///
/// Compilateur : MinGw-g++ 6.3.0

#include "lecture.h"

#include <fstream>

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
            vDictionnaire.push_back(line);
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