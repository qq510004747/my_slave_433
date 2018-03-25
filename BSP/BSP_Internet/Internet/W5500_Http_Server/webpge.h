
/**
******************************************************************************
* @file   webpge.h
* @author  WIZnet Software Team
* @version V1.0
* @date    2015-xx-xx
* @brief   web���������ڵ�����
* @attention
******************************************************************************
**/
#ifndef __WEBPAGE_H
#define __WEBPAGE_H
#define INDEX_HTML  "<!DOCTYPE html>"\
"<html>"\
"<head>"\
"<title>�����л��ĸ߿���Ϣ���޹�˾�������ϵͳ�����������</title>"\
"<meta http-equiv='Content-Type' content='text/html; charset=GB2312'/>"\
"<style type='text/css'>"\
"body {text-align:left; background-color:#c0deed;font-family:Verdana;}"\
"#main {margin-right:auto;margin-left:auto;margin-top:30px;}"\
"label{display:inline-block;width:150px;}"\
"#main h3{color:#66b3ff; text-decoration:underline;}"\
"</style>"\
"<script>"\
"function $(id) { return document.getElementById(id); };"\
"function settingsCallback(o) {"\
"if ($('txtVer')) $('txtVer').value = o.ver;"\
"if ($('txtMac')) $('txtMac').value = o.mac;"\
"if ($('txtIp')) $('txtIp').value = o.ip;"\
"if ($('txtSub')) $('txtSub').value = o.sub;"\
"if ($('txtGw')) $('txtGw').value = o.gw;"\
"if ($('txtport')) $('txtport').value = o.port;"\
"if ($('txtRip')) $('txtRip').value = o.Rip;"\
"if ($('txtRport')) $('txtRport').value = o.Rport;"\
"if ($('txtGip')) $('txtGip').value = o.Gip;"\
"if ($('txtGport')) $('txtGport').value = o.Gport;"\
"if ($('txtDerstatus')) $('txtDerstatus').value = o.Derstatus;"\
"if ($('txtNetstatus')) $('txtNetstatus').value = o.Netstatus;"\
"if ($('txtGPRSstatus')) $('txtGPRSstatus').value = o.GPRSstatus;"\
"if ($('txtGPSstatus')) $('txtGPSstatus').value = o.GPSstatus;"\
"if ($('txtTemp')) $('txtTemp').value = o.Temp;"\
"if ($('txtHumidity')) $('txtHumidity').value = o.Humidity;"\
"if ($('txtGmstatus')) $('txtGmstatus').value = o.Gmstatus;"\
"if ($('txtWaterstatus')) $('txtWaterstatus').value = o.Waterstatus;"\
"if ($('txtCH1status')) $('txtCH1status').value = o.CH1status;"\
"if ($('txtCH2status')) $('txtCH2status').value = o.CH2status;"\
"if ($('txtTDKG')) $('txtTDKG').value = o.TDKG;"\
"if ($('txtCSKG')) $('txtCSKG').value = o.CSKG;"\
"if ($('txtTUKG')) $('txtTUKG').value = o.TUKG;"\
"if ($('txtJSKG')) $('txtJSKG').value = o.JSKG;"\
"if ($('txtCHZstatus')) $('txtCHZstatus').value = o.CHZstatus;"\
"if ($('txtCHZvin')) $('txtCHZvin').value = o.CHZvin;"\
"if ($('txtCHZcur')) $('txtCHZcur').value = o.CHZcur;"\
"if ($('txtCHZleak')) $('txtCHZleak').value = o.CHZleak;"\
"if ($('txtPwrstatus')) $('txtPwrstatus').value = o.Pwrstatus;"\
"if ($('txtPwrCH1S')) $('txtPwrCH1S').value = o.PwrCH1S;"\
"if ($('txtPwrCH2S')) $('txtPwrCH2S').value = o.PwrCH2S;"\
"if ($('txtPwrCH3S')) $('txtPwrCH3S').value = o.PwrCH3S;"\
"if ($('txtPwrCH4S')) $('txtPwrCH4S').value = o.PwrCH4S;"\
"if ($('txtPwrCH5S')) $('txtPwrCH5S').value = o.PwrCH5S;"\
"if ($('txtPwrCH6S')) $('txtPwrCH6S').value = o.PwrCH6S;"\
"};"\
"</script>"\
"</head>"\
"<body>"\
"<div id='main'>"\
"<div style='background:snow; display:block;padding:10px 20px; width: 400px; margin-right: 10px; float: left;'>"\
"<h3>�豸�������</h3>"\
"<form id='frmSetting' method='POST' action='config.cgi'>"\
"<p><label for='txtIp'>�̼��汾��:</label><input type='text' id='txtVer' name='ver' size='16' disabled='disabled' /></p>"\
"<p><label for='txtIp'>MAC��ַ:</label><input type='text' id='txtMac' name='mac' size='16' disabled='disabled' /></p>"\
"<p><label for='txtIp'>IP��ַ:</label><input type='text' id='txtIp' name='ip' size='16' maxlength='15' /></p>"\
"<p><label for='txtSub'>��������:</label><input type='text' id='txtSub' name='sub' size='16' maxlength='15' /></p>"\
"<p><label for='txtGw'>Ĭ������:</label><input type='text' id='txtGw' name='gw' size='16' maxlength='15' /></p>"\
"<p><label for='txtport'>�豸�˿ں�:</label><input type='text' id='txtport' name='port' size='16' maxlength='5' /></p>"\
"<h4>�������������</h4>"\
"<p><label for='txtRip'>IP��ַ:</label><input type='text' id='txtRip' name='Rip' size='16' maxlength='15'  /></p>"\
"<p><label for='txtRport'>�˿ں�:</label><input type='text' id='txtRport' name='Rport' size='16' maxlength='5'  /></p>"\
"<h4>GPRS�������������</h4>"\
"<p><label for='txtGip'>IP��ַ:</label><input type='text' id='txtGip' name='Gip' size='16' maxlength='15' /></p>"\
"<p><label for='txtGport'>�˿ں�:</label><input type='text' id='txtGport' name='Gport' size='16' maxlength='5' /></p>"\
"<p><input type='submit' value='���沢����' /></p>"\
"<h4>�޸��豸���ƺ�����</h4>"\
"<p><label for='txtAdmin'>�豸��:</label><input type='text' placeholder='���豸����' id='txtAdmin' name='admin' size='16' maxlength='6' /></p>"\
"<p><label for='txtPassword'>����:</label><input type='password' placeholder='�µ�¼����' id='txtPassword' name='password' size='16' maxlength='6'/></p>"\
"<p><input type='submit' value='ȷ��������' /> </p>"\
"</div>"\
"</form>"\
"<div style='background:snow; display:block;padding:10px 20px; width: 400px; margin-right: 10px; float: left;'>"\
"<h3>ϵͳ����״̬</h3>"\
"<form id='frmSetting' method='POST' action='config.cgi'>"\
"<p><label for='txtDerstatus'>�豸״̬:</label><input type='text' id='txtDerstatus' name='Derstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtNetstatus'>����״̬:</label><input type='text' id='txtNetstatus' name='Netstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtGPRSstatus'>GPRS״̬:</label><input type='text' id='txtGPRSstatus' name='GPRSstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtGPSstatus'>GPS״̬:</label><input type='text' id='txtGPSstatus' name='GPSstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtTemp'>�¶�:</label><input type='text' id='txtTemp' name='Temp' size='16' disabled='disabled' /></p>"\
"<p><label for='txtHumidity'>ʪ��:</label><input type='text' id='txtHumidity' name='txtHumidity' size='16' disabled='disabled' /></p>"\
"<p><label for='txtGmstatus'>����״̬:</label><input type='text' id='txtGmstatus' name='Gmstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtWaterstatus'>��ˮ״̬:</label><input type='text' id='txtWaterstatus' name='Waterstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtCH1status'>CH1״̬:</label><input type='text' id='txtCH1status' name='CH1status' size='16' disabled='disabled' /></p>"\
"<p><label for='txtCH2status'>CH2״̬:</label><input type='text' id='txtCH2status' name='CH2status' size='16' disabled='disabled'  /></p>"\
"<p><label for='txtTDKG'>���¿���״̬:</label><input type='text' id='txtTDKG' name='TDKG' size='16'disabled='disabled'  /></p>"\
"<p><label for='txtCSKG'>��ʪ����״̬:</label><input type='text' id='txtCSKG' name='CSKG' size='16' disabled='disabled' /></p>"\
"<p><label for='txtTUKG'>���¿���״̬:</label><input type='text' id='txtTUKG' name='TUKG' size='16' disabled='disabled'  /></p>"\
"<p><label for='txtJSKG'>��ʪ����״̬:</label><input type='text' id='txtJSKG' name='JSKG' size='16' disabled='disabled' /></p>"\
"<p><label for='txtCHZstatus'>�غ�բ״̬:</label><input type='text' id='txtCHZstatus' name='CHZstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtCHZvin'>�غ�բ��ѹ:</label><input type='text' id='txtCHZvin' name='CHZvin' size='16' disabled='disabled' /></p>"\
"<p><label for='txtCHZcur'>�غ�բ����:</label><input type='text' id='txtCHZcur' name='CHZcur' size='16' disabled='disabled'  /></p>"\
"<p><label for='txtCHZleak'>�غ�բ©��:</label><input type='text' id='txtCHZleak' name='CHZleak' size='16' disabled='disabled'  /></p>"\
"</form>"\
"</div>"\
"<div style='background:snow; display:block;padding:10px 30px; width: 400px; margin-right: 10px; float: left;'>"\
"<h3>��Դ״̬��Ϣ</h3>"\
"<form id='frmSetting' method='POST' action='config.cgi'>"\
"<p><label for='txtPwrstatus'>��Դģ��״̬:</label><input type='text' id='txtPwrstatus' name='Pwrstatus' size='16' disabled='disabled' style='width: 140px;' /></p>"\
"<p><label for='txtPwrCH1S'>��Դͨ��1״̬:</label><input type='text' id='txtPwrCH1S' name='PwrCH1S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"<p><label for='txtPwrCH2S'>��Դͨ��2״̬:</label><input type='text' id='txtPwrCH2S' name='PwrCH2S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"<p><label for='txtPwrCH3S'>��Դͨ��3״̬:</label><input type='text' id='txtPwrCH3S' name='PwrCH3S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"<p><label for='txtPwrCH4S'>��Դͨ��4״̬:</label><input type='text' id='txtPwrCH4S' name='PwrCH4S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"<p><label for='txtPwrCH5S'>��Դͨ��5״̬:</label><input type='text' id='txtPwrCH5S' name='PwrCH5S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"<p><label for='txtPwrCH6S'>��Դͨ��6״̬:</label><input type='text' id='txtPwrCH6S' name='PwrCH6S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"</div>"\
"</div>"\
"</div>"\
"</div>"\
"</form>"\
"</div>"\
"<div style='margin:5px 5px; display: inline-block; width: 100%; padding: 35px; text-align: center;'>"\
"&copy;Copyright 2016 by �����л��ĸ߿���Ϣ���޹�˾"\
"</div>"\
"<script type='text/javascript' src='w5500.js'></script>"\
"</body>"\
"</html>"

