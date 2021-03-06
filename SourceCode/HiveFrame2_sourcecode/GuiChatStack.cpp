#include "GuiChatStack.h"

////////////////////////////top//////////////////////////////////////
//GuiChatStack_top_bar::GuiChatStack_top_bar(UsrProfileStruct *usrProfileStruct, QWidget *parent) : QWidget(parent)
//{
//  ///usrKey<<usrName<<ipAddr<<avatarPathr
//  QPalette palette;
//  palette.setColor(QPalette::Window, QColor(255,255,255));
//  this->setPalette(palette);
//  this->setAutoFillBackground(true);

//  avatar_button = new GuiAvatarButton(usrProfileStruct->avatar_str, 90, this);
//  avatar_button->setAlignment(Qt::AlignLeft);

//  usr_name_label = new QLabel(usrProfileStruct->name_str, this);
//  usr_name_label->setFont(GlobalData::font_scrollStackTitle);

//  usr_ip_label = new QLabel(usrProfileStruct->ip_str, this);
//  usr_ip_label->setFont(GlobalData::font_scrollStackSubtitle);


//  QVBoxLayout *usr_info_layout = new QVBoxLayout();
//  usr_info_layout->setContentsMargins(0,0,10,10);
//  usr_info_layout->addWidget(usr_name_label);
//  usr_info_layout->addWidget(usr_ip_label);


//  main_layout = new QHBoxLayout(this);
//  main_layout->setAlignment(Qt::AlignLeft);
//  main_layout->setContentsMargins(15,10,10,0);
//  main_layout->setSpacing(10);
//  main_layout->addWidget(avatar_button);
//  main_layout->addLayout(usr_info_layout);

//  this->setFixedHeight(69);
//}

//GuiChatStack_top_bar::~GuiChatStack_top_bar()
//{

//}

//void GuiChatStack_top_bar::setProfile(UsrProfileStruct *usrProfileStruct)
//{
//  avatar_button->setAvatar(usrProfileStruct->avatar_str);
//  usr_name_label->setText(usrProfileStruct->name_str);
//  usr_ip_label->setText(usrProfileStruct->ip_str);
//}

//////////////////////////mid////////////////////////////////

GuiChatStack_chat_widget::GuiChatStack_chat_widget(QWidget *parent) : QWidget(parent)
{
  setAutoFillBackground(true);
  QPalette palette = this->palette();
  palette.setColor(QPalette::Window, Qt::white);
  this->setPalette(palette);

  chat_bubble_layout = new QVBoxLayout();
  chat_bubble_layout->setAlignment(Qt::AlignTop);
  chat_bubble_layout->addStretch();
  chat_bubble_layout->setContentsMargins(5,30,5,30);

  ///lines
  QFrame *top_line = new QFrame(this);
  top_line->setFrameShape(QFrame::HLine);
  top_line->setFrameShadow(QFrame::Plain);
  top_line->setFixedHeight(2);
  top_line->setStyleSheet ("QFrame{  background: #ffd77e; border: 0px transparent;  }");

  QFrame *bottom_line = new QFrame(this);
  bottom_line->setFrameShape(QFrame::HLine);
  bottom_line->setFrameShadow(QFrame::Plain);
  bottom_line->setFixedHeight(4);
  bottom_line->setStyleSheet ("QFrame{  background: #ffb500; border: 0px transparent;  }");

  main_layout = new QVBoxLayout(this);
  main_layout->setAlignment(Qt::AlignTop);
  main_layout->setSpacing(5);
  main_layout->setContentsMargins(0,0,0,0);
  main_layout->addWidget(top_line);
  main_layout->addLayout(chat_bubble_layout);
  main_layout->addWidget(bottom_line);


}

GuiChatStack_chat_widget::~GuiChatStack_chat_widget()
{

}

void GuiChatStack_chat_widget::clearChatBubbles()
{
  foreach (GuiChatBubble *temp_chat_bubble_pointer, chat_bubble_list)
    {
      temp_chat_bubble_pointer->deleteLater();
    }
}

void GuiChatStack_chat_widget::addChatBubble(const QString &message, const bool &fromMe)
{
  gui_chat_bubble = new GuiChatBubble(message, !fromMe, this);
  if(fromMe)
    {
      chat_bubble_layout->addWidget(gui_chat_bubble);
    }
  else
    {
      chat_bubble_layout->addWidget(gui_chat_bubble);
    }
  chat_bubble_list.append(gui_chat_bubble);
}

//////////////////////////bottom//////////////////////////////////////

