#include <iostream>
#include <random>

#define MAX_COUNT_OF_CARDS 14
#define MAX_COUNT_OF_SUIT 4

std::random_device generator;

char cardsList[MAX_COUNT_OF_CARDS][3] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
short cardPower[MAX_COUNT_OF_CARDS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
char cardSuit[MAX_COUNT_OF_SUIT][11] = {"пики", "трефы", "червы", "бубны"};

struct Player {

    char name[25];
    int balance;
    int bet;
    int power;
};

bool getConfirmation(bool isFirstRun) {

    if (!isFirstRun) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }

    auto key = getchar();

    if (key == 121)
        return true;

    return false;
}

int getRandomValue(int a, int b) {

    std::uniform_int_distribution<int> distribution(a,b);
    return distribution(generator);
}

bool makeBet(Player *player) {

    int bet = 0;
    std::cout << "Сделайте ставку: ";
    std::cin >> bet;

    if (bet < 1 || bet > player->balance)
        return false;

    player->bet = bet;
    player->balance -= bet;
    return true;
}

bool gameStep(Player *player, int *dillerPower, bool *playerTake) {

    if (*playerTake) {

        std::cout << std::endl
                  << "Выдать дополнительную карту?" << std::endl
                  << "Введите \'Y\' для того, чтобы взять дополнительную карту: ";

        if (getConfirmation(false)) {

            int cardIndex = getRandomValue(0, 13);
            int suitCard = getRandomValue(0, 3);

            std::cout << std::endl
                      << "Диллер выдал вам карту: " << cardsList[cardIndex] << " " << cardSuit[suitCard] << std::endl;

            player->power += cardPower[cardIndex];
        } else *playerTake = false;

        std::cout << std::endl;
    }

    if (*dillerPower < 17) {

        int cardIndex = getRandomValue(0, 13);
        *dillerPower += cardPower[cardIndex];

        std::cout << "Диллер взял себе дополнительную карту" << std::endl;
    }

    if (player->power > 21 && *dillerPower > 21) {

        player->balance += player->bet;
        std::cout << std::endl
                  << "Ничья!" << std::endl
                  << "Ваша ставка вернулась. Текущий баланс: " << player->balance << std::endl;
        return false;
    }
    else if (player->power > 21) {

        std::cout << std::endl << "Вы поиграли, у вас перебор: " << player->power << std::endl;
        return false;
    }
    else if (*dillerPower > 21) {

        player->balance += player->bet*2;
        std::cout << std::endl
                  << "Вы выйграли! У диллера перебор: " << *dillerPower << std::endl
                  << "Ваша ставка увеличена в 2 раза. Текущий баланс: " << player->balance << std::endl;
        return false;
    }

    if (*dillerPower > 16 && !(*playerTake)) {

        std::cout << std::endl
        << "Вы с диллером отказались брать карты" << std::endl
        << "Вы набрали " << player->power << " очк(-ов\\-а). Диллер набрал " << *dillerPower << " очк(-ов\\-а)";

        if (player->power == *dillerPower) {

            player->balance += player->bet;
            std::cout << std::endl
                      << "Ничья!" << std::endl
                      << "Ваша вернулась. Текущий баланс: " << player->balance << std::endl;
        }
        else if (player->power > *dillerPower) {

            player->balance += player->bet*2;
            std::cout << std::endl << "Вы выйграли! Текущий баланс: " << player->balance << std::endl;
        }
        else std::cout << std::endl << "Вы поиграли. Текущий баланс: " << player->balance << std::endl;

        return false;
    }

    return true;
}

