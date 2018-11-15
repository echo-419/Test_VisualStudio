#include <iostream>
#include <stdlib.h>
#include"CVect2D.h"


int main() {

	CVect2D Resultat(0.0f, 0.0f);
	CVect2D Vect_Alpha(11.7f,34.3f);
	CVect2D Vect_Bravo(41.9f,93.3f);
	float resultat=0.0f;
	float  Scalaire = 2.5f;
	
	
	Vect_Alpha.AddVect(Vect_Alpha, Vect_Bravo, Resultat);
	std::cout << "L'Addition a pour resultat (" << Resultat.m_fltX << "," << Resultat.m_fltY << ")" << std::endl;
	

	Vect_Alpha.SousVect(Vect_Alpha, Vect_Bravo, Resultat);
	std::cout << "La Soustraction a pour resultat (" << Resultat.m_fltX << "," << Resultat.m_fltY << ")" << std::endl;
	

	Vect_Alpha.MultScal(Vect_Alpha, Scalaire, Resultat);
	std::cout << "La Multiplication par un Scalaire a pour resultat (" << Resultat.m_fltX << "," << Resultat.m_fltY << ")" << std::endl;
	
	Vect_Alpha.ProdScalVect(Vect_Alpha, Vect_Bravo, resultat);
	std::cout << "Le Prodiut Scalaire des 2 vecteur a pour resultat (" << resultat << ")" << std::endl;

	Vect_Alpha.Norme(Vect_Alpha, Vect_Bravo, resultat);
	std::cout << "La Norme de AB a pour resultat (" << resultat << ")" << std::endl;

	Vect_Alpha.ProdVec(Vect_Alpha, Vect_Bravo, Resultat);
	std::cout << "Le produit Vectoriel des 2 vecteurs a pour resultat (" << Resultat.m_fltX << "," << Resultat.m_fltY << ")" << std::endl;
	

	system("pause");

	return 0;
}
