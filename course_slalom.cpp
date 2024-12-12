#include "course_slalom.hpp"
#include <iostream>
#include <random> //random
#include <algorithm> //sort


using namespace std;

// Constructeur par défaut
Course_Slalom::Course_Slalom() : m_nbParticipant(0) {}


// Constructeur avec paramètres
Course_Slalom::Course_Slalom(std::string emplacement, std::string date, Competiteur participants[])
    : m_emplacement(emplacement), m_date(date), m_nbParticipant(100) {
        
        std::cout << "localisation " <<  emplacement << " le " <<date  << endl;
    for (int i = 0; i < 100; ++i) {
        m_participants[i] = participants[i];
    }
}


// Méthode privée pour attribuer un numéro de dossard unique
int Course_Slalom::attribuerDossard(int borneInf, int borneSup) {
    int dossard;
    do {
        dossard = rand() % (borneSup - borneInf + 1) + borneInf; // Génère un nombre aléatoire entre borneInf et borneSup
    } while (dossardsAttribues[dossard]);

    dossardsAttribues[dossard] = true;
    return dossard;
}

void Course_Slalom::traitementDossards () {
    // Tri par classement WCSL décroissant
    // Objectif : Appliquer les règles de tirage au sort en triant les participants par leur classement WCSL (World Cup Start List).

    int i = 0; // Initialisation de l'index pour parcourir les participants.
    while (i < m_nbParticipant - 1) { // Parcourt tous les participants sauf le dernier (car il sera déjà trié).
        int indexMax = i; // On suppose que le participant à l'index 'i' a le meilleur classement WCSL.
        int j = i + 1; // Début de la recherche pour le participant avec le meilleur classement WCSL dans la partie non triée.

        // Recherche du participant avec le classement WCSL le plus élevé dans la partie non triée.
        while (j < m_nbParticipant) {
            if (m_participants[j].getClassementWCSL() > m_participants[indexMax].getClassementWCSL()) {
                indexMax = j; // Mise à jour de l'index si un meilleur classement WCSL est trouvé.
            }
            ++j; // Passe au participant suivant.
        }

        // Échange les participants si le meilleur classement WCSL trouvé n'est pas déjà en position 'i'.
        if (indexMax != i) {
            Competiteur temp = m_participants[i]; // Sauvegarde temporaire du participant actuel.
            m_participants[i] = m_participants[indexMax]; // Place le participant avec le meilleur classement à l'index 'i'.
            m_participants[indexMax] = temp; // Place l'ancien participant de 'i' à la position trouvée.
        }

        ++i; // Passe à la position suivante pour continuer le tri.
    }

    // Étape 1 : Attribution aléatoire des dossards pour les 7 premiers
    for (i = 0; i < 7; ++i) {
        int dossard = attribuerDossard(1, 7); // Tirage au sort pour les 7 premiers (dossards 1 à 7)
        m_participants[i].setNumDossard(dossard);
        m_participants[i].setClassement(i + 1);
    }

    // Étape 2 : Attribution aléatoire des dossards pour les 8 suivants (dossards 8 à 15)
    for (i = 7; i < 15; ++i) {
        int dossard = attribuerDossard(8, 15); // Tirage au sort pour les 8 suivants (dossards 8 à 15)
        m_participants[i].setNumDossard(dossard);
        m_participants[i].setClassement(i + 1);
    }

    // Étape 3 : Attribution des dossards 16 à 30 dans l'ordre de la WCSL
    for (i = 15; i < 30; ++i) {
        m_participants[i].setNumDossard(i + 1); // Dossards 16 à 30 attribués dans l'ordre de la WCSL
        m_participants[i].setClassement(i + 1);
    }

    
    // Étape 4 : Tri des participants restants par classement FIS décroissant
    // Implémentation de l'algorithme de tri par sélection.

    i = 30; // Initialisation à l'index 30 (les 30 premiers participants sont déjà triés ou ne font pas partie de cette étape).
    while (i < m_nbParticipant - 1) { // Parcourt les participants restants (de l'index 30 au dernier).
        int indexMax = i; // On suppose que le participant à l'index 'i' a le plus haut classement FIS.
        int j = i + 1; // Début de la recherche du participant avec le meilleur classement FIS parmi les suivants.

        // Recherche du participant avec le classement FIS le plus élevé dans la partie non triée.
        while (j < m_nbParticipant) {
            if (m_participants[j].getClassementFIS() > m_participants[indexMax].getClassementFIS()) {
                indexMax = j; // Mise à jour de l'index si un meilleur classement FIS est trouvé.
            }
            ++j; // Passe au participant suivant.
        }

        // Échange les participants si le meilleur classement FIS trouvé n'est pas déjà en position 'i'.
        if (indexMax != i) {
            Competiteur temp = m_participants[i]; // Sauvegarde temporaire du participant actuel.
            m_participants[i] = m_participants[indexMax]; // Place le participant avec le meilleur classement à l'index 'i'.
            m_participants[indexMax] = temp; // Place l'ancien participant de 'i' à la position trouvée.
        }

        ++i; // Passe à la position suivante pour continuer le tri.
    }

    // Étape 5 : Attribution des dossards 31 à 100 dans l'ordre de FIS
    for (i = 30; i < m_nbParticipant; ++i) {
        m_participants[i].setNumDossard(i + 1); // Dossards 31 à 100 attribués dans l'ordre FIS
        m_participants[i].setClassement(i + 1);
    }

    // Étape 6 : Tri final des participants par numéro de dossard pour l'affichage
    // Implémentation de l'algorithme de tri par sélection.
    i = 0; // Initialisation de l'index pour parcourir les participants.
    while (i < m_nbParticipant - 1) { // Parcourt tous les participants sauf le dernier (car il sera déjà trié).
        int indexDossardMin = i; // On suppose que le participant à l'index 'i' a le plus petit numéro de dossard.
        int j = i + 1; // Début de la recherche pour le minimum dans la partie non triée.

        // Recherche du participant avec le plus petit numéro de dossard dans la partie non triée.
        while (j < m_nbParticipant) {
            if (m_participants[j].getNumDossard() < m_participants[indexDossardMin].getNumDossard()) {
                indexDossardMin = j; // Mise à jour de l'index si un plus petit numéro de dossard est trouvé.
            }
            ++j; // Passe au participant suivant.
        }

        // Échange des participants si le minimum trouvé n'est pas déjà en position 'i'.
        if (indexDossardMin != i) {
            Competiteur temp = m_participants[i]; // Sauvegarde temporaire du participant actuel.
            m_participants[i] = m_participants[indexDossardMin]; // Place le minimum à l'index 'i'.
            m_participants[indexDossardMin] = temp; // Remet l'ancien participant de 'i' à la place trouvée.
        }

        ++i; // Passe à la position suivante pour continuer le tri.
    }



    // Affichage des participants dans l'ordre des dossards
    afficherParticipants();
}



// Affichage des participants
void Course_Slalom::afficherParticipants() {
    for (int i = 0; i < m_nbParticipant; ++i) {
        m_participants[i].afficheEtat();
    }
}
