SCR02_TR00_LIQUIDACION_NOTIFICACIONES()
{
	web_set_sockets_option("SSL_VERSION", "2&3");
	web_set_max_html_param_len("50000");
	
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	
	lr_think_time(3);
	
	web_reg_find("Text=createdOn", LAST);
	
	lr_start_transaction("SCR02_TR02_LIQUIDACION_NOTIFICACIONES_DELIVERY");
	
	web_rest("POST: https://api1-intapp.correospre.es/logistics/logist...",
		"URL=https://api1-intapp.correospre.es/logistics/logistics/api/v1/delivery",
		"Method=POST",
		"EncType=raw",
		"Body={\r\n"
		"\"Delivery pods\": [\r\n"
		"{\r\n"
		//"\"deliveryDate\": \"${__time(YYYY-MM-dd,fecha_actual)}T${__time(HH:MM:ss,hora_actual)}+0100\"\r\n"
		"\"deliveryDate\": \"{fec_actual}\"\r\n"
		"}\r\n"
		"],\r\n"
		"\"assignedDeliveryPerson\": \"D0001\",\r\n"
		"\"centerId\": \"{cod_centro_notificacion}\",\r\n"
		"\"changeProduct\": 0,\r\n"
		"\"codired\": \"CR001\",\r\n"
		"\"deliveryMethod\": 1,\r\n"
		"\"email\": \"example@correos.com\",\r\n"
		"\"firm\": 1,\r\n"
		"\"gps\": {\r\n"
		"\"date\": \"2021-10-15T18:25:43+0100\",\r\n"
		"\"latitude\": 23.32,\r\n"
		"\"longitude\": 23.32\r\n"
		"},\r\n"
		"\"groupId\": {groupid_notificacion},\r\n"
		"\"itemCode\": \"{itemid_notificacion}\",\r\n"
		//"\"itemsQuantity\": {num_bulto_notificacion},\r\n"
		"\"itemsQuantity\": 1,\r\n"
		"\"route\": \"{ruta_notificacion}\",\r\n"
		//"\"serviceDate\": \"${__time(YYYY-MM-dd,fecha_actual)}T${__time(HH:MM:ss,hora_actual)}+0100\",\r\n"
		"\"serviceDate\": \"{fec_actual}\",\r\n"
		"\"warningCode\": \"ARR001\"\r\n"
		"}\r\n",
		HEADERS,
		"Name=Authorization", "Value=Bearer {token}", ENDHEADER,
		"Name=Content-Type", "Value=application/json", ENDHEADER,
		LAST);
		

	lr_end_transaction("SCR02_TR02_LIQUIDACION_NOTIFICACIONES_DELIVERY",LR_AUTO);
	
	lr_think_time(3);
	
	lr_start_transaction("SCR02_TR03_LIQUIDACION_NOTIFICACIONES_UNITRETURNS");
	
	web_rest("POST: https://api1-intapp.correospre.es/logistics/logist...",
		"URL=https://api1-intapp.correospre.es/logistics/logistics/api/v1/unitreturns",
		"Method=POST",
		"EncType=raw",
		"Body={\r\n"
		//"\"date\": \"${__time(YYYY-MM-dd,fecha_actual)}T${__time(HH:MM:ss,hora_actual)}+0100\",\r\n"
		"\"date\": \"{fec_actual}\",\r\n"
		"\"deviceCode\": \"PDA1458763\",\r\n"
		"\"interfaceCode\": \"INT5248967\",\r\n"
		"\"route\": \"{ruta_notificacion}\",\r\n"
		"\"userCode\": \"P001234\",\r\n"
		"\"centerId\": \"{cod_centro_notificacion}\"\r\n"
		"}\r\n",
		HEADERS,
		"Name=Authorization", "Value=Bearer {token}", ENDHEADER,
		"Name=Content-Type", "Value=application/json", ENDHEADER,
		LAST);
	
	
	lr_end_transaction("SCR02_TR03_LIQUIDACION_NOTIFICACIONES_UNITRETURNS",LR_AUTO);
	
	return 0;
}