GuiChatStack_message_editor::GuiChatStack_message_editor(QWidget *parent) : QWidget(parent)
{
  QPalette palette;
  palette.setColor(QPalette::Window, QColor(255,255,255));
  this->setPalette(palette);
  this->setAutoFillBackground(true);

  text_editor = new GuiTextEdit(this);
  text_editor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  text_editor->setFrameStyle(QFrame::NoFrame);
  text_editor->setFont(GlobalData::font_chatTextEditor);
  text_editor->installEventFilter(this);

  ///tools
  expression_label = new GuiLabelButton(this);
  image_label = new GuiLabelButton(this);
  file_label = new GuiLabelButton(this);

  expression_label->setDefaultPixmap(":/img/img/expression_label_0.png");
  expression_label->setHoveredPixmap(":/img/img/expression_label_1.png");

  image_label->setDefaultPixmap(":/img/img/image_label_0.png");
  image_label->setHoveredPixmap(":/img/img/image_label_1.png");

  file_label->setDefaultPixmap(":/img/img/file_label_0.png");
  file_label->setHoveredPixmap(":/img/img/file_label_1.png");

  tool_layout = new QHBoxLayout();
  tool_layout->setAlignment(Qt::AlignLeft);
  tool_layout->setContentsMargins(0,5,5,5);
  tool_layout->setSpacing(15);
  tool_layout->addWidget(expression_label);
  tool_layout->addWidget(image_label);
  tool_layout->addWidget(file_label);
  ///for test period
    expression_label->setHidden(true);
    image_label->setHidden(true);
    file_label->setHidden(true);

  edit_layout = new QVBoxLayout();
  edit_layout->setAlignment(Qt::AlignLeft);
  edit_layout->setContentsMargins(10,5,15,10);
  edit_layout->setSpacing(5);
  edit_layout->addLayout(tool_layout);
  edit_layout->addWidget(text_editor);

  ///send button
  send_btn = new GuiLabelButton(this);
  send_btn->setDefaultPixmap(":/img/img/send_button_0.png");
  send_btn->setHoveredPixmap(":/img/img/send_button_1.png");
  send_btn->setAlignment(Qt::AlignRight);

  main_layout = new QHBoxLayout(this);
  main_layout->setAlignment(Qt::AlignBottom);
  main_layout->setContentsMargins(0,0,20,0);
  main_layout->setSpacing(0);
  main_layout->addLayout(edit_layout);
  main_layout->addWidget(send_btn);


  this->setMaximumHeight(130);
}

GuiChatStack_message_editor::~GuiChatStack_message_editor()
{

}

/// Event filter: capture QEvent outside the class
///   text_editor->installEventFilter(this);
bool GuiChatStack_message_editor::eventFilter(QObject *obj, QEvent *e)
{
  Q_ASSERT(obj == text_editor);
  if(e->type() == QEvent::KeyPress)
    {
      QKeyEvent *event = static_cast<QKeyEvent*>(e);
      if(event->key() == Qt::Key_Return)
        {
          if(event->modifiers() & Qt::ControlModifier)
            {
              control_pressed = true;
              text_editor->insertPlainText("\n");
            }
          else
            {
              control_pressed = false;
              send_btn->setHovered();
            }
          return true;
        }
    }
  if(e->type() == QEvent::KeyRelease)
    {
      QKeyEvent *event = static_cast<QKeyEvent*>(e);
      if (event->key() == Qt::Key_Return)
        {
          if(event->modifiers() & Qt::ControlModifier)
            {
              return true;
            }
          else
            {
              qDebug()<<"old key";
              emit sendTriggered();
              send_btn->setDefault();
              return true;
            }
        }
    }

    return false;
}


////////////////////////////main//////////////////////////////////////

//GuiChatStack_old::GuiChatStack_old(UsrProfileStruct *usrProfileStruct, QWidget *parent) : QWidget(parent)
//{
//  ///Data
//  usr_profile = *usrProfileStruct;

//  data_history_io = new DataHistoryIO(usr_profile.key_str, this);
//  refreshCurrentActiveIndex();

//  ///UI
//  top_bar = new GuiChatStack_top_bar(&usr_profile, this);

//  QFrame *top_bar_line = new QFrame(this);
//  top_bar_line->setFrameShape(QFrame::HLine);
//  top_bar_line->setFrameShadow(QFrame::Plain);
//  top_bar_line->setFixedHeight(2);
//  top_bar_line->setStyleSheet ("QFrame{  background: #ffd77e; border: 0px transparent;  }");

