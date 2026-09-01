# UTS IF2240 - Basis Data

> credit to Jenka & Qina 👈(ﾟヮﾟ👈)

---

## Daftar Isi

- [UTS IF2240 - Basis Data](#uts-if2240---basis-data)
  - [Daftar Isi](#daftar-isi)
  - [1. Pengenalan Basis Data](#1-pengenalan-basis-data)
  - [2. Model Data](#2-model-data)
  - [3. Model Relasional](#3-model-relasional)
    - [a.](#a)
    - [b.](#b)
    - [c.](#c)
  - [4. Operasi SQL](#4-operasi-sql)
  - [5. Model Entity-Relationship](#5-model-entity-relationship)
    - [a.](#a-1)
    - [b.](#b-1)

---

## 1. Pengenalan Basis Data

Jelaskan dan bandingkan kegunaan sistem basis data dengan pemrosesan file tradisional berdasarkan:

- Data sharing
- Data quality
- Standarisasi pengaksesan

Berikan masing-masing **satu contohnya**!

---

## 2. Model Data

Terdapat beberapa model data yang digunakan dalam sistem basis data, jelaskan **apa itu model data dan keuntungannya dalam analisis dan desain sistem!**

Sebutkan **tiga model data** selain relasional dan ER, **buatkan sebuah contoh kemudian modelkan** sesuai contoh tersebut!

---

## 3. Model Relasional

Berikut adalah skema basis data relasional yang belum lengkap dari sebuah aplikasi musik:

```
artis       = (IDartis, namaartis, genre)
album       = (IDalbum, namaalbum, IDartis, tanggalrelease)
track       = (IDtrack, judul, durasi, filepath)
user        = (IDuser, namauser, email, password)
playlist    = (IDplaylist, namaplaylist, tanggaldibuat)
FK          : album(IDartis) -> artis(IDartis)
```

Beberapa **aturan** berikut ingin diakomodasi/dicatat dalam skema basis data relasional tersebut.

1. Setiap artis, album, track, user, dan playlist memiliki ID berbeda
2. Setiap track merupakan bagian dari sebuah album
3. Setiap user dapat memiliki lebih dari satu email
4. Sebuah playlist dibuat oleh seorang user
5. Sebuah playlist terdiri dari sejumlah track dan sebuah track dapat masuk ke dalam lebih dari satu playlist

### a.

**Jelaskan detail perubahan** yang harus dilakukan terhadap skema relasional yang diberikan agar aturan atau informasi yang diberikan dapat diakomodasi, dengan menggunakan format tabel berikut. Perubahan dapat berupa (i) mengubah *primary key* dan *foreign key*, (ii) penambahan atribut baru, (iii) pemindahan atribut ke tabel lain, atau (iv) penambahan tabel baru. Di bagian akhir, tuliskan skema basis data yang dihasilkan setelah dilakukan semua perubahan (dalam format teks seperti skema di atas atau dalam bentuk diagram)

| No. Aturan | Keterangan Perubahan Skema | Skema relasi baru |
|:---:|:---:|:---:|
| 1 | | |
| 2 | | |
| 3 | | |
| 4 | | |
| 5 | | |
| 6 | | |

### b.

**Sebutkan dan jelaskan 3 (tiga) jenis integrity constraints** yang dapat didefinisikan pada sebuah baris data relasional. Untuk masing-masing integrity constraint, **berikan contoh** penerapannya pada model data yang telah anda hasilkan pada soal butir a.

### c.

Menurut pendapat anda, aturan apa yang paling tepat digunakan untuk **menghindari pelanggaran constraints** apabila dilakukan operasi berikut (jika ada)? Berikan penjelasan singkat untuk jawaban anda.

1. Memodifikasi nilai IDalbum pada relasi album
2. Menghapus sebuah tuple pada relasi playlist
3. Menghapus sebuah tuple pada relasi artis

---

## 4. Operasi SQL

Berikut adalah skema basis data relasional dari sebuah game online:

```
users               = (id_user, nama_user, saldo, poin, ...)
log_game            = (id_user, no_sesi, ..., waktu_main, ...)
reward              = (kode_barang, nama_reward, jenis_reward, poin_tukar, stok)
penukaran_reward    = (kode_barang, id_user, ..., jumlah_tukar)
```

> *author's note: atribut "..." menandakan bahwa data soal tidak lengkap karena kurang terdokumentasikan*

Tulis SQL sesuai perintah berikut

**a.** Buat tabel loggame, dengan waktu_masuk bertipe TIMESTAMP

**b.** Cari user yang login pada Bulan Mei 2025, dengan nama awalan M dan huruf kedua H

**c.** Buatlah 2 (dua) query berbeda untuk menampilkan id dan nama untuk pemain yang berhasil menukarkan barang bertipe boneka

**d.** Tampilkan kode barang, nama barang dan kuantitas dari kuantitas paling banyak, dengan aturan setidaknya barang tersebut ditukar dengan minimal seluruh pemain menukarnya dengan 1000 poin.

**e.** Hapus tuple penukaran reward dilakukan oleh pemain yang memiliki saldo maksimal 150000 dan kode barang yang ditukar adalah 4 huruf dengan awalan R dan akhiran 9.

---

## 5. Model Entity-Relationship

*FunWithUs* adalah sebuah tempat penyewaan playroom yang menyediakan berbagai ruangan bermain untuk anak dan keluarga. Untuk mendukung operasinya, *FunWithUs* ingin membangun basis data yang mampu mencatat data pelanggan, aktivitas bermain, serta transaksi penyewaan. Setiap pelanggan memiliki nomor anggota yang unik, nama, alamat yang terdiri atas nama jalan, kota, dan negara, serta kontak yang dapat lebih dari satu. Selain itu, setiap pelanggan juga memiliki saldo dan tanggal daftar. Di sini terdapat sejumlah petugas yang menjaga, setiap tugas memiliki nomor petugas yang unik, nama, jabatan, gaji, serta kontak yang dapat lebih dari satu.

Playroom terdiri atas beberapa ruangan. Setiap ruangan memiliki nomor ruang yang berbeda, serta dicatat tema ruangan, kapasitas maksimal, tarif per jam, dan status ruangan. Di dalam setiap ruangan terdapat beberapa permainan dengan nama permainan yang unik dan permainan dengan nama yang sama dapat ditemukan pada ruangan yang berbeda. Untuk setiap permainan dicatat juga durasi standar, jumlah partisipan minimum, dan jumlah partisipan maksimum. Seorang pelanggan dapat melakukan suatu transaksi penyewaan. Setiap transaksi memiliki id transaksi yang unik, tanggal transaksi, metode pembayaran, diskon, dan total biaya. Nilai total biaya diperoleh dari perhitungan biaya penggunaan ruangan berdasarkan tarif per jam dan lama waktu pemakaian. Setiap transaksi dilayani oleh tepat satu petugas, dan seorang petugas dapat melayani banyak transaksi.

Dalam satu transaksi, pelanggan dapat menyewa satu atau lebih ruangan. Untuk setiap ruangan yang digunakan dalam suatu transaksi, dicatat waktu mulai dan waktu selesai pemakaian. Selain itu, setiap transaksi yang dilakukan, dapat ditentukan petugas yang bertanggungjawab untuk mendampingi permainan dalam suatu ruangan (jika diperlukan). Kemudian, pada setiap kegiatan pendampingan tersebut, dicatat juga waktu pendampingannya.

### a.

**Buatlah model *entity-relationship* (E-R)** dalam bentuk E-R diagram untuk basis data tempat penyewaan *FunWithUs*. Gunakan nama-nama yang sesuai dengan deskripsi yang diberikan. Jika ada asumsi yang digunakan, tuliskan asumsi anda secara eksplisit.

### b.

**Tuliskan jawaban anda** untuk pertanyaan-pertanyaan berikut ini:

- Memilih *primary key* untuk *relationship sets* dalam pemodelan E-R akan sangat bergantung pada *cardinality constraints*, misalnya entitas X dan Y memiliki hubungan *many to many*, jelaskan bagaimana *primary key* dari *relationship sets* dipilih berdasarkan hubungan entitas X dan Y tersebut!
- Entitas lemah W memiliki hubungan *many to one* dengan entitas kuatnya, yaitu S. Apakah entitas lemah tersebut wajib memiliki atribut diskriminator? Jelaskan kenapa alasannya!