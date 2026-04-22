#include <iostream>

using namespace std;

enum PaymentType
{
    CASH,
    CARD,
    BANK_TRANSFER
};

union PaymentInfo
{
    char cashDesk[30];
    char cardNumber[30];
    char bankAccount[30];
};

struct Payment
{
    int number;
    PaymentType type;
    PaymentInfo info;
};

int main()
{
    int n;
    cout << "Enter number of payments: ";
    cin >> n;

    Payment payments[100];

    int cashCount = 0, cardCount = 0, bankCount = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Payment " << i + 1 << endl;
        cout << "Number: ";
        cin >> payments[i].number;

        cout << "Type (0-Cash, 1-Card, 2-Bank): ";
        int t;
        cin >> t;
        payments[i].type = (PaymentType)t;

        if (payments[i].type == CASH)
        {
            cout << "Cash_desk: ";
            cin >> payments[i].info.cashDesk;
            cashCount++;
        }
        else if (payments[i].type == CARD)
        {
            cout << "Card_number: ";
            cin >> payments[i].info.cardNumber;
            cardCount++;
        }
        else if (payments[i].type == BANK_TRANSFER)
        {
            cout << "Bank_account: ";
            cin >> payments[i].info.bankAccount;
            bankCount++;
        }
    }

    cout << "Payments:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Number: " << payments[i].number << endl;

        if (payments[i].type == CASH)
        {
            cout << "Cash: " << payments[i].info.cashDesk << endl;
        }
        else if (payments[i].type == CARD)
        {
            cout << "Card: " << payments[i].info.cardNumber << endl;
        }
        else
        {
            cout << "Bank: " << payments[i].info.bankAccount << endl;
        }
    }

    cout << "Cash count: " << cashCount << endl;
    cout << "Card count: " << cardCount << endl;
    cout << "Bank count: " << bankCount << endl;

    return 0;
}