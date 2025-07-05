#include "functii.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    biblioteca *bib = aloc_bibl();
    int nr_carti = 100;
    int nr_genuri = 5;
    char* nume = malloc(50);
    // nume = "Biblioteca lui Ruxi";
    strcpy(nume, "Biblioteca lui Ruxi");
    init_bibl(bib, nr_carti, nr_genuri, nume);
    printf("Nume biblioteca: %s\n", bib->Nume);
    printf("Numar carti din biblioteca: %d\n", bib->nr_carti);
    printf("Numar genuri din biblioteca: %d\n", bib->nr_genuri_literare);

    free(nume);
    free_bibl(bib);

    printf("\n");

    carte* book = aloc_carte();
    char* titlu = malloc(50);
    strcpy(titlu, "One Day");
    char* autor = malloc(50);
    strcpy(autor, "David Nicholls");
    char* sectiune = malloc(50);
    strcpy(sectiune, "Fiction");
    char* editura = malloc(50);
    strcpy(editura, "Pinguin");
    int nr_pagini = 448;

    init_carte(book, titlu, autor, sectiune, editura, nr_pagini);

    printf("Titlu: %s\n", book->titlu);
    printf("Autor: %s\n", book->autor);
    printf("Editura: %s\n", book->editura);
    printf("Sectiune: %s\n", book->sectiune);
    printf("Numar de pagini: %d\n", book->nr_pagini);

    free_carte(book);
    free(titlu);
    free(autor);
    free(sectiune);
    free(editura);

    printf("\n");

    cititor* reader = aloc_cititor();

    char *nume_cititor = malloc(10);
    strcpy(nume_cititor, "Ruxi");
    int varsta = 19;
    int permis = 124;
    int nr_carti_imp = 4;

    init_cititor(reader, nume_cititor, varsta, nr_carti_imp, permis);

    printf("Numele cititorului: %s\n", reader->nume);
    printf("Varsta cititorului: %d\n", reader->varsta);
    printf("Numarul permisului de biblioteca: %d\n", reader->nr_permis_biblioteca);
    printf("Numarul de carti imprumutate: %d\n", reader->nr_carti_imprumutate);

    free(nume_cititor);
    return 0;
}