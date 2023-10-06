#ifndef DEF_UMPORT
#define DEF_UMPORT

#include <fstream>
#include <sstream>
#include "tab_dyn/tab_dyn.hpp"
#include "eleves.hpp"

std::string ouvrirFichierParLigne(std::string const nom_fichier);
/*
en param�tre le nom du fichier a ouvrir
le programme �crit en console les lignes du fichier ouvert et les renvoie
*/

std::string ouvrirFichierParMot(std::string const nom_fichier);
/*
en param�tre le nom du fichier a ouvrir
le programme parcours chaque mot du fichier
*/

void ouvrirFichierParCaractere(std::string const nom_fichier);
/*
en param�tre le nom du fichier a ouvrir
le programme parcours chaque caract�re du fichier
*/


TabDynEleve genererEleveViaCsv(std::string const nom_fichier);
/*
encore en travail
en param�tre le nom du fichier � extraire
en surtie une liste des donn�es rang�s dans la classe Eleve d'Ethan
*/

TabDynString splitFichier(std::string nom_fichier, char split, char end);
/*
en parametre le fichier � lire, le caractere � sauter et la caracter (unique !) de fin
renvoie un tableau de valeur s�par� par le split jusqu'� atteindre end
*/

int convertString(std::string nombre);
/*
transforme la chaine de caract�re entr�e en int si correspondance
*/
#endif