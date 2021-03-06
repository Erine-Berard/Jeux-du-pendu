#ifndef __FONCTION__
#define __FONCTION__

#include <string>
#include <iostream>
#include <fstream>


char GetCaractere();

int GetNombreAlleatoire(int min, int max);

std::string ChoisirMot(std::string mots[], int taille);

std::string ChoisirMot(std::string& ligne);

void InitEtoile(std::string& mot);

void TestCaractere(char lettre, std::string& mot, std::string motCache);

bool TestGagne(std::string mot);

void DessinePendu(int i);

#endif // !__FONCTION__

