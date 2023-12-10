using clientHTTP.StocksStructures;
using clientHTTP.Utilitare;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace clientHTTP
{
    public partial class Form1 : Form
    {
        private HttpClient _client;
        public static Form1 _instance;
        public DataGridView gridView;

        public Form1()
        {
            _client = HttpClient.getHttpClient();

            InitializeComponent();

            _instance = this;
            gridView = _dataGridViewStockData;
        }

        private void getGoogStockData(object sender, EventArgs e)
        {
            var stockName = _stockName.Text;
            var startingDate = _startTextBox.Text;
            var endingDate = _stopTextBox.Text;

            if (
                string.IsNullOrEmpty(_stockName.Text)
                || !Validator.isDateValid(startingDate)
                || !Validator.isDateValid(endingDate)
            )
            {
                MessageBox.Show("The introduced data is not valid.");
                return;
            }

            var stockDataText = _client.getStockData(stockName, startingDate, endingDate);

           var stockData = StockConvertor.convertFromHttpResponseToArray(stockDataText);

            _dataGridViewStockData.DataSource = stockData;
        }

        private void openGraphWindow(object sender, EventArgs e)
        {
            Form graphWindow = new Graph();
            graphWindow.Show();
        }

        private void openCompareWindow(object sender, EventArgs e)
        {
            this.Hide();
            new Compare().Show();
        }
    }
}
