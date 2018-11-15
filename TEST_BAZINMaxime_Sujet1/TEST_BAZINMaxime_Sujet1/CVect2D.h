#pragma once

class CVect2D
{
public:

	//Constructeur
	CVect2D();
	CVect2D(float fltX,float fltY);
	//CVect2D(float fltX=4.0, float fltY=5.0);


	//Fonction

	void AddVect(CVect2D vec_A, CVect2D vec_B, CVect2D &addvec_AB);
	void SousVect(CVect2D vec_A, CVect2D vec_B, CVect2D &Sousvec_AB);
	void MultScal(CVect2D vec, float Scal, CVect2D &MultScalvect);
	void ProdScalVect(CVect2D vec_A, CVect2D vec_B, float &PScal);
	void Norme(CVect2D vec_A, CVect2D vec_B, float &Norme);
	void ProdVec(CVect2D vec_A, CVect2D vec_B, CVect2D &Prodvec_AB);
	
	float m_fltX;
	float m_fltY;

private:

	
	float m_angle;
	int m_sens;
};



