#ifndef DEF_UMPORT
#define DEF_UMPORT

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

void genererEleveViaCsv(std::string const nom_fichier);
/*
en param�tre le nom du fichier a ouvrir
le programme g�n�re les �l�ves de la classe d'Ethan via leur ID (fictif), leur nom, leur prenom et leur mati�res
*/
#endif