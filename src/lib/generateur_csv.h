#ifndef DEF_GENERATEUR_CSV
#define DEF_GENERATEUR_CSV

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tab_dyn/tab_dyn.h"
#include "fichier.h"


class CsvGenerateur
{
public:
    CsvGenerateur();
    CsvGenerateur(unsigned int M_NOMBRE_ELEVE);
    ~CsvGenerateur();

    void creerCsv(bool entete);

    unsigned int M_NOMBRE_ELEVE;

private:
    TabDynString m_prenom;
    TabDynString m_nom;
    TabDynString m_matiere_spe;
    TabDynString m_matiere_restante;
    TabDynChar split;


    unsigned int m_id_eleve;

    unsigned int NOMBRE_MATIERE_SPE;
    unsigned int M_NOMBRE_NOM;
    unsigned int M_NOMBRE_PRENOM;
    unsigned int M_NOMBRE_MATIERE_SPE;
};

#endif