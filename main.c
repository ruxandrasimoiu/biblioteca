#include <gtk/gtk.h>
#include "functii.h"

biblioteca bibl;

void afiseaza_carti(gpointer data) {
    GtkTextBuffer *buffer = GTK_TEXT_BUFFER(data);
    gtk_text_buffer_set_text(buffer, "", -1);
    GtkTextIter iter;

    for (int i = 0; i < bibl->nr_carti; i++) {
        gchar *linie = g_strdup_printf("Titlu: %s | Autor: %s | Pagini: %d\n",
            bibl->toate_cartile[i]->titlu,
            bibl->toate_cartile[i]->autor,
            bibl->toate_cartile[i]->nr_pagini);
        gtk_text_buffer_get_end_iter(buffer, &iter);
        gtk_text_buffer_insert(buffer, &iter, linie, -1);
        g_free(linie);
    }
}

void afiseaza_cititori(gpointer data) {
    GtkTextBuffer *buffer = GTK_TEXT_BUFFER(data);
    gtk_text_buffer_set_text(buffer, "", -1);
    GtkTextIter iter;

    for (int i = 0; i < bibl->nr_cititori; i++) {
        gchar *linie = g_strdup_printf("Nume: %s | Varsta: %d | Numar permis biblioteca: %d | Numar carti imprumutate: %d\n",
            bibl->cititori[i]->nume,
            bibl->cititori[i]->varsta,
            bibl->cititori[i]->nr_permis_biblioteca,
            bibl->cititori[i]->nr_carti_imprumutate);
        gtk_text_buffer_get_end_iter(buffer, &iter);
        gtk_text_buffer_insert(buffer, &iter, linie, -1);
        g_free(linie);
    }
}

void fereastra_adauga_carte(gpointer data) {
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Adaugă carte",
        GTK_WINDOW(data),
        GTK_DIALOG_MODAL,
        "_Adaugă", GTK_RESPONSE_ACCEPT,
        "_Renunță", GTK_RESPONSE_CANCEL,
        NULL);

    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    GtkWidget *entry_titlu = gtk_entry_new();
    GtkWidget *entry_autor = gtk_entry_new();
    GtkWidget *entry_editura = gtk_entry_new();
    GtkWidget *entry_pagini = gtk_entry_new();
    GtkWidget *entry_sectiune = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Titlu:"), 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_titlu, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Autor:"), 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_autor, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Editura:"), 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_editura, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Nr. pagini:"), 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_pagini, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Secțiune:"), 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_sectiune, 1, 4, 1, 1);

    gtk_widget_show_all(dialog);
    gint result = gtk_dialog_run(GTK_DIALOG(dialog));

    if (result == GTK_RESPONSE_ACCEPT) {
        const char *titlu = gtk_entry_get_text(GTK_ENTRY(entry_titlu));
        const char *autor = gtk_entry_get_text(GTK_ENTRY(entry_autor));
        const char *editura = gtk_entry_get_text(GTK_ENTRY(entry_editura));
        const char *sectiune = gtk_entry_get_text(GTK_ENTRY(entry_sectiune));
        int pagini = atoi(gtk_entry_get_text(GTK_ENTRY(entry_pagini)));

        carte book = aloc_carte();
        init_carte(book, strdup(titlu), strdup(autor), strdup(sectiune), strdup(editura), pagini, bibl->nr_carti);
        adaug_sectiune(bibl, book->sectiune);  // adaugă dacă nu există
        adaug_carte(book, bibl, book->sectiune);
    }

    gtk_widget_destroy(dialog);
}

void fereastra_adauga_cititor(gpointer data) {
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Adaugă cititor",
        GTK_WINDOW(data),
        GTK_DIALOG_MODAL,
        "_Adaugă", GTK_RESPONSE_ACCEPT,
        "_Renunță", GTK_RESPONSE_CANCEL,
        NULL);

    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    GtkWidget *entry_nume = gtk_entry_new();
    GtkWidget *entry_varsta = gtk_entry_new();
    GtkWidget *entry_permis = gtk_entry_new();
    // GtkWidget *entry_pagini = gtk_entry_new();
    // GtkWidget *entry_sectiune = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Nume:"), 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_nume, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Varsta:"), 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_varsta, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Numar permis:"), 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_permis, 1, 2, 1, 1);

    gtk_widget_show_all(dialog);
    gint result = gtk_dialog_run(GTK_DIALOG(dialog));

    if (result == GTK_RESPONSE_ACCEPT) {
        const char *nume = gtk_entry_get_text(GTK_ENTRY(entry_nume));
        const char *varsta = gtk_entry_get_text(GTK_ENTRY(entry_varsta));
        const char *permis = gtk_entry_get_text(GTK_ENTRY(entry_permis));

        cititor reader = aloc_cititor();
        int varsta_int = atoi(varsta);
        int permis_int = atoi(permis);
        init_cititor(reader, strdup(nume), varsta_int, permis_int);
        // adaug_sectiune(bibl, book->sectiune);  // adaugă dacă nu există
        adaug_cititor(bibl, reader);
    }

    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    bibl = aloc_bibl();
    init_bibl(bibl, 0, "Biblioteca GUI", 10);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Biblioteca lui Ruxi");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *btn_adauga_carte = gtk_button_new_with_label("Adaugă carte");
    gtk_box_pack_start(GTK_BOX(vbox), btn_adauga_carte, FALSE, FALSE, 0);

    GtkWidget *btn_afiseaza = gtk_button_new_with_label("Afișează cărțile");
    gtk_box_pack_start(GTK_BOX(vbox), btn_afiseaza, FALSE, FALSE, 0);

    GtkWidget *btn_adauga_cititor = gtk_button_new_with_label("Adaugă cititor");
    gtk_box_pack_start(GTK_BOX(vbox), btn_adauga_cititor, FALSE, FALSE, 0);

    GtkWidget *btn_afiseaza_cititor = gtk_button_new_with_label("Afișează cititorii");
    gtk_box_pack_start(GTK_BOX(vbox), btn_afiseaza_cititor, FALSE, FALSE, 0);

    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_vexpand(scroll, TRUE);
    gtk_box_pack_start(GTK_BOX(vbox), scroll, TRUE, TRUE, 0);

    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_container_add(GTK_CONTAINER(scroll), text_view);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    g_signal_connect(btn_afiseaza, "clicked", G_CALLBACK(afiseaza_carti), buffer);
    g_signal_connect(btn_adauga_carte, "clicked", G_CALLBACK(fereastra_adauga_carte), window);
    g_signal_connect(btn_afiseaza_cititor, "clicked", G_CALLBACK(afiseaza_cititori), buffer);
    g_signal_connect(btn_adauga_cititor, "clicked", G_CALLBACK(fereastra_adauga_cititor), window);

    gtk_widget_show_all(window);
    gtk_main();

    free_bibl(bibl);
    return 0;
}
