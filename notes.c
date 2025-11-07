#include <stdio.h>
#include <string.h>
#define maxNumberOfNotes 100
#define maxNoteLength 500

char notes[maxNumberOfNotes][maxNoteLength]; 
int count = 0; 

void addNote() {
 if (count >= maxNumberOfNotes) {
    printf("Too many notes! Delete one first.\n");
return;
}
printf("Enter your note: ");
scanf(" %[^\n]", notes[count]);
count++;
printf("Added note!\n");
}

void showNotes() {
if (count == 0) {
printf("No notes saved.\n");
return;
}

printf("Your notes:\n");

for (int i = 0; i < count; i++) {
printf("%d: %s\n", i + 1, notes[i]);
  }
}

void deleteNote() {
    
int deleteNumber;

showNotes();

printf("Enter the note number to delete: ");
scanf("%d", &deleteNumber);
if (deleteNumber < 1 || deleteNumber > count) {
printf("Invalid number.\n");
return;
} 

for (int i = deleteNumber - 1; i < count - 1; i++) {
strcpy(notes[i], notes[i + 1]);
}

count--;

printf("Note deleted.\n");
}

int main() {
    
int choice;

while(1) {
printf("choice:\n");
printf("1. Add Note\n");
printf("2. Show Notes\n");
printf("3. Delete Note\n");
printf("0. Exit\n");
printf("Choose: ");

scanf("%d", &choice);

switch (choice) {

case 1: 
addNote(); 
break;

case 2: 
showNotes(); 
break;

case 3: 
deleteNote(); 
break;

case 0:
printf("exiting\n"); 
return 0;

default: printf("choose a number listed in the menu\n");
 }
}

return 0;
}
