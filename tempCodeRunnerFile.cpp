void displayPanel(int pickedAmount, int currentNumber, int sortedNumbers[], int sortedCount)
{
    cout << "Picked Amount: " << pickedAmount << "\n";
    cout << "Panel:\n";

    int totalNumbersToDisplay = (pickedAmount <= NUMEROS) ? pickedAmount : NUMEROS;

    for (int i = 1; i <= totalNumbersToDisplay; i++)
    {
        bool isCurrent = (i == currentNumber);
        bool isSorted = false;

        if (i <= sortedCount)
        {
            isSorted = (find(sortedNumbers, sortedNumbers + sortedCount, i) != sortedNumbers + sortedCount);
        }

        if (isCurrent)
        {
            cout << blue << setw(5) << i;
        }
        else if (isSorted)
        {
            cout << red << setw(5) << i;
        }
        else
        {
            cout << blue << setw(5) << i;
        }

        if (i % COLUNAS == 0)
        {
            cout << reset << endl;
        }
        else
        {
            cout << "\t";
        }
    }

    if (totalNumbersToDisplay % COLUNAS != 0)
    {
        cout << reset << endl;
    }
}