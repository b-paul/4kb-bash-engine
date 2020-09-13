#include <stdio.h>
#include <string.h>

enum {
    NO_PIECE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};

char board[128],
     str[2048],
     representation[] = {
         -16, -15, 17, 0,
         16, 15, 17, 0,
         1, -1, 16, -16, 0,
         1, -1, 16, -16, 15, -15, 17, -17, 0,
         14, -14, 18, -18, 31, -31, 33, -33, 0,
         -1, 3, 21, 12, 16, 7, 12,
         ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
#ifdef DEV
     ,pieceChars[] = " PNBRQK  pnbrqk"
#endif
     ;

int i,
    eighthRank = 0x70;

int main() {
    while (fgets(str, 2048, stdin) != NULL) {
        if (strstr(str, "uci") == str)
            printf("uciok\n");
        else if (strstr(str, "isready") == str)
            printf("readyok\n");
        else if (strstr(str, "position") == str) {
            // Set the board so the starting position
            for (i = 0; i < 8; i++) {
                // Set the piece row behind the pawns
                // +40 indicates it is a white piece in its
                // original position and +48 is the same for black
                board[i] = (board[i+eighthRank] = representation[i]+40)+8;

                // Set the pawns, 17 indicating a black pawn
                // and 9 indicating a white pawn
                board[i+16] = 17;
                board[i+96] = 9;
            }
        }
#ifdef DEV
        else if (strstr(str, "print") == str) {
            for (i = 0; i < 121; i++)
                printf("%c", 
                        // If i&8 basically means if i is at
                        // the end of the current row on the board
                        i&8
                        // If this is the case, then increment 
                        // i by 7 to move it up to the next row
                        &&i+=7
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
