//
//  Vect3d.hpp


#ifndef Vect3d_hpp
#define Vect3d_hpp

#include <iostream>

using namespace std;

 template <class T> class Vect3D
 {
 protected:
     float m_x, m_y, m_z; //Les coordonnées caractérisants le vecteur 3D
 public :
     //Les constructeurs
     Vect3D(T x=0.f, T y=0.f, T z=0.f); //Le constructeur
     Vect3D(const Vect3D&); //Le constructeur de copie

     //Fonction d'affichage
     void Affiche() const;

     //Opérations usuelles sur les Vecteurs.
     Vect3D Addition(Vect3D vec3dA);
     Vect3D Soustraction(Vect3D vec3dA);
     Vect3D MultiplicationParScalaire(T scalaire);
     T ProduitScalaire(Vect3D vec3dA);
     Vect3D ProduitVectoriel(Vect3D vec3dA);
     T CalculDeterminant(Vect3D vec3dA, Vect3D vec3dB);
     Vect3D ProduitMixte(Vect3D vec3dA, T determinant);

     //Fonctions amies
     friend bool Coincide(Vect3D const vec3dA, Vect3D const vec3dB)
     {
         bool bResult;

         bResult = ((vec3dA.m_x == vec3dB.m_x) && (vec3dA.m_y == vec3dB.m_y) && (vec3dA.m_z == vec3dB.m_z));

         return bResult;
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

 template <class T>
 inline Vect3D<T> Vect3D<T>::Addition(Vect3D vec3dA)
 {
     Vect3D vecResult;
     vecResult.m_x = this->m_x + vec3dA.m_x;
     vecResult.m_y = this->m_y + vec3dA.m_y;
     vecResult.m_z = this->m_z + vec3dA.m_z;

     return vecResult;
 }

 template <class T>
 inline Vect3D<T> Vect3D<T>::Soustraction(Vect3D vec3dA)
 {
     Vect3D vecResult;
     vecResult.m_x = this->m_x - vec3dA.m_x;
     vecResult.m_y = this->m_y - vec3dA.m_y;
     vecResult.m_z = this->m_z - vec3dA.m_z;

     return vecResult;
 }

 template <class T>
 inline Vect3D<T> Vect3D<T>::MultiplicationParScalaire(T scalaire)
 {
     Vect3D vecResult;

     vecResult.m_x = this->m_x * scalaire;
     vecResult.m_y = this->m_y * scalaire;
     vecResult.m_z = this->m_z * scalaire;

     return vecResult;
 }

 template <class T>
 inline T Vect3D<T>::ProduitScalaire(Vect3D vec3dA)
 {
     T scalaireResult;

     scalaireResult = (this->m_x * vec3dA.m_x) + (this->m_y * vec3dA.m_y) + (this->m_z * vec3dA.m_z);

     return scalaireResult;
 }

 template <class T>
 inline Vect3D<T> Vect3D<T>::ProduitVectoriel(Vect3D vec3dA)
 {
     Vect3D vecResult;

     vecResult.m_x = (this->m_y * vec3dA.m_z) - (this->m_z * vec3dA.m_y);
     vecResult.m_y = (this->m_z * vec3dA.m_x) - (this->m_x * vec3dA.m_z);
     vecResult.m_z = (this->m_x * vec3dA.m_y) - (this->m_y * vec3dA.m_x);

     return vecResult;
 }

 template <class T>
 inline T Vect3D<T>::CalculDeterminant(Vect3D vec3dA, Vect3D vec3dB)
 {
     T determinantResult;

     determinantResult = vec3dB.ProduitScalaire(this->ProduitVectoriel(vec3dA));

     return determinantResult;
 }


 template <class T>
 inline Vect3D<T> Vect3D<T>::ProduitMixte(Vect3D vec3dA, T determinant)
 {
     Vect3D vecResult;

     vecResult = (this->ProduitVectoriel(vec3dA)).MultiplicationParScalaire(determinant);

     return vecResult;
 }

#endif /* Vect3d_hpp */
