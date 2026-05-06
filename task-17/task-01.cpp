#include <iostream>
#include <string>

using namespace std;

struct Product
{
    string name;
    double price;
    int nutrients[3];
    int calories;
};

int calculateCalories(int proteins, int fats, int carbs)
{
    return 4 * proteins + 9 * fats + 4 * carbs;
}

void fillCalories(Product products[], int size)
{
    for (int i = 0; i < size; i++)
    {
        products[i].calories = calculateCalories(
            products[i].nutrients[0],
            products[i].nutrients[1],
            products[i].nutrients[2]
        );
    }
}

void printProducts(Product products[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Name: " << products[i].name << endl;
        cout << "Price: " << products[i].price << endl;
        cout << "Proteins: " << products[i].nutrients[0] << endl;
        cout << "Fats: " << products[i].nutrients[1] << endl;
        cout << "Carbs: " << products[i].nutrients[2] << endl;
        cout << "Calories: " << products[i].calories << endl;
        cout << "------------------------" << endl;
    }
}

void selectionSortByCalories(Product products[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (products[j].calories > products[maxIndex].calories)
            {
                maxIndex = j;
            }
        }

        if (maxIndex != i)
        {
            swap(products[i], products[maxIndex]);
        }
    }
}

void copyArray(Product source[], Product destination[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

void gnomeSortByPrice(Product products[], int size)
{
    int index = 0;

    while (index < size)
    {
        if (index == 0 || products[index].price >= products[index - 1].price)
        {
            index++;
        }
        else
        {
            swap(products[index], products[index - 1]);
            index--;
        }
    }
}

void linearSearchByPrice(Product products[], int size, double targetPrice)
{
    bool found = false;

    cout << "\nSearch results for price " << targetPrice << ":" << endl;

    for (int i = 0; i < size; i++)
    {
        if (products[i].price == targetPrice)
        {
            cout << products[i].name << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No products found." << endl;
    }
}

int main()
{
    const int SIZE = 5;

    Product products[SIZE] =
    {
        {"Apple", 25.5, {1, 0, 14}, 0},
        {"Milk", 40.0, {3, 4, 5}, 0},
        {"Bread", 22.0, {8, 2, 49}, 0},
        {"Cheese", 85.0, {25, 30, 2}, 0},
        {"Chicken", 120.0, {27, 14, 0}, 0}
    };

    Product priceSorted[SIZE];

    fillCalories(products, SIZE);

    cout << "Original array:\n";
    printProducts(products, SIZE);

    selectionSortByCalories(products, SIZE);

    cout << "\nSorted by calories (descending):\n";
    printProducts(products, SIZE);

    copyArray(products, priceSorted, SIZE);
    gnomeSortByPrice(priceSorted, SIZE);

    cout << "\nSorted by price (ascending):\n";
    printProducts(priceSorted, SIZE);

    linearSearchByPrice(products, SIZE, 40.0);

    return 0;
}