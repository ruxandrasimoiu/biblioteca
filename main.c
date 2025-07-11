#include "functii.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    biblioteca bib = aloc_bibl();
    // // int nr_carti = 100;
    int nr_genuri = 6;
    int nr_cititori = 5;
    char* nume = malloc(50);
    // // nume = "Biblioteca lui Ruxi";
    strcpy(nume, "Biblioteca lui Ruxi");
    init_bibl(bib, nr_genuri, nume, nr_cititori);
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
    // int nr_carti_imp = 4;

    init_cititor(reader, nume_cititor, varsta, permis);

    afisez_cititor(reader);

    printf("----------------------------------------\n\n");

    adaug_carte(book, bib, sectiune);
    adaug_sectiune(bib, sectiune);
    adaug_carte(book, bib, sectiune);
    afisez_sectune(bib, sectiune);

    adaug_cititor(bib, reader);
    afisez_cititor(bib->cititori[bib->nr_cititori - 1]);
    // afisez_toate_cartile(bib);

    printf("----------------------------------------\n\n");
    // imprumut_carte(book, reader, bib);
    // afisez_imprumut(reader);
    // printf("----------------------------------------\n\n");
    // return_carte(book, reader, bib);
    // afisez_imprumut(reader);

    sterg_carte(book, bib);
    sterg_cititor(reader, bib);

    
    

    // free_carte(book);
    free(titlu);
    free(autor);
    free(sectiune);
    free(editura);
    // free_cititor(reader);
    free(nume);
    free_bibl(bib);
    free(nume_cititor);
    return 0;
}