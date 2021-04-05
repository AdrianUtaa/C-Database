#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char is;
	int cod_restaurant;
	char nume[50];
	char oras[50];
	struct restaurant {
		char nume_locatie[50];
		int nr_mese;
		int nr_clienti;
		int nr_seturitacamuri;
	} loc;
	struct manager_restaurant {
		char nume[50];
		int varsta;
		float salariu;
	} manager;
} restaurant;

int nr_art(FILE* f, int p) {
	int l, m;
	l = ftell(f);
	fseek(f, 0, 2);
	m = ftell(f) / p;
	fseek(f, l, 0);
	return m;
}

void ocupare(char nume_fis[50]) {
	FILE* f;
	restaurant a;
	int n, i;
	f = fopen(nume_fis, "wb+");
	printf("n="); scanf_s("%d", &n);
	while (!feof(stdin)) {
		if (n > nr_art(f, sizeof(restaurant))) {
			fseek(f, 0, 2);
			a.is = 0;
			for (i = nr_art(f, sizeof(restaurant)); i < n; i++)
				fwrite(&a, sizeof(restaurant), 1, f);
			fseek(f, (n - 1) * sizeof(restaurant), 0);
			a.is = 1;
			a.cod_restaurant = n;
			printf("Introduceti numele restaurantului: "); getc(stdin); gets_s(a.nume);
			printf("Introduceti numele orasului in care se afla restaurantul: "); gets_s(a.oras);
			printf("Numele locatiei: "); gets_s(a.loc.nume_locatie);
			printf("Numar mese: "); scanf_s("%d", &a.loc.nr_mese);
			printf("Numar clienti: "); scanf_s("%d", &a.loc.nr_clienti);
			printf("Numar seturi tacamuri: "); scanf_s("%d", &a.loc.nr_seturitacamuri);
			printf("Introduceti numele managerului de restaurant: "); getc(stdin); gets_s(a.manager.nume);
			printf("Anii de experienta ai managerului restaurantului: "); scanf_s("%d", &a.manager.varsta);
			printf("Salariul managerului restaurantului: "); scanf_s("%f", &a.manager.salariu);
			fwrite(&a, sizeof(restaurant), 1, f);
		}
		else {
			fseek(f, (n - 1) * sizeof(restaurant), 0);
			fread(&a, sizeof(restaurant), 1, f);
			if (a.is == 0) {
				a.is = 1;
				a.cod_restaurant = n;
				printf("Introduceti numele restaurantului: "); getc(stdin); gets_s(a.nume);
				printf("Introduceti numele orasului in care se afla restaurantul: "); gets_s(a.oras);
				printf("Numele locatiei: "); gets_s(a.loc.nume_locatie);
				printf("Numar mese: "); scanf_s("%d", &a.loc.nr_mese);
				printf("Numar clienti: "); scanf_s("%d", &a.loc.nr_clienti);
				printf("Numar seturi tacamuri: "); scanf_s("%d", &a.loc.nr_seturitacamuri);
				printf("Introduceti numele managerului restaurantului: "); getc(stdin); gets_s(a.manager.nume);
				printf("Anii de experienta ai managerului restaurantului: "); scanf_s("%d", &a.manager.varsta);
				printf("Salariul managerului restaurantului: "); scanf_s("%f", &a.manager.salariu);
				fseek(f, (n - 1) * sizeof(restaurant), 0);
				fwrite(&a, sizeof(restaurant), 1, f);
			}
			else printf("inregistrarea exista\n");
		}
		printf("\nn="); scanf_s("%d", &n);
	}
	fclose(f);
}