void startGame(Player *player, bool *active) {

    int dillerPower = 0;
    bool playerTake = true;

    player->bet = 0;
    player->power = 0;

    system("clear");
    std::cout << std::endl << player->name << " ваш баланс: " << player->balance << std::endl;

    while (!makeBet(player));

    std::cout << std::endl << "Диллер раздает карты..." << std::endl;

    int playerCardIndex = getRandomValue(0, 13);
    int dillerCardIndex = getRandomValue(0, 13);
    int suitCard = 0;

    suitCard = getRandomValue(0, 3);
    std::cout << "Вы получили первую карту: " << cardsList[playerCardIndex] << " " << cardSuit[suitCard] << std::endl;

    suitCard = getRandomValue(0, 3);
    std::cout << "Диллер получил первую карту: " << cardsList[dillerCardIndex] << " " << cardSuit[suitCard] << std::endl;

    player->power = cardPower[playerCardIndex];
    dillerPower = cardPower[dillerCardIndex];

    std::cout << std::endl << "Диллер раздает карты..." << std::endl;

    playerCardIndex = getRandomValue(0, 13);
    dillerCardIndex = getRandomValue(0, 13);

    suitCard = getRandomValue(0, 3);
    std::cout << "Вы получили вторую карту: " << cardsList[playerCardIndex] << " " << cardSuit[suitCard] << std::endl;
    std::cout << "Последующие карты диллера скрыты" << std::endl;

    player->power += cardPower[playerCardIndex];
    dillerPower += cardPower[dillerCardIndex];

    if (player->power == 21 && dillerPower == 21) {

        player->balance += player->bet;
        std::cout << std::endl
                  << "Ничья!" << std::endl
                  << "Ваша ставка вернулась. Текущий баланс: " << player->balance << std::endl;
        return;
    }
    else if (player->power == 21) {

        player->balance += player->bet*2;
        std::cout << std::endl
                  << "BlackJack!" << std::endl
                  << "Ваша ставка увеличена в 2 раза. Текущий баланс: " << player->balance << std::endl;
        return;
    }
    else if (dillerPower == 21) {

        std::cout << std::endl << "Вы поиграли, диллер собрал BlackJack!" << std::endl;
        return;
    }
    else if (player->power > 21)
        player->power -= 10;
    else if (dillerPower > 21)
        dillerPower -= 10;

    while (gameStep(player, &dillerPower, &playerTake)) {}

    std::cout << std::endl
              << "Хотите продолжить игру?" << std::endl
              << "Введите \'Y\' для продолжения, \'N\' для выхода: ";

    if (!getConfirmation(false))
        *active = false;
}

int main() {

    system("clear");

    std::cout << std::endl
              << "Добро пожаловать в карточную игру BlackJack!" << std::endl
              << "Хотите узнать об основах игры?" << std::endl
              << "Введите \'Y\' для ознакомления, \'N\' для отмены: ";

    if (getConfirmation(true)) {

        system("clear");
        std::cout << std::endl
                  << "===============================================================" << std::endl << std::endl
                  << "Цель игры заключается в том, чтобы собрать комбинацию карт, " << std::endl
                  << "превосходящую руку дилера, но без перебора. Лучшая рука" << std::endl
                  << "имеет 21 очко. Если сумма очков больше 21 игрок выбывает." << std::endl << std::endl
                  << "Обратите внимание, не нужно всегда набирать 21 очко для того," << std::endl
                  << "чтобы выиграть у дилера. Для этого достаточно иметь руку, " << std::endl
                  << "сумма очков которой, превышает общую сумму очков у дилера." << std::endl << std::endl
                  << "Карты: король, дама и валет приносят 10 очков. Туз считается " << std::endl
                  << "за 11. Если при подсчете сумма очков в вашей руке превышает 21," << std::endl
                  << "то туз считается за 1. Стоимость остальных карт равна их " << std::endl
                  << "числовому значению. Масть карты  отношения к стоимости не имеет." << std::endl << std::endl
                  << "===============================================================" << std::endl;
    }

    Player player;

    std::cout << std::endl << "Введите ваше имя: ";
    std::cin >> player.name;

    player.balance = getRandomValue(230, 310);

    bool active = true;

    while (active)
    {
        if (player.balance == 0) {

            std::cout << std::endl
                      << "К сожалению, вы проиграли все деньги." << std::endl
                      << "Дальнейшая игра невозможна." << std::endl << std::endl;
            return 0;
        }
        startGame(&player, &active);
    }
}