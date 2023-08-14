using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clientHTTP.Structures
{
    public class Credentials
    {
        public string username { get; set; }
        public string password { get; set; }

        public Credentials(string usernameIn, string passwordIn)
        { 
            username = usernameIn;
            password = passwordIn;
        }
    }
}
