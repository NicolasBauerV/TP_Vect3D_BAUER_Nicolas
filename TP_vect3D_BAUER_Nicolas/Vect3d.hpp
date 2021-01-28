//
//  Vect3d.hpp
//
//  Created by Nicolas BAUER on 28/01/2021.
//


#ifndef Vect3d_hpp
#define Vect3d_hpp

#include <iostream>

using namespace std;

template <class T> class Vect3D {
protected:
    T m_x, m_y, m_z; //Les coordonnées du vecteur 3D créer
public :
    //Les constructeurs
    Vect3D(T x=0.f, T y=0.f, T z=0.f); //Le constructeur
    Vect3D(const Vect3D&); //Le constructeur de copie

    //Fonction d'affichage
    void Affiche() const;
    
    //Opérations usuelles sur les Vecteurs.
    Vect3D Addition(Vect3D vect3dA);
    Vect3D Soustraction(Vect3D vect3dA);
    Vect3D MultiplicationParScalaire(T scal);
    T ProduitScalaire(Vect3D vect3dA);
    Vect3D ProduitVectoriel(Vect3D vect3dA);
    T CalculDeterminant(Vect3D vect3dA, Vect3D vect3dB);
    Vect3D ProduitMixte(Vect3D vect3dA, T determ);

    //Fonctions amies
    friend bool Coincide(Vect3D const vect3dA, Vect3D const vect3dB) {
        bool valid;

        valid = ((vect3dA.m_x == vect3dB.m_x) && (vect3dA.m_y == vect3dB.m_y) && (vect3dA.m_z == vect3dB.m_z));

        return valid;
    }

    //Surcharges d'opérateurs :
    Vect3D operator+(const Vect3D vect3dA); //Addition
    Vect3D operator-(const Vect3D vect3dA); //Soustraction
    Vect3D operator*(const T scal); //Multiplication Scalaire
    T operator*(const Vect3D vect3dA); //Produit Scalaire
    Vect3D operator^(const Vect3D vect3dA); //Produit Vectoriel
    Vect3D operator=(const Vect3D vect3dA); //Affectation
    bool operator==(const Vect3D vect3dA); //Coincide
    
    //Affichage
    friend ostream& operator<<(ostream& os, const Vect3D& vect3d) {
        cout << "X = " << vect3d.m_x << " Y = " << vect3d.m_y << " Z = " << vect3d.m_z;
        return os;
    }
};

//Les constructeurs

template <class T>
inline Vect3D<T>::Vect3D(T x, T y, T z) {
    m_x = x;
    m_y = y;
    m_z = z;
}

template <class T>
inline Vect3D<T>::Vect3D(const Vect3D& vectCopie) {
    m_x = vectCopie.m_x;
    m_y = vectCopie.m_y;
    m_z = vectCopie.m_z;
}

//Fonction d'affichage
template <class T>
inline void Vect3D<T>::Affiche() const {
    cout << "X = " << m_x << " Y = " << m_y << " Z = " << m_z << endl;
}

//Opérations usuelles sur les Vecteurs.

template <class T>
inline Vect3D<T> Vect3D<T>::Addition(Vect3D vect3dA) {
    Vect3D vectResult;
    vectResult.m_x = this->m_x + vect3dA.m_x;
    vectResult.m_y = this->m_y + vect3dA.m_y;
    vectResult.m_z = this->m_z + vect3dA.m_z;

    return vectResult;
}

template <class T>
inline Vect3D<T> Vect3D<T>::Soustraction(Vect3D vect3dA) {
    Vect3D vectResult;

    vectResult.m_x = this->m_x - vect3dA.m_x;
    vectResult.m_y = this->m_y - vect3dA.m_y;
    vectResult.m_z = this->m_z - vect3dA.m_z;

    return vectResult;
}

template <class T>
inline Vect3D<T> Vect3D<T>::MultiplicationParScalaire(T scal) {
    Vect3D vectResult;

    vectResult.m_x = this->m_x * scal;
    vectResult.m_y = this->m_y * scal;
    vectResult.m_z = this->m_z * scal;

    return vectResult;
}

