#include <stdio.h>
#include <string.h>

enum {
    NO_PIECE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};

char board[128],
     startBoard[] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
#ifdef DEV
     pieceChars[] = " PNBRQK  pnbrqk"
#endif
     ;

int main() {
    char str[2048];
    while (fgets(str, 2048, stdin) != NULL) {
        if (strstr(str, "uci") == str)
            printf("uciok\n");
        else if (strstr(str, "isready") == str)
            printf("isready\n");
        else if (strstr(str, "position") == str) {
            // Set the board so the starting position
            for (int i = 0; i < 8; i++) {
                // Set the piece row behind the pawns
                // +40 indicates it is a white piece in its
                // original position and +48 is the same for black
                board[i] = (board[i+112] = startBoard[i]+40)+8;

                // Set the pawns, 17 indicating a black pawn
                // and 9 indicating a white pawn
                board[i+16] = 17;
                board[i+96] = 9;
            }
            char *ptr = str;
            ptr += 24;
            // Parse moves here
        }
#ifdef DEV
        else if (strstr(str, "print") == str) {
            for (int i = 0; i < 121; i++)
                printf("%c", 
                        // If i&8 basically means if i is at
                        // the end of the current row on the board
                        i&8
                        // If this is the case, then increment 
                        // i by 7 to move it up to the next row
                        &&(i+=7)
                        // 10 is the character for a new line
                        ?10:
                        // Else print the character of the piece
                        // at square i
                        pieceChars[board[i]&15]);
        }
#endif
        else if (strstr(str, "quit") == str)
            return 0;
    }
    return 0;
}
