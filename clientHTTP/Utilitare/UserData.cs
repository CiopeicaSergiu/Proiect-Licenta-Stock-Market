using System;
using System.Collections.Generic;
using System.Drawing.Design;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clientHTTP.Utilitare
{
    public class UserData
    {
        private string _userName;
        private uint _userId;
        static private UserData _userData = null;
        public string UserName { get { return _userName; } }
        public uint UserId { get { return _userId; } }
        private UserData(string userName, uint userId)
        {
            _userName = userName;
            _userId = userId;
        }

        static public void setUserDataOnce(string userName, uint userId)
        {
            if (_userData == null)
            {
                _userData = new UserData(userName, userId);
            }
        }

        static public UserData getUserData()
        {
            return _userData;
        }


    }
}
