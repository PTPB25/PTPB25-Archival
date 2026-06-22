# UTS IF2130 - Sistem Operasi 2025/2026
### credits to: Fibar & Moreno

### __PROCESS__
1. *Process Control Block* (PCB) brisikan banyak bagian dari informasi yang berhubungan dengan sebuah prosses secara spesifik, salah satunya adalah status proses. Misalkan Proses R adalah tab baru di web browser yang akan memuat sebuah halaman web yang berupa situs berita dengan banyak tulisan, gambar dan iklan. Tentukan transisi status **(status awal - status terkini)** dari proses R untuk urutan eksekusi berikut:
   * Anda menekan tombol Enter setelah mengetik URL di address bar. Program browser membuat Proses R (tab) untuk mulai memuat halaman web.
   * Sistem Operasi (OS) memindahkan proses R ke dalam memori utama dan menempatkannya pada natrean proses yang siap dieksekusi.
   * Proses R mendapatkan alokasi waktu CPU dan mulai menjlanakan instruksi untuk mengirim permintaan ke jaringan (DNS Lookup).
   * Proses R harus menunggu balasan dari server DNS dan kemudian menunggu balasan HTTP dari server web. (Kondisi: Aksi I/O melalui jaringan, sangat lambat)
   * Balasan HTTP (data HTML awal) telah diterima. Proses R mulai menjalankan script.
   * Waktu maksimum yang dialokasikan OS untuk Proses R sudah habis sehingga OS harus beralih ke roses lain.
   * Setelah proses lain selesai, Proses R kembali mendapatkan alokasi waktu CPU, melanjutkan pemuatan halaman web, dan akhirnya selesai memuat semua elemen halaman.

### __CPU SCHEDULING__

2. Enam proses berikut dijadwalkan menggunakan algoritma **Round Robin preemptive dengan prioritas**.
   * Angka prioritas yang lebih rendah menunjukkan proses dengan prioritas yang lebih tinggi.
   * Selain keenam proses tersebut, sistem juga memiliki satu task idle (disebut **P_idle**) yang memiliki prioritas 99 dan tidak mengonsumsi sumber daya CPU. P_idle hanya dijalankan ketika tidak ada proses lain yang siap dijalankan.
   * Panjang satu time quantum = **5 unit waktu**. Jika sebuah proses di-*preempt* oleh proses lain dengan prioritas lebih tinggi, proses yang di-*preempt* akan ditempatkan di akhir antrian *ready-queue*.

    | Proses | Prioritas | Burst Time (unit) | Arrival Time (unit) |
    |:--------:|:-----------:|:--------------------:|:----------------------:|
    | P1     | 12        | 6                  | 0                    |
    | P2     | 9         | 8                  | 4                    |
    | P3     | 9         | 8                  | 9                    |
    | P4     | 11        | 5                  | 12                   |
    | P5     | 2         | 3                  | 15                   |
    | P6     | 3         | 3                  | 18                   |

    a. Gambarkan **Gantt Chart** yang menunjukkan urutan eksekusi proses.

    b. Hitung **TAT** (*turn-around time*) untuk masing-masing proses.

    c. Hitung **WT** (*waiting-time*) untuk masing-masing proses.

    d. Hitung **CPU utilization rate** (tingkat pemanfaatan CPU).

> *Asumsi: abaikan context switch overhead; P_idle hanya berjalan jika ready queue kosong.*

### __SYNCHRONIZATION__
3. Pada suatu sistem perbankan terdapat fungsi utama deposit dan tarik saldo. Saldo awal adalah 1 juta rupiah. Jika pada saat bersamaan Ayah melakukan deposit 500 ribu rupiah di teller dan Kakak menarik uang lewat atm sebesar 200 ribu rupiah di rekening yang sama, hal tersebut bisa mengakibatkan terjadinya *race condition*.

    a. Apa itu *race condition* dan bagaimana solusinya?

    b. Buatlah simulasi singkat bagaimana *race condition* pada kasus diatas

    | Urutan | Operasi yang terjadi | Nilai Saldo |
    |--------|------------------------|-------------|
    |   ...  |                        |             |
    |   ...  |                        |             |
    |   ...  |                        |             |
    |   ...  |                        |             |
    |   ...  |                        |             |
    |   ...  |                        |             |

    c. Buatkan dan jelaskan potongan *pseudocode* cara mencegah terjadinya *race condition* menggunakan **Semaphore**.

### __DEADLOCKS__

4. Jawab pertanyaan-pertanyaan berikut:

    a. Jelaskan 4 syarat terjadinya Deadlock

    b. Keadaan dari sebuah sistem adalah sebagai berikut:

    |        | **Allocation**<br>A B C D | **Max**<br>A B C D | **Available**<br>A B C D |
    |--------|----------------------------|----------------------|----------------------------|
    | P0     | 0 0 1 2                    | 0 0 1 2              | 1 5 2 0                    |
    | P1     | 1 0 0 0                    | 1 7 5 0              |                            |
    | P2     | 1 3 5 4                    | 2 3 5 6              |                            |
    | P3     | 0 6 3 2                    | 0 6 5 2              |                            |
    | P4     | 0 0 1 4                    | 0 6 5 6              |                            |

    Dengan menggunakan algoritma **Bankers**, tunjukkan apakah sistem berada dalam keadaan (*state*) **Safe** atau **tidak**?