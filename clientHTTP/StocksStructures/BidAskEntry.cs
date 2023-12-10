using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clientHTTP.StocksStructures
{
    public class BidAskEntry
    {
        public string StockName { get; set;}
        public uint Quantity { get; set; }
        public double Price { get; set; }
    }
}
