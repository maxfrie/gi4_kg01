#include <stdio.h>
#include <stdlib.h>

/* Student - Datenstruktur */
struct student {
	char str_nachname[31];
	char str_vorname[21];
	int i_matnr;
};

/* Ausgabefunktion */
void printStudent(struct student* ptr_student)
{
  printf("%s, %s: %d\n", ptr_student->str_nachname, ptr_student->str_vorname, ptr_student->i_matnr);
}

/* Globaler Student */
struct student globalStudent = {"Frisch", "Maximilian", 357234};

int main(int argc, char* argv[], char* envp[])
{
  /* Lokaler Student */
  struct student localStudent = {"Friedel", "Maximilian", 332175};

  /* Heap Student */
  struct student *ptr_heapStudent = malloc (sizeof(struct student));
  if(ptr_heapStudent == NULL) return 1;
  strncpy(ptr_heapStudent->str_nachname, "Dahlmann", 30 * sizeof(char));
  strncpy(ptr_heapStudent->str_vorname, "Stefahn", 20 * sizeof(char));
  ptr_heapStudent->i_matnr = 333050;

  printStudent(&localStudent);
  printStudent(&globalStudent);
  printStudent(ptr_heapStudent);


  struct student *ptr_eingabeStudent = malloc (sizeof(struct student));
  printf("\nGeben Sie einen neuen Studenten an:\n<Nachname>: ");
  scanf("%s", ptr_eingabeStudent->str_nachname);
  printf("<Vorname>: ");
  scanf("%s", ptr_eingabeStudent->str_vorname);
  printf("<Matrikelnummer>: ");
  scanf("%i", &(ptr_eingabeStudent->i_matnr));
  
  printf("\nKontrolle:\n");
  printStudent(ptr_eingabeStudent);

  free(ptr_heapStudent);
  free(ptr_eingabeStudent);

  return 0;
}
