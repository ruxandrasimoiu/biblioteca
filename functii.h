#ifndef FUNCTII_H
#define FUNCTII_H
#include "structuri.h"

sectiune aloc_sectiune();
void init_sectiune(sectiune sect, char* nume);
void adaug_sectiune(biblioteca bibl, char *nume);
void free_sectiune(sectiune sect);

biblioteca aloc_bibl();
void init_bibl(biblioteca b, int nr_genuri, char* nume, int nr_max_cititori);
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
void afisez_toate_cartile(biblioteca bib);
void afisez_sectune(biblioteca bib, char* sectiune);

void adaug_carte(carte book, biblioteca bibl, char* sectiune);
void adaug_cititor(biblioteca bibl, cititor reader);


void imprumut_carte(carte book, cititor reader, biblioteca bibl);

#endif