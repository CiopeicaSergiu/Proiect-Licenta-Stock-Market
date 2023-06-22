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
        private Dictionary<string, string> _settings = new Dictionary<string, string>();

        public Settings(String path)
        {
            readSettingsFromFile(path);
        }

        private void readSettingsFromFile(String path)
        {
            // when exception is happening close everything
            string[] lines = File.ReadAllLines(path);

            foreach (string line in lines)
            { 
                var setting = line.Split('=');
                if (setting.Length ==2) {
                    _settings.Add(setting[0], setting[1]);
                }
            }
        }


        public String getServerAddress()
        {
            if (!_settings.ContainsKey("server"))
            {
                return "";
            }

            return _settings["server"];
        }

        public String getServerPort()
        {
            if (!_settings.ContainsKey("port"))
            {
                return "";
            }

            return _settings["port"];
        }



    }
}
