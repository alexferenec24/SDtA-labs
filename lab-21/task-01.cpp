#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

struct Position {
    string name;
    int A;
    int B;
    int count;
    double coefficient;
    double salary;
    double totalSalary;
};

class HospitalSalaryOptimizer {
private:
    vector<Position> positions;
    const double TARGET_FUND = 380000.0;
    const double MAX_DEVIATION = 0.01;

public:
    HospitalSalaryOptimizer() {
        positions = {
            {"Nurse", 1, 1, 7, 0, 0, 0},
            {"Registered Nurse", 6, 5, 10, 0, 0, 0},
            {"Doctor", 8, 5, 10, 0, 0, 0},
            {"Pharmacy Head", 9, 5, 1, 0, 0, 0},
            {"Department Head", 2, 1, 3, 0, 0, 0},
            {"Chief Doctor", 12, 5, 1, 0, 0, 0},
            {"Facility Manager", 13, 5, 1, 0, 0, 0},
            {"Hospital Director", 3, 1, 1, 0, 0, 0}
        };

        for (auto& pos : positions) {
            pos.coefficient = static_cast<double>(pos.A) / pos.B;
        }
    }

    double calculateTotalFund(double baseSalary) {
        double total = 0.0;
        for (auto& pos : positions) {
            double salary = baseSalary * pos.coefficient;
            total += salary * pos.count;
        }
        return total;
    }

    void optimizeSalaries() {
        double left = 0.0;
        double right = TARGET_FUND / positions[0].count;
        double bestBaseSalary = 0.0;
        double bestFund = 0.0;

        for (int iteration = 0; iteration < 100; iteration++) {
            double mid = (left + right) / 2;
            double currentFund = calculateTotalFund(mid);

            if (currentFund <= TARGET_FUND) {
                bestBaseSalary = mid;
                bestFund = currentFund;
                left = mid;
            } else {
                right = mid;
            }
        }

        for (auto& pos : positions) {
            pos.salary = bestBaseSalary * pos.coefficient;
            pos.totalSalary = pos.salary * pos.count;
        }

        printResults(bestBaseSalary, bestFund);
    }

    void printResults(double baseSalary, double actualFund) {
        cout << "\n========== HOSPITAL SALARY CALCULATION RESULTS ==========\n\n";
        cout << "Target salary fund: " << fixed << setprecision(0)
             << TARGET_FUND << " UAH\n";
        cout << "Actual salary fund: " << fixed << setprecision(0)
             << actualFund << " UAH\n";
        cout << "Deviation: " << fixed << setprecision(2)
             << ((actualFund - TARGET_FUND) / TARGET_FUND * 100) << "%\n\n";

        cout << "Base nurse salary: " << fixed << setprecision(2)
             << baseSalary << " UAH\n\n";

        cout << left << setw(22) << "Position"
             << setw(14) << "Coefficient"
             << setw(12) << "Count"
             << setw(18) << "Salary"
             << "Total Salary\n";
        cout << string(75, '-') << "\n";

        for (const auto& pos : positions) {
            cout << left << setw(22) << pos.name
                 << setw(14) << fixed << setprecision(2) << pos.coefficient
                 << setw(12) << pos.count
                 << setw(18) << fixed << setprecision(2) << pos.salary
                 << fixed << setprecision(2) << pos.totalSalary << "\n";
        }

        cout << string(75, '-') << "\n";
        cout << left << setw(48) << "TOTAL:"
             << fixed << setprecision(2) << actualFund << " UAH\n";
    }
};

int main() {
    cout << "LABORATORY WORK No. 21\n";
    cout << "TASK 1: Hospital Staff Salary Calculation\n";

    HospitalSalaryOptimizer optimizer;
    optimizer.optimizeSalaries();

    return 0;
}