# UAS IF1221 II - Logika Komputasional 2024/2025

## __BAGIAN I__
### 1
Anda diminta untuk membuat program Prolog untuk menghitung nilai akhir mahasiswa dari tiga penilaian dengan porsi sama. Jika diberikan fakta berikut
```prolog
% Fakta nilai mahasiswa: nilai(Nama, Kuis, UTS, UAS)
nilai(andi, 80, 70, 85).
nilai(budi, 60, 65, 70).
```
1. Buat aturan `rata_rata/2` untuk menghitung rata-rata dari tiga penilaian tersebut.
2. Buat aturan `lulus/1` yang menyatakan bahwa mahasiswa yang memiliki rata-rata lebih dari 75 akan lulus.
3. Apa hasil dari query berikut
```prolog
?- lulus(budi)
```
```prolog
?- rata-rata(andi, N)
```
### 2
Diberikan fakta dan aturan dalam sistem Prolog berikut:
```prolog
pemilik(andi, toko_buku).
pemilik(rina, toko_kue).
pemilik(andi, toko_elektronik).
karyawan(santi, toko_buku).
karyawan(budi, toko_buku).
karyawan(wati, toko_kue).
karyawan(agus, toko_elektronik).
karyawan(mira, toko_elektronik).

bekerja_dengan(Karyawan1, Karyawan2) :-
    karyawan(Karyawan1, Toko),
    karyawan(Karyawan2, Toko).
```
1. Jika diberikan query `bekerja_dengan(Siapa1, Siapa2)`, apa jawaban prolog terhadap Siapa1 dan Siapa2?
2. Coba tambahkan aturan `bekerja_dengan_dimana(Karyawan1, Karyawan2, Toko)` yang hanya menampilkan pasangan karyawan yang benar-benar bekerja bersama orang lain di toko yang sama. Artinya, toko tersebut harus memiliki minimal 2 karyawan.
3. Setelah aturan baru ditambahkan, apa hasil query `bekerja_dengan_dimana(Siapa1, Siapa2, Toko)`?
## __BAGIAN II__
### 1
Terdapat daftar fakta orang tua-anak sebagai berikut:
```prolog
parent(john, mary).
parent(john, tom).
parent(mary, alice).
parent(tom, bob).
parent(alice, kevin).
```
1. Buatlah sebuah aturan `descendant(X, Y)` yang bernilai true jika X adalah keturunan dari Y, baik anak langsung maupun cucu, cicit, dst. Gunakan **rekursi** untuk menyelesaikannya.
### 2
Diberikan sekumpulan fakta dan aturan dalam sebuah program sebagai berikut
```prolog
grade(peter, 85).
grade(lisa, 92).
grade(john, 68).

passed(Student) :- grade(Student, Score), Score >= 70.
passed(Student) :- grade(Student, Score), Score < 70, write('Remedial allowed').
```
1. Berikan hasil dari ketiga query di bawah ini, dan jelaskan secara singkat mengapa hasil tersebut didapatkan:
    ```prolog
    ?- passed(peter).
    ?- passed(john).
    ?- passed(lisa).
    ```
2. Seharusnya mahasiswa yang lolos (passed) adalah yang nilainya >= 70. Perbaiki program di atas dengan menambahkan cut dan/atau fail. Tuliskan ulang program yang sudah diperbaiki dan jelaskan maksud perubahannya.
### 3
Diberikan sekumpulan fakta dan aturan dalam sebuah program sebagai berikut
```prolog
recommend_vacation(Destination, Season) :-
    vacation(Destination,Season, Budget),
    is_popular(Destination),
    !,
    Budget < 1500.

vacation(bali, summer, 1600).
vacation(bali, winter, 1400).
vacation(tokyo, spring, 1300).
vacation(tokyo, summer, 1700).
vacation(paris, autumn, 1400).

is_popular(bali).
is_popular(tokyo).
```
1. Gambarkan pohon eksekusi dari query di bawah ini, dan tuliskan hasilnya. Jelaskan kenapa hasil tersebut muncul.
    ```prolog
    ?- recommend_vacation(bali, Season).
    ```
2. Ubah program agar tetap menggunakan cut namun bisa memberikan hasil yang sesuai untuk bali di musim winter saja.
## __BAGIAN III__
### 1
Buatlah sebuah predikat dalam bahasa Prolog yaitu `rataSyarat` yang menerima masukan sebuah list integer dan sebuah integer A, menghasilkan keluaran hasil rata-rata elemen list yang bilangan ganjil dan habis dibagi A. Diperbolehkan membuat maksimal satu predikat antara. Dilarang menggunakan predikat bawaan Prolog.
### 2
Diketahui kode program prolog berikut. Jawablah pertanyaan berdasarkan program tersebut.
```prolog
pred1([], []).
pred1([X|Xs], [Z|Zs]) :- pred2(x, Xs, Ys, 1, Z), pred1(Ys, Zs).

pred2(X, [], [], 1, X).
pred2(X, [], [], N, [N, X]) :- N > 1.
pred2(X, [Y|Ys], [Y|Ys], 1, X) :- X \= Y.
pred2(X, [Y|Ys], [Y|Ys], N, [N, X]) :- N > 1, X \= Y.
pred2(X, [X|Xs], Ys, K, T) :- K1 is K+1, pred2(X, Xs, Ys, K1, T).
```
1. Apa hasil query berikut,
   1. `pred1([e, e, f, g, g, g, e, f, f, h], X).`
   2. `pred1([e, f, g, h], X).`
2. Apa predikat yang direpresentasikan oleh pred1 dan pred2?
3. Jika hasil pred1 ingin diubah agar tidak menampilkan frekuensinya, bagaimana hasil perubahan program di atas
### 3
Diberikan 2 file yang berupa file teks dan file program Prolog sebagai berikut.

> File: data user.txt 
> *(Keterangan: user(nama_user, kota, jumlah_follower); friend(nama1, nama2))*
```prolog
user(asri, bandung, 3600).
user(buddy, jakarta, 3200).
user(citra, bandung, 5000).
user(dina, bogor, 100).
user(elo, bandung, 120).
user(fajar, jakarta, 2300).
user(gia, bogor, 700).

friend(asri, citra).
friend(asri, elo).
friend(citra, dina).
friend(buddy, fajar).
friend(gia, dina).
friend(fajar, asri).
```

> File: main.pl
```prolog
% Memuat data eksternal
start :-
    consult('data_user.txt'),
    write('Data berhasil dimuat!'), nl.

p1(X, Y) :-
    friend(X, Y),
    user(X, Kota, _),
    user(Y, Kota, _).

p2(X, Y) :-
    friend(X, Y),
    user(Y, _, Follower),
    Follower > 3000.

p3(X, Y) :-
    friend(X, Y);
    (friend(X, Z), friend(Z, Y), X \= Y, Y \= Z, X \= Z).

p4(Kota, RataRata) :-
    findall(Follower, user(_, Kota, Follower) FList),
    sumlist(FList, Total),
    length(FList, Count),
    Count > 0,
    RataRata is Total / Count.

p5(Kota, Nama) :-
    p4(Kota, Avg),
    user(Nama, Kota, Follower),
    Follower < Avg.
```

1. Buatlah query: Siapa saja yang memiliki teman yang follower-nya lebih dari 3000? Bagaimana hasil query tsb.
2. Buatlah query yang menampilkan semua pasangan teman yang berasal dari kota yang sama. Bagaimana hasil query tsb.
3. Apa hasil query berikut dan tulisan alasannya.
   `p3(asri, giya).`
4. Apa hasil query berikut dan tuliskan alasannya.
   `p5(bandung, Nama).`