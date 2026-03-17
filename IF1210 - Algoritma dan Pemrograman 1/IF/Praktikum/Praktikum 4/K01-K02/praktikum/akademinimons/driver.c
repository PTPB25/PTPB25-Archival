#include "akademinimons.h"

/**
 * driver.c
 *
 * Contoh cara pengujian program untuk praktikan
 *
 * NOTE:
 * - Cara compile:
 *   - gcc akademinimons.c driver.c -o akademinimons
 *   - Harus compile driver.c dan juga implementasi akademinimons.c
 * - Cara run:
 *  - Jalankan ./akademinimons
 *  - Masukkan nama/path file input (bisa relative path). Misalnya "input.txt"
 */
int main()
{
  char inputFileName[MAX_IO_LENGTH];

  // Input nama file input
  scanf("%s", inputFileName);

  // Jalankan program
  int result = run(inputFileName);

  return result;
}