template <class T>
inline T Vect3D<T>::ProduitScalaire(Vect3D vect3dA) {
    T scalaireResult;

    scalaireResult = (this->m_x * vect3dA.m_x) + (this->m_y * vect3dA.m_y) + (this->m_z * vect3dA.m_z);

    return scalaireResult;
}

template <class T>
inline Vect3D<T> Vect3D<T>::ProduitVectoriel(Vect3D vect3dA) {
    Vect3D vectResult;

    vectResult.m_x = (this->m_y * vect3dA.m_z) - (this->m_z * vect3dA.m_y);
    vectResult.m_y = (this->m_z * vect3dA.m_x) - (this->m_x * vect3dA.m_z);
    vectResult.m_z = (this->m_x * vect3dA.m_y) - (this->m_y * vect3dA.m_x);

    return vectResult;
}

template <class T>
inline T Vect3D<T>::CalculDeterminant(Vect3D vect3dA, Vect3D vect3dB) {
    T determRes;

    determRes = vect3dB.ProduitScalaire(this->ProduitVectoriel(vect3dA));

    return determRes;
}

template <class T>
inline Vect3D<T> Vect3D<T>::ProduitMixte(Vect3D vect3dA, T determ) {
    Vect3D vectResult;

    vectResult = (this->ProduitVectoriel(vect3dA)).MultiplicationParScalaire(determ);

    return vectResult;
}

//Surcharge des opérateurs.
template <class T>
inline Vect3D<T> Vect3D<T>::operator+(const Vect3D vect3dA) {
    Vect3D vectResult;
    vectResult.m_x = this->m_x + vect3dA.m_x;
    vectResult.m_y = this->m_y + vect3dA.m_y;
    vectResult.m_z = this->m_z + vect3dA.m_z;

    return vectResult;
}

template <class T>
inline Vect3D<T> Vect3D<T>::operator-(const Vect3D vect3dA) {
    Vect3D vectResult;

    vectResult.m_x = this->m_x - vect3dA.m_x;
    vectResult.m_y = this->m_y - vect3dA.m_y;
    vectResult.m_z = this->m_z - vect3dA.m_z;

    return vectResult;
}

template <class T>
inline Vect3D<T> Vect3D<T>::operator*(const T scal) {
    Vect3D vectResult;

    vectResult.m_x = this->m_x * scal;
    vectResult.m_y = this->m_y * scal;
    vectResult.m_z = this->m_z * scal;

    return vectResult;
}

template <class T>
inline T Vect3D<T>::operator*(const Vect3D vect3dA) {
    T scalaireResult;

    scalaireResult = (this->m_x * vect3dA.m_x) + (this->m_y * vect3dA.m_y) + (this->m_z * vect3dA.m_z);

    return scalaireResult;
}

template <class T>
inline Vect3D<T> Vect3D<T>::operator^(const Vect3D vect3dA) {
    Vect3D vectResult;

    vectResult.m_x = (this->m_y * vect3dA.m_z) - (this->m_z * vect3dA.m_y);
    vectResult.m_y = (this->m_z * vect3dA.m_x) - (this->m_x * vect3dA.m_z);
    vectResult.m_z = (this->m_x * vect3dA.m_y) - (this->m_y * vect3dA.m_x);

    return vectResult;
}

template <class T>
inline Vect3D<T> Vect3D<T>::operator=(const Vect3D vect3dA) {
    this->m_x = vect3dA.m_x;
    this->m_y = vect3dA.m_y;
    this->m_z = vect3dA.m_z;

    return *this;
}

template <class T>
inline bool Vect3D<T>::operator==(const Vect3D vect3dA) {
    bool valid;

    valid = ((vect3dA.m_x == this->m_x) && (vect3dA.m_y == this->m_y) && (vect3dA.m_z == this->m_z));
    
    return valid;
}

#endif /* Vect3d_hpp */
