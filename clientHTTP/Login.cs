using clientHTTP.Structures;
using clientHTTP.Utilitare;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace clientHTTP
{
    public partial class Login : Form
    {
        private HttpClient _httpClient;

        public Login()
        {
            Settings settings = Settings.getSettings();

            var server = settings.getServerAddress();
            var host = settings.getServerPort();

            _httpClient = HttpClient.getHttpClient();

            InitializeComponent();
        }

        private void loginEvent(object sender, EventArgs e)
        {
            string loginStatus = _httpClient.login(new Credentials(_username.Text, _password.Text));
            _statusTextBox.Text = loginStatus;

            if (loginStatus == "Loged in succesfully")
            {
                this.Hide();
                new Form1().Show();
            }
        }
    }
}
