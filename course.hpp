#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include "competiteur.hpp"

class Course
{
public:
    Course();  // Constructeur par défaut

    Course(std::string emplacement, std::string date, Competiteur participants[]);
    
    virtual void traitementDossards() = 0;
    virtual void afficherParticipants() ; 

private:
    Competiteur m_participants[100];
    std::string m_nomCompetition;
    std::string m_dateCompetition;
 
    int m_nbParticipants;  // Nombre de participants dans la course
    
    
protected:
    void classerLesParticipants();  // Méthode pour classer les participants (à utiliser dans les sous-classes)
};

#endif /* COURSE_HPP */


