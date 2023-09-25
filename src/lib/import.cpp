#include "import.hpp"
;
std::string ouvrirFichierParLigne(std::string const nom_fichier)
{
	std::ifstream myfile; //on enregistre le "lecteur/enregisteur" de dossier au nom myfile

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 			 //on ouvre le fichier en param�tre
		std::string ligne;						 //on g�n�re la variable ligne pour ensuite la remplir
		std::getline(myfile, ligne);	    	 //on pr�l�ve la premi�re ligne dans la variable ligne, elle servira d'identificteur de fin de programme
		std::string lignef = "\n";
		int fusible = 0;						 //une pr�caution de sauvegarde pour ne pas rester bloquer dans la fichier
		int max = 2;
		while ((ligne != "") and (fusible < max))
		{
//			std::cout << lignef << std::endl;			//on renvoie la partie lu du fichier pour les test
			std::getline(myfile, ligne);				//on donne a la ligne la valeur de la ligne suivante
			lignef += ligne + " \n";					//on ajoute la derni�re ligne dans la m�me variable pour un renvoie propre
			fusible += 1;
		}
		//std::cout << lignef << std::endl;		//on renvoie le fichier lu pour les test
		return lignef;							// on renvoie toutes les lignes
	}
	else //en cas de probl�me d'ouverture du fichier
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " "; 
		return a;												   //on renvoie une cha�ne vide en cas de probl�me
	}
}

std::string ouvrirFichierParMot(std::string const nom_fichier)
{
	std::ifstream myfile; //on enregistre le "lecteur/enregisteur" de dossier au nom myfile

	if (myfile) //on verifie que le fichier s'ouvre bien
	{
		std::cout << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 			 //on ouvre le fichier en param�tre
		std::string mot;				     //on g�n�re la variable caractere pour ensuite la remplir
		myfile >> mot;	    			 //on pr�l�ve le premier caractere dans la variable caractere, elle servira d'identificteur de fin de programme
		std::string motf = "";
		int fusible = 0;						 //une pr�caution de sauvegarde pour ne pas rester bloquer dans la fichier
		int max = 2;
		while (fusible < max)
		{
			//std::cout << caractere << std::endl;			//on renvoie la partie lu du fichier pour les test
			myfile >> mot;							//on donne au caractere la valeur du caractere suivant
			if (mot == ";")
			{
				motf += "  ";
			}

			else
			{
				motf += mot;						//on ajoute le dernier caract�re dans la m�me variable pour un renvoie propre
			}

			fusible += 1;
		}
		std::cout << motf << std::endl;		//on renvoie le fichier lu pour les test
		return motf;							// on renvoie la premi�re ligne
	}
	else //en cas de probl�me d'ouverture du fichier
	{
		std::cout << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " ";
		return a;												   //on renvoie une cha�ne vide en cas de probl�me
	}
}

void ouvrirFichierParCaractere(std::string const nom_fichier)
{
	std::string source = ouvrirFichierParLigne(nom_fichier);
	char carac;
	std::string texte = "lecture csv : \n";
	for (char character : source)
	{
		carac = character;
		if (carac == ';')
		{
			texte += '\n';
		}
		else
		{
			texte += carac;
		}
	}
	std::cout << texte;
	return;
}