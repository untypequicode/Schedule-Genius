#include "import.hpp"
#include "eleves.hpp"
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
		int max = 2500;
		while (fusible < max)
		{
			//std::cout << lignef << std::endl;			//on renvoie la partie lu du fichier pour les test
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
		std::cerr << "Le fichier est ouvert !!" << std::endl; //on annonce que tout ce passe bien
		std::cout << std::endl;

		myfile.open(nom_fichier);	 			 //on ouvre le fichier en param�tre
		std::string mot;				     //on g�n�re la variable caractere pour ensuite la remplir
		myfile >> mot;	    			 //on pr�l�ve le premier caractere dans la variable caractere, elle servira d'identificteur de fin de programme
		std::string motf = "";
		int fusible = 0;						 //une pr�caution de sauvegarde pour ne pas rester bloquer dans la fichier
		int max = 2000;
		while (fusible < max)
		{
			//std::cout << caractere << std::endl;			//on renvoie la partie lu du fichier pour les test
			myfile >> mot;							//on donne au caractere la valeur du caractere suivant
			if (mot == ";")
			{
				motf += " ";
			}

			else
			{
				motf += mot + "\n";						//on ajoute le dernier caract�re dans la m�me variable pour un renvoie propre
			}

			fusible += 1;
		}
		//std::cout << motf << std::endl;		//on renvoie le fichier lu pour les test
		return motf;							// on renvoie la premi�re ligne
	}
	else //en cas de probl�me d'ouverture du fichier
	{
		std::cerr << "Erreur d'ouverture du dossier" << std::endl; //on dit que le fichier ne s'ouvre pas
		std::string a = " ";
		return a;												   //on renvoie une cha�ne vide en cas de probl�me
	}
}

void ouvrirFichierParCaractere(std::string const nom_fichier)
{
	std::string source = ouvrirFichierParLigne(nom_fichier);
	std::string texte = "lecture csv : \n";
	for (char character : source)
	{
		//std::cout << character;
		/*if (character == ' ')
		{
			break;
		}*/
		if (character == ';')
		{
			texte += ' ';
		}

		else if (character == '\n')
		{
			texte += "\n \n";
		}

		else
		{
			texte += character;
		}
	}
	std::cout << texte;
	return;
}


void genererEleveViaCsv(std::string const nom_fichier)
{
	std::string mot = "";
	std::string nom = "";
	std::string prenom = "";
	std::string matiere = "";
	std::string niveau = "";
	int test = 0;
	std::string id = "";
	int fake_id = 0;

	std::ifstream myfile;
	myfile.open(nom_fichier);
	std::string ligne;
	std::getline(myfile, ligne);		//on se d�barrasse de la premi�re ligne qui ne contient que les en-t�te
	for(int i = 0; i < 5000 ; ++i)
	{
		myfile >> mot;
		for (char character : mot)
		{

			if (character == ';' and test != 4)
			{
				test += 1;
			}

			else if (test == 0)
			{
				id += character;
			}

			else if (test == 1)
			{
				prenom += character;
			}

			else if (test == 2)
			{
				nom += character;
			}

			else if (test == 3)
			{
				niveau += character;
			}

			else if (test == 4)
			{
				if (not (character == '1' or character == '2' or character == '3' or character == '4' or character == '5' or character == '6' or character == '7' or character == '8' or character == '9' or character == '0'))
				{
					if (character == ';')
					{
						matiere += " ";
					}

					else
						matiere += character;
				}

				else
				{
					test = 5;
				}
			}

			if (test == 5)
			{
				Eleve Elevetest = Eleve(fake_id, prenom, nom, niveau);
				//test.addMatiere(matiere);

				std::cout << "eleve numero " << id << " : ";
				std::cout << prenom << " " << nom << std::endl;
				std::cout << "en annee " << niveau << std::endl;
				std::cout << "matieres optionnelles : " << matiere << std::endl << std::endl;

				nom = "";
				prenom = "";
				niveau = "";
				matiere = "";
				id = character;
				test = 0;
				fake_id++;
			}
		}

	}
}