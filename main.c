#include "functii.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    biblioteca bib = aloc_bibl();
    // int nr_carti = 100;
    int nr_genuri = 6;
    char* nume = malloc(50);
    // nume = "Biblioteca lui Ruxi";
    strcpy(nume, "Biblioteca lui Ruxi");
    init_bibl(bib, nr_genuri, nume);
    afisez_biblioteca(bib);

    printf("\n");

    carte book = aloc_carte();

    char* titlu = malloc(50);
    strcpy(titlu, "One Day");
    char* autor = malloc(50);
    strcpy(autor, "David Nicholls");
    char* sectiune = malloc(50);
    strcpy(sectiune, "Fiction");
    char* editura = malloc(50);
    strcpy(editura, "Pinguin");
    int nr_pagini = 448;
    int index = 23;

    init_carte(book, titlu, autor, sectiune, editura, nr_pagini, index);

    afisez_carte(book);

    printf("\n");

    cititor reader = aloc_cititor();

    char *nume_cititor = malloc(10);
    strcpy(nume_cititor, "Ruxi");
    int varsta = 19;
    int permis = 124;
    int nr_carti_imp = 4;

    init_cititor(reader, nume_cititor, varsta, nr_carti_imp, permis);

    afisez_cititor(reader);

    printf("----------------------------------------\n\n");

    adaug_carte(book, bib, sectiune);

    afisez_toate_cartile(bib);
    

    free_carte(book);
    free(titlu);
    free(autor);
    free(sectiune);
    free(editura);
    free_cititor(reader);
    free(nume);
    free_bibl(bib);
    free(nume_cititor);
    return 0;
}