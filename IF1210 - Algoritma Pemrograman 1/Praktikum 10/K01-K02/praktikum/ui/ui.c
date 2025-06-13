
#include "ui.h"

/**
 * @brief Mendealokasi semua elemen list dan mengatur list menjadi kosong.
 * @param l Pointer ke list yang akan di-dealokasi.
 * I.S. l terdefinisi, mungkin kosong.
 * F.S. Semua elemen list di-dealokasi. *l menjadi NULL.
 */
void dealokasiList(List *l){
    Address curr = *l;
    while(curr){
        Address temp = NEXT(curr);
        free(curr);
        curr = temp;
    }
}

/**
 * @brief Melakukan insert val ke list l secara terurut
 * @param *l adalah list yang dituju.
 * @param val adalah data yang ingin dimasukkan.
 * I.S. l terdefinisi, mungkin kosong.
 * F.S. val sudah ada di dalam l dengan semua elemen l terurut membesar.
 */
void insertSorted(List *l, ElType val){
    Address curr;
    
    curr = FIRST(*l);
    if(!curr || INFO(curr) > val){
        insertFirst(l, val);
        return;
    }
    if(INFO(curr) == val){
        return;
    }

    int inserted = 0;
    while(NEXT(curr)){
        if(INFO(NEXT(curr)) == val){
            inserted = 1;
            break;
        }

        if(INFO(NEXT(curr)) > val){
            Address new = newNode(val);
            Address temp = NEXT(curr);
            NEXT(curr) = new;
            NEXT(new) = temp;
            inserted = 1;
            break;
        }
        curr = NEXT(curr);
    }
    if(!inserted){
        insertLast(l, val);
    }
}

/**
 * @brief Mengeluarkan hasil union dari 2 buah list
 * @param l1 adalah list pertama.
 * @param l2 adalah list kedua.
 * I.S. l1 dan l2 terdefinisi, mungkin kosong.
 * F.S. l1 dan l2 tetap, tidak berubah
 * @return list yang merupakan hasil union antara list pertama dan kedua
 */
List getUnion(List l1, List l2){
    List result;
    CreateList(&result);
    Address curr;

    curr = FIRST(l1);
    while(curr){
        insertSorted(&result, INFO(curr));
        curr = NEXT(curr);
    }

    curr = FIRST(l2);
    while(curr){
        insertSorted(&result, INFO(curr));
        curr = NEXT(curr);
    }

    return result;
}

/**
 * @brief Mengeluarkan hasil intersect dari 2 buah list
 * @param l1 adalah list pertama.
 * @param l2 adalah list kedua.
 * I.S. l1 dan l2 terdefinisi, mungkin kosong.
 * F.S. l1 dan l2 tetap, tidak berubah
 * @return list yang merupakan hasil intersect antara list pertama dan kedua
 */
List getIntersect(List l1, List l2){
    List result;
    CreateList(&result);
    Address curr;

    curr = FIRST(l1);
    while(curr){
        Address check = FIRST(l2);
        int found = 0;
        while(check){
            if(INFO(check) == INFO(curr)){
                found = 1;
                break;
            }
            check = NEXT(check);
        }

        if(found){
            insertSorted(&result, INFO(curr));
        }
        curr = NEXT(curr);
    }

    return result;
}
/**
 * @brief Melakukan input untuk mendapatkan n (hari). Kemudian untuk setiap n akan menerima input x (jumlah nimons pada hari itu) dan melakukan input list dengan elemen sebanyak x untuk setiap n. Berikan Union dan Intersect akhir yang disimpan ke dalam variabel "Union" dan "Irisan".
 * @param *Union adalah pointer list Union.
 * @param *Irisan adalah pointer list Irisan.
 * I.S. Union dan Irisan terdefinisi dengan elemen awal kosong.
 * F.S. Union dan Irisan berisi hasil union dan intersect seluruh data yang diinputkan.
 */
void getData(List *Union, List *Irisan){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        List curr;
        CreateList(&curr);

        int x;
        scanf("%d", &x);
        for(int j = 0; j < x; j++){
            int val;
            scanf("%d", &val);
            insertSorted(&curr, val);
        }

        if(i == 0){
            *Union = curr;
            *Irisan = curr;
        }
        else{
            *Union = getUnion(*Union, curr);
            *Irisan = getIntersect(*Irisan, curr);
            dealokasiList(&curr);
        } 
    }
}