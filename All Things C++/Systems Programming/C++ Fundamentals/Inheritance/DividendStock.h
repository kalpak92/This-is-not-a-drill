#ifndef _DIVIDENDSTOCK_H_
#define _DIVIDENDSTOCK_H_

#include <string>

#include "Stock.h"

using namespace std;

// Represents a stock purchase that also pays dividends.
class DividendStock : public Stock {
    public:
    DividendStock(string symbol, double share_price = 0.0);

    // DividendStock's mutator and accessor methods.
    virtual void PayDividend(double amount_per_share);

    // DividentStock's "investment" interface.
    virtual double GetMarketValue() const override;
    virtual double GetDividends() const;

    // Print out the DividendStock information.
    virtual void Print() const override;

    private:
    double dividends_;
};

#endif  // _DIVIDEND_STOCK_