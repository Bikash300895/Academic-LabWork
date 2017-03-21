function preloadImages() {if (document.images) {for (var i = 0; i < preloadImages.arguments.length; i++) {(new Image()).src = preloadImages.arguments[i];}}}
preloadImages('/im/tnav/bg.png','/im/tm/bg.jpg','/im/snav/bgnew.jpg','/im/snav/bgmidnew.jpg','/im/snav/mid.jpg','/im/snav/whbrn8x8a.gif');
if (top.location != self.location) {top.location.replace(self.location);}
if (top.location.host != self.location) {top.location.host.replace(self.location);}
function toggleMenu(currMenu) {
if (document.getElementById) {thisMenu = document.getElementById(currMenu).style
if (thisMenu.display == "block") {thisMenu.display = "none"}
else {thisMenu.display = "block"}
return false}
else {return true}
}
/* ---------------------------
AutoBlink. Puts Google's Autolink on the Blink :) . (c) 2005 Chris Ridings http://www.searchguild.com. Redistribute at will but leave this message intact */
var linkcount;
function checklinks() {
if (!(linkcount==document.links.length)) {
for (i=0; i < document.links.length; i++) {
if (document.links[i].id.substring(0,5)=="_goog") {
var tr = document.links[i].parentTextEdit.createTextRange();tr.moveToElementText(document.links[i]);tr.execCommand("Unlink",false);tr.execCommand("Unselect",false);
			}
		}
	}
setTimeout("checklinks()",500);}
if (document.getElementById && document.createElement) {linkcount=document.links.length;setTimeout("checklinks()",500);}