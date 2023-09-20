#include "import.hpp"

std::string ouvrirFichier(std::string const nom_fichier)
{
	std::ifstream myfile; //on enregistre le "lecteur/enregisteur" de dossier au nom myfile

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 		  //on ouvre le fichier en param�tre
		std::string ligne1;					  //on g�n�re la variable ligne pour ensuite la remplir
		std::getline(myfile, ligne1);	    	 //on pr�l�ve la premi�re ligne dans la variable ligne
		std::string ligne2;					  //idem
		std::getline(myfile, ligne2);
		std::cout << ligne1 << std::endl;	  //on �crit la ligne en console (pour les test, � modifier pour fontion plus avanc�)
		std::cout << ligne2 << std::endl;	  //comme pr�c�demment avec la deuxi�me ligne

		std::string ligne = ligne1 + ligne2;//on entre les deux lignes dans la m�me variable pour un renvoie propre
		return ligne; // on renvoie la premi�re ligne
	}
	else //en cas de probl�me d'ouverture du fichier
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " "; 
		return a;												   //on renvoie une cha�ne vide en cas de probl�me
	}
}

