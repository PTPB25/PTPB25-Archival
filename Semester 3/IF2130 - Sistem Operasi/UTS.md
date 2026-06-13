# UTS IF2130 - Sistem Operasi 2025/2026
### credits to: Fibar

1. Tentukan status proses **(New, Ready, Running, Waiting, atau Terminated)** yang dialami sebuah proses ketika pengguna membuka web browser hingga antarmuka (UI) sebuah website berhasil ditampilkan.

2. Diberikan tabel penjadwalan proses menggunakan algoritma Priority Round Robin (Preemptive). Hitung:
   * **Waiting Time (WT)**
   * **Turnaround Time (TAT)**
   * **CPU Utilization**

    Jelaskan pengertian Race Condition. Berdasarkan kasus yang diberikan:

1. Jelaskan mengapa kondisi tersebut termasuk race condition. Tuliskan potongan program yang dapat mencegah race condition menggunakan semaphore.

2. Sebutkan dan jelaskan empat syarat terjadinya deadlock.

| Process | Alloc A | Alloc B | Alloc C | Alloc D | Max A | Max B | Max C | Max D |
|----------|-------------|-------------|-------------|-------------|-------|-------|-------|-------|
| P0 | 0 | 0 | 1 | 2 | 0 | 0 | 1 | 2 |
| P1 | 1 | 0 | 0 | 0 | 1 | 7 | 5 | 0 |
| P2 | 1 | 3 | 5 | 4 | 2 | 3 | 5 | 6 |
| P3 | 0 | 6 | 3 | 2 | 0 | 6 | 5 | 2 |
| P4 | 0 | 0 | 1 | 4 | 0 | 6 | 5 | 6 |

Apakah deadlock terjadi pada tabel di atas?