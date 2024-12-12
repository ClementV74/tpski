#ifndef COURSE_SLALOM_HPP
#define COURSE_SLALOM_HPP

#include <string>
#include "competiteur.hpp"
#include "course.hpp"

class Course_Slalom : public Course {
private:
    Competiteur m_participants[100]; // Tableau des compétiteurs
    bool dossardsAttribues[101] = {false}; // Suivi des dossards attribués (1 à 100)
    std::string m_emplacement;
    std::string m_date;
    int m_nbParticipant;

    int attribuerDossard(int borneInf, int borneSup); // Méthode privée pour attribuer un dossard unique

public:
    Course_Slalom();
    Course_Slalom(std::string emplacement, std::string date, Competiteur participants[]);

    void traitementDossards() override; // Méthode spécifique au slalom pour traiter les dossards
    void afficherParticipants() override; // Afficher les participants avec les dossards
};

#endif // COURSE_SLALOM_HPP
