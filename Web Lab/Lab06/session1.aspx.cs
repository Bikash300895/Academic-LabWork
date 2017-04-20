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


public partial class session1 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["name"] != null)
        {
            show_s.Text = "the session value = "+Convert.ToString(Session["name"]);
        }
        else
        {
            show_s.Text = "there is no name in the session variable";
        }
    }
    protected void set_session_Click(object sender, EventArgs e)
    {
        Session["name"] = name.Text;
        show_s.Text ="the session value = " + Convert.ToString(Session["name"]);
    }
}
