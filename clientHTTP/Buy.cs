using clientHTTP.StocksStructures;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Http;
using System.Net.NetworkInformation;
using System.Runtime.InteropServices.ComTypes;
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
        private DataTable _tableAskPrice;
        private int _selectedRowIndexBid;
        private int _selectedRowIndexAsk;
        private HttpClient _httpClient;


        public Buy()
        {
            _selectedRowIndexBid = 0;
            _table = new DataTable();
            _tableAskPrice = new DataTable();

            _httpClient = HttpClient.getHttpClient();

            setUpTables();
            InitializeComponent();
            setUpPopularOptions();

            _tableBid.DataSource = _table;
            _tableAsk.DataSource = _tableAskPrice;
            initializeBidPrices();
            initializeAskPrices();
        }

        private void initializeBidPrices()
        {
             _bid = _httpClient.getBidPrices();
            foreach (var bidPrice in _bid)
            {
                _table.Rows.Add(bidPrice.stockName, bidPrice.price, bidPrice.quantity);
            }

        }

        private void initializeAskPrices()
        {
            _ask = _httpClient.getAskPrices();
            foreach (var askPrice in _ask)
            {
                _tableAskPrice.Rows.Add(askPrice.stockName, askPrice.price, askPrice.quantity);
            }
        }

        private void setUpTables()
        {
            _table.Columns.Add("Stock Name", typeof(string));// data type int
            _table.Columns.Add("Price", typeof(double));// data type int
            _table.Columns.Add("Quantity", typeof(uint));// data type int

            _tableAskPrice.Columns.Add("Stock Name", typeof(string));// data type int
            _tableAskPrice.Columns.Add("Price", typeof(double));// data type int
            _tableAskPrice.Columns.Add("Quantity", typeof(uint));// data type int
        }

        private void setUpPopularOptions()
        {
            _popularOptions.Items.Add("goog");
        }

        private void putStockCommand(object sender, EventArgs e)
        {

            _table.Rows.Add(_securityTextBox.Text,
                            Double.Parse(_priceTextBox.Text),
                            uint.Parse(_quantityTextBox.Text));

            BidAskEntry bidAskEntry = new BidAskEntry();
            bidAskEntry.price = Double.Parse(_priceTextBox.Text);
            bidAskEntry.quantity = uint.Parse(_quantityTextBox.Text);
            bidAskEntry.stockName = _securityTextBox.Text;
            _bid.Add(bidAskEntry);
            var stockAskPrice = _httpClient.sendBuyRequest(bidAskEntry);

            _tableAskPrice.Rows.Add(stockAskPrice.stockName, stockAskPrice.price, stockAskPrice.quantity);
            _ask.Add(stockAskPrice);

        }

        private void deleteCommand(object sender, EventArgs e)
        {
            if (_selectedRowIndexBid == _table.Rows.Count)
            {
                return;
            }

            _table.Rows.RemoveAt(_selectedRowIndexBid);
            _bid.RemoveAt(_selectedRowIndexBid);
        }

        private void clickedCell(object sender, DataGridViewCellEventArgs e)
        {
            _selectedRowIndexBid = e.RowIndex;
        }

        private void selectPopularOption(object sender, EventArgs e)
        {

            _securityTextBox.Text = (string)_popularOptions.SelectedItem;
        }

        private void matchBidAskEntry(object sender, EventArgs e)
        {
            _httpClient.sendMatchRequest(_bid.ElementAt(_selectedRowIndexBid).id, _ask.ElementAt(_selectedRowIndexAsk).id);
        }

        private void clickedAskTable(object sender, DataGridViewCellEventArgs e)
        {
            _selectedRowIndexAsk = e.RowIndex;
        }
    }

}

