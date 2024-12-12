#include "competiteur.hpp"
#include <iostream>

// Constructeur par défaut
Competiteur::Competiteur()
    : m_numeroCompetiteur(0), m_classementFIS(0), m_classementWCSL(0) {}

// Constructeur avec paramètres
Competiteur::Competiteur(int numero, std::string nom, std::string prenom, int fis, int wcsl){
    m_numeroCompetiteur = numero;
    m_nomCompetiteur = nom;
    m_prenomCompetiteur = prenom;
    m_classementFIS = fis;
    m_classementWCSL  = wcsl;
    
}

// Getter pour le classement FIS
int Competiteur::getClassementFIS() {
  
    return m_classementFIS; // Retourner le classement FIS
}

// Getter pour le classement WCSL
int Competiteur::getClassementWCSL() {
      
    return m_classementWCSL; // Retourner le classement WCSL
}


void Competiteur::setClassement(int classement) {
    participation.setClassement(classement); // Transfère la valeur à l'objet Participation
}




// Getter pour le nom du compétiteur
std::string Competiteur::getNomCompetiteur() {
    return m_nomCompetiteur;
}

// Getter pour le prénom du compétiteur
std::string Competiteur::getPrenomCompetiteur() {
    return m_prenomCompetiteur;
}

// Setters et getters pour le dossard
void Competiteur::setNumDossard(int dossard) {
    participation.setNumDossard(dossard);
}

int Competiteur::getNumDossard() {
    return participation.getNumDossard();
}

// Affichage des informations du compétiteur
void Competiteur::afficheEtat() {
    
    
    
    
    std::cout << "Dossard : " << participation.getNumDossard()
              << " | Classement : " << participation.getClassement() // appel la methode getclassement de participation pour obtenir le classement
              << " | Numero Competiteur : " << m_numeroCompetiteur
              << " | Nom : " << m_nomCompetiteur
              << " | Prenom : " << m_prenomCompetiteur
              << " | Classement FIS : " << m_classementFIS
              << " | Classement WCSL : " << m_classementWCSL << std::endl;
}
