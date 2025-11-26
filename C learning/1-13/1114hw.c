#include <stdio.h>
#include <string.h>
#include <ctype.h>

char caesar(char c, int offset) {
    return (c >= 'a' && c <= 'z') ? (char)((c - 'a' - offset + 26) % 26 + 'a') :
           (c >= 'A' && c <= 'Z') ? (char)((c - 'A' - offset + 26) % 26 + 'A') :
           c;
}

int main(void) {
    char line[1000];
    if (!fgets(line, sizeof(line), stdin)) return 0; 

    size_t len = strlen(line);
    (len > 0 && line[len-1] == '\n') ? (line[--len] = '\0') : (0);

    while (len > 0 && isspace((unsigned char)line[len-1])) { line[--len] = '\0'; }

    ssize_t last_space = -1;
    for (ssize_t i = (ssize_t)len - 1; i >= 0; --i) {
        if (isspace((unsigned char)line[i])) { last_space = i; break; }
    }

    int offset = 0;
    last_space >= 0
        ? (sscanf(line + last_space + 1, "%d", &offset) == 1
            ? ( (line[last_space] = '\0'), 0 )
            : ( (offset = 0), 0 )
          )
        : ( (offset = 0), 0 );

    for (size_t i = 0; line[i]; ++i) line[i] = caesar(line[i], offset);
    printf("%s\n", line);
    return 0;
}
