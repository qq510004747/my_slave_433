
/**
******************************************************************************
* @file   webpge.h
* @author  WIZnet Software Team
* @version V1.0
* @date    2015-xx-xx
* @brief   web服务器现在的内容
* @attention
******************************************************************************
**/
#ifndef __WEBPAGE_H
#define __WEBPAGE_H
#define INDEX_HTML  "<!DOCTYPE html>"\
"<html>"\
"<head>"\
"<title>临沂市华夏高科信息有限公司机柜管理系统网络参数配置</title>"\
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
"<h3>设备网络参数</h3>"\
"<form id='frmSetting' method='POST' action='config.cgi'>"\
"<p><label for='txtIp'>固件版本号:</label><input type='text' id='txtVer' name='ver' size='16' disabled='disabled' /></p>"\
"<p><label for='txtIp'>MAC地址:</label><input type='text' id='txtMac' name='mac' size='16' disabled='disabled' /></p>"\
"<p><label for='txtIp'>IP地址:</label><input type='text' id='txtIp' name='ip' size='16' maxlength='15' /></p>"\
"<p><label for='txtSub'>子网掩码:</label><input type='text' id='txtSub' name='sub' size='16' maxlength='15' /></p>"\
"<p><label for='txtGw'>默认网关:</label><input type='text' id='txtGw' name='gw' size='16' maxlength='15' /></p>"\
"<p><label for='txtport'>设备端口号:</label><input type='text' id='txtport' name='port' size='16' maxlength='5' /></p>"\
"<h4>服务器网络参数</h4>"\
"<p><label for='txtRip'>IP地址:</label><input type='text' id='txtRip' name='Rip' size='16' maxlength='15'  /></p>"\
"<p><label for='txtRport'>端口号:</label><input type='text' id='txtRport' name='Rport' size='16' maxlength='5'  /></p>"\
"<h4>GPRS服务器网络参数</h4>"\
"<p><label for='txtGip'>IP地址:</label><input type='text' id='txtGip' name='Gip' size='16' maxlength='15' /></p>"\
"<p><label for='txtGport'>端口号:</label><input type='text' id='txtGport' name='Gport' size='16' maxlength='5' /></p>"\
"<p><input type='submit' value='保存并重启' /></p>"\
"<h4>修改设备名称和密码</h4>"\
"<p><label for='txtAdmin'>设备名:</label><input type='text' placeholder='新设备名称' id='txtAdmin' name='admin' size='16' maxlength='6' /></p>"\
"<p><label for='txtPassword'>密码:</label><input type='password' placeholder='新登录密码' id='txtPassword' name='password' size='16' maxlength='6'/></p>"\
"<p><input type='submit' value='确定并重启' /> </p>"\
"</div>"\
"</form>"\
"<div style='background:snow; display:block;padding:10px 20px; width: 400px; margin-right: 10px; float: left;'>"\
"<h3>系统运行状态</h3>"\
"<form id='frmSetting' method='POST' action='config.cgi'>"\
"<p><label for='txtDerstatus'>设备状态:</label><input type='text' id='txtDerstatus' name='Derstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtNetstatus'>网络状态:</label><input type='text' id='txtNetstatus' name='Netstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtGPRSstatus'>GPRS状态:</label><input type='text' id='txtGPRSstatus' name='GPRSstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtGPSstatus'>GPS状态:</label><input type='text' id='txtGPSstatus' name='GPSstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtTemp'>温度:</label><input type='text' id='txtTemp' name='Temp' size='16' disabled='disabled' /></p>"\
"<p><label for='txtHumidity'>湿度:</label><input type='text' id='txtHumidity' name='txtHumidity' size='16' disabled='disabled' /></p>"\
"<p><label for='txtGmstatus'>柜门状态:</label><input type='text' id='txtGmstatus' name='Gmstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtWaterstatus'>浸水状态:</label><input type='text' id='txtWaterstatus' name='Waterstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtCH1status'>CH1状态:</label><input type='text' id='txtCH1status' name='CH1status' size='16' disabled='disabled' /></p>"\
"<p><label for='txtCH2status'>CH2状态:</label><input type='text' id='txtCH2status' name='CH2status' size='16' disabled='disabled'  /></p>"\
"<p><label for='txtTDKG'>降温开关状态:</label><input type='text' id='txtTDKG' name='TDKG' size='16'disabled='disabled'  /></p>"\
"<p><label for='txtCSKG'>除湿开关状态:</label><input type='text' id='txtCSKG' name='CSKG' size='16' disabled='disabled' /></p>"\
"<p><label for='txtTUKG'>升温开关状态:</label><input type='text' id='txtTUKG' name='TUKG' size='16' disabled='disabled'  /></p>"\
"<p><label for='txtJSKG'>加湿开关状态:</label><input type='text' id='txtJSKG' name='JSKG' size='16' disabled='disabled' /></p>"\
"<p><label for='txtCHZstatus'>重合闸状态:</label><input type='text' id='txtCHZstatus' name='CHZstatus' size='16' disabled='disabled' /></p>"\
"<p><label for='txtCHZvin'>重合闸电压:</label><input type='text' id='txtCHZvin' name='CHZvin' size='16' disabled='disabled' /></p>"\
"<p><label for='txtCHZcur'>重合闸电流:</label><input type='text' id='txtCHZcur' name='CHZcur' size='16' disabled='disabled'  /></p>"\
"<p><label for='txtCHZleak'>重合闸漏电:</label><input type='text' id='txtCHZleak' name='CHZleak' size='16' disabled='disabled'  /></p>"\
"</form>"\
"</div>"\
"<div style='background:snow; display:block;padding:10px 30px; width: 400px; margin-right: 10px; float: left;'>"\
"<h3>电源状态信息</h3>"\
"<form id='frmSetting' method='POST' action='config.cgi'>"\
"<p><label for='txtPwrstatus'>电源模块状态:</label><input type='text' id='txtPwrstatus' name='Pwrstatus' size='16' disabled='disabled' style='width: 140px;' /></p>"\
"<p><label for='txtPwrCH1S'>电源通道1状态:</label><input type='text' id='txtPwrCH1S' name='PwrCH1S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"<p><label for='txtPwrCH2S'>电源通道2状态:</label><input type='text' id='txtPwrCH2S' name='PwrCH2S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"<p><label for='txtPwrCH3S'>电源通道3状态:</label><input type='text' id='txtPwrCH3S' name='PwrCH3S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"<p><label for='txtPwrCH4S'>电源通道4状态:</label><input type='text' id='txtPwrCH4S' name='PwrCH4S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"<p><label for='txtPwrCH5S'>电源通道5状态:</label><input type='text' id='txtPwrCH5S' name='PwrCH5S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"<p><label for='txtPwrCH6S'>电源通道6状态:</label><input type='text' id='txtPwrCH6S' name='PwrCH6S' size='16' disabled='disabled' style='width: 140px;'/></p>"\
"</div>"\
"</div>"\
"</div>"\
"</div>"\
"</form>"\
"</div>"\
"<div style='margin:5px 5px; display: inline-block; width: 100%; padding: 35px; text-align: center;'>"\
"&copy;Copyright 2016 by 临沂市华夏高科信息有限公司"\
"</div>"\
"<script type='text/javascript' src='w5500.js'></script>"\
"</body>"\
"</html>"

#define Admin_HTML  "<!DOCTYPE html>"\
"<html>"\
"<head>"\
"<title>临沂市华夏高科信息有限公司机柜管理系统</title>"\
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
"<h3>智能机柜管理系统</h3>"\
"<form id='frmSetting' method='POST' action='config.cgi'>"\
"<p><label for='txtAdmin'>设备名:</label><input type='text' placeholder='用户名' id='txtAdmin' name='admin' size='16' /></p>"\
"<p><label for='txtPassword'>密码:  </label><input type='password' placeholder='密码' id='txtPassword' name='password' size='16' /></p>"\
"<p><input type='submit' value='登录' /></p>"\
"</form>"\
"</div>"\
"</div>"\
"<div style='margin:5px 5px;'>"\
"&copy;Copyright 2016 by 临沂市华夏高科信息有限公司"\
"</div>"\
"<script type='text/javascript' src='w5500.js'></script>"\
"</body>"\
"</html>"
#endif
