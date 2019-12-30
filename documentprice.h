#ifndef DOCUMENTPRICE_H
#define DOCUMENTPRICE_H

#include <QtCore>
#include "pageprice.h"

struct DocumentPrice {
public:
    QList<PagePrice> listOfpagePrice;
    qreal totalPrice() {
        qreal price = 0;
        foreach(PagePrice pagePrice, listOfpagePrice) { price += pagePrice.totalPrice(); }
        return price;
    }
};

#endif // DOCUMENTPRICE_H
