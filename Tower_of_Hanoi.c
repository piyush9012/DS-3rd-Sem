#include <stdio.h>
void towers(int num, char from_peg, char to_peg, char aux_peg);
int main()
{
    int num;
    printf("Enter the number of decks\n");
    scanf("%d", &num);
    printf("The seq of moves involved:\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}

void towers(int num, char from_peg, char to_peg, char aux_peg)
{
    if (num == 1)
    {
        printf("Move disc 1 from peg %c to peg %c\n", from_peg, to_peg);
        return;
    }
        towers(num - 1, from_peg, aux_peg, to_peg);
        printf("Move disc %d from peg %c to peg %c\n", num, from_peg, to_peg);
        towers(num - 1, aux_peg, to_peg, from_peg);
}