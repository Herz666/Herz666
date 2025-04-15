#include <iostream>
#include <fstream>
#include <vector>
#include <TRandom3.h>
#include <TLorentzVector.h>
#include <TMath.h>

using namespace std;

const int NUM_COLS_INITIAL = 4; // Nombre de colonnes initiales dans le fichier

int main() {
    ifstream fichier("p_qqff.dat");
    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier de données." << endl;
        return 1;
    }

    // Vecteurs pour stocker les données du fichier
    vector<vector<double>> data;
    double valeur;

    // Lecture des données à partir du fichier
    while (fichier >> valeur) {
        vector<double> ligne(NUM_COLS_INITIAL, valeur);
        for (int i = 1; i < NUM_COLS_INITIAL; ++i) {
            fichier >> ligne[i];
        }
        data.push_back(ligne);
    }
    fichier.close();

    // Calcul des nouvelles valeurs avec fluctuation Gaussienne
    TRandom3 rand; // Initialisation d'un générateur de nombres aléatoires
    for (int i = 0; i < data.size(); ++i) {
        data[i][3] = data[i][3] + data[i][3] * 0.035 * rand.Gaus(0, 1); // Nouvelle valeur de Eq_s
    }

    // Ouverture du fichier de sortie pour écrire les résultats
    ofstream fout("resultatsqqff_energies.dat");
    if (!fout) {
        cerr << "Erreur : Impossible d'ouvrir le fichier de sortie pour écriture." << endl;
        return 1;
    }

    // Écriture des résultats dans le fichier .dat
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < NUM_COLS_INITIAL; ++j) {
            fout << data[i][j] << " ";
        }
        fout << endl;
    }

    fout.close();

    cout << "Les nouvelles valeurs ont été calculées et écrites dans le fichier resultats_energies.dat." << endl;

    return 0;
}
