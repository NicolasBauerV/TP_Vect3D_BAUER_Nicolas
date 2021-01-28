//
//  Vect2D.hpp
//  TP_vect3D_BAUER_Nicolas
//

#ifndef Vect2D_hpp
#define Vect2D_hpp

#include <iostream>
#include "Vect3d.hpp"

template <class T> class Vect2D : public Vect3D<T> {
public:
    //Les constructeurs
    Vect2D(T x = 0.f, T y = 0.f); //Le constructeur
    Vect2D(const Vect2D&); //Le constructeur de copie

    //Fonction d'affichage
    void Affiche() const;

    //Opérations usuelles sur les Vecteurs avec des Surcharges d'opérateurs :
    Vect2D operator+(const Vect2D vect2dA); //Addition
    Vect2D operator-(const Vect2D vect2dA); //Soustraction
    Vect2D operator*(const T scal); //Multiplication par Scalaire
    T operator*(const Vect2D vect2dA); //Produit Scalaire
    Vect2D operator^(const Vect2D vect2dA); //Produit Vectoriel

    Vect2D operator=(const Vect2D vect2dA); //Affectation
    bool operator==(const Vect2D vect2dA); //Coincide
    
    //Affichage
    friend ostream& operator<<(ostream& os, const Vect2D& vect2d) {
        cout << "X = " << vect2d.m_x << " Y = " << vect2d.m_y;
        return os;
    }
    
    //Fonctions amies
    friend bool Coincide(Vect2D const vect2dA, Vect2D const vect2dB) {
        bool valid;

        valid = ((vect2dA.m_x == vect2dB.m_x) && (vect2dA.m_y == vect2dB.m_y));

        return valid;
    }
};

//Les constructeurs

template <class T>
inline Vect2D<T>::Vect2D(T x, T y):Vect3D<T>(x,y,static_cast<T>(1)) {}

template <class T>
inline Vect2D<T>::Vect2D(const Vect2D& vectCopie) {
    this->m_x = vectCopie.m_x;
    this->m_y = vectCopie.m_y;
}

//Fonction d'affichage
template <class T>
inline void Vect2D<T>::Affiche() const {
    cout << "X = " << this->m_x << " Y = " << this->m_y << endl;
}

//Opérations usuelles sur les Vecteurs avec des Surcharges d'opérateurs :
#pragma region Opérations usuelles sur les Vecteurs.
template <class T>
inline Vect2D<T> Vect2D<T>:: operator+(const Vect2D vect2dA) {
    Vect2D vectRes;
    vectRes.m_x = this->m_x + vect2dA.m_x;
    vectRes.m_y = this->m_y + vect2dA.m_y;

    return vectRes;
}

template <class T>
inline Vect2D<T> Vect2D<T>::operator-(const Vect2D vect2dA) {
    Vect2D vectRes;

    vectRes.m_x = this->m_x - vect2dA.m_x;
    vectRes.m_y = this->m_y - vect2dA.m_y;

    return vectRes;
}

template <class T>
inline Vect2D<T> Vect2D<T>::operator*(const T scal) {
    Vect2D vectRes;

    vectRes.m_x = this->m_x * scal;
    vectRes.m_y = this->m_y * scal;
    
    return vectRes;
}

template <class T>
inline T Vect2D<T>::operator*(const Vect2D vect2dA) {
    T scalaireResult;

    scalaireResult = (this->m_x * vect2dA.m_x) + (this->m_y * vect2dA.m_y);

    return scalaireResult;
}

template <class T>
inline Vect2D<T> Vect2D<T>::operator^(const Vect2D vect2dA) {
    Vect2D vectRes;

    vectRes.m_x = this->m_y - vect2dA.m_y;
    vectRes.m_y = vect2dA.m_x - this->m_x;

    return vectRes;
}

template <class T>
inline Vect2D<T> Vect2D<T>:: operator=(const Vect2D vect2dA) {
    this->m_x = vect2dA.m_x;
    this->m_y = vect2dA.m_y;

    return *this;
}

template <class T>
inline bool Vect2D<T>::operator==(const Vect2D vect2dA) {
    bool valid;

    valid = ((vect2dA.m_x == this->m_x) && (vect2dA.m_y == this->m_y));

    return valid;
}
#pragma endregion


#endif /* Vect2D_hpp */