void adaugare(char nume_fis[50]) {
	FILE* f;
	restaurant companie;
	int n, i;
	f = fopen(nume_fis, "rb+");
	int nr = sizeof(restaurant);
	printf("Cod restaurant = "); scanf_s("%d", &n);
	while (!feof(stdin)) {
		if (n > nr_art(f, nr)) {
			fseek(f, 0, 2);
			companie.is = 0;
			for (i = nr_art(f, nr); i < n; i++) {
				fwrite(&companie, sizeof(restaurant), 1, f);
			}
			fseek(f, (n - 1) * sizeof(restaurant), 0);
			companie.is = 1;
			printf("Introduceti numele restaurantului: ");
			getc(stdin); gets_s(companie.nume);
			printf("Introduceti numele orasului in care se afla restaurantul: "); gets_s(companie.oras);
			printf("Introduceti numele locatiei: "); gets_s(companie.loc.nume_locatie);
			printf("Numar mese: "); scanf("%d", &companie.loc.nr_mese);
			printf("Numar clienti: "); scanf("%d", &companie.loc.nr_clienti);
			printf("Numar seturi tacamuri: "); scanf("%d", &companie.loc.nr_seturitacamuri);
			printf("Introduceti numele managerului restaurantului: "); getc(stdin); gets_s(companie.manager.nume);
			printf("Varsta managerului restaurantului: "); scanf("%d", &companie.manager.varsta);
			printf("Salariul managerului restaurantului : "); scanf("%f", &companie.manager.salariu);
			fwrite(&companie, sizeof(restaurant), 1, f);
		}
		else {
			fseek(f, (n - 1) * sizeof(restaurant), 0);
			fread(&companie, sizeof(restaurant), 1, f);
			if (companie.is == 0) {
				companie.is = 1;
				companie.cod_restaurant = n;
				printf("Introduceti numele restaurantului: ");
				getc(stdin); gets_s(companie.nume);
				printf("Introduceti numele orasului in care se afla restaurantul: "); gets_s(companie.oras);
				printf("Introduceti numele locatiei: "); gets_s(companie.loc.nume_locatie);
				printf("Numar mese: "); scanf_s("%d", &companie.loc.nr_mese);
				printf("Numar clienti: "); scanf_s("%d", &companie.loc.nr_clienti);
				printf("Numar seturi tacamuri: "); scanf_s("%d", &companie.loc.nr_seturitacamuri);
				printf("Introduceti numele managerului restaurantului: "); getc(stdin); gets_s(companie.manager.nume);
				printf("Varsta managerului restaurantului: "); scanf_s("%d", &companie.manager.varsta);
				printf("Salariul managerului restaurantului: \n"); scanf_s("%f", &companie.manager.salariu);
				fseek(f, (n - 1) * sizeof(restaurant), 0);
				fwrite(&companie, sizeof(companie), 1, f);

			}
			else {
				printf("Inregistrarea exista deja, va rugam sa introduceti una noua\n");
			}
		}
		printf("Nr.crt = "); scanf_s("%d", &n);
	}
	fclose(f);
}



void modificare(char nume_fis[50]) {
	FILE* f;
	restaurant companie;
	int n;
	f = fopen(nume_fis, "rb+");
	if (!f) printf("Fisierul nu exista");
	else {
		printf("Selectati numarul curent al restaurantului din baza de date: ");
		scanf_s("%d", &n);
		while (!feof(stdin)) {
			if (n > nr_art(f, sizeof(restaurant))) printf("Dimensiunea fisierului este depasita.\n");
			else {
				fseek(f, (n - 1) * sizeof(restaurant), 0);
				fread(&companie, sizeof(restaurant), 1, f);
				if (companie.is == 1) {
					printf("\n%-3d || %-3d || %3d\n", companie.loc.nr_mese, companie.loc.nr_clienti , companie.loc.nr_seturitacamuri);
					printf("Numar mese: "); scanf_s("%d", &companie.loc.nr_mese);
					printf("Numar clienti: "); scanf_s("%d", &companie.loc.nr_clienti);
					printf("Numar seturi tacamuri: "); scanf_s("%d", &companie.loc.nr_seturitacamuri);
					fseek(f, (n - 1) * sizeof(restaurant), 0);
					fwrite(&companie, sizeof(restaurant), 1, f);

				}
				else printf("Inregistrarea nu exista.\n");
			}
			printf("Selectati numarul curent al restaurantului din baza de date: ");
			scanf_s("%d", &n);
		}
		fclose(f);
	}

}

void afisare(char nume_f[50]) {
	FILE* f, * g;
	restaurant a;
	if (!(f = fopen(nume_f, "rb"))) printf("nu exista fisierul");
	else {
		g = fopen("lista_fis.txt", "w");
		fread(&a, sizeof(restaurant), 1, f);
		while (!feof(f)) {
			if (a.is == 1) {
				fprintf(g, "%d %s %s %s %d %d %d %s %d %f", a.cod_restaurant, a.nume, a.oras, a.loc.nume_locatie, a.loc.nr_clienti, a.loc.nr_mese, a.loc.nr_seturitacamuri, a.manager.nume, a.manager.varsta, a.manager.salariu);
				fread(&a, sizeof(a), 1, f);
			}
			fread(&a, sizeof(restaurant), 1, f);

		}
		fclose(f); fclose(g);
	}
}


