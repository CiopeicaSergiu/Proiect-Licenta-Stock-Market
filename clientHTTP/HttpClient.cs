using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace clientHTTP
{
public class HttpClient
{
    private string _rootAdress;

    public HttpClient(string rootAdress)
    {
        _rootAdress = rootAdress;
    }
    public string getStockData(string stockName, string startTime, string endTime)
    {
        var request = WebRequest.Create($"{_rootAdress}{stockName}?startTime={startTime}&endTime={endTime}");
        request.Method = "GET";
        return new StreamReader(request.GetResponse().GetResponseStream()).ReadToEnd();
    }
}
}
