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
            Settings settings = new Settings("settings.txt");

            var server = settings.getServerAddress();
            var host = settings.getServerPort();

            _client = new HttpClient($"http://{server}:{host}/");

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

            char[] delimitersNewLine = { '\n' };
            var stockDataLines = stockDataText.Split(delimitersNewLine);

            var stockData = new List<Stock>(stockDataLines.Length);
            for (var i = 0; i < stockDataLines.Length - 1; ++i)
            {
                char[] delimData = { ',' };
                var data = stockDataLines[i].Split(delimData);

                stockData.Add(
                    new Stock()
                    {
                        Date = data[0],
                        Open = data[1],
                        High = data[2],
                        Low = data[3],
                        Close = data[4],
                        AdjClose = data[5],
                        Volume = data[6],
                    }
                );
            }

            _dataGridViewStockData.DataSource = stockData;
        }

        private void openGraphWindow(object sender, EventArgs e)
        {
            Form graphWindow = new Graph();
            graphWindow.Show();
        }
    }
}
