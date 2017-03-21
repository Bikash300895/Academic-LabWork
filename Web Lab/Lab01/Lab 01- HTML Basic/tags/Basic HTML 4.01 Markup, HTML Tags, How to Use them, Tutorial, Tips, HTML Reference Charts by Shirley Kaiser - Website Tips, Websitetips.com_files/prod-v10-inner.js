(function() {
amznUts.refPage = document.location.toString();
amznUts.refPage = encodeHTML(encodeURIComponent(amznUts.refPage));
amznUts.DomainId = encodeHTML(encodeURIComponent(amznUts.DomainId));
amznUts.EntityId = encodeHTML(encodeURIComponent(amznUts.EntityId));
amznUts.TransientId = encodeHTML(encodeURIComponent(amznUts.TransientId));
amznUts.DefinitiveId = encodeHTML(encodeURIComponent(amznUts.DefinitiveId));
amznUts.EventId = encodeHTML(encodeURIComponent(amznUts.EventId));
amznUts.PageId = encodeHTML(encodeURIComponent(amznUts.PageId));
amznUts.njh = encodeHTML(encodeURIComponent(amznUts.njh));
var cbuster = Math.random()*10000000000000000;
var varsToPass = "dmnId="+amznUts.DomainId
+"&tId="+amznUts.TransientId
+"&dId="+amznUts.DefinitiveId
+"&enId="+amznUts.EntityId
+"&eId="+amznUts.EventId
+"&pId="+amznUts.PageId
+"&rP="+amznUts.refPage
+"&njh="+amznUts.njh
+"&cB="+cbuster;
var svcHostname = "uts.amazon.com";
var imgHostname = "g-ecx.images-amazon.com";
var imgPath = "/images/G/01/x-locale/personalization/uts/flash/PTv8.swf";
var protocol = "http";
if( document.location.toString().indexOf( 'https://' ) != -1 ) {
protocol = "https";
imgHostname = "images-na.ssl-images-amazon.com";  
} 
if (typeof swfobject != 'undefined' && swfobject.hasFlashPlayerVersion("9.0.0")) {
var fn = function() {
try {
var att = { data: protocol+"://"+imgHostname+imgPath, width:"1", height:"1" };
var par = { flashvars: varsToPass, allowScriptAccess: "always" };
var id = "utsFlashContent";
var swf1 = swfobject.createSWF(att, par, id);
} catch (e) {
return;
}
}
try {
var d1 = document.createElement('div');
d1.id = "utsFlashContent";
document.getElementsByTagName("body")[0].appendChild(d1);
} catch (e) {
return;
}
fn();
} else {
var script = document.createElement('script');
script.type = "text/javascript";
script.src = protocol+"://"+svcHostname+"/uts/IaR?"+varsToPass; 
document.getElementsByTagName("head")[0].appendChild(script);
}
function encodeHTML(inputStr) {
if (!inputStr) return inputStr;
var myStr= inputStr;
myStr = (myStr.replace(/&/g, '&amp;')
.replace(/\"/g, '&quot;')
.replace(/</g, '&lt;')
.replace(/>/g, '&gt;'));
return myStr;
}
})();
function utsIH(str) {
var imgHostname = "g-ecx.images-amazon.com";
var protocol = "http";
if( document.location.toString().indexOf( 'https://' ) != -1 ) {
protocol = "https";
imgHostname = "images-na.ssl-images-amazon.com";  
} 
var utsImageHack = document.createElement('img');
utsImageHack.src = protocol+'://'+imgHostname+'/images/G/01/gateway/1x1_trans.gif';
utsImageHack.id = 'utsImageHack';
utsImageHack.style.display = 'none';
document.getElementsByTagName("body")[0].appendChild(utsImageHack);
}
