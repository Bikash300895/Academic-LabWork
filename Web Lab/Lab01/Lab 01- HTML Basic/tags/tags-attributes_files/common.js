var submitCount = 0;

function isMsie4orGreater()
{
 var ua = window.navigator.userAgent;
 var msie = ua.indexOf ("MSIE");
 if (msie > 0)
 {
  return (parseInt (ua.substring (msie+5, ua.indexOf (".", msie))) >= 4);
 }
 else
 {
  return false;
 }
}  

function checkEmail(strEmail)
{
 if (strEmail.length >= 5 && strEmail.indexOf('@') != -1 && strEmail.indexOf('.') != -1)
 {
  var atpos = strEmail.indexOf('@')
  var dotpos = strEmail.indexOf('.', atpos)
  var user = strEmail.substring(0, atpos)
  var domname = strEmail.substring(atpos + 1, dotpos)
  var domlast = strEmail.substring(dotpos + 1)
  if (user.length > 0 && domname.length > 0 && domlast.length > 0)
  {
   return true;
  }
  else
  {
   return false;
  }
 }
 else
 {
  return false;
 }
}

function disableAllButtons()
{
 for(var j = 0; j < document.forms.length; j++)
 {
  for(var i = 0; i < document.forms[j].elements.length; i++)
  {
   if (document.forms[j].elements[i].type == 'submit')
   {
    document.forms[j].elements[i].disabled=true;
   }
  }
 }
}

function showhide(divName, state)
{
 if (document.all)
 {
  eval('document.all.'+divName+'.style.visibility = \''+state+'\'');
 }
 if (document.layers)
 {
  document.layers[divName].visibility = state;
 }
 if (document.getElementById && !document.all)
 {
  temp = document.getElementById(divName);
  temp.style.visibility = state;
 }
}

function checkContact()
{
 if (submitCount == 0)
 {
  if (document.getElementById('contactform').cname.value == '')
  {
   alert('Error! You must write down your name!');
   document.getElementById('contactform').cname.focus();
   return false;
  }
  else
  {
   if (document.getElementById('contactform').cemail.value == '')
   {
    alert('Error! You must write down your e-mail address!');
    document.getElementById('contactform').cemail.focus();
    return false;
   }
   else
   {
    if (!checkEmail(document.getElementById('contactform').cemail.value))
    {
     alert('Error! Your e-mail address has syntax errors!');
     document.getElementById('contactform').cemail.focus();
     return false;
    }
    else
    {
     if (document.getElementById('contactform').cmessage.value == '')
     {
      alert('Error! You must write down a message!');
      document.getElementById('contactform').cmessage.focus();
      return false;
     }
     else
     {
      if (document.getElementById('contactform').ccode.value == '' || document.getElementById('contactform').ccode.value.length != 4)
      {
       alert('Error! The validation code must be 4 characters length!');
       document.getElementById('contactform').ccode.focus();
       return false;
      }
      else
      {
       submitCount+=1;
       disableAllButtons();
       return true;
      }
     }
    }
   }
  }
 }
 else
 {
  return false;
 }
}

function checkSendToAFriend()
{
 if (submitCount == 0)
 {
  if (document.getElementById('sendtoafriendform').syourname.value == '')
  {
   alert('Error! You must input your name!');
   document.getElementById('sendtoafriendform').syourname.focus();
   return false;
  }
  else
  {
   if (!checkEmail(document.getElementById('sendtoafriendform').syouremail.value))
   {
    alert('Error! Your email is not valid!');
    document.getElementById('sendtoafriendform').syouremail.focus();
    return false;
   }
   else
   {
    if (document.getElementById('sendtoafriendform').sfriendname.value == '')
    {
     alert('Error! You must input your friend\'s name!');
     document.getElementById('sendtoafriendform').sfriendname.focus();
     return false;
    }
    else
    {
     if (!checkEmail(document.getElementById('sendtoafriendform').sfriendemail.value))
     {
      alert('Error! Your friend\'s email is not valid!');
      document.getElementById('sendtoafriendform').sfriendemail.focus();
      return false;
     }
     else
     {
      submitCount+=1;
      disableAllButtons();
      return true;
     }
    }
   }
  }
 }
 else
 {
  return false;
 }
}

function showFavorites(url, title)
{
 if (isMsie4orGreater())
 {
  document.write('<a href="'+url+'" onclick="window.external.AddFavorite(\''+url+'\', \''+title+' - HTMLQuick.com\');return false;"><img class="icon" src="http://www.htmlquick.com/img/favorites.gif" width="14" height="14" alt=\"Add to favorites\"> Add to favorites</a>&nbsp;&nbsp;|&nbsp;&nbsp;');
 }
 else
 {
  document.write('CTRL+D to bookmark this page&nbsp;&nbsp;|&nbsp;&nbsp;');
 }
}

function color(strColor)
{
 var i;
 for (i = 0; i < document.getElementById('changeform').elem.length;i++)
 {
  if (document.getElementById('changeform').elem[i].checked) break;
 }
 if (document.getElementById('changeform').elem[i].value == 'back1' || document.getElementById('changeform').elem[i].value == 'back2')
 {
  document.getElementById(document.getElementById('changeform').elem[i].value).style.backgroundColor = '#'+strColor;
  document.getElementById('changeform').elements['color'+document.getElementById('changeform').elem[i].value].value = '#'+strColor;
 }
 else
 {
  if (document.getElementById('changeform').elem[i].value == 'border1')
  {
   document.getElementById('back2').style.borderColor = '#'+strColor;
   document.getElementById('changeform').elements['colorborder1'].value = '#'+strColor;
  }
  else
  {
   document.getElementById(document.getElementById('changeform').elem[i].value).style.color = '#'+strColor;
   document.getElementById('changeform').elements['color'+document.getElementById('changeform').elem[i].value].value = '#'+strColor;
  }
 }
}

function do_something_click(objElement)
{
 objElement.style.color = 'green';
}

function do_something_mouse_over(objElement)
{
 objElement.style.color = 'red';
}