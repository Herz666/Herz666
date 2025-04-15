#include <iostream>
#include <fstream>
#include <vector>
#include <TRandom3.h>
#include <TLorentzVector.h>
#include <TMath.h>

using namespace std;

const int NUM_COLS_INITIAL = 4; // Nombre de colonnes initiales dans le fichier

int main() {
    ifstream fichier("p_hqq.dat");
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

    // Vérification du nombre de lignes
    int num_lignes = data.size();
    if (num_lignes % 2 != 0) {
        cerr << "Erreur : Le nombre de lignes du fichier doit être pair." << endl;
        return 1;
    }

    // Calcul des nouvelles valeurs avec fluctuation Gaussienne
    TRandom3 rand; // Initialisation d'un générateur de nombres aléatoires
    for (int i = 0; i < num_lignes; ++i) {
        data[i][2] = data[i][2] + data[i][2] * 0.035 * rand.Gaus(0, 1); // Nouvelle valeur de Eq_s
    }

    // Ouverture du fichier de sortie pour écrire les résultats
    ofstream fout("r_hqq.dat");
    if (!fout) {
        cerr << "Erreur : Impossible d'ouvrir le fichier de sortie pour écriture." << endl;
        return 1;
    }

    // Calcul du boson Z et des grandeurs associées pour chaque paire de lignes
    for (int i = 0; i < num_lignes; i += 2) {
        // Définition des vecteurs Lorentz pour quark et Quark
        TLorentzVector quark(data[i][0], data[i][1], data[i][2], data[i][3]);
        TLorentzVector Quark(data[i + 1][0], data[i + 1][1], data[i + 1][2], data[i + 1][3]);

        // Calcul du boson Z comme la somme des vecteurs Lorentz de quark et Quark
        TLorentzVector Z_boson = quark + Quark;

        // Calcul de la masse du boson Z
        double Mz = Z_boson.M();

        // Calcul de m_rec
        double m_rec = sqrt(pow(sqrt(data[i][3]) + sqrt(data[i + 1][3]), 2) - 2 * sqrt(data[i][3]) * sqrt(data[i + 1][3]));

        // Calcul de cos(theta_Z)
        double cos_theta_z = Z_boson.CosTheta();

        // Calcul de cos(theta*) dans le référentiel du Z boson
        
    
        TVector3 boostvector = - Z_boson.BoostVector();
        quark.Boost(boostvector); // Boost du quark dans le sens opposé au boost du Z boson
        double cos_theta_star = quark.Vect().Dot(Z_boson.Vect()) / (Z_boson.Vect().Mag() * quark.Vect().Mag());
        

        // Écriture des résultats dans le fichier de sortie
        fout << Mz <<" "<< m_rec <<" "<< cos_theta_z  <<" "<< cos_theta_star << endl;
    }

    fout.close();

    cout << "Les résultats ont été calculés et écrits dans le fichier resultats_energies.dat." << endl;

    return 0;
}
