using clientHTTP.StocksStructures;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clientHTTP.Utilitare
{
    public class StockConvertor
    {
        public static List<Stock> convertFromHttpResponseToArray(string httpResponse)
        {
            char[] delimitersNewLine = { '\n' };
            var stockDataLines = httpResponse.Split(delimitersNewLine);

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

            return stockData;
        }
    }
}
