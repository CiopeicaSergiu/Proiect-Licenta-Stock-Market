using clientHTTP.StocksStructures;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace clientHTTP
{
    public partial class Graph : Form
    {
        public Graph()
        {
            InitializeComponent();
            loadDataInGraph();
        }

        private void closeGraphWindow(object sender, EventArgs e)
        {
            this.Close();
        }

        private void loadDataInGraph()
        {
            var stockData = Form1._instance.gridView.DataSource as List<Stock>;
            _stockDataChart.Series["StockValue"].Points.Clear();

            foreach (var stock in stockData)
            {
                _stockDataChart.Series["StockValue"].Points.AddXY(stock.Date, Double.Parse(stock.High));
            }
        }
    }
}
