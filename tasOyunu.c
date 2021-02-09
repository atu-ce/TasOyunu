#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player1[2][20], player2[2][20];
int game(int, int, int, int);
int game_over(int, int, int);

void beginning()
{
    int color, number;

    for (color = 0; color < 2; color++)
    {
        for (number = 0; number < 20; number++)
        {
            player1[color][number] = 1;
            player2[color][number] = 1;
        }
    }
    return;
}

void table()
{
    int which_player = 1;

    while (which_player <= 2)
    {
        int i, j, k, l, counter = 0, stone_value = 1;
        printf("\n --> %d. oyuncunun tablosu\n", which_player);
        for (i = 0; i < 3; i++)
        {
            printf("|");
            for (j = 0; j <= 20; j++)
            {
                if (j == 0)
                    printf("---------|");
                else
                    printf("----|");
            }
            printf("\n");
            printf("|");
            for (k = 0; k <= 20; k++)
            {
                if (k == 0)
                {
                    if (counter == 0)
                    {
                        printf("         |");
                        counter++;
                    }
                    else if (counter == 1)
                    {
                        printf(" Mavi    |");
                        counter++;
                    }
                    else if (counter == 2)
                    {
                        printf(" Kirmizi |");
                    }
                }
                else
                {
                    if (stone_value < 10)
                    {
                        printf("  %d |", stone_value);
                        stone_value++;
                    }
                    else if (stone_value <= 20)
                    {
                        printf(" %d |", stone_value);
                        stone_value++;
                    }
                    else
                    {
                        if (which_player == 1)
                            printf("  %d |", player1[i - 1][k - 1]);
                        else
                            printf("  %d |", player2[i - 1][k - 1]);
                    }
                }
            }
            printf("\n");
        }
        printf("|");
        for (l = 0; l <= 20; l++)
        {
            if (l == 0)
                printf("---------|");
            else
                printf("----|");
        }
        printf("\n");
        which_player++;
    }
    printf("\n");
    return;
}

int change_color(int color)
{
    if (color == 0)
        return 1;
    return 0;
}

int is_game_over = 0;
int other_possibility = 0;
int next_player, next_color, next_number;

int set_moves_to_play(int color, int two_times_number, int four_missing_number, int possibility)
{
    if (possibility == 2)
    {
        int random_selection_stone = rand() % 2;
        if (random_selection_stone == 0)
        {
            next_color = color;
            next_number = two_times_number;

            other_possibility = four_missing_number;
        }
        else
        {
            next_color = change_color(color);
            next_number = four_missing_number;

            other_possibility = two_times_number;
        }
    }
    else if (possibility == 1)
    {
        next_color = color;
        next_number = two_times_number;

        other_possibility = four_missing_number;
    }
    else if (possibility == 0)
    {
        next_color = change_color(color);
        next_number = four_missing_number;

        other_possibility = two_times_number;
    }
    return 0;
}

int game_control(int player_control, int color_control, int number_control)
{
    int two_times_number = (number_control + 1) * 2 - 1;
    int four_missing_number = number_control - 4;

    if (player_control == 1)
        next_player = 2;
    else
        next_player = 1;

    if ((two_times_number >= 0 && two_times_number < 20) && (four_missing_number >= 0 && four_missing_number < 20))
    {
        if (next_player == 1)
        {
            if ((player1[color_control][two_times_number] == 1 || player1[color_control][two_times_number] == 2) &&
                (player1[!color_control][four_missing_number] == 1 || player1[!color_control][four_missing_number] == 2))
            {
                set_moves_to_play(color_control, two_times_number, four_missing_number, 2);
            }
            else if (player1[color_control][two_times_number] == 1 || player1[color_control][two_times_number] == 2)
            {
                set_moves_to_play(color_control, two_times_number, four_missing_number, 1);
            }
            else if (player1[!color_control][four_missing_number] == 1 || player1[!color_control][four_missing_number] == 2)
            {
                set_moves_to_play(color_control, two_times_number, four_missing_number, 0);
            }
            else
            {
                is_game_over = 1;
                game_over(next_player, two_times_number, four_missing_number);
            }
        }
        else
        {
            if ((player2[color_control][two_times_number] == 1 || player2[color_control][two_times_number] == 2) &&
                (player2[!color_control][four_missing_number] == 1 || player2[!color_control][four_missing_number] == 2))
            {
                set_moves_to_play(color_control, two_times_number, four_missing_number, 2);
            }
            else if (player2[color_control][two_times_number] == 1 || player2[color_control][two_times_number] == 2)
            {
                set_moves_to_play(color_control, two_times_number, four_missing_number, 1);
            }
            else if (player2[!color_control][four_missing_number] == 1 || player2[!color_control][four_missing_number] == 2)
            {
                set_moves_to_play(color_control, two_times_number, four_missing_number, 0);
            }
            else
            {
                is_game_over = 1;
                game_over(next_player, two_times_number, four_missing_number);
            }
        }
    }
    else if (two_times_number >= 0 && two_times_number < 20)
    {
        if (next_player == 1)
        {
            if (player1[color_control][two_times_number] == 1 || player1[color_control][two_times_number] == 2)
            {
                set_moves_to_play(color_control, two_times_number, four_missing_number, 1);
            }
            else
            {
                is_game_over = 1;
                game_over(next_player, two_times_number, four_missing_number);
            }
        }
        else
        {
            if (player2[color_control][two_times_number] == 1 || player2[color_control][two_times_number] == 2)
            {
                set_moves_to_play(color_control, two_times_number, four_missing_number, 1);
            }
            else
            {
                is_game_over = 1;
                game_over(next_player, two_times_number, four_missing_number);
            }
        }
    }
    else
    {
        if (next_player == 1)
        {
            if (player1[!color_control][four_missing_number] == 1 || player1[!color_control][four_missing_number] == 2)
            {
                set_moves_to_play(color_control, two_times_number, four_missing_number, 0);
            }
            else
            {
                is_game_over = 1;
                game_over(next_player, two_times_number, four_missing_number);
            }
        }
        else
        {
            if (player2[!color_control][four_missing_number] == 1 || player2[!color_control][four_missing_number] == 2)
            {
                set_moves_to_play(color_control, two_times_number, four_missing_number, 0);
            }
            else
            {
                is_game_over = 1;
                game_over(next_player, two_times_number, four_missing_number);
            }
        }
    }
    game(next_player, next_color, next_number, is_game_over);
    return 0;
}

