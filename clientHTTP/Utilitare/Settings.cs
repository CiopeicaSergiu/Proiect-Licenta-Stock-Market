using Microsoft.SqlServer.Server;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clientHTTP.Utilitare
{
    public class Settings
    {
        private Dictionary<string, string> _settingsData = new Dictionary<string, string>();
        static private Settings _settings = null;
        private static string _path = "settings.txt";
        private Settings(String path)
        {
            readSettingsFromFile(path);
        }

        public static Settings getSettings()
        {
            if (_settings == null)
            {
                _settings = new Settings(_path);
            }

            return _settings;
        }



        private void readSettingsFromFile(String path)
        {
            // when exception is happening close everything
            string[] lines = File.ReadAllLines(path);

            foreach (string line in lines)
            { 
                var setting = line.Split('=');
                if (setting.Length ==2) {
                    _settingsData.Add(setting[0], setting[1]);
                }
            }
        }


        public String getServerAddress()
        {
            if (!_settingsData.ContainsKey("server"))
            {
                return "";
            }

            return _settingsData["server"];
        }

        public String getServerPort()
        {
            if (!_settingsData.ContainsKey("port"))
            {
                return "";
            }

            return _settingsData["port"];
        }



    }
}
