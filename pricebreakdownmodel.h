#ifndef PRICINGTABLEMODEL_H
#define PRICINGTABLEMODEL_H

#include <QAbstractTableModel>
#include "documentprice.h"

class PriceBreakdownModel: public QAbstractTableModel {
    
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const {
        Q_UNUSED(parent)
        return documentPrice.listOfpagePrice.count();
    }
    
    int columnCount(const QModelIndex &parent = QModelIndex()) const {
        Q_UNUSED(parent)
        return headers.count();
    }
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const {
        
        if (role != Qt::DisplayRole) return QVariant();
        
        PagePrice pagePrice = documentPrice.listOfpagePrice.at(index.row());
        
        QVariant dat;
        switch(index.column()) {
                
            case 0:
                dat = index.row()+1;
                break;
                
            case 1:
                dat = pagePrice.paperSize.name();
                break;
                
            case 2:
                dat = local.toCurrencyString( pagePrice.options.paperPrice );
                break;
                
            case 3:
                dat = pagePrice.blackPixels;
                break;
                
            case 4:
                dat = local.toCurrencyString( pagePrice.blackPrice() );
                break;
                
            case 5:
                dat = pagePrice.colorPixels;
                break;
                
            case 6:
                dat = local.toCurrencyString( pagePrice.colorPrice() );
                break;
                
            case 7:
                dat = local.toCurrencyString( pagePrice.totalPrice() );
                break;
                
            default:
                break;
        }
        
        return dat;
    }
    
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const {
        
        if (role != Qt::DisplayRole || orientation == Qt::Vertical) return QVariant();
        
        QString header = headers.at(section);
        
        return header;
    }
    
    PriceBreakdownModel(DocumentPrice documentPrice) {
        this->documentPrice = documentPrice;
        QLocale::setDefault(QLocale(QLocale::Indonesian, QLocale::Indonesia));
        headers = QStringList()
        << "Page"
        << "Paper Size"
        << "Paper Price"
        << "Black Pixels"
        << "Black Price"
        << "Color Pixels"
        << "Color Price"
        << "Total Price"
        ;
    }
    
    virtual ~PriceBreakdownModel();
    
    
private:
    DocumentPrice documentPrice;
    QLocale local;
    QStringList headers;
};

#endif // PRICINGTABLEMODEL_H
