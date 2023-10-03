#ifndef DEF_FILE
#define DEF_FILE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "tab_dyn/tab_dyn.hpp"

class Fichier
{
	public:
		Fichier();
		//cr�er un fichier vide nomm� empty.csv
		Fichier(std::string);
		//enregistre le fichier (privil�gier un fichier existant)
		Fichier(std::string, int);
		//enregistre le fichier ainsi que le nombre de ligne le composant
		~Fichier();

		std::string GetNom() const;
		//renvoie le nom du fichier
		std::string GetTexte() const;
		//renvoie le contenu textuel du fichier
		int GetNbLigne() const;
		//renvoie le nombre de ligne du fichier, ou -1 s'il n'a pas �t� rentr�
		std::string Split(char split);
		//renvoie le texte du fichier, s�par� par le Split, jusqu'� atteindre le end

	private:
		std::string m_name;
		int m_nb_ligne;
};
#endif