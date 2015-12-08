#include "mainwindow.h"
#include <QDebug>
#include <QBitmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  QPalette palette;
  palette.setColor(QPalette::Base, QColor(255,204,0,255));
  this->setPalette(palette);

  gui_central_widget = new GuiCentralWidget(this);
  connect(gui_central_widget->gui_tab_block->exit_hint, SIGNAL(clicked()), this, SLOT(close()));
  connect(gui_central_widget->gui_tab_block->min_hint, SIGNAL(clicked()), this, SLOT(showMinimized()));
  connect(gui_central_widget->gui_tab_block->max_hint, SIGNAL(clicked()), this, SLOT(setWindowMaximized()));

  this->setMinimumHeight(600);
  this->setMinimumWidth(900);
  this->setCentralWidget(gui_central_widget);
  this->setAttribute(Qt::WA_TranslucentBackground);
  this->setWindowFlags(Qt::FramelessWindowHint);
  this->setWindowState(Qt::WindowNoState);
  //this->setWindowFlags(Qt::CustomizeWindowHint);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent*)
{
  ///rounded frame     //scroll bug here!
  /*QBitmap bmp(this->size());
  bmp.fill();
  QPainter p(&bmp);
  p.setPen(Qt::NoPen);
  p.setBrush(Qt::black);
  p.setRenderHint(QPainter::Antialiasing, true);
  p.setRenderHint(QPainter::SmoothPixmapTransform);
  p.drawRoundedRect(bmp.rect(), 8, 8);
  this->setMask(bmp);

  ///color
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.fillRect(rect(), QColor(255,255,255,255));*/

  QRectF rectangle(0, 0, this->width(), this->height());
  QPainter paint;
  paint.begin(this);
  paint.setPen(QPen(Qt::NoPen));
  paint.setBrush(QBrush(Qt::white,Qt::SolidPattern));
  paint.drawRoundedRect(rectangle,5,5);
  paint.end();
}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
  if(event->button() == Qt::LeftButton)
    {
      mouse_pressed = true;
      //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
      move_point = event->pos();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
  if(mouse_pressed)
    {
      //鼠标相对于屏幕的位置
      QPoint move_pos = event->globalPos();
      this->move(move_pos - move_point);
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_pressed = false;
}

void MainWindow::setWindowMaximized()
{
  if(maximized)
    {
      setWindowState(Qt::WindowNoState);
      maximized = false;
    }
  else
    {
      setWindowState(Qt::WindowFullScreen);
      maximized = true;
    }
}

