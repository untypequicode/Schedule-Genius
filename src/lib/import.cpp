#include "import.hpp"

std::string ouvrirFichier(std::string const nom_fichier)
{
	std::ifstream myfile; //on enregistre le "lecteur/enregisteur" de dossier au nom myfile

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 		 //on ouvre le fichier en param�tre
		std::string ligne;					 //on g�n�re la variable ligne pour ensuite la remplir
		std::getline(myfile, ligne);	   	 //on pr�l�ve la premi�re ligne dans la variable ligne
		std::cout << ligne << std::endl;	 //on renvoie la ligne en console (pour les test, � modifier pour fontion plus avanc�)

		return ligne; // on renvoie la premi�re ligne
	}
	else //en cas de probl�me d'ouverture du fichier
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " "; 
		return a;												   //on renvoie une cha�ne vide en cas de probl�me
	}
}

