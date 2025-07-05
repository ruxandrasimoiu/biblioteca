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
    bibl->Nume = NULL;
    return bibl;
}

void init_bibl (biblioteca* bibl, int nr_carti, int nr_genuri, char *nume) {
    bibl->nr_carti = nr_carti;
    bibl->nr_genuri_literare = nr_genuri;
    strcpy(bibl->Nume, nume);
}

void free_bibl(biblioteca *bibl) {
    free(bibl->Nume);
    bibl->Nume = NULL;
    free(bibl);
}