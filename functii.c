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
    sect->nume[19] = '\0';
}

void adaug_sectiune(biblioteca bibl, char *nume) {
    for (int i = 0; i < bibl->nr_genuri_literare; i++) {
        if(strcmp(bibl->sectiuni[i]->nume, nume) == 0) {
            printf("Sectiunea '%s' exista deja in biblioteca!\n", nume);
            return;
        }
    }
    if (bibl->nr_genuri_literare >= 10) {
        printf("Nu mai pot fi adaugate alte sectiuni!\n");
        return;
    }
    sectiune nou = aloc_sectiune();
    init_sectiune(nou, nume);
    bibl->sectiuni[bibl->nr_genuri_literare] = nou;
    bibl->nr_genuri_literare++;
}

void free_sectiune(sectiune sect) {
    free(sect->nume);
    free(sect->carti);
    free(sect);
}

carte aloc_carte() {
    carte book = malloc(sizeof(struct book));
    if (book == NULL) {
        printf ("Eroarea la alocare");
        return NULL;
    }
    book->nr_pagini = 0;
    book->titlu = malloc(50);
    book->titlu[49] = '\0';
    book->autor = malloc(50);
    book->autor[49] = '\0';
    book->editura = malloc(50);
    book->editura[49] = '\0';
    book->sectiune = malloc(50);
    book->sectiune[49] = '\0';
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

void init_cititor(cititor reader, char* nume, int varsta, int nr_permis) {
    reader->varsta = varsta;
    reader->nr_permis_biblioteca = nr_permis;
    strcpy(reader->nume, nume);
}

void free_cititor(cititor reader) {
    free(reader->nume);
    free(reader->carti_imprumutate);
    free(reader);
}

biblioteca aloc_bibl() {
    biblioteca bibl = malloc(sizeof(struct bibl));
    if (bibl == NULL) {
        printf ("Eroare la alocare");
        return NULL;
    }
    bibl->nr_carti = 0;
    bibl->nr_genuri_literare = 0;
    bibl->nr_cititori = 0;
    bibl->Nume = malloc(100);
    bibl->toate_cartile = malloc(1000 * sizeof(carte));
    bibl->sectiuni = malloc(10 * sizeof(sectiune));
    if (bibl->sectiuni == NULL) {
        printf ("Eroare la alocare");
        return NULL;
    }
    bibl->cititori = malloc(100 * sizeof(cititor));
    if (bibl->cititori == NULL) {
        printf ("Eroare la alocare");
        return NULL;
    }
    return bibl;
}

void init_bibl (biblioteca bibl, int nr_genuri, char *nume, int nr_max_cititori) {
    bibl->nr_carti = 0;
    bibl->nr_genuri_literare = nr_genuri;
    for (int i = 0; i < bibl->nr_genuri_literare; i++) {
        bibl->sectiuni[i] = aloc_sectiune();
        if (bibl->sectiuni[i]) {
            char nume_sect[20];
            sprintf(nume_sect, "Sectiune_%d", i+1);
            init_sectiune(bibl->sectiuni[i], nume_sect);
        }
    }
    bibl->nr_max_cititori = 100;
    if(nr_max_cititori > 100) {
        cititor *c = realloc(bibl->cititori, nr_max_cititori * sizeof(cititor));
        bibl->cititori = c;
        bibl->nr_max_cititori = nr_max_cititori;
    }
    for(int i = 0; i < nr_max_cititori; i++) {
        bibl->cititori[i] = NULL;
    }
    strcpy(bibl->Nume, nume);
    bibl->Nume[99] = '\0';
}

void free_bibl (biblioteca bibl) {
    free(bibl->Nume);
    bibl->Nume = NULL;
    free(bibl->toate_cartile);
    for (int i = 0; i < bibl->nr_genuri_literare; i++) {
        free_sectiune(bibl->sectiuni[i]);
    }
    free(bibl->sectiuni);
    free(bibl->cititori);
    free(bibl);
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

void afisez_imprumut (cititor reader) {
    printf("Lista de carti imprumutate pentru cititorul %s este:\n", reader->nume);
    printf("\n");
    // printf("%d\n", reader->nr_carti_imprumutate);
    for(int i = 0; i < reader->nr_carti_imprumutate; i++) {
        afisez_carte(reader->carti_imprumutate[i]);
        printf("\n");
    }
}

void adaug_carte(carte book, biblioteca bibl, char* sectiune) {
    bibl->toate_cartile[bibl->nr_carti] = book;
    book->index_biblioteca = bibl->nr_carti;
    bibl->nr_carti++;
    for (int i = 0; i < bibl->nr_genuri_literare; i++) {
        if(bibl->sectiuni[i] && strcmp(bibl->sectiuni[i]->nume, sectiune) == 0) {
            bibl->sectiuni[i]->carti[bibl->sectiuni[i]->nr_carti] = book;
            bibl->sectiuni[i]->nr_carti++;
            return;
        }
    }
    printf("Sectiunea %s nu exista!\n", sectiune);
}

void adaug_cititor(biblioteca bibl, cititor reader) {
    if (bibl->nr_cititori + 1 >= bibl->nr_max_cititori) {
        bibl->nr_max_cititori *= 2;
    }
    bibl->cititori[bibl->nr_cititori] = reader;
    bibl->nr_cititori++;
    reader->nr_permis_biblioteca = bibl->nr_cititori;
}

void imprumut_carte(carte book, cititor reader, biblioteca bibl) {
    if (reader->nr_carti_imprumutate >= 10) {
        printf ("Cititorul a imprumutat deja numarul maxim de carti disponibile!\n");
        return;
    }
    reader->carti_imprumutate[reader->nr_carti_imprumutate] = book;
    reader->nr_carti_imprumutate++;

    bibl->carti_impr_per_cititor[reader->nr_permis_biblioteca - 1]++;
}

void return_carte(carte book, cititor reader, biblioteca bibl) {
    for (int i = 0; i < reader->nr_carti_imprumutate; i++) {
        if (strcmp(reader->carti_imprumutate[i]->titlu, book->titlu) == 0) {
            for(int j = i; j < reader->nr_carti_imprumutate - 1; j++) {
                reader->carti_imprumutate[j] = reader->carti_imprumutate[j + 1];
            }
            bibl->carti_impr_per_cititor[reader->nr_permis_biblioteca]--;
            reader->nr_carti_imprumutate--;
            printf("Cititorul %s a returnat cartea %s!\n", reader->nume, book->titlu);
            return;
        }
    }
    printf("Cititorul %s nu a imprumutat cartea %s!\n", reader->nume, book->titlu);
}

void sterg_carte(carte book, biblioteca bibl) {
    if(bibl == NULL || book == NULL) {
        return;
    }

    for(int i = 0; i < bibl->nr_genuri_literare; i++) {
        if(strcmp(bibl->sectiuni[i]->nume, book->sectiune) == 0) {
            for(int j = 0; j < bibl->sectiuni[i]->nr_carti; j++) {
                if(bibl->sectiuni[i]->carti[j] == book) {
                    for(int k = j; k < bibl->sectiuni[i]->nr_carti - 1; k++) {
                        bibl->sectiuni[i]->carti[k] = bibl->sectiuni[i]->carti[k + 1];
                    }
                    bibl->sectiuni[i]->nr_carti--;
                    break;
                }
            }
            break;
        }
    }
    for(int i = 0; i < bibl->nr_carti; i++) {
        if(bibl->toate_cartile[i] == book) {
            for(int j = i; j < bibl->nr_carti - 1; j++) {
                bibl->toate_cartile[j] = bibl->toate_cartile[j + 1];
                bibl->toate_cartile[j]->index_biblioteca = j;
            }
            printf("Cartea %s a fost stearsa din biblioteca!\n", book->titlu);
            free_carte(bibl->toate_cartile[i]);
            bibl->nr_carti--;
            return;
        }
    }
    printf("Cartea %s nu exista in biblioteca!\n", book->titlu);
}

void sterg_cititor(cititor reader, biblioteca bibl) {
    if(reader == NULL || bibl == NULL) return;
    if(reader->nr_carti_imprumutate != 0) {
        printf("Cititorul %s nu poate fi sters din baza de date pana nu returneaza toate cartile imprumutate!\n", reader->nume);
        return;
    }
    for(int i = 0; i <bibl->nr_cititori; i++) {
        if (bibl->cititori[i] == reader) {
            for (int j = i; j < bibl->nr_cititori - 1; j++) {
                bibl->cititori[j] = bibl->cititori[j + 1];
                bibl->cititori[j]->nr_permis_biblioteca = j;
            }
            bibl->nr_cititori--;
            printf("Cititorul %s a fost sters din baza de date a bibliotecii!\n", reader->nume);
            free_cititor(bibl->cititori[i]);
            return;
        }
    }
    printf("Cititorul %s nu exista in baza de date a bibliotecii!\n", reader->nume);
}