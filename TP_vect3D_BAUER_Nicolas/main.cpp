//
//  main.cpp
//  TP_vect3D_BAUER_Nicolas
//
//  Created by Nicolas BAUER on 28/01/2021.
//

#include <iostream>
#include "Vect3d.hpp"
#include "Vect2D.hpp"
#include "Conteneur.hpp"

using namespace std;

 int main() {
     setlocale(LC_ALL, ""); //Pour mettre les accents dans la console.
     
     cout << "Version 1: " << endl;

     Vect3D<float> vect3A(1.f, 4.f, 3.f);
     Vect3D<float> vect3B(3.f, 5.f, 6.f);
     Vect3D<float> vect3C(5.f, 2.f, 2.f);

     cout << "Affichage des vecteurs A, B et C : " << endl;
     vect3A.Affiche();
     vect3B.Affiche();
     vect3C.Affiche();

     cout << "Addition des vecteurs A et B : " << endl;
     vect3A.Addition(vect3B).Affiche();

     cout << "Soustration du vecteur A par B : " << endl;
     vect3A.Soustraction(vect3B).Affiche();

     cout << "Produit Scalaire de A et B : " << vect3A.ProduitScalaire(vect3B) << endl;

     cout << "Produit Vectoriel de A et B : " << endl;
     vect3A.ProduitVectoriel(vect3B).Affiche();

     float determ;
     determ = vect3A.CalculDeterminant(vect3B, vect3C);
     cout << "Calcul du déterminant de A, B et C : " << determ << endl;

     cout << "Calcul du Produit mixte de A, B et du déterminant précédent : " << endl;
     vect3A.ProduitMixte(vect3B, determ).Affiche();
     cout << endl;
     
     // ---------------- Version 2 --------------
     
     cout << "Version 2: " << endl;
     
     cout << "Les surcharges d'opérateurs: " << endl;

     cout << "Addition des vecteurs A et B : " << endl << (vect3A + vect3B) << endl;

     cout << "Soustration du vecteur A par B : " << endl << (vect3A - vect3B) << endl;

     cout << "Produit Scalaire de A et B : " << (vect3A*vect3B) << endl;

     cout << "Produit vectoriel de A et B : " << endl << (vect3A ^ vect3B) << endl;
     
     cout << endl;
     
     //------------------ Travail 2 : ----------------
     
     cout << "Travail 2: " << endl;

     Vect2D<int> vect2A(4, 2);
     Vect2D<int> vect2B(1, 2);

     cout << "Affichage des vecteurs A et B : " << endl;
     vect2A.Affiche();
     vect2B.Affiche();

     cout << "Addition des vecteurs A et B : " << endl << (vect2A + vect2B) << endl;

     cout << "Soustraction du vecteur A par B : " << endl << (vect2A - vect2B) << endl;

     cout << "Produit Scalaire de A et B : " << (vect2A * vect2B) << endl;

     cout << "Produit vectoriel de A et B : " << endl << (vect2A ^ vect2B) << endl;
     cout << endl;
     //-------------- Travail 3 : -----------------
     
     cout << "Travail 3: " << endl;
     cout << "Les conteneurs de vecteurs" << endl;
     cout << "Tableau 2D: " << endl;
        
     Conteneur<Vect2D<int>, 2> tab2D;
     tab2D[0] = vect2A;
     tab2D[1] = vect2B;
     for (int i = 0; i < 2; i++) {
         cout<<tab2D[i]<<endl;
         
     }
     
     cout << endl;
     cout << "Tableau 3D: " << endl;
     
     Conteneur<Vect3D<float>, 3> tab3D;
     tab3D[0] = vect3A;
     tab3D[1] = vect3B;
     tab3D[2] = vect3C;
     for (int i = 0; i < 3; i++) {
         cout << tab3D[i] << endl;
         
     }

     return 0;
 }
