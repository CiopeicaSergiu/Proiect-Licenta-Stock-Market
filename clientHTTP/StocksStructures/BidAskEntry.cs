using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clientHTTP.StocksStructures
{
    public class BidAskEntry
    {
        public string stockName { get; set;}
        public uint quantity { get; set; }
        public double price { get; set; }
    }
}
