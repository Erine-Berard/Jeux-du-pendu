#include "fonction.h"

using namespace std;


// Fonction qui demande le caractère 
char GetCaractere(){

	char lettre; 

	cout << "Proposez une lettre : "; 
	cin >> lettre;
	cout << endl;

	return lettre;
}


//Fonction pour renvoyer un nombre aléatoire entre deux nombre
int GetNombreAlleatoire(int min, int max) {

	srand((unsigned int)time(0));

	int nombreAlleatoire = rand() %  max + min;

	return nombreAlleatoire;
}


//Retourne un mot a partir d'un nombre aléatoire avec le tableau
string ChoisirMot(string mots[], int taille) {

	int nombreAlleatoir= GetNombreAlleatoire(0, taille-1);

	return mots[nombreAlleatoir];
}	

//Retourne un mot a partir d'un nombre aléatoire avec le fichier 
string ChoisirMot(string& ligne) {

	ifstream fichier("C:../ChoixDeMots.txt");

	if (fichier) {

	}
	else {
		ligne = "ERREUR";
	}

	int taille = 0;
	while (getline(fichier, ligne)) {
		taille++;
	}

	fichier.clear();

	fichier.seekg(0,ios::beg);

	int nombreAlleatoir = GetNombreAlleatoire(1, taille);

	;

	for (int i = 1; getline(fichier, ligne); i++ ) {

		

		if (i == nombreAlleatoir-1) {

			getline(fichier, ligne);

			break;

		}
		else if (i == taille) {

			ligne = "ERREUR";

		}

	}

	return ligne;
	

}


//Remplace les lettres par des étoiles 
void InitEtoile(string& mot) {
	
	int taille = mot.length();

	mot = "";

	for (int i = 0; i < taille; i++) {
		
		mot.push_back('*');
	}

	return; 
}



//Remplacer les étoile par la lettre chercher 
void TestCaractere(char lettre, string& mot, string motCache) {

	int tailleMot = motCache.length();


	string lettreS = "";
	lettreS.push_back(lettre);

	for (int i = 0; i < tailleMot; i++) {

		int a = motCache.find(lettre, i);

		if (a == -1) {
			break;
		}
		else {

			mot.replace(a, 1, lettreS);

		}
	}

	return;
}



//Esce qu'on a gagné 
bool TestGagne(string mot) {

	string etoile("*");

	int tailleMot = mot.length();

	int a = mot.find(etoile);

	if (a == -1) {
		return 1;
	}
	else {
		return 0;
	}
}


//Desin du pendu 
void DessinePendu(int i) {

	string tab[10];
	tab[0] =
		"       \n"
		"       \n"
		"       \n"
		"       \n"
		" \|     \n"
		"_\|_    \n";
	tab[1]=
		"       \n"
		"       \n"
		" |     \n"
		" |     \n"
		" |     \n"
		"_|_    \n";
	tab[2] =
		" __    \n"
		" |     \n"
		" |     \n"
		" |     \n"
		" |     \n"
		"_|_    \n";
	tab[3] =
		" _____ \n"
		" |     \n"
		" |     \n"
		" |     \n"
		" |     \n"
		"_|_    \n";
	tab[4] =
		" _____ \n"
		" |  |  \n"
		" |  O  \n"
		" |     \n"
		" |     \n"
		"_|_    \n";
	tab[5] =
		" _____ \n"
		" |  |  \n"
		" |  O  \n"
		" |  |  \n"
		" |     \n"
		"_|_    \n";
	tab[6] =
		" _____ \n"
		" |  |  \n"
		" |  O  \n"
		" |  |/ \n"
		" |     \n"
		"_|_    \n";
	tab[7] =
		" _____ \n"
		" |  |  \n"
		" |  O  \n"
		" | \\|/ \n"
		" |     \n"
		"_|_    \n";
	tab[8] =
		" _____ \n"
		" |  |  \n"
		" |  O  \n"
		" | \\|/ \n"
		" |   \\ \n"
		"_|_    \n";
	tab[9] =
		" _____ \n"
		" |  |  \n"
		" |  O  \n"
		" | \\|/ \n"
		" | / \\ \n"
		"_|_    \n";

	cout << tab[i];
	
}



