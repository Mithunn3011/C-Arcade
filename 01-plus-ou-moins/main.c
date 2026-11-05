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
    int mode;
    printf("Bienvenue au Jeu : Plus ou Moins\n");
    printf("Choisissez le mode jeu [Simple (0) ou Difficile (1)] : ");
    scanf("%d",&mode);
    if (mode == 0) {
        printf("Choisissez le minumum :");
        scanf("%d", &min);
        printf("Choisissez le maximum :");
        scanf("%d", &max);
    }
    else if (mode == 1){
        min = 0;
        max = 1000; 
    }
    int nb_secret = tirer_nombre(min,max);
    do {
        printf("Ton Essai : ");
        scanf("%d,", &proposition);
        int r = comparer(proposition, nb_secret);
        if (r == 1) {
            printf("Plus petit !\n");
        }
        else if (r == -1) {
            printf("Plus grand !\n");
        }
        if (proposition < min){
            printf("C'est plus petit que l'intervalle choisi");
        }
        else if (proposition > max){
            printf("C'est plus grand que l'intervalle choisi");
        }
        t +=1;
        if (mode == 1 && t == 10) {
            printf("Perdu !\n");
            return 0;
        }
    } while (proposition != nb_secret);
    printf("Trouvé !\n");
    if (t <= 5){
        printf("Devin !\n");
    } else if (t <=8){
        printf("Pas Mal !\n");
    } else {
        printf("Tu va y arriver !\n");
    }
    
}
