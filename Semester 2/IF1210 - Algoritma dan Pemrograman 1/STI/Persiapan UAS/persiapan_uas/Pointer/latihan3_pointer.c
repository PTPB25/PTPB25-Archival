

int main() {
    char blocks[3] = {'I','T','B'}; // asumsi,alamat array blok adalah 4434
    char *ptr = &blocks[0]; //refer ke elemen indeks ke-0 dari blocks

    char temp;
    temp = blocks[0]; //temp merupakan salinan dari elemen indeks ke-0 dari blocks

    temp = *(blocks + 2); //nilai temp sekarang adalah hasil dereferencing ke blocks, tepatnya elemen indeks ke-2

    temp = *(ptr + 1); //dereference dulu, baru tambah 1
    //harusnya "T"
    
    temp = *ptr; //kembali lagi nilai temp adalah "I"
    
    ptr = blocks + 1; //alamat dari head arraynnya, ditambah satu. Maka pointer sama saja menunjuk ke elemen ke-1
    //Berarti, ptr nunjuk ke huruf T

    temp = *ptr; //oleh karena itu, nilai dereferencenya adalah "T"

    temp = *(ptr + 1); //nilai dereferencenya sekarang adalah "B"

    ptr = blocks; //alamat dari pointer ptr adalah alamat head dari blocks

    temp = *++ptr; //alamat dari pointer bertambah satu (increment dulu), terus didereference, alhasil nilai tempnya sekarang T

    temp = ++*ptr; //nah, sebelumnya berarti ptr sudah menunjuk ke T. Karena di-increment, nilai temp adalah U


    temp = *ptr++; //dereference dulu, berarti nilai temp adalah B, nah terus alamat ptr di-increment, luarannya huruf B
    temp = *ptr; //akibat dari code line sebelumnya, nilai yang didereferece sekarang adalah B
    return 0;
}

