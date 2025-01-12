#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>
#define TRIES 50
#define PRISONERSCOUNT 100

void shuffle(std::vector<int>& boxes) {

    for (int i = boxes.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
       std:: swap(boxes[i], boxes[j]);  
    }
}

bool findOwnNumber(std::vector<int>& boxes) {

    for (int i = 0; i < PRISONERSCOUNT; i++) {
        bool found = false;
        for (int tries = 0, choice = i; tries < TRIES; tries++, choice = boxes[choice]) {
            if (boxes[choice] == i) {
                found = true;
               // std::cout << "Заключенный " << i + 1 << " нашел свой номер\n";
                break;
            }
        }

        if (!found) {
           // std::cout << "Заключенный " << i + 1 << " не нашел свой номер. Всех убили";
            return false;
        }


    }


    return true;

}


bool findRand(const std::vector<int>& boxes) {
    for (int prisoner = 0; prisoner < PRISONERSCOUNT; prisoner++) {
        std::vector<bool> opened(PRISONERSCOUNT, false);
        bool found = false;

        for (int tries = 0; tries < TRIES; tries++) {
            int choice;
            do {
                choice = rand() % PRISONERSCOUNT;
            } while (opened[choice]);

            opened[choice] = true;

            if (boxes[choice] == prisoner) {
                found = true;
                //std::cout << "Заключенный " << prisoner + 1 << " нашел свой номер.\n";
                break;
            }
        }

        if (!found) {
            //std::cout << "Заключенный " << prisoner + 1 << " не нашел свой номер. Всех убили.\n";
            return false;
        }
    }
    return true;
}




int main() {
    setlocale(LC_ALL, "Ru");
    srand(time(NULL));

  
    std::vector<int> boxes(PRISONERSCOUNT);
    for (int i = 0; i < PRISONERSCOUNT; i++) {

        boxes[i] = i;
    }
    shuffle(boxes);

    std::cout << "Введите количество раундов: ";
    int N;
    std::cin >> N;
    int countRand = 0, countBox = 0;

    for(int i = 0; i < N; i++)
    {
        shuffle(boxes);
        if (findOwnNumber(boxes))
            countBox++;
        if (findRand(boxes))
            countRand++;

    }


    std::cout << "Способ с переходом по номеру в коробке: "<<countBox<<" / "<<N<<"\n";

    

    std::cout << "\n\n\nРандомный поиск номера: " << countRand << " / " << N << "\n";
   


}


