#ifndef PAGEPRICE_H
#define PAGEPRICE_H

#include "pricingoptions.h"
#include <QPageSize>

struct PagePrice {

    qreal blackPrice()  {
        return blackPixels * options.blackInkPrice;
    }
    
    qreal colorPrice() {
        return colorPixels * options.colorInkPrice;
    }
    
    qreal totalPrice()  {
        return options.paperPrice + blackPrice() + colorPrice();
    }

public:
    PricingOptions options;

    QPageSize paperSize;
    int blackPixels = 0;
    int colorPixels = 0;
};

#endif // PAGEPRICE_H
