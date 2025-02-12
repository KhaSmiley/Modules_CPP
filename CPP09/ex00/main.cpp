
// Format dans fichier csv -> YYYY-MM-DD,Value = 2021-09-21,42901.56



// Format dans infile date | value = 2011-01-03 | 3
// Ouvrir le fichier, check les droits, lire tout le fichier et check les dates + valeurs
// Parsing -> Format Date = 0YYYY4-MM-DD YYYY = 0-2025, 0-12, 0-31
// Valeur entre 0 - 1000 : Flotant ou int
// Trouver dans fichier infile le nombre de btc et trouver la valeur avec la date la plus proche
// Afficher Date => Nbr de btc = Valeur a la date

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        BitcoinExchange Exchanger;
        try
        {

            Exchanger.parse_file(av[1]);
            if (Exchanger.stock_data())
                return 1;
            Exchanger.makeitwork();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what();
        }
    }
}