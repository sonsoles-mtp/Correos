SCR01_TR00_EMBARRIADO_CITYPAQ()
{
	web_set_sockets_option("SSL_VERSION", "2&3");
	web_set_max_html_param_len("50000");
	
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	lr_think_time(3);
	
	web_reg_find("Text=Asignado correctamente", LAST);
	
	// {"data":{"isPickup":false,"response":"KO","message":"Env\xC3\xADo indocumentado."}
	
	lr_start_transaction("SCR01_TR02_EMBARRIADO_CITYPAQ_ASSIGMENT");
	
	web_rest("POST: https://api1-intapp.correospre.es/logistics/logist...",
		"URL=https://api1-intapp.correospre.es/logistics/logistics/api/v1/assignment",
		"Method=POST",
		"EncType=raw",
		"Body={\r\n"
		"\"adminMode\": true,\r\n"
		//"\"assignmentDate\": \"${__time(YYYY-MM-dd,fecha_actual)}T${__time(HH:MM:ss,hora_actual)}+0100\",\r\n"
		"\"assignmentDate\": \"{fec_actual}\",\r\n"
		"\"deliveryManCode\": \"P001234\",\r\n"
		"\"device\": \"2738632764\",\r\n"
		"\"interfaceId\": \"AI00001\",\r\n"
		"\"itemId\": \"{cod_bulto_citypaq}\",\r\n"
		//"\"language\": \"Español\",\r\n"
		"\"language\": \"Espa&#241;ol\",\r\n"
		"\"latitude\": 23.5,\r\n"
		"\"longitude\": 12.4,\r\n"
		"\"route\": \"{id_ruta_citypaq}\",\r\n"
		"\"centerCode\": \"{cod_centro_citypaq}\",\r\n"
		"\"onRoute\": false,\r\n"
		"\"userCode\": \"E012345\",\r\n"
		"\"changeProduct\": 0\r\n"
		"}\r\n",
		HEADERS,
		"Name=Authorization", "Value=Bearer {token}", ENDHEADER,
		"Name=Content-Type", "Value=application/json", ENDHEADER,
		LAST);

	lr_end_transaction("SCR01_TR02_EMBARRIADO_CITYPAQ_ASSIGMENT",LR_AUTO);
	
//	lr_start_transaction("SCR01_EMBARRIADO_CITYPAQ_LIBERARHUCO_SHIVA");
//	
//	web_rest("POST: https://api1-intapp.correospre.es/logistics/doors/...",
//		"URL=https://api1-intapp.correospre.es/logistics/doors/api/v1/management/releasePackage",
//		"Method=POST",
//		"EncType=raw",
//		"Body={\r\n"
//		"\t\"packageCode\": \"${citypaq1_itemid}\"\r\n"
//		"}",
//		HEADERS,
//		"Name=Authorization", "Value=Bearer {token}", ENDHEADER,
//		"Name=Content-Type", "Value=application/json", ENDHEADER,
//		LAST);
//
//	lr_end_transaction("SCR01_EMBARRIADO_CITYPAQ_LIBERARHUCO_SHIVA",LR_AUTO);
	
	return 0;
}
