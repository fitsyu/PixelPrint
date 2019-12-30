#include "widget.h"
#include "ui_widget.h"

#include <QtDebug>
#include <QFileDialog>
#include <QPrintPreviewWidget>
#include <QPainter>

#include <poppler-qt5.h>

#include <QProcess>

Widget::Widget(QWidget *parent) :
QWidget(parent),
ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    setupLayout();
    
    setupInterplays();
    
    // TODO: remove this ato de ne
    checkDocument("/Users/fitsyu/Desktop/cnds.pdf");
    //    pdfDoc = nullptr;
}


Widget::~Widget()
{
    delete ui;
}

void Widget::setupLayout() {
    
    ui->openDocumentButton->setFixedHeight(40);
    
    ui->documentFileNameLabel->setText("no doc");
    ui->titleLabel->clear();
    ui->authorLabel->clear();
    ui->creatorLabel->clear();
    ui->createdAtLabel->clear();
    ui->pagesCountLabel->clear();
}

void Widget::setupInterplays() {
    
    connect(ui->openDocumentButton, &QPushButton::clicked, this, &Widget::openDocument);
    
    connect(this, &Widget::documentFileNameDidSet, this, &Widget::checkDocument);
    
    connect(this, &Widget::documentDidChecked, this, &Widget::loadDocument);
    
    connect(this, &Widget::documentDidLoad, this, &Widget::showDocInfo);
    
    connect(this, &Widget::documentDidLoad, this->ui->previewWidget, &QPrintPreviewWidget::updatePreview );
    
    connect(ui->previewWidget, &QPrintPreviewWidget::paintRequested, this, &Widget::previewPages);
    
    connect(this, &Widget::documentDidRendered, this, &Widget::doneRendering);
    
    connect(this, &Widget::documentDidRendered, this, &Widget::calculateDocumentPrice);
    
    connect(this, &Widget::documentPriceCalculated, this, &Widget::showDocumentPrice);
    
    connect(ui->printButton, &QPushButton::clicked, ui->previewWidget, &QPrintPreviewWidget::print);
}

void Widget::openDocument() {
    
    QString fileName = "";
    
    fileName = QFileDialog::getOpenFileName(this,
                                            "Select a document file",
                                            "",
                                            "Supported files (*.doc *.docx *.odt *.pdf)"
                                            );
    
    
    
    if (fileName.count() > 0) {
        
        ui->documentFileNameLabel->setText(fileName);
        
        // done
        emit documentFileNameDidSet(fileName);
    }
}

void Widget::checkDocument(QString fileName) {
    
    QFileInfo fileInfo(fileName);
    bool isPDF = fileInfo.suffix() == "pdf";
    
    if (!isPDF) {
        
        // the converted file would be in temp dir
        QString convertedFileName = QDir::tempPath() + QDir::separator() +fileInfo.baseName() + ".pdf";
        
        // prepare for conversion process
        QProcess* soffice = new QProcess(this);
        
        // read output
        connect(soffice, &QProcess::readyRead, [=]() {
            qDebug() << "READ" << soffice->readLine();
        });
        
        // read error
        connect(soffice, &QProcess::errorOccurred, [=]() {
            qDebug() << "eh err aw: " << soffice->errorString();
        });
        
        // on finished
        connect(soffice, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
                [=](int exitCode, QProcess::ExitStatus exitStatus){
            
            Q_UNUSED(exitCode)
            
            if (exitStatus != QProcess::NormalExit) {
                qDebug() << "Doc conversion fails";
            }
            
            // done
            emit documentDidChecked(convertedFileName);
            
            delete soffice;
        });
        
        // convert to PDF!
        soffice->start("/usr/local/bin/soffice",
                       QStringList()
                       << "--convert-to"
                       << "pdf"
                       << fileName
                       << "--outdir"
                       << QDir::tempPath() );
        
    } else {
        
        // already pdf
        emit documentDidChecked(fileName);
    }
}

void Widget::loadDocument(QString fileName) {
    
    Poppler::Document* document = Poppler::Document::load(fileName);
    if (!document || document->isLocked()) {
        // ... error message ....
        delete document;
        return;
    }
    
    // Paranoid safety check
    if (document == nullptr) {
        // ... error message ...
        return;
    }
    
    // save
    this->pdfDoc = document;
    
    // done
    emit documentDidLoad();
}

void Widget::previewPages(QPrinter* printer) {
    
    
    if ( pdfDoc == nullptr ) return;
    
    
    int pagesCount = pdfDoc->numPages();
    
    // printer->setPageSize(QPageSize(QSize(612, 792)));
    
    QPainter painter(printer);
    
    // render each page
    for (int p=0; p<pagesCount; p++) {
        
        // get image
        Poppler::Page* page = pdfDoc->page(p);
        QImage image = page->renderToImage();
        
        // sizing
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(image.rect());
        
        // render
        painter.drawImage(0, 0, image);
        
        if (p != pagesCount-1)
            printer->newPage();
        
        // done for this page
        delete page;
    }
    
    painter.end();
    
    // done
    emit documentDidRendered();
}

void Widget::showDocInfo() {
    
    ui->pagesCountLabel->setText( QString("%1").arg(pdfDoc->numPages()) );
    ui->titleLabel->setText( pdfDoc->title() );
    ui->authorLabel->setText( pdfDoc->author() );
    ui->creatorLabel->setText( pdfDoc->creator() );
    ui->createdAtLabel->setText( pdfDoc->creationDate().toString(Qt::DateFormat::TextDate) );
}

void Widget::doneRendering() {
    
    qDebug() << "Done.";
}

void Widget::calculateDocumentPrice() {
    
    if ( pdfDoc == nullptr ) return;
    
    int pagesCount = pdfDoc->numPages();
    
    QList<PagePrice> prices;
    
    for (int p=0; p<pagesCount; p++) {
        
        // get image
        Poppler::Page* page = pdfDoc->page(p);
        QImage image = page->renderToImage();
        
        prices << calculatePriceFor(&image);
    }
    
    // get grand total price
    DocumentPrice docPrice;
    docPrice.listOfpagePrice = prices;
    
    // save
    this->docPrice = docPrice;
    
    // done
    emit documentPriceCalculated();
}

PagePrice Widget::calculatePriceFor(QImage* image) {
    
    PagePrice pagePrice;
    pagePrice.options = PricingOptions();
    
    // inspect the image
    QSize size = image->size();
    pagePrice.paperSize = QPageSize(size);
    
    // fix grayscale by dithering
    if (image->isGrayscale()) {
        *image = (image->convertToFormat(QImage::Format_Mono, Qt::MonoOnly));
    }
    
    int blackPixels = 0;
    int colorPixels = 0;
    
    for(int row=0; row<size.width(); row++){
        for(int col=0; col<size.height(); col++){
            
            QColor pixel = image->pixel(row, col);
            
            // only colored ones get counted
            if (pixel != Qt::white) {
                if (pixel == Qt::black)
                    blackPixels += 1;
                else
                    colorPixels += 1;
            }
        }
    }
    
    pagePrice.blackPixels = blackPixels;
    pagePrice.colorPixels = colorPixels;
    
    return pagePrice;
}

void Widget::showDocumentPrice() { 
    
    ui->tableView->setModel( new PriceBreakdownModel(docPrice) );
    QString localPrice = QLocale().toCurrencyString(docPrice.totalPrice());
    ui->finalPriceLabel->setText( localPrice );
}


