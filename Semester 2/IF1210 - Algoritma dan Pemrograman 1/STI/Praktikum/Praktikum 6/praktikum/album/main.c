#include "album.h"

int main() {
    Album A1, A2, A3;
    
    /* Membuat album kosong */
    CreateEmptyAlbum(&A1);
    CreateEmptyAlbum(&A2);
    CreateEmptyAlbum(&A3);

    if (IsEmptyAlbum(A1)) {
        printf("Album 1 kosong\n");
    }
    else {
        printf("Album 1 tidak kosong\n");
    }

    /* Menambahkan lagu ke Album A1 */
    printf("<A1 diisi>\n");
    InsertSong(&A1, "abc def");
    InsertSong(&A1, "bcd efg");
    InsertSong(&A1, "zyxwvut");
    InsertSong(&A1, "title4");

    
    if (IsEmptyAlbum(A1)) {
        printf("Album 1 kosong\n");
    }
    else {
        printf("Album 1 tidak kosong\n");
    }
    
    printf("\nIsi Album 1:\n");
    PrintAlbum(A1);
    
    if(IsSongInAlbum(A1, "abc def")) {
        printf("\nLagu 'abc def' ada di album A1\n");
    }
    else {
        printf("\nLagu 'abc def' tidak ada di album A1\n");
    }

    if(IsSongInAlbum(A1, "song1")) {
        printf("Lagu 'song1' ada di album A1\n");
    }
    else {
        printf("Lagu 'song1' tidak ada di album A1\n");
    }

    /* Menambahkan lagu ke Album A2 */
    InsertSong(&A2, "title1");
    InsertSong(&A2, "bcd efg");
    InsertSong(&A2, "zyxwvut");
    InsertSong(&A2, "song4");

    printf("\nIsi Album 2:\n");
    PrintAlbum(A2);

    /* Menghapus lagu */
    printf("\nMenghapus 'song4' dari A2...\n");
    DeleteSong(&A2, "song4");

    printf("Album A2 setelah delete:\n");
    PrintAlbum(A2);

    /* Melakukan Union */
    printf("\nUnion Album A1 dan A2:\n");
    A3 = UnionAlbum(A1, A2);
    PrintAlbum(A3);

    /* Melakukan Intersection */
    printf("\nIntersection Album A1 dan A2:\n");
    A3 = IntersectionAlbum(A1, A2);
    PrintAlbum(A3);

    /* Melakukan Difference */
    printf("\nDifference Album A1 - A2:\n");
    A3 = DifferenceAlbum(A1, A2);
    PrintAlbum(A3);

    return 0;
}