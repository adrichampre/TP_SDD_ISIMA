#include "tp1.h"

Liste insererEnTete(Liste l, int periode, int coutProd, int numero);
Liste insererEnFin(Liste l, int periode, int coutProd, int numero);
Liste nouvelleListe(void);
void libererListe(Liste l);
void afficherListe(Liste l);
void libererElt(maillon *m);
Liste supprElt(maillon *prec, maillon *suppr);
Liste supprPremierElt(Liste l);