#ifndef PRICINGOPTIONS_H
#define PRICINGOPTIONS_H

#include <QtCore>

struct PricingOptions {
public:
    qreal paperPrice       = 100;
    qreal blackInkPrice    = 0.010;
    qreal colorInkPrice    = 0.015;
};

#endif // PRICINGOPTIONS_H
