#include <fstream>
#include <iostream>
#include <string>

#include "Arrays.h"

int main()
{
    std::string stringInput;
    int numInput;

    SmartDynamicGenericArray<std::string> stringy;
    SmartDynamicGenericArray<int> inty;

    const std::string filepath = "C:/Users/spect/Projects/ArrayLate/Resources/Words.txt";
    const std::string filepathTwo = "C:/Users/spect/Projects/ArrayLate/Resources/Nums.txt";
    std::string line;
    int num;

    std::ifstream wordFile(filepath);

    if (!wordFile.is_open())
    {
        return -1;
    }

    while (std::getline(wordFile, line))
    {
        stringy.pushBack(line);
    }
    wordFile.close();

    stringy.print();

    std::cout << "\n\n";

    stringy.ascendingNaiveSort();

    stringy.print();

    std::cout << "\nWhat string to search for?: ";

    std::cin >> stringInput;

    stringy.sequentialSearch(stringInput);

    system("pause");

    std::ifstream numFile(filepathTwo);

    if (!numFile.is_open())
    {
        return -2;
    }

    while (numFile >> num)
    {
        inty.pushBack(num);
    }
    numFile.close();

    inty.print();

    std::cout << "\n\n";

    inty.ascendingNaiveSort();

    inty.print();

    std::cout << "\nWhat integer to search for?: ";
    std::cin >> numInput;

    inty.sequentialSearch(numInput);

    return 0;
}
