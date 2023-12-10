using clientHTTP.Structures;
using System.IO;
using System.Net;
using System.Net.NetworkInformation;
using System.Text;
using Newtonsoft.Json;
using clientHTTP.Utilitare;
using System.Windows.Forms.DataVisualization.Charting;
using clientHTTP.StocksStructures;

namespace clientHTTP
{
    public class HttpClient
    {
        private string _rootAdress;
        private static HttpClient _httpClient = null;

        public static HttpClient getHttpClient()
        {
            if (_httpClient == null)
            {
                var settings = Settings.getSettings();


                _httpClient = new HttpClient($"http://{settings.getServerAddress()}:{settings.getServerPort()}");


            }

            return _httpClient;
        }
        private HttpClient(string rootAdress)
        {
            _rootAdress = rootAdress;
        }

        private string getRequest(string url)
        {
            var request = WebRequest.Create(url);
            request.Method = "GET";
            return new StreamReader(request.GetResponse().GetResponseStream()).ReadToEnd();
        }

        private string postRequest(string url, string postData)
        {
            var request = WebRequest.Create(url);
            request.ContentType = "application/json; charset=utf-8";
            request.Method = "POST";
            ASCIIEncoding encoding = new ASCIIEncoding();
            byte[] data = encoding.GetBytes(postData);
            request.ContentLength = data.Length;
            Stream newStream = request.GetRequestStream(); //open connection
            newStream.Write(data, 0, data.Length); // Send the data.
            newStream.Close();

            var response = (HttpWebResponse)request.GetResponse();

            return new StreamReader(response.GetResponseStream()).ReadToEnd();
        }

        public string getStockData(string stockName, string startTime, string endTime)
        {
            return getRequest($"{_rootAdress}/{stockName}?startTime={startTime}&endTime={endTime}");
        }

        public string login(Credentials credentials)
        {
            return postRequest($"{_rootAdress}/login", JsonConvert.SerializeObject(credentials));
        }

        public string sendBuyRequest(BidAskEntry bidAskEntry)
        {
            return postRequest($"{_rootAdress}/buy", JsonConvert.SerializeObject(bidAskEntry));
        }


    }
}
