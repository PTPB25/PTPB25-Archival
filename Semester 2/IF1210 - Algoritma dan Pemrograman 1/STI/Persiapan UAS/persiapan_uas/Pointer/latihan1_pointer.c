int f(void){
    /*declaration*/
    int s = 1;
    int t = 1;

    Fase pertama : s = 1, t = 1
    /*referencing process*/

    int *ps = &s;

    ps : pointer to integer
    ps <- s

    int **pps = &ps; /*pointer to pointer, ps has the type "pointer of integer*/

    /*jadi kalau ngepoint ke pointer, simbol starnya dua kali supaya ekuivalen*/
    
    int *pt = &t;
    /*pointer refers to alamat int t*/

    **pps =2 ;

    karena pps nunjuk ke ps, dan ps nunjuk ke alamat memori s, artinya apapun yang ditunjuk dari pps itu harus angka 2
    Fase kedua : s = 2, t = 1

    /* ini artinya nilai yang diderefence untuk pointer ps adalah 2*/
    /* ini juga ekuivalen dengan mengganti nilai (info) s menjadi 2*/

    pt = ps;
    /* alamat yang diacu pointer pt adalah alamat yang diacu ps*/
    
    *pt = 3;
    Fase ketiga, s = 3, t = 1
    /* artinya karena dereferencing value dari pt adalah 3, dan pt menunjuk ke alamat yang sama dengan ps, artinya s akan punya nilai baru, yakni 3*/

    t = s;
    Fase keempat : s = 3, t = 3s
    /*nilai t adalah salinan nilai dari s, yakni 3*/
}