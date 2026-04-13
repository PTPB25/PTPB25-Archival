#include <stdio.h>

int cekMatang(int x) {
    if (x > 0 && x < 2) return 1;
    else if (x > 2 && x < 6) return 2;
    else if (x > 5) return 3;
}

void printMatang(int x) {
    switch (x) {
    case 1: printf("Tingkat Kematangan Mentah\n"); break;
    case 2: printf("Tingkat Kematangan Matang\n"); break;
    case 3: printf("Tingkat Kematangan Terlalu matang\n"); break;
    default:
        break;
    }
}

void printStat(int tah, int tang, int ter) {
    printf("Laporan Kematangan Pisang\n");
    printf("Mentah: %d\nMatang: %d\nTerlalu matang: %d\n", tah, tang, ter);
}

int main() {
    int N;
    int mentah = 0, matang = 0, terlalu = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int done = 0;
        int inp1, inp2;
        while (!done) {
            // Loop to handle inp1 input
            while (1) {
                int res = scanf("%d", &inp1);
                if (res != 1) {
                    printf("Input tidak valid!\nSilahkan masukkan input yang benar\n");
                    // Clear the buffer manually by scanning until the next newline
                    while (scanf("%c") != '\n'); 
                    continue;
                }

                if (inp1 == 1 || inp1 == 2) break;
                printf("Input tidak valid!\nSilahkan masukkan input yang benar\n");
            }

            if (inp1 == 2) {
                // If inp1 is 2, print stats and skip to next iteration
                printStat(mentah, matang, terlalu);
                i--;
                break;  // Exit loop
            } else {
                // If inp1 is 1, ask for inp2 (banana ripeness value)
                while (1) {
                    int res = scanf("%d", &inp2);
                    if (res != 1) {
                        printf("Input tidak valid! Masukkan nilai kematangan yang benar\n");
                        // Clear the buffer manually by scanning until the next newline
                        while (scanf("%c") != '\n');
                        done
                    }

                    if (inp2 >= 0) break;  // Ensure inp2 is a valid number
                    printf("Input tidak valid! Masukkan nilai kematangan yang benar\n");
                }

                printMatang(cekMatang(inp2));

                // Update counts based on the ripeness level
                switch (cekMatang(inp2)) {
                    case 1: mentah++; break;
                    case 2: matang++; break;
                    case 3: terlalu++; break;
                }
                done = 1; // Exit loop after valid inp1 and inp2
            }
        }
    }

    printf("Program telah selesai\n");
    return 0;
}
