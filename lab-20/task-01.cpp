#include <iostream>

using namespace std;

int main() {
    int choice;
    double limit_mass = 35.0;
    double limit_vol = 45.0;

    cout << "1 - Auto data, 2 - Manual input: ";
    cin >> choice;

    if (choice == 2) {
        cout << "Enter max mass and max volume: ";
        cin >> limit_mass >> limit_vol;
    }

    double max_cal = 0;
    double best_meat = 0, best_flour = 0, best_milk = 0, best_sugar = 0;

    for (double i = 0; i <= limit_mass; i += 0.5) {
        for (double j = 8 * i; j <= limit_mass; j += 0.5) {
            for (double k = j; k <= limit_mass; k += 0.5) {
                for (double l = 2 * k; l <= limit_mass; l += 0.5) {
                    if (l + k + j + i <= limit_mass && l * 1.0 + k * 1.5 + j * 2.0 + i * 1.0 <= limit_vol) {
                        double current_cal = l * 1500 + k * 5000 + j * 5000 + i * 4000;
                        if (current_cal > max_cal) {
                            max_cal = current_cal;
                            best_meat = l;
                            best_flour = k;
                            best_milk = j;
                            best_sugar = i;
                        }
                    }
                }
            }
        }
    }

    cout << "Meat: " << best_meat << " kg\n";
    cout << "Flour: " << best_flour << " kg\n";
    cout << "Milk: " << best_milk << " kg\n";
    cout << "Sugar: " << best_sugar << " kg\n";
    cout << "Max Calories: " << max_cal << " kcal\n";

    return 0;
}