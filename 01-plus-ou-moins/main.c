#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tirer_nombre(int min, int max) {
    int nombre_secret = rand() % (max - min + 1) + min;
    return nombre_secret;
}

int comparer(int proposition, int secret) {
    if (proposition < secret){
        return -1;
    }
    if (proposition > secret){
        return 1;
    }
    return 0;
}

int main(){
    srand(time(NULL));
    int min;
    int max;
    int proposition;
    int t=0;
    printf("Bienvenue au Jeu : Plus ou Moins\n");
    printf("Choisissez le minumum :");
    scanf("%d", &min);
    printf("Choisissez le maximum :");
    scanf("%d", &max);
    int nb_secret = tirer_nombre(min,max);
    do {
        printf("Ton Essai : ");
        scanf("%d,", &proposition);
        int r = comparer(proposition, nb_secret);
        if (r == -1) {
            printf("Plus petit !\n");
        }
        else if (r == 1) {
            printf("Plus grand !\n");
        }
        t +=1;
    } while (proposition != nb_secret);
    printf("Trouvé !\n");
    if (t <= 5){
        printf("Devin !");
    } else if (t <=8){
        printf("Pas Mal !");
    } else {
        printf("Tu va y arriver !");
    }
}
