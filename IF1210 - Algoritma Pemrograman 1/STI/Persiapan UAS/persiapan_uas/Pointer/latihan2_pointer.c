int *value (void) { //luarannya adalah "pointer to data integer"
    int i = 3; //buat memori lokal, terus kasih value 3
    return &i; //return pointer, yang arahnya ke memori lokal i = 3


} /* dihasilkan pointer to integer yang refer to alamat lokal i*/

void callme (void) {
    int x = 35;
}


int main (void) {
    int *ip;
    ip = value (); 

    /* apa yang terjadi sebenarnya adalah...*/
    /* ketika FUNGSI value dipanggil, memory dialokasikan untuk i*/
    /*ketika FUNGSInya exit, memorynya di-deallocated, tidak tersedia lagi untuk i*/

    printf ("*ip == %d\n", *ip); //ada kemungkinan outputnya adalah 3
    
    callme ();

    /* tapi ketika VOID callme dipanggil, memory yang free tadi bisa direuse untuk function/procedure berikutnya*/
    /* di konteks ini, prosedurnya adalah callme*/
    /*VOID callme tidak ada istilah return/exit*/
    /*jadi, secara tersirat, memory yang digunakan utnuk nilai x tetap sama*/
    /*Akibatnya, nilai yang di-dereference oleh pointer di "alamat memori" yang sama adalah nilai x*/


    printf ("*ip == %d\n", *ip);
}

/*ini contoh code yang buruk*/
/*jangan pernah return local memory address*/
/*biasanya trigger seg fault, print random values, or others*/