#include "GlobalData.h"



///UI
QFont GlobalData::font_main;
QFont GlobalData::font_chatTextEditor;
QFont GlobalData::font_chatBubble;
QFont GlobalData::font_combWidgetUsrName;
QFont GlobalData::font_combWidgetIpAddr;
QFont GlobalData::font_menuButton;
QFont GlobalData::font_scrollStackTitle;
QFont GlobalData::font_scrollStackSubtitle;

QColor GlobalData::bc_darkGrey = QColor(100,100,100);
QColor GlobalData::bc_lightGrey = QColor(225,225,225);
QColor GlobalData::bc_brown = QColor(103,72,0);
QColor GlobalData::bc_hiveYellow = QColor(255,181,0);
QColor GlobalData::bc_lightYellow = QColor(255,215,126);

QColor GlobalData::color_window = QColor(255,255,255);
QColor GlobalData::color_alphaTab = QColor(255,255,255,230);
QColor GlobalData::color_tab = QColor(0,0,0,0);

QColor GlobalData::color_defaultChatBubbleI = GlobalData::bc_lightYellow;
QColor GlobalData::color_defaultChatBubbleO = GlobalData::bc_lightGrey;

QPalette GlobalData::palette_bkg_normalWhite;
QPalette GlobalData::palette_bkg_transparent;
QPalette GlobalData::palette_txt_brown;


///data
char GlobalData::g_version[3] = {'0','0','6'};
SettingStruct GlobalData::g_settings_struct;
QMap<QString, UsrProfileStruct> GlobalData::saved_usr_profile_map;
QMap<QString, UsrProfileStruct> GlobalData::online_usr_profile_map;

QMap<QString, UserData*> GlobalData::online_usr_data_map;//used

///netr
QString GlobalData::g_localHostIP;

QString GlobalData::g_currentTime()
{
  return QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss");
}

void GlobalData::TEST_printUsrProfileStruct(const UsrProfileStruct &usrProfileStruct, const QString &str)
{
  qDebug()<<endl<<"Test by "<<str;
  qDebug()<<usrProfileStruct.key_str;
  qDebug()<<usrProfileStruct.name_str;
  qDebug()<<usrProfileStruct.ip_str;
  qDebug()<<usrProfileStruct.avatar_str<<endl;

}


