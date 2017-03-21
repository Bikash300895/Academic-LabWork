if(document.referrer!='' && document.referrer.indexOf("http://www.apachefriends.org")!=0)
{
	var r="referer="+escape(document.referrer);
	document.open();
	document.write("<script language=\"JavaScript\" type=\"text/javascript\" src=\"http://www.apachefriends.org/minireferer.php?"+r+"\"></script>");
	document.close();
}
