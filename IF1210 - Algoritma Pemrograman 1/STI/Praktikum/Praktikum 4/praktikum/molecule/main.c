#include "molecule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  Molecule molecules[n];
  for (int i = 0; i < n; ++i) {
      createMolecule(&molecules[i]);
  }

  char command[30];
  int idx1, idx2, idx_res, count;
  char symbol[MAX_SYMBOL_LEN];

  while(1)
  {
    scanf("%s", command);
    if(strcmp(command, "END")==0)
      break;
    if(strcmp(command, "ADD")==0)
    {
      scanf("%d %s %d", &idx1, symbol, &count);
      addAtom(&molecules[idx1], symbol, count);
    }
    else if(strcmp(command, "PRINT")==0){
      scanf("%d", &idx1);
      printMoleculeFormula(&molecules[idx1]);
    }
    else if(strcmp(command, "WEIGHT")==0){
      scanf("%d", &idx1);
      printf("%.3f\n", calculateMolecularWeight(&molecules[idx1]));
    }
    else if(strcmp(command, "GET_COUNT")==0){
      scanf("%d %s", &idx1, symbol);
      printf("%d\n", getAtomCount(&molecules[idx1], symbol));
    }
    else if(strcmp(command, "ARE_EQUAL")==0){
      scanf("%d %d", &idx1, &idx2);
      if(areEqual(&molecules[idx1], &molecules[idx2]))
        printf("Ya\n");
      else
        printf("Tidak\n");
    }
    else if(strcmp(command, "COMBINE")==0){
      scanf("%d %d %d", &idx_res, &idx1, &idx2);
      molecules[idx_res] = combineMolecules(&molecules[idx1], &molecules[idx2]);
    }
    else if(strcmp(command, "CAN_SUBTRACT")==0){
      scanf("%d %d", &idx1, &idx2);
      if(canSubtract(&molecules[idx1], &molecules[idx2]))
        printf("Ya\n");
      else
        printf("Tidak\n");
    }
    else if(strcmp(command, "SUBTRACT")==0){
      scanf("%d %d %d", &idx_res, &idx1, &idx2);
      molecules[idx_res] = subtractMolecule(&molecules[idx1], &molecules[idx2]);
    }
  }

  return 0;
}