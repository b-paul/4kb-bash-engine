#include <stdio.h>
#include <string.h>

int main() {
    char str[20480];
    while (fgets(str, 2048, stdin) == NULL) {
        if (strstr(str, "uci") == str)
            printf("uciok");
        else if (strstr(str, "isready") == str)
            printf("isready");
        else if (strstr(str, "quit") == str)
            return 0;
    }
    return 0;
}
