using System;
using System.Collections;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

public partial class session2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        
        show.Text="the session value =" + Convert.ToString(Session["name"]);
        Session["name"] = Session["name"] + " 5";
        
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Session.Remove("name");
        show.Text = "session value is removed";
    }
}
