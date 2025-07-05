#include "functii.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


biblioteca *aloc_bibl() {
    biblioteca *bibl = malloc(sizeof(biblioteca));
    if (bibl == NULL) {
        printf ("Eroare la alocare");
        return NULL;
    }
    bibl->nr_carti = 0;
    bibl->nr_genuri_literare = 0;
    bibl->Nume = malloc(100);
    return bibl;
}

void init_bibl (biblioteca* bibl, int nr_carti, int nr_genuri, char *nume) {
    bibl->nr_carti = nr_carti;
    bibl->nr_genuri_literare = nr_genuri;
    strcpy(bibl->Nume, nume);
}

void free_bibl (biblioteca *bibl) {
    free(bibl->Nume);
    bibl->Nume = NULL;
    free(bibl);
}

carte *aloc_carte() {
    carte *book = malloc(sizeof(struct book));
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

void init_carte(carte* book, char* titlu, char* autor, char* sectiune, char* editura, int nr_pag) {
    strcpy(book->titlu, titlu);
    strcpy(book->autor, autor);
    strcpy(book->sectiune, sectiune);
    strcpy(book->editura, editura);
    book->nr_pagini = nr_pag;
}

void free_carte(carte* book) {
    free(book->titlu);
    free(book->autor);
    free(book->sectiune);
    free(book->editura);
    book->titlu = book->autor = book->sectiune = book->editura = NULL;
    free(book);
}

cititor* aloc_cititor() {
    cititor *reader = malloc(sizeof(struct reader));
    if (reader == NULL) {
        printf ("Eroarea la alocare");
        return NULL;
    }
    reader->nr_carti_imprumutate = 0;
    reader->nr_permis_biblioteca = 0;
    reader->varsta = 0;
    reader->nume = malloc(50);
    return reader;
}

void init_cititor(cititor* reader, char* nume, int varsta, int nr_carti, int nr_permis) {
    reader->varsta = varsta;
    reader->nr_carti_imprumutate = nr_carti;
    reader->nr_permis_biblioteca = nr_permis;
    strcpy(reader->nume, nume);
}