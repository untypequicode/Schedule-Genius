#include "import.hpp"

std::string ouvrirFichier(std::string const nom_fichier)
{
	std::ifstream myfile; //on enregistre le "lecteur/enregisteur" de dossier au nom myfile

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 			 //on ouvre le fichier en param�tre
		std::string ligne;						 //on g�n�re la variable lignetest pour ensuite la remplir
		std::getline(myfile, ligne);	    	 //on pr�l�ve la premi�re ligne dans la variable ligne, elle servira d'identificteur de fin de programme
		std::string lignef = "";
		lignef += ligne + "\n";
		int fusible = 0;
		while ((ligne != "") and (fusible < 0))
		{
//			std::cout << lignef << std::endl;			//on renvoie la partie lu du fichier pour les test
			std::getline(myfile, ligne);				//on donne a la ligne la valeur de la ligne suivante
			lignef += ligne + " \n";					//on ajoute la derni�re ligne dans la m�me variable pour un renvoie propre
			fusible += 1;
		}
		std::cout << lignef << std::endl;		//on renvoie le fichier lu pour les test
		std::cout << fusible << std::endl;
		return lignef;							// on renvoie la premi�re ligne
	}
	else //en cas de probl�me d'ouverture du fichier
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " "; 
		return a;												   //on renvoie une cha�ne vide en cas de probl�me
	}
}

