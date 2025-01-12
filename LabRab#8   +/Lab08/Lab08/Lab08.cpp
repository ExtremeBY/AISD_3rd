#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;


struct Item {
    string name;
    int weight;
    int value;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);



    int W; 
    int N;

    cout << "Введите вместимость рюкзака: ";
    cin >> W;

    cout << "Введите количество предметов: ";
    cin >> N;

    vector<Item> items(N);
    cout << "Введите название, вес и стоимость каждого предмета:\n";
    for (int i = 0; i < N; i++) {
        cin >> items[i].name >> items[i].weight >> items[i].value;
    }


    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Максимальная стоимость: " << dp[N][W] << endl;


    cout << "Предметы в рюкзаке:\n";
    int w = W;
    for (int i = N; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "- " << items[i - 1].name << " (вес: " << items[i - 1].weight << ", стоимость: " << items[i - 1].value << ")\n";
            w -= items[i - 1].weight;
        }
    }

}
