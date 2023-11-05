#include <stdio.h>

int main() {
    char affichages[4][100] = {
        "1: Ajouter une tache",
        "2: supprimer une tache",
        "3: Mettre a jour une tache",
        "4: Afficher les tache",
    };

     for (int i = 0; i < 4; i++) {
        printf("%s \n", affichages[i]);
        printf("------------------------\n");
    }

    return 0;
}