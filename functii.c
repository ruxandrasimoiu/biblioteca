#include "functii.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

sectiune aloc_sectiune() {
    sectiune sect = malloc(sizeof(struct sect));
    if (sect == NULL) {
        printf ("Eroare la alocare");
        return NULL;
    }
    sect->nume = malloc(20);
    sect->carti = malloc(100 * sizeof(carte));
    if (sect->carti == NULL) {
        printf ("Eroare la alocare");
        return NULL;
    }
    return sect;
}

void init_sectiune(sectiune sect, char* nume) {
    sect->nr_carti = 0;
    strcpy(sect->nume, nume);
}

void free_sectiune(sectiune sect) {
    free(sect->nume);
    free(sect->carti);
    free(sect);
}

biblioteca aloc_bibl() {
    biblioteca bibl = malloc(sizeof(struct bibl));
    if (bibl == NULL) {
        printf ("Eroare la alocare");
        return NULL;
    }
    bibl->nr_carti = 0;
    bibl->nr_genuri_literare = 0;
    bibl->Nume = malloc(100);
    bibl->toate_cartile = malloc(1000 * sizeof(carte));
    bibl->sectiuni = malloc(10 * sizeof(sectiune));
    if (bibl->sectiuni == NULL) {
        printf ("Eroare la alocare");
        return NULL;
    }
    return bibl;
}

void init_bibl (biblioteca bibl, int nr_genuri, char *nume) {
    bibl->nr_carti = 0;
    bibl->nr_genuri_literare = nr_genuri;
    for (int i = 0; i < bibl->nr_genuri_literare; i++) {
        bibl->sectiuni[i] = aloc_sectiune();
    }
    strcpy(bibl->Nume, nume);
}

void free_bibl (biblioteca bibl) {
    free(bibl->Nume);
    bibl->Nume = NULL;
    free(bibl->toate_cartile);
    for (int i = 0; i < bibl->nr_genuri_literare; i++) {

    }
    free(bibl);
}

carte aloc_carte() {
    carte book = malloc(sizeof(struct book));
    if (book == NULL) {
        printf ("Eroarea la alocare");
        return NULL;
    }
    book->nr_pagini = 0;
    book->titlu = malloc(50);
    book->autor = malloc(50);
    book->editura = malloc(50);
    book->sectiune = malloc(50);
    return book;
}

void init_carte(carte book, char* titlu, char* autor, char* sectiune, char* editura, int nr_pag, int index_bibl) {
    strcpy(book->titlu, titlu);
    strcpy(book->autor, autor);
    strcpy(book->sectiune, sectiune);
    strcpy(book->editura, editura);
    book->nr_pagini = nr_pag;
    book->index_biblioteca = index_bibl;
}

void free_carte(carte book) {
    free(book->titlu);
    free(book->autor);
    free(book->sectiune);
    free(book->editura);
    book->titlu = book->autor = book->sectiune = book->editura = NULL;
    free(book);
}

cititor aloc_cititor() {
    cititor reader = malloc(sizeof(struct reader));
    if (reader == NULL) {
        printf ("Eroarea la alocare");
        return NULL;
    }
    reader->nr_carti_imprumutate = 0;
    reader->nr_permis_biblioteca = 0;
    reader->varsta = 0;
    reader->nume = malloc(50);
    reader->carti_imprumutate = malloc(10 * sizeof(carte));
    if (reader->carti_imprumutate == NULL) {
        printf("Eroare la alocare");
        return NULL;
    }

    return reader;
}

void init_cititor(cititor reader, char* nume, int varsta, int nr_carti, int nr_permis) {
    reader->varsta = varsta;
    reader->nr_carti_imprumutate = nr_carti;
    reader->nr_permis_biblioteca = nr_permis;
    strcpy(reader->nume, nume);
}

void free_cititor(cititor reader) {
    free(reader->nume);
    free(reader->carti_imprumutate);
    free(reader);
}

void afisez_carte(carte book) {
    printf("Titlu: %s\n", book->titlu);
    printf("Autor: %s\n", book->autor);
    printf("Editura: %s\n", book->editura);
    printf("Sectiune: %s\n", book->sectiune);
    printf("Numar de pagini: %d\n", book->nr_pagini);
    printf("Index biblioteca: %d\n", book->index_biblioteca);
}

void afisez_cititor(cititor reader) {
    printf("Numele cititorului: %s\n", reader->nume);
    printf("Varsta cititorului: %d\n", reader->varsta);
    printf("Numarul permisului de biblioteca: %d\n", reader->nr_permis_biblioteca);
    printf("Numarul de carti imprumutate: %d\n", reader->nr_carti_imprumutate);
}

void afisez_biblioteca(biblioteca bib) {
    printf("Nume biblioteca: %s\n", bib->Nume);
    printf("Numar carti din biblioteca: %d\n", bib->nr_carti);
    printf("Numar genuri din biblioteca: %d\n", bib->nr_genuri_literare);
}

void afisez_toate_cartile(biblioteca bib) {
    for (int i = 0; i < bib->nr_carti; i++) {
        afisez_carte(bib->toate_cartile[i]);
        printf("\n");
    }
}

void afisez_sectune(biblioteca bib, char* sectiune) {
    for (int i = 0; i < bib->nr_genuri_literare; i++) {
        if(strcmp(bib->sectiuni[i]->nume, sectiune) == 0) {
            for (int j = 0; j < bib->sectiuni[i]->nr_carti; j++) {
                afisez_carte(bib->sectiuni[i]->carti[j]);
            }
        }
    }
}

void adaug_carte(carte book, biblioteca bibl, char* sectiune) {
    bibl->toate_cartile[bibl->nr_carti] = book;
    book->index_biblioteca = bibl->nr_carti;
    bibl->nr_carti++;
    for (int i = 0; i < bibl->nr_genuri_literare; i++) {
        if(strcmp(bibl->sectiuni[i]->nume, sectiune) == 0) {
            bibl->sectiuni[i]->carti[bibl->sectiuni[i]->nr_carti] = book;
            bibl->sectiuni[i]->nr_carti++;
        }
    }
}