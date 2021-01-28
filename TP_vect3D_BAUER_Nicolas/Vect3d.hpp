//
//  Vect3d.hpp


#ifndef Vect3d_hpp
#define Vect3d_hpp

#include <iostream>

using namespace std;

 template <class T> class Vect3D {
 protected:
     float m_x, m_y, m_z; //Les coordonnées caractérisants le vecteur 3D
 public :
     //Les constructeurs
     Vect3D(T x=0.f, T y=0.f, T z=0.f); //Le constructeur
     Vect3D(const Vect3D&); //Le constructeur de copie

     //Fonction d'affichage
     void Affiche() const;

     //Opérations usuelles sur les Vecteurs.
     Vect3D Addition(Vect3D vect3dA);
     Vect3D Soustraction(Vect3D vect3dA);
     Vect3D MultiplicationParScalaire(T scalaire);
     T ProduitScalaire(Vect3D vect3dA);
     Vect3D ProduitVectoriel(Vect3D vect3dA);
     T Calculdeterm(Vect3D vect3dA, Vect3D vect3dB);
     Vect3D ProduitMixte(Vect3D vect3dA, T determ);

     //Fonctions amies
     friend bool Coincide(Vect3D const vect3dA, Vect3D const vect3dB)
     {
         bool bResult;

         bResult = ((vect3dA.m_x == vect3dB.m_x) && (vect3dA.m_y == vect3dB.m_y) && (vect3dA.m_z == vect3dB.m_z));

         return bResult;
     }
     
     //Surcharges d'opérateurs :
     Vect3D operator+(const Vect3D vect3dA); // Addition
     Vect3D operator-(const Vect3D vect3dA); // Soustraction
     Vect3D operator*(const T scalaire); // Multiplication Scalaire
     T operator*(const Vect3D vect3dA); // Produit Scalaire
     Vect3D operator^(const Vect3D vect3dA); // Produit Vectoriel
     Vect3D operator=(const Vect3D vect3dA); // Affectation
     bool operator==(const Vect3D vect3dA); // Coincide
     friend ostream& operator<<(ostream& os, const Vect3D& vect3d) { // Affichage
         cout << "X = " << vect3d.m_x << " Y = " << vect3d.m_y << " Z = " << vect3d.m_z;
         return os;
     }
 };

 //Les constructeurs

 template <class T>
 inline Vect3D<T>::Vect3D(T x, T y, T z)
 {
     m_x = x;
     m_y = y;
     m_z = z;
 }

 template <class T>
 inline Vect3D<T>::Vect3D(const Vect3D& vectCopie)
 {
     m_x = vectCopie.m_x;
     m_y = vectCopie.m_y;
     m_z = vectCopie.m_z;
 }

 //Fonction d'affichage
 template <class T>
 inline void Vect3D<T>::Affiche() const
 {
     cout << "X = " << m_x << " Y = " << m_y << " Z = " << m_z << endl;
 }

