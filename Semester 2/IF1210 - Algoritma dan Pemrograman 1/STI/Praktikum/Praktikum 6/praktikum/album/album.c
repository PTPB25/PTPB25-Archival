#include "album.h"
#include <stdio.h>

void CreateEmptyAlbum(Album *A){
    A->Count = Nil;
}

boolean IsEmptyAlbum(Album A){
    return A.Count == Nil;
}

boolean IsFullAlbum(Album A){
    return A.Count == MaxElSong;
}

boolean IsSongInAlbum(Album A, char SongTitle[]){
    for(int i = 0; i < A.Count; i++){
        if(strcmp(SongTitle, A.Songs[i]) == 0){
            return true;
        }
    }
    return false;
}

int cmpstr(const void *a, const void *b){
    const char *sa = (const char *)a;
    const char *sb = (const char *)b;
    return strcmp(sa, sb);
}

void SortAlbum(Album *A){
    qsort((*A).Songs, (*A).Count, sizeof((*A).Songs[0]), cmpstr);
}

void InsertSong(Album *A, char SongTitle[]){
    if(A->Count != MaxElSong && !IsSongInAlbum(*A,SongTitle)){
        strcpy(A->Songs[A->Count], SongTitle);
        A->Count++;
    }

    SortAlbum(A);
}

void DeleteSong(Album *A, char SongTitle[]){
    if(IsSongInAlbum(*A,SongTitle)){
        for(int i = 0; i < A->Count; i++){
            if(strcmp(SongTitle, A->Songs[i]) == 0){
                for(int j = i; j<A->Count-1; j++){
                    strcpy(A->Songs[j], A->Songs[j+1]);
                }
                return;
            }
        }
    }
}
/* Menghapus SongTitle dari Album A. */
/* I.S. A tidak kosong
        SongTitle mungkin anggota / bukan anggota dari A */
/* F.S. SongTitle bukan anggota dari A */
/* Bisa memanfaatkan strcmp dan strcpy */

Album UnionAlbum(Album A1, Album A2){
    Album merged;
    CreateEmptyAlbum(&merged);
    int i;
    int indexMerg = 0;
    for(i = 0; i<A1.Count; i++){
        strcpy(merged.Songs[i], A1.Songs[i]);
        indexMerg++;
        merged.Count++;
    }

    for(i = 0; i<A2.Count; i++){
        if(!IsSongInAlbum(merged, A2.Songs[i])){
            strcpy(merged.Songs[indexMerg],A2.Songs[i]);
            indexMerg++;
            merged.Count++;
        }
    }
    SortAlbum(&merged);
    return merged;
}

Album IntersectionAlbum(Album A1, Album A2){
    Album intersect;
    CreateEmptyAlbum(&intersect);

    int i =0;
    int k = 0;

    while(i < A1.Count){
        if(IsSongInAlbum(A2, A1.Songs[i])){
            strcpy(intersect.Songs[k++], A1.Songs[i]);
        
        }
        i++;
    }

    intersect.Count = k;
    SortAlbum(&intersect);
    return intersect;
}

Album DifferenceAlbum(Album A1, Album A2){
    Album diff;
    CreateEmptyAlbum(&diff);

    int k = 0;
    for(int i = 0; i<A1.Count; i++){
        if(!IsSongInAlbum(A2,A1.Songs[i])){
            strcpy(diff.Songs[k++], A1.Songs[i]);
        }
    }

    diff.Count=k;
    SortAlbum(&diff);
    return diff;
}

void PrintAlbum(Album A){
    Album sorted = A;
    SortAlbum(&sorted);

    printf("{");
    if(sorted.Count > 0){
        for(int i = 0; i<sorted.Count;i++){
            printf("%s", sorted.Songs[i]);
            
            if(i < sorted.Count-1){
                printf(", ");
            }
        }
    }
    printf("}\n");
}
