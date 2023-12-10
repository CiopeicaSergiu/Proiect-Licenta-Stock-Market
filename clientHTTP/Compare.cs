using clientHTTP.StocksStructures;
using clientHTTP.Utilitare;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace clientHTTP
{
    public partial class Compare : Form
    {
        HttpClient _client;

        public Compare()
        {
            Settings settings = Settings.getSettings();

            var server = settings.getServerAddress();
            var host = settings.getServerPort();

            _client = HttpClient.getHttpClient();
            InitializeComponent();
        }

        private void addStockForCompare(object sender, EventArgs e)
        {
            _compareA.Items.Add(_addStockTextBox.Text);
            _compareB.Items.Add(_addStockTextBox.Text);
        }

        private void compareStocks(object sender, EventArgs e)
        {
            string stockA = _client.getStockData(_compareA.Text, _startingDate.Text, _endingDate.Text);
            string stockB = _client.getStockData(_compareB.Text, _startingDate.Text, _endingDate.Text);

            var stockAList = StockConvertor.convertFromHttpResponseToArray(stockA);
            var stockBList = StockConvertor.convertFromHttpResponseToArray(stockB);

            for (var i = 0; i < stockAList.Count; ++i)
            {
                _compareChart.Series["StockA"].Points.AddXY(stockAList[i].Date, Double.Parse(stockAList[i].High));
                _compareChart.Series["StockB"].Points.AddXY(stockBList[i].Date, Double.Parse(stockBList[i].High));
            }
        }
    }
}
