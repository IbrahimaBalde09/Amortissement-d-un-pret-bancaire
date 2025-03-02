#include <stdio.h>
#include <math.h>

int main() {
	 
    double montant, taux_annuel, mensualite, interet, principal, restant;
    int duree, i;

    
    printf("Saisissez le montant du pret : ");
    scanf("%lf", &montant);

    printf("Saisissez la duree du pret en mois : ");
    scanf("%d", &duree);

    printf("Saisissez le taux d interet annuel (en pourcentage) : ");
    scanf("%lf", &taux_annuel);

    
    double taux_mensuel = (taux_annuel / 100) / 12;


    mensualite = montant * taux_mensuel / (1 - pow(1 + taux_mensuel, -duree));

    printf("\nTableau d amortissement du pret:\n");
    printf("--------------------------------------------------\n");
    printf("Mois\t| INTERET\t| Principal\t| Reste a payer\n");
    printf("--------------------------------------------------\n");

    restant = montant;


    for(i = 1; i <= duree; i++) {
        interet = restant * taux_mensuel;
        principal = mensualite - interet;
        restant -= principal;

    
        if (restant < 0) {
            restant = 0;
        }

        printf("%d\t| %.2lf\t| %.2lf\t| %.2lf\n", i, interet, principal, restant);
    }

    return 0;
}
