#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>

#include "DividendStock.h"
#include "Stock.h"

using namespace std;

// print info about a stock to cout followed by newline
// (same code does the "right thing" for subclass objects
//  by calling overridden Print function)
void PrintStock(Stock * s) {
    s->Print();
    cout << endl;
}

int main() {
    // create several investments
    Stock* stock = new Stock("MSFT");
    stock->Purchase(50, 10.00);
    stock->set_share_price(9.50);

    DividendStock* dividend = new DividendStock("INTC");
    dividend->Purchase(100, 20.00);
    dividend->PayDividend(5.00);
    dividend->set_share_price(30);

    // display info about each investment
    stock->Print();
    cout << endl;
    dividend->Print();
    cout << endl << endl;

    // print info again, but using a function
    PrintStock(stock);
    PrintStock(dividend);

    delete stock;
    delete dividend;

    return EXIT_SUCCESS;
}