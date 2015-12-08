#include "GuiChatTab.h"
#include <QApplication>
#include <QMenu>
#include <QDebug>

GuiChatTab::GuiChatTab(QWidget *parent) : QWidget(parent)
{
  comb_scrollarea = new QScrollArea(this);

  comb_scrollarea->setFrameShape(QFrame::NoFrame);
  QPalette comb_scrollarea_palette;
  comb_scrollarea_palette.setColor(QPalette::Background, Qt::white);
  comb_scrollarea->setPalette(comb_scrollarea_palette);

  GuiChatTab_comb_scroll_widget *sssa = new GuiChatTab_comb_scroll_widget();
  comb_scrollarea->setWidget(sssa);

  /*comb_treewidget = new QTreeWidget(this);
  comb_treewidget->setHeaderHidden(true);
  comb_treewidget->setAnimated(true);
  comb_treewidget->setAlternatingRowColors(false);
  comb_treewidget->setFrameStyle(QFrame::NoFrame);

  connect(comb_treewidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(onItemClicked(QTreeWidgetItem*, int)));

  QTreeWidgetItem *item=new QTreeWidgetItem(comb_treewidget,QStringList(QString("Tree")));//添加节点
      //添加子节点


  for(int i = 0; i <= 10; i++)
    {
      QTreeWidgetItem *item1=new QTreeWidgetItem(item,QStringList(QString("Band")+QString::number(i+1)));
      item->addChild(item1);
    }
  //comb_treewidget->setFixedWidth(100);
*/
  ////main layout



  main_layout = new QVBoxLayout(this);
  main_layout->addWidget(comb_scrollarea);





}


void GuiChatTab::addNewComb(QString title)
{
  /*comb_treewidget_item = new QTreeWidgetItem();
  comb_treewidget_item->setText(1,title);
  comb_treewidget_item->setIcon(0,QIcon(":/GuiTabBlock/right_btn_line_label0.png"));

  comb_treewidget->addTopLevelItem(comb_treewidget_item);*/
}

void addNewGroup(QString title)
{

}





void GuiChatTab::onItemClicked(QTreeWidgetItem *item, int column)
{
  qDebug()<<"sss";
    if (qApp->mouseButtons() == Qt::LeftButton)
    {
        return;
        qDebug()<<"hhh";
    }

    if (qApp->mouseButtons() == Qt::RightButton)
    {
        if (item->childCount() > 0)
        {
            return;
        }
        qDebug()<<"halo";
        showMenu();
    }
}


void GuiChatTab::showMenu()
{
    /*QPoint pos;
    //QMenu menu(comb_treewidget);
    QIcon myIcon(":/GuiTabBlock/right_btn_line_label1.png");
    menu.addAction(myIcon,tr("菜单_1"));
    menu.addAction(myIcon,tr("菜单_2"));
    menu.addAction(myIcon,tr("菜单_3"));
    menu.addAction(myIcon,tr("菜单_4"));
    menu.addAction(myIcon,tr("菜单_5"));
    menu.addAction(myIcon,tr("菜单_6"));
    menu.exec(QCursor::pos());*/
}


//////////////////////////////////////
GuiChatTab_comb_scroll_widget::GuiChatTab_comb_scroll_widget(QWidget *parent) : QWidget(parent)
{

  this->setParent(parent);

  ///main layout
  main_layout = new QVBoxLayout(this);
  main_layout->setContentsMargins(0,0,0,0);
  main_layout->setSpacing(0);
  GuiCombWidget *hahaha;

  for(int i = 0; i < 9; i++)
    {
      hahaha = new GuiCombWidget("/Users/Echo/Desktop/squirrel.jpg", "@Echo", QString("192.168.1."+QString::number(i)), this);
      main_layout->addWidget(hahaha);

    }
}