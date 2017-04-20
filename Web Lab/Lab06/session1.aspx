<%@ Page Language="C#" AutoEventWireup="true" CodeFile="session1.aspx.cs" Inherits="session1" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server" >
    <div>
    
        <br />
        <asp:Label ID="show_s" runat="server"></asp:Label>
        <br />
        <br />
        <br />
        Name:
        <asp:TextBox ID="name" runat="server"></asp:TextBox>
        <br />
        <asp:Button ID="set_session" runat="server" onclick="set_session_Click" 
            Text="set Session" />
        <br />
        
    
    </div>
    </form>
    
</body>
</html>
