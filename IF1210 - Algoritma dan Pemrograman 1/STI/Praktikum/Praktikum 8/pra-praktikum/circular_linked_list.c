#include <stdio.h>
#include "circular_linked_list.h"
/**
 * @brief Membuat node baru.
 *
 * @param data Nilai integer yang akan disimpan dalam node baru.
 * @return Node* Pointer ke node yang baru dibuat.
 * NULL jika alokasi memori gagal.
 */
Node *createNode(int data){
    Node *new = malloc(sizeof(Node));
    if(new != NULL){
        new->data = data;
        new->next = NULL;
    }
    return new;
}

/**
 * @brief Mengecek apakah circular linked list kosong.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @return int 1 jika list kosong, 0 jika tidak.
 */
int isEmpty(Node *last){
    return last == NULL;
}

/**
 * @brief Menambahkan node di awal circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi jika list awalnya kosong atau saat node baru ditambahkan.
 * @param data Nilai integer yang akan ditambahkan.
 * @return true jika penambahan berhasil, false jika penambahan node gagal.
 */
bool insertAtBeginning(Node **last, int data){
    Node *new =createNode(data);
    if(new == NULL){
        return false;
    }
    if(isEmpty(*last)){
        new->next = new;
        *last = new;
        return true;
    }

    new->next = (**last).next;
    (**last).next = new;
    return  true;

}

/**
 * @brief Menambahkan node di akhir circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi saat node baru ditambahkan.
 * @param data Nilai integer yang akan ditambahkan.
 * @return true jika penambahan berhasil, false jika penambahan node gagal.
 */
bool insertAtEnd(Node **last, int data){
    Node *new = createNode(data);
    if(new == NULL) return false;
    if(isEmpty(*last)){
        new->next = new;
        *last = new;
        return true;
    }

    new->next = (**last).next;
    (**last).next = new;
    *last = new;
    return true;
}

/**
 * @brief Menambahkan node setelah node dengan nilai tertentu.
 * Jika ada beberapa node dengan nilai 'searchValue', node baru akan
 * dimasukkan setelah kemunculan pertama.
 * Jika 'searchValue' tidak ditemukan, node tidak ditambahkan.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @param searchValue Nilai data dari node yang dicari untuk penyisipan
 * setelahnya.
 * @param data Nilai integer yang akan ditambahkan pada node baru.
 * @return true jika penambahan berhasil, false jika penambahan node gagal.
 */
bool insertAfter(Node **last, int searchValue, int data){
    Node *new = createNode(data);
    if(new == NULL) return false;
    if(isEmpty(*last)) {
    free(new);
    return false;
    }
    Node *pos = (*last)->next;

    do {
        if(pos->data == searchValue){
            new->next = pos->next;
            pos->next = new;
            if(pos == *last){
                *last = new;
            }
            return true;
        }
        pos = pos->next;
    } while(pos != (*last)->next);

    free(new); 
    return false;
}

/**
 * @brief Menghapus node di awal circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi.
 */
void deleteFromBeginning(Node **last){
    if(isEmpty(*last)) return;

    Node *del = (*last)->next;

    if(del == *last){
        free(del);
        *last = NULL;
    }else{
        (*last)->next = del->next;
        free(del);
    }
}

/**
 * @brief Menghapus node di akhir circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list
 *
 * @return Node* Pointer ke node terakhir setelah penghapusan.
 * NULL jika list kosong setelah penghapusan.
 *
 * Keterangan:
 */
void deleteFromEnd(Node **last){
    if(isEmpty(*last)) return;
    Node *del = (*last)->next;

    if(del == *last){
        free(del);
        *last = NULL;
        return;
    }

    Node *prev = NULL;
    while(del->next != *last){
        del = del->next;
    }
    prev = del;

    prev->next = (*last)->next;
    free(*last);
    *last = prev;
}

/**
 * @brief Menghapus node dengan nilai tertentu dari circular linked list.
 * Jika ada beberapa node dengan nilai 'dataToDelete', hanya kemunculan
 * pertama yang akan dihapus.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi jika node yang dihapus adalah node terakhir atau
 * satu-satunya node.
 * @param dataToDelete Nilai integer dari node yang akan dihapus.
 * @return Node* Pointer ke node terakhir setelah penghapusan.
 * NULL jika list menjadi kosong atau jika dataToDelete tidak ditemukan.
 */
void deleteNodeWithValue(Node **last, int dataToDelete){
    if(isEmpty(*last)) return;

    Node *pos = (*last)->next;
    Node *prev = *last;

    do{
        if(pos->data == dataToDelete){

            if(pos == *last && pos->next == *last){
                free(pos);
                *last = NULL;
            }else{
                prev->next = pos->next;
                if(pos == *last) {
                    *last = prev;
                }
                
                free(pos);
            }
            return;

        }

        prev = pos;
        pos = pos->next;
    } while (pos != (*last)->next);
}

/**
 * @brief Mencari sebuah nilai dalam circular linked list.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @param searchValue Nilai integer yang akan dicari.
 * @return Node* Pointer ke node yang mengandung searchValue jika ditemukan.
 * NULL jika searchValue tidak ditemukan dalam list atau list kosong.
 */
Node *searchNode(Node *last, int searchValue){
    if(last == NULL) return NULL;

    Node *result = last->next;

    do{
        if(result->data == searchValue){
            return result;
        }

        result = result->next;
    } while (result != last->next);
    return NULL;
}

/**
 * @brief Menampilkan semua elemen dalam circular linked list.
 * Dimulai dari node setelah node 'last' (yang secara efektif adalah awal list).
 *
 * @param last Pointer ke node terakhir dalam list.
 *
 * Keterangan:
 * 1. Jika list kosong maka keluarkan "KOSONG"
 * 2. Contoh keluaran: 1 -> 2 -> 3
 * 3. Akhiri keluaran dengan newline
 */
void displayList(Node *last){
    if(isEmpty(last)){
        printf("KOSONG\n");
        return;
    }

    Node *pos = last->next;
    do{
        printf("%d", pos->data);
        pos = pos->next;
        if(pos != last->next) printf(" -> ");
    } while (pos != last->next);
    printf("\n");
}

/**
 * @brief Menghapus semua node dalam circular linked list dan membebaskan
 * memorinya.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan diatur menjadi NULL setelah semua node dihapus.
 */
void deleteAllNodes(Node **last){
    if(isEmpty(*last)) return;

    Node *start = (*last)->next;
    Node *curr = start;

    do {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    } while(curr != start);

    *last = NULL;

}

