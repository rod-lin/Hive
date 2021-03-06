#include "GuiCentralWidget.h"

GuiCentralWidget::GuiCentralWidget(QWidget *parent) : QWidget(parent)
{
//! do not delete yet, see if it causes problems.
//  QPalette palette;
//  palette.setColor(QPalette::Window, QColor(250,250,250));
//  this->setPalette(palette);

  this->setMinimumHeight(600);
  this->setMinimumWidth(900);
  this->setAttribute(Qt::WA_TranslucentBackground);
  this->setWindowTitle(QString("Hive! %1.%2.%3 alpha-test")
                       .arg(GlobalData::g_version[0])
                       .arg(GlobalData::g_version[1])
                       .arg(GlobalData::g_version[2]));

  ////Gui
  gui_tab_block = new GuiTabBlock(this);
  gui_main_block = new GuiMainBlock(this);

  QFrame *line = new QFrame(this);
  line->setFrameShape(QFrame::VLine);
  line->setFrameShadow(QFrame::Plain);
  line->setFixedWidth(1);
  line->setStyleSheet ("QFrame{  background: #CFCFCF; border: transparent;  }");

  //main_layout
  main_layout = new QHBoxLayout(this);
  main_layout->setMargin(0);
  main_layout->setSpacing(0);
  main_layout->addWidget(gui_tab_block);
  main_layout->addWidget(line);
  main_layout->addWidget(gui_main_block);

  //connect

  connect(gui_tab_block->gui_chat_tab->comb_scroll_widget, SIGNAL(combWidgetClicked(const QString&)), gui_main_block->gui_chat_stack, SLOT(refreshUI(const QString&)));

  ///buttons~~
  connect(gui_tab_block->gui_home_tab->welcome_btn, SIGNAL(clicked(StaticStackType)), gui_main_block, SLOT(displayStaticStack(StaticStackType)));
  connect(gui_tab_block->gui_home_tab->list_btn, SIGNAL(clicked(StaticStackType)), gui_main_block, SLOT(displayStaticStack(StaticStackType)));
  connect(gui_tab_block->gui_home_tab->storage_btn, SIGNAL(clicked(StaticStackType)), gui_main_block, SLOT(displayStaticStack(StaticStackType)));

  connect(gui_tab_block->gui_settings_tab->messaging_btn, SIGNAL(clicked(StaticStackType)), gui_main_block, SLOT(displayStaticStack(StaticStackType)));
  connect(gui_tab_block->gui_settings_tab->profile_btn, SIGNAL(clicked(StaticStackType)), gui_main_block, SLOT(displayStaticStack(StaticStackType)));
  connect(gui_tab_block->gui_settings_tab->questions_btn, SIGNAL(clicked(StaticStackType)), gui_main_block, SLOT(displayStaticStack(StaticStackType)));



}

GuiCentralWidget::~GuiCentralWidget()
{
  qDebug()<<"\n@Hive UI is destructed";
}


void GuiCentralWidget::addUsr(UserData *userData)
{
  gui_tab_block->gui_chat_tab->comb_scroll_widget->addComb(userData->usrProfileStruct());

  GlobalData::TEST_printUsrProfileStruct(*userData->usrProfileStruct(), "GuiCentralWidget recieved package generated just now");
  //these will be eliminated
  gui_main_block->gui_home_stack_list->addUsr(userData->usrProfileStruct());
}

void GuiCentralWidget::delUsr(UserData *userData)
{

}

void GuiCentralWidget::changeUsr(UserData *userData)
{
  gui_tab_block->gui_chat_tab->comb_scroll_widget->refreshComb(userData->usrProfileStruct());
  gui_main_block->gui_home_stack_list->refreshUsrProfile(userData->usrProfileStruct());

  //these will be eliminated
  //  gui_main_block->gui_chat_stack_map.value(usrProfileStruct->key_str)->refreshUsrProfile(usrProfileStruct);<<
}

void GuiCentralWidget::refreshUI()
{
  gui_main_block->gui_home_stack_welcome->refreshUI();
}

