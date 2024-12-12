#ifndef COMPETITEUR_HPP
#define COMPETITEUR_HPP

#include <string>
#include "participation.hpp"

class Competiteur {
private:
    int m_numeroCompetiteur;
    std::string m_nomCompetiteur;
    std::string m_prenomCompetiteur;
    int m_classementFIS;
    int m_classementWCSL;
 
    Participation participation; // Lien avec l'objet Participation
 

public:
    Competiteur();
    Competiteur(int numero, std::string nom, std::string prenom, int fis, int wcsl);

    
    
    int getClassementFIS() ;
    int getClassementWCSL() ;
    
    void setClassement(int classement); // Définit le classement via Participation
    int getClassement();
    
    
    std::string getNomCompetiteur() ;
    std::string getPrenomCompetiteur() ;

    void setNumDossard(int dossard);
    int getNumDossard() ;

    void afficheEtat() ;
};

#endif // COMPETITEUR_HPP
