//
//  Conteneur.hpp
//  TP_vect3D_BAUER_Nicolas
//
//  Created by Nicolas BAUER on 28/01/2021.
//

#ifndef Conteneur_hpp
#define Conteneur_hpp

#include <iostream>

using namespace std;

template <class T,int n> class Conteneur {
private :
    T m_Tableau[n];
public :
    //Les constructeurs
    Conteneur(); //Le constructeur
    Conteneur(const Conteneur&); //Le constructeur de copie
    ~Conteneur();//Le destructeur

    //Les surcharges de l'opérateur d'indexation
    T operator[](int const n_i)const;
    T& operator[](int const n_i);
};

//Le constructeur
template <class T, int n>
inline Conteneur<T,n>::Conteneur() {}

//Le constructeur de copie
template <class T, int n>
inline Conteneur<T, n>::Conteneur(const Conteneur& tab_origin) {
    m_Tableau = new T[n];
    m_Tableau = tab_origin.m_Tableau;
}

//Le destructeur
template <class T, int n>
inline Conteneur<T, n>::~Conteneur() {}

//Les surcharges de l'opérateur d'indexation
template <class T, int n>
inline T Conteneur<T, n>::operator[](int const n_i)const {
    if (n_i >= 0 && n_i < n) {
        return m_Tableau[n_i];
    }
    else {
        cout << "Erreur dépassement de Tableau." << endl;
        return m_Tableau[0];
    }
}

template <class T, int n>
inline T& Conteneur<T, n>::operator[](int const n_i) {
    if (n_i >= 0 && n_i < n) {
        return m_Tableau[n_i];
    }
    else {
        cout << "Erreur dépassement de Tableau." << endl;
        return m_Tableau[0];
    }
}

#endif /* Conteneur_hpp */
