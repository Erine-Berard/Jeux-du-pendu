#include "fonction.h"

using namespace std;



int main() {

	bool rejouer = 1;

		while (rejouer == 1) {


			
			/*cree tableau
			string tab[20];
			tab[0] = "un";
			tab[1] = "deux";
			tab[2] = "cinq";
			tab[3] = "rouge";
			tab[4] = "membre";
			tab[5] = "conseil";
			tab[6] = "donner";
			tab[7] = "reponse";
			tab[8] = "etat";
			tab[9] = "son";
			tab[10] = "armement";
			tab[11] = "peu";
			tab[12] = "apres";
			tab[13] = "vacances";
			tab[14] = "annonce";
			tab[15] = "mercredi";
			tab[16] = "evident";
			tab[17] = "regime";
			tab[18] = "affirmer";
			tab[19] = "arme";*/

			//Choisi le mot

			string tab[10];
			tab[0] = "C'est partit on commence";
			tab[1] = "Deja un essai perdu !";
			tab[2] = "Reesaye";
			tab[3] = "Concentre toi !";
			tab[4] = "deja a la moitie passe" ;
			tab[5] = "La corde se tend ...";
			tab[6] = "Ca sent le bourreau";
			tab[7] = "Reesaye, Encore";
			tab[8] = "T'es pas si bon !";
			tab[9] = "ATTENTION !! Plus qu'une chance";

			char tableau[10];


			string motCache;

			ChoisirMot(motCache);

			if (motCache == "ERREUR") {
				cout << endl << "ERREUR : Dans le choix du mot cache ou Impossible d'ouvrir le fichier." << endl;
				break;
			}

			//cree mon mot avec les étoiles
			string mot = motCache;

			InitEtoile(mot);

			cout << "Vous avez 10 chances, essayer de trouver le mot avant qu'on finisse de pendre le pendu !" << endl << endl; 

			for (int i = 0; i < 10; i++) {

				cout << "---" << tab[i] <<"---" << endl;
				
				cout << "Le mot secret est : " << mot << endl;

				char lettre = GetCaractere();

				TestCaractere(lettre, mot, motCache);

				bool test = TestGagne(mot);
				
				DessinePendu(i);

				tableau[i] = lettre;

				cout << endl << "___________________________________________________________________________________________________" << endl<< endl;

				

				if ((i == 9) && (test == 0)) {
					cout << endl << "Desole vous avez perdu ! Le mot secret etait : " << motCache << endl;
				}
				else if (test == 0) {

					cout << "Vous avez essayer les lettres : ";

					for (int j = 0; j < i+1; j++) {
						cout << tableau[j] << " ;";
					}

					cout << endl << endl;

					continue;
				}
				else {
					cout << endl << "Vous avez gagne, le mot secret etait : " << motCache << endl;
					break;
				}
				
				cout << endl << "___________________________________________________________________________________________________" << endl;

			}
			//pour rejouer
			char ouiNon = 'o';
			cout << endl << " Voulez-vous rejouer ? (o/n)";
			cin >> ouiNon;

			if (ouiNon == 'o') {
				rejouer = 1;
			}
			else {
				break;
			}
		}

	return 0; 
}