//  chat_widget = new GuiChatStack_chat_widget(this);
//  chat_scroll_area = new QScrollArea(this);
//  chat_scroll_area->setWidgetResizable(true);
//  chat_scroll_area->setWidget(chat_widget);
//  QPalette palette = chat_scroll_area->palette();
//  palette.setColor(QPalette::Base, QColor(255,255,255,255));
//  chat_scroll_area->setPalette(palette);
//  chat_scroll_area->setFrameStyle(0);

////  message_editor = new GuiChatStack_message_editor(usr_profile.key_str, this);

//  ////main layout
//  main_layout = new QVBoxLayout(this);
//  main_layout->setAlignment(Qt::AlignCenter);
//  main_layout->addWidget(top_bar);
//  main_layout->addWidget(top_bar_line);
//  main_layout->addWidget(chat_scroll_area);
//  main_layout->addWidget(message_editor);
//  main_layout->setMargin(0);
//  main_layout->setSpacing(0);

//  connect(message_editor, SIGNAL(sendTriggered()), this, SLOT(onSendButtonClicked()));
//  connect(message_editor->send_btn, SIGNAL(clicked()), this, SLOT(onSendButtonClicked()));

//  loadHistory(current_active_index);

//  chat_scroll_area->verticalScrollBar()->setValue(chat_scroll_area->verticalScrollBar()->maximum());
//}

//GuiChatStack_old::~GuiChatStack_old()
//{

//}

//void GuiChatStack_old::setUserData(UserData *usr_data)
//{

//}

//void GuiChatStack_old::refreshCurrentActiveIndex()
//{
//  current_active_index = data_history_io->currentActiveIndex();
//}


/////slots


//void GuiChatStack_old::checkMessage(MessageStruct &messageStruct, bool fromMe)
//{
//  chat_widget->addChatBubble(messageStruct.message_str, fromMe);

//  data_history_io->wirteMessage(messageStruct, fromMe);

//  refreshCurrentActiveIndex();

//  chat_scroll_area->verticalScrollBar()->setValue(chat_scroll_area->verticalScrollBar()->maximum());

//}

//void GuiChatStack_old::dragEnterEvent(QDragEnterEvent *event)
//{
//  event->accept();
//}

//void GuiChatStack_old::dropEvent(QDropEvent *event)
//{
//  qDebug()<<"0890809090909000file entre0000000000000000000";
//  QList<QUrl> urls = event->mimeData()->urls();
//  if (urls.isEmpty())
//    {
//      return;
//    }
//  QString fileName = urls.first().toLocalFile();
//  if (fileName.isEmpty())
//    {
//      return;
//    }

//}

//void GuiChatStack_old::onSendButtonClicked()
//{
//  QString message_str = message_editor->text_editor->toPlainText();
//  emit sendMessage(&usr_profile.key_str, &message_str);
//  message_editor->text_editor->clear();

//}

//void GuiChatStack_old::onKeyEnterTriggered(bool &pressed)
//{
//  qDebug()<<"enter key pressed";
//  if(pressed)
//    {
//      message_editor->send_btn->setHovered();
//    }
//  else
//    {
//      message_editor->send_btn->setDefault();
//      onSendButtonClicked();
//    }
//}

//void GuiChatStack::loadHistory(int index)
//{
//  if(index <= index)
//    {
//      for(int i = 0; i < history_json_array.count(); i++)
//        {
//          QJsonArray a;
//          QJsonObject history_json_obj = a[i].toObject();
//          chat_widget->addChatBubble(history_json_obj["message"].toString(), history_json_obj["fromMe"].toBool());
//        }
//    }
//  else
//    {
//      qDebug()<<"@GuiChatStack::loadHistory(): History index error!!";
//      return;
//    }
//}

//void GuiChatStack_old::refreshUsrProfile(UsrProfileStruct *usrProfileStruct)
//{
//  top_bar->setProfile(usrProfileStruct);
//}



GuiTextEdit::GuiTextEdit(QWidget *parent)
{
  this->setParent(parent);
}

GuiTextEdit::~GuiTextEdit()
{

}


///Not applicatable because "QWidget::keyPressEvent(e);" doesn't work as expected
//void GuiTextEdit::keyPressEvent(QKeyEvent *e)
//{
//  if(e->key() == Qt::Key_Return)
//    {
//      if(e->modifiers() & Qt::ControlModifier)
//        {
//          control_pressed = true;
//          this->insertPlainText("\n");
//        }
//      else
//        {
//          control_pressed = false;
//          emit keyEnterTriggered(true);
//        }
//    }
//  else
//    {
//      QWidget::keyPressEvent(e);
//    }
//}

