
#include <iostream>
#include "participation.hpp"

using namespace std;

//Constructeur

Participation::Participation() : m_numDossard(0), m_classement(0){}



//dossard

void Participation::setNumDossard(int dossard) {  //setter num dossard
    m_numDossard = dossard;
}

int Participation::getNumDossard() { //getter num dossard
    return m_numDossard;
}





//classement

void Participation::setClassement(int classement) {  //setter classement
    m_classement = classement;
}

int Participation::getClassement()  { //getter classement
    return m_classement;
}




