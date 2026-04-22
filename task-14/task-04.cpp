#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    int N, K;
    cout << "Enter number of words: ";
    cin >> N;

    set<string> orderedWords;
    unordered_set<string> unorderedWords;
    string words[1000];
    string checkWords[1000];
    string word;

    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    clock_t startSetInsert = clock();
    for (int i = 0; i < N; i++)
    {
        orderedWords.insert(words[i]);
    }
    clock_t endSetInsert = clock();

    clock_t startUnorderedInsert = clock();
    for (int i = 0; i < N; i++)
    {
        unorderedWords.insert(words[i]);
    }
    clock_t endUnorderedInsert = clock();

    cout << "Enter number of words to check: ";
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> checkWords[i];
    }

    clock_t startSetSearch = clock();
    for (int i = 0; i < K; i++)
    {
        if (orderedWords.find(checkWords[i]) != orderedWords.end())
            cout << checkWords[i] << " found in set\n";
        else
            cout << checkWords[i] << " not found in set\n";
    }
    clock_t endSetSearch = clock();

    clock_t startUnorderedSearch = clock();
    for (int i = 0; i < K; i++)
    {
        if (unorderedWords.find(checkWords[i]) != unorderedWords.end())
            cout << checkWords[i] << " found in unordered_set\n";
        else
            cout << checkWords[i] << " not found in unordered_set\n";
    }
    clock_t endUnorderedSearch = clock();

    double setInsertTime = (double)(endSetInsert - startSetInsert) / CLOCKS_PER_SEC;
    double unorderedInsertTime = (double)(endUnorderedInsert - startUnorderedInsert) / CLOCKS_PER_SEC;
    double setSearchTime = (double)(endSetSearch - startSetSearch) / CLOCKS_PER_SEC;
    double unorderedSearchTime = (double)(endUnorderedSearch - startUnorderedSearch) / CLOCKS_PER_SEC;

    cout << "\nInsertion time in set: " << setInsertTime << " sec\n";
    cout << "Insertion time in unordered_set: " << unorderedInsertTime << " sec\n";
    cout << "Search time in set: " << setSearchTime << " sec\n";
    cout << "Search time in unordered_set: " << unorderedSearchTime << " sec\n";

    if (unorderedInsertTime < setInsertTime)
        cout << "unordered_set works faster for insertion\n";
    else
        cout << "set works faster for insertion\n";

    if (unorderedSearchTime < setSearchTime)
        cout << "unordered_set works faster for search\n";
    else
        cout << "set works faster for search\n";

    return 0;
}