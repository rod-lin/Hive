#ifndef GUICENTRALWIDGET_H
#define GUICENTRALWIDGET_H

#include "GuiTabBlock.h"
#include "GuiMainBlock.h"

#include <QSystemTrayIcon>

class GuiCentralWidget : public QWidget
{
  Q_OBJECT

public:
  explicit GuiCentralWidget(QWidget *parent = 0);
  ~GuiCentralWidget();

  QHBoxLayout *main_layout;
  GuiTabBlock *gui_tab_block;
  GuiMainBlock *gui_main_block;

private:
  QString usr_key_str;
  QString usr_name_str;
  QString avatar_path_str;

  QStringList my_profile_str_list;

public slots:
  void addUsr(UserData *userData);
  void delUsr(UserData *userData);
  void changeUsr(UserData *userData);
  void refreshUI();


  void iconActivated(QSystemTrayIcon::ActivationReason reason)
  {
    switch (reason)
    {
      case QSystemTrayIcon::Trigger:
        {
          this->show();
          break;
        }
      case QSystemTrayIcon::DoubleClick:
        {
          this->show();
          break;
        }
      case QSystemTrayIcon::MiddleClick:
        {
          this->show();
          break;
        }
      default:;
    }
  }

private slots:


};

#endif // GUICENTRALWIDGET_H
