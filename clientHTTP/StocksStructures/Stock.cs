using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clientHTTP.StocksStructures
{
    public class Stock
    {
        public String Date { get; set; }
        public String Open { get; set; }
        public String High { get; set; }
        public String Low { get; set; }
        public String Close { get; set; }
        public String AdjClose { get; set; }
        public String Volume { get; set; }
    }
}
