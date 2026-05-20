#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class LogisticsOptimizer {
private:
    static const int ROWS = 3;
    static const int COLS = 3;

    vector<vector<int>> costMatrix;
    vector<int> supply;
    vector<int> demand;

public:
    LogisticsOptimizer() {
        costMatrix = {
            {8, 7, 2},
            {1, 4, 3},
            {5, 1, 6}
        };

        supply = {1500, 1900, 1600};
        demand = {1800, 1200, 2000};
    }

    void checkBalance(int& totalSupply, int& totalDemand) {
        totalSupply = 0;
        totalDemand = 0;

        for (int s : supply) totalSupply += s;
        for (int d : demand) totalDemand += d;

        if (totalSupply != totalDemand) {
            cout << "Unbalanced problem!\n";
            cout << "Total supply: " << totalSupply << "\n";
            cout << "Total demand: " << totalDemand << "\n";

            if (totalSupply > totalDemand) {
                cout << "Adding dummy consumer\n";
                demand.push_back(totalSupply - totalDemand);
                costMatrix.push_back(vector<int>(COLS + 1, 0));
                for (int i = 0; i < ROWS; i++) {
                    costMatrix[i].push_back(0);
                }
            } else {
                cout << "Adding dummy supplier\n";
                supply.push_back(totalDemand - totalSupply);
                costMatrix.push_back(vector<int>(COLS, 0));
                for (int j = 0; j < COLS; j++) {
                    costMatrix[ROWS][j] = 0;
                }
            }
        }
    }

    pair<vector<vector<int>>, int> northWestCorner() {
        vector<int> tempSupply = supply;
        vector<int> tempDemand = demand;
        vector<vector<int>> plan(tempSupply.size(), vector<int>(tempDemand.size(), 0));

        int i = 0, j = 0;
        int totalCost = 0;

        while (i < tempSupply.size() && j < tempDemand.size()) {
            int amount = min(tempSupply[i], tempDemand[j]);
            plan[i][j] = amount;
            totalCost += amount * costMatrix[i][j];

            tempSupply[i] -= amount;
            tempDemand[j] -= amount;

            if (tempSupply[i] == 0) i++;
            if (tempDemand[j] == 0) j++;
        }

        return {plan, totalCost};
    }

    pair<vector<vector<int>>, int> minimumCost() {
        vector<int> tempSupply = supply;
        vector<int> tempDemand = demand;
        vector<vector<int>> plan(tempSupply.size(), vector<int>(tempDemand.size(), 0));

        int totalCost = 0;

        while (true) {
            int minCost = INT_MAX;
            int minI = -1, minJ = -1;

            for (int i = 0; i < tempSupply.size(); i++) {
                for (int j = 0; j < tempDemand.size(); j++) {
                    if (tempSupply[i] > 0 && tempDemand[j] > 0 && costMatrix[i][j] < minCost) {
                        minCost = costMatrix[i][j];
                        minI = i;
                        minJ = j;
                    }
                }
            }

            if (minI == -1) break;

            int amount = min(tempSupply[minI], tempDemand[minJ]);
            plan[minI][minJ] = amount;
            totalCost += amount * costMatrix[minI][minJ];

            tempSupply[minI] -= amount;
            tempDemand[minJ] -= amount;
        }

        return {plan, totalCost};
    }

    void printPlan(const vector<vector<int>>& plan, const string& title) {
        cout << "\n" << title << ":\n";

        cout << left << setw(10) << "Warehouses";
        for (int j = 0; j < COLS; j++) {
            cout << setw(12) << ("S" + to_string(j + 1));
        }
        cout << setw(12) << "Supply\n";
        cout << string(55, '-') << "\n";

        for (int i = 0; i < ROWS; i++) {
            cout << left << setw(10) << ("W" + to_string(i + 1));
            for (int j = 0; j < COLS; j++) {
                cout << setw(12) << plan[i][j];
            }
            cout << setw(12) << supply[i] << "\n";
        }

        cout << left << setw(10) << "Demand";
        for (int j = 0; j < COLS; j++) {
            cout << setw(12) << demand[j];
        }
        cout << "\n";
    }

    void printOptimalPlan(const vector<vector<int>>& plan, const string& title) {
        cout << "\n" << title << ":\n";
        cout << left << setw(10) << "|";
        for (int j = 0; j < COLS; j++) {
            cout << setw(8) << ("M" + to_string(j + 1));
        }
        cout << "|\n";
        cout << string(35, '-') << "\n";

        for (int i = 0; i < ROWS; i++) {
            cout << left << setw(10) << ("S" + to_string(i + 1));
            for (int j = 0; j < COLS; j++) {
                cout << setw(8) << plan[i][j];
            }
            cout << "|\n";
        }
        cout << string(35, '-') << "\n";
    }

    void optimizeWithPotentials() {
        auto [plan, cost] = northWestCorner();

        cout << "\n========== LOGISTICS OPTIMIZATION ==========\n";
        printPlan(plan, "Initial Plan (North-West Corner Method)");
        cout << "\nTransportation cost: " << cost << " monetary units\n";

        auto [optimalPlan, optimalCost] = minimumCost();
        printOptimalPlan(optimalPlan, "Optimal Delivery Plan");
        cout << "\nMinimum total delivery cost: "
             << optimalCost << " monetary units\n";
    }

    void run() {
        cout << "\nLABORATORY WORK No. 21\n";
        cout << "TASK 2: Goods Delivery Logistics Optimization\n";

        cout << "\nInitial Data:\n";
        cout << "Transportation cost matrix:\n";
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << setw(5) << costMatrix[i][j];
            }
            cout << " | Supply: " << supply[i] << "\n";
        }
        cout << "Demand: ";
        for (int j = 0; j < COLS; j++) {
            cout << demand[j] << " ";
        }
        cout << "\n";

        optimizeWithPotentials();
    }
};

int main() {
    LogisticsOptimizer optimizer;
    optimizer.run();

    return 0;
}