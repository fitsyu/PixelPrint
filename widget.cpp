#include "widget.h"
#include "ui_widget.h"

#include <QtDebug>
#include <QFileDialog>
#include <QPrintPreviewWidget>
#include <QPainter>

#include <poppler-qt5.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    setupLayout();

    setupInterplays();

    // remove this ato de ne
    loadDocument("/Users/fitsyu/Desktop/cnds.pdf");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setupLayout() {

    ui->openDocumentButton->setFixedHeight(40);
}

void Widget::setupInterplays() {

    connect(ui->openDocumentButton, &QPushButton::clicked, this, &Widget::openDocument);

    connect(this, &Widget::documentFileNameDidSet, this, &Widget::loadDocument);

    connect(this, &Widget::documentDidLoad, this, &Widget::showDocInfo);

    connect(this, &Widget::documentDidLoad, this->ui->previewWidget, &QPrintPreviewWidget::updatePreview );

    connect(ui->previewWidget, &QPrintPreviewWidget::paintRequested, this, &Widget::previewPages);

    connect(this, &Widget::documentDidRendered, this, &Widget::doneRendering);

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