//Opérations usuelles sur les Vecteurs.
#pragma region Opérations usuelles sur les vecteurs

 template <class T>
 inline Vect3D<T> Vect3D<T>::Addition(Vect3D vect3dA)
 {
     Vect3D vectRes;
     vectRes.m_x = this->m_x + vect3dA.m_x;
     vectRes.m_y = this->m_y + vect3dA.m_y;
     vectRes.m_z = this->m_z + vect3dA.m_z;

     return vectRes;
 }

 template <class T>
 inline Vect3D<T> Vect3D<T>::Soustraction(Vect3D vect3dA)
 {
     Vect3D vectRes;
     vectRes.m_x = this->m_x - vect3dA.m_x;
     vectRes.m_y = this->m_y - vect3dA.m_y;
     vectRes.m_z = this->m_z - vect3dA.m_z;

     return vectRes;
 }

 template <class T>
 inline Vect3D<T> Vect3D<T>::MultiplicationParScalaire(T scalaire)
 {
     Vect3D vectRes;

     vectRes.m_x = this->m_x * scalaire;
     vectRes.m_y = this->m_y * scalaire;
     vectRes.m_z = this->m_z * scalaire;

     return vectRes;
 }

 template <class T>
 inline T Vect3D<T>::ProduitScalaire(Vect3D vect3dA)
 {
     T scalRes;

     scalRes = (this->m_x * vect3dA.m_x) + (this->m_y * vect3dA.m_y) + (this->m_z * vect3dA.m_z);

     return scalRes;
 }

 template <class T>
 inline Vect3D<T> Vect3D<T>::ProduitVectoriel(Vect3D vect3dA)
 {
     Vect3D vectRes;

     vectRes.m_x = (this->m_y * vect3dA.m_z) - (this->m_z * vect3dA.m_y);
     vectRes.m_y = (this->m_z * vect3dA.m_x) - (this->m_x * vect3dA.m_z);
     vectRes.m_z = (this->m_x * vect3dA.m_y) - (this->m_y * vect3dA.m_x);

     return vectRes;
 }

 template <class T>
 inline T Vect3D<T>::Calculdeterm(Vect3D vect3dA, Vect3D vect3dB)
 {
     T determResult;

     determResult = vect3dB.ProduitScalaire(this->ProduitVectoriel(vect3dA));

     return determResult;
 }


 template <class T>
 inline Vect3D<T> Vect3D<T>::ProduitMixte(Vect3D vect3dA, T determ)
 {
     Vect3D vectRes;

     vectRes = (this->ProduitVectoriel(vect3dA)).MultiplicationParScalaire(determ);

     return vectRes;
 }

#pragma endregion

 //Surcharge des opérateurs.
 #pragma region surchage des opérateurs.
 template <class T>
 inline Vect3D<T> Vect3D<T>:: operator+(const Vect3D vect3dA)
 {
     Vect3D vecResult;
     vecResult.m_x = this->m_x + vect3dA.m_x;
     vecResult.m_y = this->m_y + vect3dA.m_y;
     vecResult.m_z = this->m_z + vect3dA.m_z;

     return vecResult;
 }

 template <class T>
 inline Vect3D<T> Vect3D<T>::operator-(const Vect3D vect3dA)
 {
     Vect3D vecResult;

     vecResult.m_x = this->m_x - vect3dA.m_x;
     vecResult.m_y = this->m_y - vect3dA.m_y;
     vecResult.m_z = this->m_z - vect3dA.m_z;

     return vecResult;
 }

 template <class T>
 inline Vect3D<T> Vect3D<T>::operator*(const T scalaire)
 {
     Vect3D vecResult;

     vecResult.m_x = this->m_x * scalaire;
     vecResult.m_y = this->m_y * scalaire;
     vecResult.m_z = this->m_z * scalaire;

     return vecResult;
 }

 template <class T>
 inline T Vect3D<T>::operator*(const Vect3D vect3dA)
 {
     T scalaireResult;

     scalaireResult = (this->m_x * vect3dA.m_x) + (this->m_y * vect3dA.m_y) + (this->m_z * vect3dA.m_z);

     return scalaireResult;
 }

 template <class T>
 inline Vect3D<T> Vect3D<T>::operator^(const Vect3D vect3dA)
 {
     Vect3D vecResult;

     vecResult.m_x = (this->m_y * vect3dA.m_z) - (this->m_z * vect3dA.m_y);
     vecResult.m_y = (this->m_z * vect3dA.m_x) - (this->m_x * vect3dA.m_z);
     vecResult.m_z = (this->m_x * vect3dA.m_y) - (this->m_y * vect3dA.m_x);

     return vecResult;
 }

 template <class T>
 inline Vect3D<T> Vect3D<T>:: operator=(const Vect3D vect3dA)
 {
     return vect3dA;
 }

 template <class T>
 inline bool Vect3D<T>::operator==(const Vect3D vect3dA)
 {
     const Vect3D vect3dB(3.f, 2.f, 1.f); // Création d'un vecteur par défaut
     bool bResult;

     bResult = ((vect3dA.m_x == vect3dB.m_x) && (vect3dA.m_y == vect3dB.m_y) && (vect3dA.m_z == vect3dB.m_z));

     return bResult;
 }

 #pragma endregion

#endif /* Vect3d_hpp */
