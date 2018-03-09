#include "tp1.h"

void afficherElt(Liste l);
Liste insererEnTete(Liste l, int val, int usine);
Liste nouvelleListe(void);
void libererListe(Liste l);
Liste insererEnFin(Liste l, int *periode, int n);

Liste supprElt(maillon *prec, maillon *suppr);
void afficherListe(Liste l);
Liste supprPremierElt(Liste l);
void libererElt(maillon *m);