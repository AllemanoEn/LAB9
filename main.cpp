#include <iostream>
#include "recherche.cpp"
#include "lecture.cpp"

#include <vector>

using namespace std;

int main() {
    vector<string> v = lecture("../dico_test.txt");

    cout << rechercheLineaire(v,"je");

    /*
    for (const auto& i : v) {
        cout << i << endl;
    }
    */

    return 0;
}
