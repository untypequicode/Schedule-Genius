#ifndef DEF_FILE
#define DEF_FILE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "tab_dyn/tab_dyn.hpp"

/*
* Classe Fichier
* Classe de stockage pour exploiter les fichiers
* COntient le nom du fichier et potentiellement son nombre de ligne
* 
* Constructeurs :
* Fichier() : m_name("empty.csv"), m_nb_ligne(0)
* Fichier(std::string nom_fichier) : m_name(nom_fichier), m_nb_ligne(-1) <= valeur inconnu
* Fichier(std::string nom_fichier, unsigned int nombre_de_ligne) : m_name(nom_fichier), m_nb_ligne(nombre_de_ligne)
* 
* Destructeur:
* ~Fichier()
* 
* M�thodes :
* 
* std::string Split(char TabDynChar)
* TabDyn GiveMot(TabDyn split)
* 
* Accesseurs:
* std::string GetNom() const
* int GetNbLigne() const
* std::string GetTexte() const
* 
* Attributs :
* int or insigned int m_nb_ligne
* string m_name
*/
class Fichier
{
public:
	Fichier();
	//cr�er un fichier vide nomm� empty.csv
	Fichier(std::string nom_fichier);
	//enregistre le fichier (privil�gier un fichier existant)
	Fichier(std::string nom_fichier, unsigned int nombre_de_ligne);
	//enregistre le fichier ainsi que le nombre de ligne le composant
	~Fichier();

	std::string GetNom() const;
	//renvoie le nom du fichier
	std::string GetTexte() const;
	//renvoie le contenu textuel du fichier
	int GetNbLigne() const;
	//renvoie le nombre de ligne du fichier, ou -1 s'il n'a pas �t� rentr�
	std::string Split(TabDynChar split);
	//renvoie le texte du fichier, s�par� par le Split
	TabDynString GiveTab(TabDynChar split);
	//renvoie le contenue du texte dans un tableau dynamique en s�parant les �l�mens par les splits (qui ne seront pas inscrit dans le tableau)

private:
	int m_nb_ligne;

protected :
	std::string m_name;
};
#endif