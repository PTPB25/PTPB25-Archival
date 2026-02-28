#include <stdio.h>
#include "MegaNimons.h"


void runMegaDuel(LabTrack *L) {
    while (L->nEff > 1) {
        MegaNimons m1 = getElmt(*L, firstIdx(*L));
        MegaNimons m2 = getElmt(*L, lastIdx(*L));

        printf("\n== DUEL ROUND ==\n");
        duelOnce(m1, m2);
        MegaNimons winner = resolveDuel(m1, m2);

        if (winner.id == m1.id) {
            deleteLast(L, &m2);
        } else {
            deleteFirst(L, &m1);
        }
    }
    MegaNimons champ = getElmt(*L, firstIdx(*L));
    printf("\n== The Champion: %s ==\n", champ.name);
}