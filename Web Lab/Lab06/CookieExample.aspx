<%@ Page language="c#" src="CookieExample.aspx.cs" AutoEventWireup="false" Inherits="YourNamespace.CookieExample" %>
<HTML>
  <body>
    <form id="Form1" method="post" runat="server">
      <asp:Label id="lblWelcome" style="Z-INDEX: 100; LEFT: 16px; POSITION: absolute; TOP: 24px"
        runat="server" Width="412px" Height="130px" BackColor="LightYellow" Font-Size="Medium"
        Font-Names="Verdana" BorderWidth="2px" BorderStyle="Groove"></asp:Label>
      <asp:Button id="Button1" style="Z-INDEX: 105; LEFT: 288px; POSITION: absolute; TOP: 264px" runat="server"
        Width="137px" Text="Submit Page"></asp:Button>
      <asp:TextBox id="txtName" style="Z-INDEX: 101; LEFT: 96px; POSITION: absolute; TOP: 200px" runat="server"
        Width="184px" Height="24px"></asp:TextBox>
      <asp:Button id="cmdStore" style="Z-INDEX: 103; LEFT: 288px; POSITION: absolute; TOP: 200px"
        runat="server" Width="137px" Text="Create Cookie"></asp:Button>
      <asp:Label id="Label1" style="Z-INDEX: 104; LEFT: 24px; POSITION: absolute; TOP: 204px" runat="server"
        Width="56px" Height="16px" Font-Size="X-Small" Font-Names="Verdana">Name:</asp:Label>
    </form>
  </body>
</HTML>

