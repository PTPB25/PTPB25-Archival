#include "server.h"

/* Removes all trailing and leading space, tab, and newline from a string (on the left and right of a string) */
void strip(char *s) {
    char *start = s, *end;
    int i;

    while (*start == ' ' || *start == '\r' || *start == '\n' || *start == '\t') start++;

    if (*start == '\0') {
        s[0] = '\0';
        return;
    }

    end = start + strlen(start) - 1;
    while (end > start && (*end == ' ' || *end == '\r' || *end == '\n' || *end == '\t')) end--;

    *(end + 1) = '\0';

    i = 0;
    while (start[i]) {
        s[i] = start[i];
        i++;
    }
    s[i] = '\0';
}

void solution(){
    FILE *in, *out;
    in = fopen("request.txt", "r");
    out = fopen("response.txt", "w");
    int i, j;
    char line[MAX_LINE+5], method[MAX_LINE+5], path[MAX_LINE+5], content_type[MAX_LINE+5], key[MAX_LINE+5], value[MAX_LINE+5];
    char body[MAX_BODY+5];

    fgets(line, MAX_LINE, in);

    i = 0; j = 0;
    while(line[i] != ' '){
        method[j] = line[i];
        i++; j++;
    }
    method[j] = '\0';

    i++; j = 0;
    while(strncmp(line+i, " HTTP/1.1", 9)){
        path[j] = line[i];
        i++; j++;
    }
    path[j] = '\0';

    strcpy(content_type, "N/A");
    while(fgets(line, MAX_LINE, in)){
        if(line[0] == '\n')break;
        if(strlen(line) > 1 && line[0] == '\r' && line[1] == '\n')break;

        i = 0; j = 0;
        while(line[i] != ':'){
            key[j] =  line[i];
            i++; j++;
        }
        key[j] = '\0';

        i++; j = 0;
        while(line[i] != '\n'){
            value[j] = line[i];
            i++; j++;
        }
        value[j] = '\0';

        strip(key);
        strip(value);
        if(!strncmp(key, "Content-Type", 12)){
            strcpy(content_type, value);
        }
    }

    fprintf(out, "HTTP/1.1 200 OK\n");
    fprintf(out, "Content-Type: text/plain\n");
    fprintf(out, "\n");
    fprintf(out, "Method: %s\n", method);
    fprintf(out, "Path: %s\n", path);
    fprintf(out, "Content-Type: %s\n", content_type);

    if(fgets(body, MAX_LINE, in)){
        strip(body);
        fprintf(out, "Body: %s\n", body);
    }

    fclose(in);
    fclose(out);
}