//void GuiTextEdit::keyReleaseEvent(QKeyEvent *e)
//{
//  if (e->key() == Qt::Key_Return)
//    {
//      if(e->modifiers() & Qt::ControlModifier)
//        {
//          return;
//        }
//      else
//        {
//          QString message_str = this->toPlainText();
//          emit keyEnterTriggered(false);
//          this->clear();
//        }
//    }
//  else
//    {
//      QWidget::keyPressEvent(e);
//    }
//}

void GuiTextEdit::dragEnterEvent(QDragEnterEvent *event)
{
  event->accept();
}

void GuiTextEdit::dropEvent(QDropEvent *event)
{
  QList<QUrl> url_list = event->mimeData()->urls();
  if(url_list.isEmpty())
    {
      return;
    }

  if(url_list.count() > 15)
    {
      qDebug()<<"@GuiTextEdit::dropEvent: Too many files dropped";
      return;
    }

  foreach(QUrl url, url_list)
    {
      QString fileName = url.toLocalFile();
      if (fileName.isEmpty())
        {
          break;
        }
      qDebug()<<"@file dropped"<<fileName;
    }

}






GuiChatStack::GuiChatStack(QWidget *parent)
{
  ///UI
  QFrame *top_bar_line = new QFrame(this);
  top_bar_line->setFrameShape(QFrame::HLine);
  top_bar_line->setFrameShadow(QFrame::Plain);
  top_bar_line->setFixedHeight(2);
  top_bar_line->setStyleSheet ("QFrame{  background: #ffd77e; border: 0px transparent;  }");

  chat_widget = new GuiChatStack_chat_widget(this);
  chat_scroll_area = new QScrollArea(this);
  chat_scroll_area->setWidgetResizable(true);
  chat_scroll_area->setWidget(chat_widget);
  QPalette palette = chat_scroll_area->palette();
  palette.setColor(QPalette::Base, QColor(255,255,255,255));
  chat_scroll_area->setPalette(palette);
  chat_scroll_area->setFrameStyle(0);

  message_editor = new GuiChatStack_message_editor(this);

  //this is a flag to distinguish
  ///////////////////////////////////////Eiffel Tower////////////////////////////////////

  ////main layout
  central_layout->addWidget(top_bar_line);
  central_layout->addWidget(chat_scroll_area);
  central_layout->addWidget(message_editor);


  connect(message_editor, SIGNAL(sendTriggered()), this, SLOT(onSendButtonClicked()));
  connect(message_editor->send_btn, SIGNAL(clicked()), this, SLOT(onSendButtonClicked()));

  flipLatestMessage();
  chat_scroll_area->verticalScrollBar()->setValue(chat_scroll_area->verticalScrollBar()->maximum());

  this->setParent(parent);
}

GuiChatStack::~GuiChatStack()
{
//  this->set
}

void GuiChatStack::refreshUI(const QString &usrKey)
{
  this->setIcon(*usr_data->avatar());
  this->setTitle(*usr_data->name());
  this->setSubTitle(*usr_data->ip());

  chat_widget->clearChatBubbles();

  QJsonArray message_json_array = *GlobalData::online_usr_data_map.value(usrKey)->flipLatest();
  int message_count = message_json_array.count();
  for(int i = 0; i < message_count; i++)
    {
            QJsonObject history_json_obj = message_json_array[i].toObject();

            chat_widget->addChatBubble(history_json_obj["message"].toString(), history_json_obj["fromMe"].toBool());
    }

}


void GuiChatStack::dragEnterEvent(QDragEnterEvent *event)
{
  event->accept();

}

void GuiChatStack::dropEvent(QDropEvent *event)
{
  qDebug()<<"@GuiChatStack::dropEvent(): file entered.";
  QList<QUrl> urls = event->mimeData()->urls();
  if (urls.isEmpty())
    {
      return;
    }
  QString fileName = urls.first().toLocalFile();
  if (fileName.isEmpty())
    {
      return;
    }
}

void GuiChatStack::flipLatestMessage()
{

}

void GuiChatStack::flipUpMessage()
{

}

void GuiChatStack::flipDownMessage()
{

}

void GuiChatStack::onSendButtonClicked()
{
  QString message_str = message_editor->text_editor->toPlainText();
  emit sendMessage(usr_data->key(), &message_str);
  message_editor->text_editor->clear();

}

void GuiChatStack::onKeyEnterTriggered(bool &pressed)
{
  qDebug()<<"enter key pressed";
  if(pressed)
    {
      message_editor->send_btn->setHovered();
    }
  else
    {
      message_editor->send_btn->setDefault();
      onSendButtonClicked();
    }
}

