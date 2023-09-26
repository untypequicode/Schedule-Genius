#include "generateur_csv.hpp"


std::vector <std::string> PRENOM = { "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivy", "Jack",
"Katherine", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rachel", "Samuel", "Taylor",
"Ursula", "Victor", "Wendy", "Xavier", "Yasmine", "Zane" };

std::vector <std::string> NOM = { "Dupont", "Martin", "Dubois", "Bernard", "Thomas", "Robert", "Richard", "Petit", "Durand", "Leroy",
"Moreau", "Simon", "Laurent", "Lefebvre", "Michel", "Garcia", "David", "Roux", "Bonnet", "Fournier",
"Lopez", "Legrand", "Martinez", "Ferreira", "Fernandez", "Blanc", "Andr�", "Leroux", "Rousseau" };

std::vector <std::string> MATIERE_SPE = { "Francais", "Histoire" "Geo", "EMC", "EPS", "SPC", "SVT", "Maths", "NSI", "Philo",
"Anglais", "Espagnole", "Allemand", "Italien", "Russe" };

int NOMBRE_ELEVE = 200;
int NOMBRE_PRENOM = PRENOM.size();
int NOMBRE_NOM = NOM.size();
int NOMBRE_MATIERE = MATIERE_SPE.size();

void creerCsv()
{
	std::ofstream myfile;
	myfile.open("example.csv");

	// Premi�re ligne du csv avec les diff�rentes cat�gories
	myfile << " PRENOM;" << "NOM;" << "Annee;";
	for (int i = 1; i < 11; i++)
	{
		myfile << "MATIERE OPTIONNELLE" << i << ";";
	};
	myfile << "\n";

	// Autres lignes du csv
	for (int i = 0; i < NOMBRE_ELEVE; i++)
	{
		myfile << PRENOM[rand() % NOMBRE_PRENOM] << ";";
		myfile << NOM[rand() % NOMBRE_NOM] << ";";
		myfile << rand() % 3 + 1 << ";";

		int NOMBRE_MATIERE_SPE = rand() % 10;

		std::vector <std::string> matiere_restante = MATIERE_SPE;
		for (int e = 0; e < NOMBRE_MATIERE_SPE; e++)

		{
			int RANDOM_MATIERE = rand() % 5;
			myfile << matiere_restante[RANDOM_MATIERE] << ";";
			matiere_restante.erase(matiere_restante.begin() + RANDOM_MATIERE);
		};
		myfile << "\n";
	}
	myfile.close();
}