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
    free(nume);
    free_bibl(bib);
    return 0;
}