int move = 0;

int game(int coming_player, int coming_color, int coming_number, int is_game_over)
{
    if (is_game_over == 1)
    {
        return 0;
    }
    move++;
    printf("\n---> %d. Hamle:\n", move);

    if (move == 1)
    {
        printf("\t> Rastgele secilen oyuncu: %d. oyuncu\n", coming_player);
        if (coming_color == 0)
        {
            printf("\t> Rastgele secilen tas (1-10 arasinda): Mavi %d\n", coming_number + 1);
        }
        else
        {
            printf("\t> Rastgele secilen tas (1-10 arasinda): Kirmizi %d\n", coming_number + 1);
        }
    }
    else
    {
        printf("\t> Siradaki oyuncu: %d. oyuncu\n", coming_player);
        if (coming_color == 0)
        {
            if (other_possibility >= 0 && other_possibility < 20)
            {
                printf("\t> Oynayabilecegi taslar: Mavi %d, Kirmizi %d\n", coming_number + 1, other_possibility + 1);
                printf("\t > Oynadigi tas: Mavi %d\n", coming_number + 1);
            }
            else
            {
                printf("\t> Oynayabilecegi taslar: Mavi %d (Kirmizi %d ise oyundaki taslar arasinda bulunmamaktatir.)\n", coming_number + 1, other_possibility + 1);
                printf("\t > Oynadigi tas: Secme hakki yok (Mavi %d)\n", coming_number + 1);
            }
        }
        else
        {
            if (other_possibility >= 0 && other_possibility < 20)
            {
                printf("\t> Oynayabilecegi taslar: Mavi %d, Kirmizi %d\n", other_possibility + 1, coming_number + 1);
                printf("\t > Oynadigi tas: Kirmizi %d\n", coming_number + 1);
            }
            else
            {
                printf("\t> Oynayabilecegi taslar: Kirmizi %d (Mavi %d ise oyundaki taslar arasinda bulunmamaktatir.)\n", coming_number + 1, other_possibility + 1);
                printf("\t > Oynadigi tas: Secme hakki yok (Kirmizi %d)\n", coming_number + 1);
            }
        }
    }
    int color, number;
    for (color = 0; color < 2; color++)
    {
        for (number = 0; number < 20; number++)
        {
            if (coming_player == 1 && coming_color == color && coming_number == number)
            {
                player1[color][number]--;
                player2[color][number]++;
            }
            else if (coming_player == 2 && coming_color == color && coming_number == number)
            {
                player1[color][number]++;
                player2[color][number]--;
            }
        }
    }
    table();
    game_control(coming_player, coming_color, coming_number);
    return 0;
}

void random_selection()
{
    int selection_player = (rand() % 2) + 1;
    int selection_color = rand() % 2;
    int selection_number = rand() % 10;
    game(selection_player, selection_color, selection_number, 0);
    return;
}

int game_over(int losing_player, int two_times_number, int four_missing_number)
{
    printf("\n\t\t\t\t\t\t-----> Oyun Bitti <-----\n");
    printf("\n---> Toplam oynanan hamle: %d\n", move);
    printf("\t> Kaybeden oyuncu: %d. oyuncu\n", losing_player);

    if ((two_times_number >= 0 && two_times_number < 20) && (four_missing_number >= 0 && four_missing_number < 20))
    {
        printf("\t> Kaybetme nedeni:\n\t > Elinde ayni renk, %d numarali tas veya farkli renk, %d numarali tasin olmamasidir.\n", two_times_number + 1, four_missing_number + 1);
    }
    else if (two_times_number >= 0 && two_times_number < 20)
    {
        printf("\t> Kaybetme nedeni:\n\t > Elinde ayni renk, %d numarali tasin olmamasidir.\n\t > (Farkli renk, %d numarali tas ise oyundaki taslar arasinda bulunmamaktatir.)\n", two_times_number + 1, four_missing_number + 1);
    }
    else
    {
        printf("\t> Kaybetme nedeni:\n\t > Elinde farkli renk, %d numarali tasin olmamasidir.\n\t > (Ayni renk, %d numarali tas ise oyundaki taslar arasinda bulunmamaktatir.)\n", four_missing_number + 1, two_times_number + 1);
    }
    return 0;
}

int main()
{
    srand(time(0));

    printf("\n\t\t\t\t\t---------------> TAS OYUNU <---------------\n");

    beginning();
    printf("\n---> Baslangic:\n");
    table();

    printf("\n\t\t\t\t\t\t-----> Oyun Basladi <-----\n");

    random_selection();
    printf("\n");
    return 0;
}
