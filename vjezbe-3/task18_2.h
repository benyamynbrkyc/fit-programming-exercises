#include <cmath>
#include <iostream>

// Funkcija za unos elemenata niza
void unos(float* niz, int velicina) {
    for (int i = 0; i < velicina; i++) {
        std::cout << "Unesite element niza: ";
        std::cin >> niz[i];
    }
}

// Funkcija za ispis elemenata niza
void ispis(float* niz, int velicina) {
    for (int i = 0; i < velicina; i++) {
        std::cout << niz[i] << " ";
    }
    std::cout << std::endl;
}

// Funkcija koja vraća adresu zadnjeg elementa u nizu
float* zadnji(float* niz, int velicina) {
    return &niz[velicina - 1];
}

// Funkcija koja vraća adresu elemenata po izboru korisnika
float* zeljeni(float* niz, int velicina) {
    int index;
    std::cout << "Unesite indeks elementa: ";
    std::cin >> index;
    return &niz[index];
}

// Funkcija koja vraća adresu elementa koji je po svojoj vrijednosti najbliži vašoj idealnoj ocjeni
float* najblizi(float* niz, int velicina) {
    float idealna_ocjena;
    std::cout << "Unesite idealnu ocjenu: ";
    std::cin >> idealna_ocjena;

    float* najblizi_element = &niz[0];
    float najmanja_razlika = fabs(niz[0] - idealna_ocjena);
    for (int i = 1; i < velicina; i++) {
        float trenutna_razlika = fabs(niz[i] - idealna_ocjena);
        if (trenutna_razlika < najmanja_razlika) {
            najmanja_razlika = trenutna_razlika;
            najblizi_element = &niz[i];
        }
    }

    return najblizi_element;
}

// Kreirajte funkciju cija je zadaća dodijeliti adrese funkcija zadnji, zeljeni i najbliži pokazivačima u prethodno kreiranom nizu pokazivača
void dodijeli_adrese(float* pokazivaci[]) {
    pokazivaci[0] = zadnji;
    pokazivaci[1] = zeljeni;
    pokazivaci[2] = najblizi;
}

void task18_2() {
    // Kreirajte niz od 5 realnih brojeva
    float niz[5];
    unos(niz, 5);
    ispis(niz, 5);

    // Kreirajte niz od 3 pokazivača
    float* pokazivaci[3];

    // Dodijelite adrese funkcija zadnji, zeljeni i najbliži pokazivačima u nizu pokazivača
    dodijeli_adrese(pokazivaci);

    // Pozovite funkcije zadnji, zeljeni i najbliži preko pokazivača
    std::cout << "Zadnji element: " << *pokazivaci[0](niz, 5) << std::endl;
    std::cout << "Zeljeni element: " << *pokazivaci[1](niz, 5) << std::endl;
    std::cout << "Najbliži element: " << *pokazivaci[2](niz, 5) << std::endl;
}