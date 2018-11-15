#include "CVect2D.h"
#include <iostream>
#include <stdlib.h>
#include<math.h>

CVect2D::CVect2D()
{
}

CVect2D::CVect2D(float fltX, float fltY)
{
	m_fltX = fltX;
	m_fltY = fltY;
}


//Addition de Vecteur
void CVect2D::AddVect(CVect2D vec_A, CVect2D vec_B, CVect2D &addvec_AB)
{
	addvec_AB.m_fltX = vec_A.m_fltX + vec_B.m_fltX;
	addvec_AB.m_fltY = vec_A.m_fltY + vec_B.m_fltY;
	
	
}


//Soustraction de Vecteur
void CVect2D::SousVect(CVect2D vec_A, CVect2D vec_B, CVect2D &Sousvec_AB)
{
	Sousvec_AB.m_fltX = (vec_A.m_fltX - vec_B.m_fltX);
	Sousvec_AB.m_fltY = (vec_A.m_fltY - vec_B.m_fltY);
	

}

//Multiplication de Vecteur par un Scalaire
void CVect2D::MultScal(CVect2D vec, float Scal, CVect2D &MultScalvect)
{
	MultScalvect.m_fltX = (vec.m_fltX*Scal);
	MultScalvect.m_fltY = (vec.m_fltY*Scal);
	
}


//Produit scalaire de 2 vecteurs
void CVect2D::ProdScalVect(CVect2D vec_A, CVect2D vec_B, float &PScal)
{
	PScal = (vec_A.m_fltX*vec_B.m_fltX) + (vec_A.m_fltY*vec_B.m_fltY);
}


//Norme d'un vacteur
void CVect2D::Norme(CVect2D vec_A, CVect2D vec_B, float &Norme)
{
	float X =((vec_B.m_fltX - vec_A.m_fltX)*(vec_B.m_fltX - vec_A.m_fltX) + (vec_B.m_fltY - vec_A.m_fltY)*(vec_B.m_fltY - vec_A.m_fltX));
	Norme = sqrt(X);
	
}


//Produit vectoriel de 2 vecteur
void CVect2D::ProdVec(CVect2D vec_A, CVect2D vec_B, CVect2D &Prodvec_AB)
{
	Prodvec_AB.m_fltX = vec_A.m_fltY - vec_B.m_fltY;
	Prodvec_AB.m_fltY = vec_B.m_fltX - vec_A.m_fltX;
	
}
