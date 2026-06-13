# UAS OS 2025/2026
### credits to: Acads HMIF

## 1. Dynamic Storage Allocation

Sebuah sistem operasi menggunakan *dynamic storage allocation* untuk mengelola memori utama. Tersedia sejumlah *hole* (ruang kosong) di memori dengan ukuran sebagai berikut (dalam MB):

<p align="center"><b>100, 40, 170, 205, 300, 185</b></p>

Sistem akan menjalankan beberapa proses dengan kebutuhan memori sebagai berikut (dalam MB):

<p align="center"><b>200, 15, 185, 75, 175, 80</b></p>

a. Petakan proses-proses tersebut ke dalam *hole* menggunakan algoritma:

&nbsp;&nbsp;&nbsp;&nbsp;i. First-Fit  
&nbsp;&nbsp;&nbsp;&nbsp;ii. Best-Fit  
&nbsp;&nbsp;&nbsp;&nbsp;iii. Worst-Fit

b. Apakah terdapat proses yang tidak dapat dialokasikan ke dalam *hole* yang tersedia? Jika ada, jelaskan alasan kegagalannya.

c. Berikan komentar singkat mengenai kelebihan dan kekurangan masing-masing algoritma alokasi tersebut berdasarkan hasil pemetaan.


## 2. Disk Scheduling

Sebuah hard disk memiliki rentang silinder 0–99. Diketahui terdapat antrian permintaan akses disk sebagai berikut:

<p align="center"><b>10, 15, 20, 55, 75, 90</b></p>

Posisi awal disk head berada pada silinder 40

a. Tentukan urutan pelayanan request menggunakan algoritma SSTF.

b. Tentukan urutan pelayanan request menggunakan algoritma SCAN.

c. Tentukan urutan pelayanan request menggunakan algoritma C-SCAN.

d. Sebutkan kelebihan dan kekurangan dari masing-masing algoritma.

e. Secara real-time, algoritma mana yang lebih baik antara SCAN dan SSTF? Jelaskan alasan Anda.

## 3. UNIX File Permission

### Grup

- Ga : u1, u3
- Gb : u2, u4
- Gc : u1, u2, u3

### File

* fileA
  - Owner: u1
  - Group: Ga
  - Permission: `rw- r-- ---`

* fileB
  - Owner: u2
  - Group: Gc
  - Permission: `-wx r-x r--`

* fileC
  - Owner: u3
  - Group: Gb
  - Permission: `rwx r-x ---`

a. File apa saja yang dapat ditulis oleh u1, dan siapa saja pengguna yang dapat membaca fileB?

b. Jika group fileB diubah dari Gc menjadi Gb, pengguna mana saja yang mengalami perubahan hak akses? Jelaskan.

c. Jelaskan bagaimana cara menghilangkan seluruh izin execute pada fileC menggunakan mekanisme UNIX file permission.

## 4. Protection and Security

a. Jelaskan perbedaan antara *Access Control List (ACL)* dan *Capability List (CL)*.

b. Diketahui sebuah proses P1 memiliki akses *read* terhadap file F1 dan *write* terhadap file F2. Proses P1 kemudian membuat proses anak P2 yang mewarisi hak akses tersebut. Sebutkan dua metode *revocation* yang dapat digunakan untuk menghapus hak akses P2 terhadap F1.

c. Sebutkan dua mekanisme yang dapat digunakan oleh sistem operasi untuk mencegah proses jahat mengubah *capability list* miliknya sendiri.

d. Sebutkan syarat-syarat utama agar suatu sistem operasi dapat dikatakan *secure*.