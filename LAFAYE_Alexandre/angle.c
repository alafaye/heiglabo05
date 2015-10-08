/* Fichier : angle.c
 * Auteur  : Alexandre Lafaye
 * Date    : 08.10.2015
 *
 * But     :  Labo05: Calcul des angles à partir des côtés d'un triangle.
 *
 *
 * Remarque(s) : 
 *
 *
 * Compilateur : g++
 * Debuggueur : gdb
 */
//Pour Windows
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

//Un pi plus naturel
#define pi M_PI
#define lim_hori 80.
#define lim_vert 100.

void dessine_triangle(double h, double l, double alpha)
{
    //Il faut définir une pente pour le côté du triangle afin de pouvoir utiliser les bons chara.
    double m = h/l;
    double h_dessin=h, l_dessin=l;
    //Pour dessiner un triangle qui s'adapte au standard des terminaux, il faut qu'il ne dépasse pas 80 charactères de long.
    if(l>lim_hori)
    {
	double rapport = l/lim_hori;
	h_dessin = h*rapport;
	l_dessin = l*rapport;
    }
    //De manière équivalente, on ne voudrait pas qu'il soit trop "haut" donc on limite à 100 char.
    if(h>lim_vert)
    {
	double rapport = l/lim_vert;
	h_dessin = h*rapport;
	l_dessin = l*rapport;
    }

    // On indique quel triangle on dessine
    printf("\n\n        triangle: %.1f x %.1f. \n", h, l);

    //Montrer la hauteur
    printf("%.1f\n", h);

    //dessin de la hauteur, il faudrait ajouter la diagonale
    for(int i=0; i<(int)h_dessin-1; i++)
    {
	printf(" |\n");
    }

    //Chara final de la hauteur et debut du dessin du bas du triangle
    printf(" |");
    char bas_tri[(int)l_dessin];
    for(int k=0; k<(int)l_dessin; k++)
    {
	printf("_");
    }
    // On indique l'angle.
    printf("\\ %c:%.1f  \n", 0x61, alpha);

    //Tentative d'aligner la mesure avec le milieu du bas du triangle.
    char aligneur[(int)l_dessin/2-2];
    for(int j=0; j<(int)l_dessin/2-2; j++)
    {
	printf(" ");
    }
    printf("%5.1f", l_dessin);

}

//Boucle principale
int main(void)
{
    double h, l, alpha;
    double rad_to_deg = 180./pi, deg_to_rad = pi/180.;

    printf("Programme calculant un angle à partir des deux côtés d'un triangle. \n");

    //Entrée des données par l'utilisateur.
    printf("Entrez la hauteur du batiment: ");
    scanf("%lf", &h);
    printf("Entrez la longeur de l'ombre: ");
    scanf("%lf", &l);

    //Pour éviter une division par zéro dans l'arctangente.
    if(l<=0)
    {
	printf("La longeur de l'ombre doit être un nombre strictement positif, %d ne l'est pas.", l);
	return 1;
    }

    //Calcul de l'angle en utilisant les règles du triangle
    alpha = atan(h/l);

    //Sortie pour l'utilisateur
    printf("angle rad: %f radians\n", alpha);
    printf("angle deg: %f degrés\n", alpha*rad_to_deg);

    dessine_triangle(h, l, alpha*rad_to_deg);

    getchar();
    return 0;
}
