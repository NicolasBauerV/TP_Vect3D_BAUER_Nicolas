//
//  main.cpp
//  TP_vect3D_BAUER_Nicolas
//
//  Created by Nicolas BAUER on 28/01/2021.
//

#include <iostream>
#include "Vect3d.hpp"

using namespace std;

 int main()
 {
     setlocale(LC_ALL, ""); //Pour mettre les accents dans la console.

     Vect3D<float> vectA(1.f, 4.f, 3.f);
     Vect3D<float> vectB(3.f, 5.f, 6.f);
     Vect3D<float> vectC(5.f, 2.f, 2.f);

     cout << "Affichage des vecteurs A, B et C : " << endl;
     vectA.Affiche();
     vectB.Affiche();
     vectC.Affiche();

     cout << "Addition des vecteurs A et B : " << endl;
     vectA.Addition(vectB).Affiche();

     cout << "Soustration du vecteur A par B : " << endl;
     vectA.Soustraction(vectB).Affiche();

     cout << "Produit Scalaire de A et B : " << vectA.ProduitScalaire(vectB) << endl;

     cout << "Produit Vectoriel de A et B : " << endl;
     vectA.ProduitVectoriel(vectB).Affiche();

     float determ;
     determ = vectA.Calculdeterm(vectB, vectC);
     cout << "Calcul du déterminant de A, B et C : " << determ << endl;

     cout << "Calcul du Produit mixte de A, B et du déterminant précédent : " << endl;
     vectA.ProduitMixte(vectB, determ).Affiche();
     
     // ---------------- Version 2 --------------
     
     cout << "Passons aux surcharge d'opérateurs !" << endl;

     cout << "Addition des vecteurs A et B : " << endl << (vectA + vectB) << endl;

     cout << "Soustration du vecteur A par B : " << endl << (vectA - vectB) << endl;

     cout << "Produit Scalaire de A et B : " << (vectA*vectB) << endl;

     cout << "Produit vectoriel de A et B : " << endl << (vectA ^ vectB) << endl;

     return 0;
 }
