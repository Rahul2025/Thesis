file interaction.h
#ifndef INTERACTION_H
#define INTERACTION_H
#include <QWidget>
 
class QPushButton ;
class QLineEdit ;
class QVBoxLayout ;
class MyWidget : public QWidget {
   Q_OBJECT 
 
public :
   MyWidget( QWidget *parent = 0 ) ;
private :
   QLineEdit *entryField ;
   QPushButton *increaseButton ;
   QPushButton *randomButton ;
   QVBoxLayout *myLayout ;
private slots :
   void doIncrement( ) ;
   void findRandomNumber( ) ;
} ;
#endif
file interaction.cpp
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QRegExpValidator>
#include <QVBoxLayout>
#include <QRegExp>
#include <ctime> //for the srand initialization
#include <cstdlib> //for the random number
#include "interaction.h" 
 
MyWidget::MyWidget (QWidget *parent ) : QWidget( parent ) {
   myLayout = new QVBoxLayout( ) ;
   entryField = new QLineEdit( "0" ) ;
   QRegExp rx( "\\d+" ) ;
   QValidator *myvalidator = new QRegExpValidator( rx , this ) ;
   entryField->setValidator( myvalidator ) ;
   increaseButton = new QPushButton( "increase" ) ;
   connect( increaseButton, SIGNAL( clicked( ) ) ,
	 this , SLOT( doIncrement( ) )) ;
   randomButton = new QPushButton( "random" ) ;
   connect( randomButton , SIGNAL( clicked( ) ) ,
	 this , SLOT ( findRandomNumber( ) )) ;
   myLayout->addWidget( entryField ) ;
   myLayout->addWidget( increaseButton ) ;
   myLayout->addWidget( randomButton ) ;
   setLayout( myLayout ) ;
}
 
void MyWidget::doIncrement( ) {
   bool ok ;
   int zahl = entryField->text( ).toInt( &ok, 10 ) ;
   entryField->setText( QString( "%1").arg( ++zahl ) ) ;
}
 
void MyWidget::findRandomNumber( ) {
   QMessageBox msgBox( this ) ;
   msgBox.setText( "Do you want to create a random number ?" ) ;
   msgBox.setStandardButtons( QMessageBox::Yes | QMessageBox::No ) ;
   int ret = msgBox.exec( ) ;
   switch ( ret ) {
      case QMessageBox::Yes :
	 srand( time( 0 ) ) ;
	 int zahl = random( ) ;
	 entryField->setText( QString( "%1" ).arg( zahl )) ;
	 break ;
   }
}
file main.cpp 
#include <QApplication>
#include "interaction.h"
 
int main( int argc , char *argv[ ] ) {
   QApplication app( argc, argv ) ;
   MyWidget theWidget ;
   theWidget.show( ) ;
   return app.exec( ) ;
}