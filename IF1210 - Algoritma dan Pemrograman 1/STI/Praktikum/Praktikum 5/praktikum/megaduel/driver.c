#include <stdio.h> 
#include "MegaDuel.h"

int main(){
    LabTrack track;
    createLabTrack(&track);
    track.nEff = 3;
    // track.contents[0] = (MegaNimons){1, "Zyrok", 88.5, "laser", TRUE};
    // track.contents[1] = (MegaNimons){2, "Veltra", 72.3, "fly", FALSE};
    // track.contents[2] = (MegaNimons){3, "Kranthor", 95.7, "invisibility", FALSE};
    // track.contents[3] = (MegaNimons){4, "Zakar", 95.7, "freeze", TRUE};
    // track.contents[4] = (MegaNimons){5, "Sonny", 95.7, "pyromancy", TRUE};
    track.contents[0] = (MegaNimons){0, "Kevzilla", 800.0, "laser", TRUE};
    track.contents[1] = (MegaNimons){1, "Bobzilla", 850.0, "fly", FALSE};
    track.contents[2] = (MegaNimons){2, "Melatron", 780.0, "invisibility", FALSE};

    runMegaDuel(&track);
}
