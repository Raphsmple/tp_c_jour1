#include <stdio.h>

int main(void) {
    int note;
    printf("Note (0-20) : ");
    scanf("%d", &note);

    if (note < 0 || note > 20) {
        printf("Note invalide\n");
        printf("Admis\n");
    } else if (note >= 16) {
        printf("Tres bien\n");
        printf("Admis\n");
    } else if (note >= 12) {
        printf("Bien\n");
        printf("Admis\n");
    } else if (note >= 10) {
        printf("Passable\n");
        printf("Admis\n");
    } else {
        printf("Insuffisant\n");
        printf("Refusé\n");
    }
    return 0;
}