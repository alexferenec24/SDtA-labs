#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

bool compareActivities(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int choice;
    vector<Activity> activities;

    cout << "1 - Auto data, 2 - Manual input: ";
    cin >> choice;

    if (choice == 1) {
        activities = {
            {1, 1, 4}, {2, 3, 5}, {3, 0, 6},
            {4, 5, 7}, {5, 3, 9}, {6, 5, 9},
            {7, 6, 10}, {8, 8, 11}, {9, 8, 12},
            {10, 2, 14}, {11, 12, 16}
        };
    } else {
        int n;
        cout << "Enter number of activities: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            Activity act;
            act.id = i + 1;
            cout << "Activity " << act.id << " (start finish): ";
            cin >> act.start >> act.finish;
            activities.push_back(act);
        }
    }

    if (activities.empty()) return 0;

    sort(activities.begin(), activities.end(), compareActivities);

    vector<Activity> selected;
    selected.push_back(activities[0]);
    int last_finish = activities[0].finish;

    for (size_t i = 1; i < activities.size(); i++) {
        if (activities[i].start >= last_finish) {
            selected.push_back(activities[i]);
            last_finish = activities[i].finish;
        }
    }

    cout << "Max activities: " << selected.size() << "\n";
    for (const auto& act : selected) {
        cout << act.id << " (" << act.start << "-" << act.finish << ")\n";
    }

    return 0;
}