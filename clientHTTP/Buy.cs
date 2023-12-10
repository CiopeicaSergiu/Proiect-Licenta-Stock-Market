using clientHTTP.StocksStructures;
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
    public partial class Buy : Form
    {
        private List<BidAskEntry> _bid;
        private List<BidAskEntry> _ask;
        private DataTable _table;
        private int _selectedRowIndex;
        private HttpClient _httpClient;


        public Buy()
        {
            _selectedRowIndex = 0;
            _bid = new List<BidAskEntry>();
            _ask = new List<BidAskEntry>();
            _table = new DataTable();
           
            _httpClient = HttpClient.getHttpClient();

            setUpTable();
            InitializeComponent();

            _tableBid.DataSource = _table;
        }

        private void setUpTable()
        {
            _table.Columns.Add("Stock Name", typeof(string));// data type int
            _table.Columns.Add("Price", typeof(double));// data type int
            _table.Columns.Add("Quantity", typeof(uint));// data type int
        }

        private void putStockCommand(object sender, EventArgs e)
        {

            _table.Rows.Add(_securityTextBox.Text,
                            Double.Parse(_priceTextBox.Text),
                            uint.Parse(_quantityTextBox.Text));

        }

        private void deleteCommand(object sender, EventArgs e)
        {
            if (_selectedRowIndex== _table.Rows.Count)
            {
                return;
            }

            _table.Rows.RemoveAt(_selectedRowIndex);
        }

        private void clickedCell(object sender, DataGridViewCellEventArgs e)
        {
            _selectedRowIndex = e.RowIndex;
        }
    }

}

