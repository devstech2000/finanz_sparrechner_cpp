#include <iostream>

double budgetRechner(double income, double expands){
    return income - expands;
}

double sparRechner(double target, double monthlyRate){
        return target / monthlyRate;
    }


void mainMenu(){
    int inputIncome, inputExpands;
    int inputTarget, inputMonthlyRate;

    int menuChoise;
    std::cout << "Wilkommen beim Finanz & Sparrechner\n" << std::endl;
    std::cout << "Wähle einen Rechner aus:" << std::endl;
    std::cout << "1. Budgetrechner\n" << "2. Sparrechner\n" << "3. Verlassen\n" <<std::endl;
    std::cin >> menuChoise;


    switch (menuChoise) {
        case 1:
            std::cout << "\nBerechne dein Budget" << std::endl;
            std::cout << "Gebe dein Einkommen ein: " << std::endl;
            std::cin >> inputIncome;
            std::cout << "Gebe deine Ausgaben ein: " << std::endl;
            std::cin >> inputExpands;
            std::cout << "Du hast ein Monatliches Budget von: " << budgetRechner(inputIncome, inputExpands) << std::endl;
            //mainMenu();
            break;
        case 2:
            std::cout << "\nBerechne wie lange du Sparen musst" << std::endl;
            std::cout << "Gebe dein Sparziel ein: " << std::endl;
            std::cin >> inputTarget;
            std::cout << "Gebe deine monatliche Sparrate ein: " << std::endl;
            std::cin >> inputMonthlyRate;
            if (inputMonthlyRate <= 0) {
                std::cout << "Deine Sparrate muss mehr als 0€ sein!";
            } else {
            std::cout << "Du benötigst: " << sparRechner(inputTarget, inputMonthlyRate) << " Monate um dein Sparziel zu erreichen." << std::endl;
            }
            break;
        case 3:
            std::cout << "\nBis bald" << std::endl;
    }
}

void secondMenu(){
    int secondMenuChoise;
    int inputIncome, inputExpands;
    int inputTarget, inputMonthlyRate;

    std::cout << "\nMöchtest du ein Sparziel festlegen und errechnen, wie lange du sparen müsstest?" << std::endl;
    std::cout << "1. Ja\n" << "2. Nein, verlassen\n" << std::endl;
    std::cin >> secondMenuChoise;

    switch (secondMenuChoise) {
        case 1:
            std::cout << "Berechne wie lange du Sparen musst" << std::endl;
            std::cout << "Gebe dein Sparziel ein: " << std::endl;
            std::cin >> inputTarget;
            std::cout << "Gebe deine monatliche Sparrate ein: " << std::endl;
            std::cin >> inputMonthlyRate;
            if (inputMonthlyRate <= 0) {
                std::cout << "Deine Sparrate muss mehr als 0€ sein!";
            }else if (inputMonthlyRate >=budgetRechner(inputIncome, inputExpands)) {
                std::cout << "Dein Sparrate ist zu hoch, sie muss in dein Budget passen";
            } else if (inputMonthlyRate < budgetRechner(inputIncome, inputExpands)) {
                std::cout << "Du benötigst: " << sparRechner(inputTarget, inputMonthlyRate) << " Monate um dein Sparziel zu erreichen." << std::endl;
            }
            break;
        case 2:
            std::cout << "\nBis bald" << std::endl;
    }
}

int main() {
    mainMenu();
    secondMenu();
    return 0;
}