void generare_tabel(char nume_fis[40]) {
	FILE* f, * g;
	restaurant companie;
	if (!(f = fopen(nume_fis, "rb"))) printf("Baza de date nu exista!");
	else {
		g = fopen("lista_restaurante.txt", "w");
		fprintf(g, " LISTA RESTAURANTE \n");
		fprintf(g, "=============================================================================================\n");
		fprintf(g, "   COD RESTAURANT  ||  NUME RESTAURANT ||       ORAS       ||      LOCATIE      ||    MANAGER_RESTAURANT    \n");
		fprintf(g, "=============================================================================================\n");
		fread(&companie, sizeof(restaurant), 1, f);
		while (!feof(f)) {
			if (companie.is == 1) {
				fprintf(g, "\n%16d||%-15s||%-14s||%-15s||%-12s", companie.cod_restaurant, companie.nume, companie.oras, companie.loc.nume_locatie, companie.manager.nume);
			}
			fread(&companie, sizeof(restaurant), 1, f);
		}
		fclose(f); fclose(g);

	}

}

void stergere_restaurant(char nume_fis[40]) {
	FILE* f;
	restaurant companie;
	int n;
	if (!(f = fopen(nume_fis, "rb+")))
		printf("Aceasta baza de date nu exista!");
	else {
		printf("Introduceti codul restaurantului pe care doriti sa il stergeti din inregistrari: \n");
		scanf("%d", &n);
		while (!feof(stdin)) {
			if (n > nr_art(f, sizeof(companie))) printf("Ati depasit lungimea inregistrarilor din baza de date.");
			else {
				fseek(f, (n - 1) * sizeof(companie), 0);
				fread(&companie, sizeof(companie), 1, f);
				if (companie.is == 1) {
					printf("=============================================================================================\n");
					printf("   COD RESTAURANT  ||  NUME RESTAURANT ||       ORAS       ||      LOCATIE      ||    MANAGER_RESTAURANT    \n");
					printf("=============================================================================================\n");
					printf("\n % 16d || % -15s || % -14s || % -15s || % -12s", companie.cod_restaurant, companie.nume, companie.oras, companie.loc.nume_locatie, companie.manager.nume);
					companie.is = 0;
					fseek(f, (n - 1) * sizeof(restaurant), 0);
					fwrite(&companie, sizeof(companie), 1, f);
				}
				else printf("Inregistrarea nu exista.\n");
			}
			printf("Introduceti codul restaurantului pe care doriti sa il stergeti din inregistrari: \n");
			scanf("%d", &n);

		}
		fclose(f);
	}
}



int main() {
	 
	char nume_fisier[50];
	printf("Introduceti numele bazei de date: ");
	gets_s(nume_fisier);
	printf("Salutare! Selectati una dintre optiunile urmatoare: \n");
	while (!feof(stdin)) {
		int alegere;
		char crit;
		printf("1. Creare baza de date\n");
		printf("2. Introducere elemente in baza de date\n");
		printf("3. Modificare in baza de date\n");
		printf("4. Stergere element\n");
		printf("5. Generare raport sub forma de tabel\n");
		printf("6. Generare raport in functie de urmatoarele criterii: \n"); printf("a)Locatie\nb)Numar clienti\n");
		printf("Optiune = ");
		scanf("%d", &alegere);
		if (alegere == 1)
			ocupare(nume_fisier);
		else if (alegere == 2) {
			adaugare(nume_fisier);
		}
		else if (alegere == 3) {
			modificare(nume_fisier);
		}
		else if (alegere == 4) {
			stergere_restaurant(nume_fisier);
		}
		else if (alegere == 5) {
			generare_tabel(nume_fisier);
		}
		else if (alegere == 6) {
			printf("Criteriu: "); getc(stdin);
			scanf_s("%c", &crit);
			while (crit != 'a' && crit != 'b') {
				printf("Introduceti un criteriu valid.\n");
				getc(stdin); scanf_s("%c", &crit);
			}
			if (crit == 'a') {
				printf("Urmeaza implementarea\n");
				generare_tabel(nume_fisier);
			}
			else if (crit == 'b') {
				printf("Urmeaza implementarea\n");

			}
		}
		else if (alegere < 1 || alegere > 6) {
			printf("Optiunea selectata nu exista. Va rugam sa alegeti o optiune disponibila.\n");
		}


		printf("Doriti sa faceti si alte modificari?\n");
		scanf("%d", &alegere);

	}
	return 0;
}