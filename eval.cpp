#include <iostream>
#include <fstream>
#include <cmath>
#include "TLorentzVector.h"
#include "TVector3.h"

using namespace std;

int main() {
    // Ouverture du fichier d'entrée
    ifstream fin("input.dat");
    if (!fin) {
        cerr << "Erreur lors de l'ouverture du fichier d'entrée." << endl;
        return 1;
    }

    // Ouverture du fichier de sortie
    ofstream fout("output.dat");
    if (!fout) {
        cerr << "Erreur lors de l'ouverture du fichier de sortie." << endl;
        return 1;
    }

    // Lecture des données et traitement pour chaque particule
    double px, py, pz, E;
    TLorentzVector particle;

    while (fin >> px >> py >> pz >> E) {
        // Création du vecteur Lorentz pour la particule
        particle.SetPxPyPzE(px, py, pz, E);

        // Calcul des grandeurs physiques
         
    TLorentzVector Z_boson = quark + Quark;

         // Calcul de la masse du boson Z
    double Mz = abs(Z_boson.M());

            // Calcul de m_rec
    double m_rec = sqrt(abs(pow(sqrt(Eq_s) + sqrt(EQ_s), 2) - 2 * sqrt(Eq_s) * sqrt(EQ_s)));

            // Calcul de cos(theta_Z)
    double cos_theta_z = Z_boson.CosTheta();

            // Calcul de cos(theta*) dans le référentiel du Z boson
    TVector3 boostvector = Z_boson.BoostVector();
    quark.Boost(-boostvector); // Boost du quark dans le sens opposé au boost du Z boson
    double cos_theta_star = quark.Vect().Dot(Z_boson.Vect()) / (Z_boson.Vect().Mag() * quark.Vect().Mag());

       // Écriture des résultats dans le fichier de sortie
    fout << Mz << " " << cos_theta_z << " " << cos_theta_star << " " << m_rec << endl;

    }

    // Fermeture des fichiers
    fin.close();
    fout.close();

    cout << "Calculs terminés et écriture dans le fichier 'output.dat'." << endl;

    return 0;
}
