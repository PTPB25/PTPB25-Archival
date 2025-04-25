#include "akademinimons.h"

void parseStudentData(char *line, Nimon *nimon){
    Nimon temp;
    char nilaiString[MAX_SCORES * 4];

    char *tokenLine = strtok(line, "|");

    strcpy(temp.nim, tokenLine);

    tokenLine = strtok(NULL, "|");
    strcpy(temp.name, tokenLine);

    tokenLine = strtok(NULL, "|");
    strcpy(nilaiString, tokenLine);

    char *nilai = strtok(nilaiString, ",");
    int i = 0;

    while(nilai){
        temp.scores[i] = atoi(nilai);
        i++;
        nilai = strtok(NULL, ",");
    }
    temp.scoreCount = i;

    *nimon = temp;
}

void calculateStatistics(Nimon *nimon){
    float sum;
    int min, max, i, n, currentScore;
    char *status;
    
    n = (*nimon).scoreCount;

    sum = 0.0;
    max = min = (*nimon).scores[0];
    for(i=0; i < n; i++){
        currentScore = (*nimon).scores[i];

        sum += currentScore;
        if(max < currentScore){
            max = currentScore;
        }
        if(min > currentScore){
            min = currentScore;
        }
    }   
    status = ((sum / n) < PASS_THRESHOLD) ? "FAIL" : "PASS";
    (*nimon).average = sum / n;
    (*nimon).highest = max;
    (*nimon).lowest = min;
    strcpy((*nimon).status, status);
    
}   

void writeStudentResult(Nimon *nimon){
    printf("%s|%s|%.2f|%d|%d|%s\n", (*nimon).nim, (*nimon).name, (*nimon).average, (*nimon).highest, (*nimon).lowest, (*nimon).status);
}

void writeSummary(Nimon *nimons, int nimonCount){
    float avg;
    int pass, fail, i;
    char name[MAX_NAME_LENGTH], nim[MAX_NIM_LENGTH];

    pass = fail = 0;
    avg = -9999;

    for(i=0; i<nimonCount; i++){
        if(!strcmp(nimons[i].status, "PASS")){
            pass++;
        }
        else{
            fail++;
        }

        if(avg < nimons[i].average){
            avg = nimons[i].average;
            strcpy(nim, nimons[i].nim);
            strcpy(name, nimons[i].name);
        }
    }

    printf("%d\n", nimonCount);
    printf("%d %.2f%%\n", pass, 100 * ((float) pass / nimonCount));
    printf("%d %.2f%%\n", fail, 100 * ((float) fail / nimonCount));
    printf("%s|%s|%.2f\n", nim, name, avg);

}

int run(char *inputFileName){
    FILE *f = fopen(inputFileName, "r");
    Nimon nimons[MAX_NIMONS];
    char line[MAX_LINE_LENGTH];
    int i, j;

    i = 0;
    while(fgets(line, MAX_LINE_LENGTH, f)){
        parseStudentData(line, nimons + i);
        i++;
    }

    for(j=0; j<i; j++){
        calculateStatistics(nimons + j);
        writeStudentResult(nimons + j);
    }

    writeSummary(nimons, i);

    fclose(f);
    return 0;
}
