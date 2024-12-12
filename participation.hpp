// Participation.hpp

#ifndef PARTICIPATION_HPP
#define PARTICIPATION_HPP

class Participation {
private:
    int m_numDossard;   // Numéro de dossard
    int m_classement;   // Classement calculé dans course slalom
    int m_scoreFIS;     // Score FIS
    int m_scoreWCSL;    // Score WCSL
    int m_scoreTotal;

public:
    Participation();
    
    void setNumDossard(int dossard);
    int getNumDossard();

    
    void setClassement(int classement);
    int getClassement();
    
          
};

#endif // PARTICIPATION_HPP