#define Admin_HTML  "<!DOCTYPE html>"\
"<html>"\
"<head>"\
"<title>�����л��ĸ߿���Ϣ���޹�˾�������ϵͳ</title>"\
"<meta http-equiv='Content-Type' content='text/html; charset=GB2312'/>"\
"<style type='text/css'>"\
"body {text-align:left; background-color:#c0deed;font-family:Verdana;}"\
"#main {margin-right:auto;margin-left:auto;margin-top:30px;}"\
"label{display:inline-block;width:150px;}"\
"#main h3{color:#66b3ff; text-decoration:underline;}"\
"</style>"\
"<script>"\
"function $(id) { return document.getElementById(id); };"\
"function settingsCallback(o) {"\
"if ($('txtAdmin')) $('txtAdmin').value = o.admin;"\
"if ($('txtPassword')) $('txtPassword').value = o.password;"\
"};"\
"</script>"\
"</head>"\
"<body>"\
"<div id='main'>"\
"<div style='background:snow; display:block;padding:10px 20px;'>"\
"<h3>���ܻ������ϵͳ</h3>"\
"<form id='frmSetting' method='POST' action='config.cgi'>"\
"<p><label for='txtAdmin'>�豸��:</label><input type='text' placeholder='�û���' id='txtAdmin' name='admin' size='16' /></p>"\
"<p><label for='txtPassword'>����:  </label><input type='password' placeholder='����' id='txtPassword' name='password' size='16' /></p>"\
"<p><input type='submit' value='��¼' /></p>"\
"</form>"\
"</div>"\
"</div>"\
"<div style='margin:5px 5px;'>"\
"&copy;Copyright 2016 by �����л��ĸ߿���Ϣ���޹�˾"\
"</div>"\
"<script type='text/javascript' src='w5500.js'></script>"\
"</body>"\
"</html>"
#endif
