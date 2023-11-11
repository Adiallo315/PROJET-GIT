#include <stdio.h>

void convertisseurBinaire(int n) {
    for (int k = 7; k >= 0; k--) {
        printf("%d", (n >> k) & 1);
    }
    printf(".");
}


int main() {
    char adresseIPFiltrage[16];
    char masqueFiltrage[16];  

    int adresseIPTableau[4] = {0};
    int indexIP = 0;
    int accumuleNumbreIP = 0;

    int masqueTableau[4] = {0};
    int indexMasque = 0;
    int accumuleNumbreMasque = 0;


    printf("Entrez l'adresse IP  : ");
    scanf("%s", adresseIPFiltrage);

    int i = 0;
    while (adresseIPFiltrage[i] != '\0') {
        if (adresseIPFiltrage[i] == '.') {
            adresseIPTableau[indexIP++] = accumuleNumbreIP;
            accumuleNumbreIP = 0;
        } else {
            accumuleNumbreIP = accumuleNumbreIP * 10 + (adresseIPFiltrage[i] - '0');
        }
        i++;
    }
    adresseIPTableau[indexIP] = accumuleNumbreIP;

    printf("Adresse IP stockee : %d.%d.%d.%d\n", adresseIPTableau[0], adresseIPTableau[1], adresseIPTableau[2], adresseIPTableau[3]);

    printf("Entrez le masque  : ");
    scanf("%s", masqueFiltrage);

    int y = 0;
    while (masqueFiltrage[y] != '\0') {
        if (masqueFiltrage[y] == '.') {
            masqueTableau[indexMasque++] = accumuleNumbreMasque;
            accumuleNumbreMasque = 0;
        } else {
            accumuleNumbreMasque = accumuleNumbreMasque * 10 + (masqueFiltrage[y] - '0');
        }
        y++;
    }
    masqueTableau[indexMasque] = accumuleNumbreMasque;

    printf("MAsque stocke : %d.%d.%d.%d\n", masqueTableau[0], masqueTableau[1], masqueTableau[2], masqueTableau[3]);

    printf("Adresse IP en binaire : ");
    for (int j = 0; j < 4; j++) {
        convertisseurBinaire(adresseIPTableau[j]);
    }
    printf("\n");

    
    printf("MAsque IP en binaire : ");
    for (int j = 0; j < 4; j++) {
        convertisseurBinaire(masqueTableau[j]);
    }
    printf("\n");



    return 0;
}
