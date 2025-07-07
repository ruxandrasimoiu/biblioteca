#ifndef FUNCTII_H
#define FUNCTII_H
#include "structuri.h"

biblioteca aloc_bibl();
void init_bibl(biblioteca b, int nr_carti, int nr_genuri, char* nume);
void free_bibl(biblioteca bibl);

carte aloc_carte();
void init_carte(carte book, char* titlu, char* autor, char* sectiune, char* editura, int nr_pag, int index_bibl);
void free_carte(carte book);

cititor aloc_cititor();
void init_cititor(cititor reader, char* nume, int varsta, int nr_carti, int nr_permis);
void free_cititor(cititor reader);

void afisez_carte(carte book);
void afisez_cititor(cititor reader);
void afisez_biblioteca(biblioteca bib);

void adaug_carte(carte book, biblioteca bibl);


#endif