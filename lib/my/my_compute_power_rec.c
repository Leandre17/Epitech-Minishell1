/*
** EPITECH PROJECT, 2021
** power_rec
** File description:
** return nb to the p power
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return (1);
    } else if (p < 0 || nb < 0) {
        return (0);
    } else {
        if (nb <= 2147483647) {
            return (nb * my_compute_power_rec(nb, p - 1));
        } else {
            return (0);
        }
    }
}
