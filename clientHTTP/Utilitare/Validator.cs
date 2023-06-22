using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clientHTTP.Utilitare
{
    public class Validator
    {
        static uint referencePoint = 2000;

        public static bool isDateValid(String date)
        {
            if (string.IsNullOrEmpty(date))
            {
                return false;
            }

            var dateComponents = date.Split('.');

            if (dateComponents.Length != 3)
            {
                return false;
            }

            try
            {
                var day = uint.Parse(dateComponents[0]);
                var month = uint.Parse(dateComponents[1]);
                var year = uint.Parse(dateComponents[2]);

                if (year < referencePoint)
                {
                    return false;
                }

                if (month == 0 || month > 12)
                {
                    return false;
                }

                if (
                    day == 0
                    || day >= 31
                    || isLeapYear(year) && month == 2 && day >= 29
                    || month == 2 && day >= 28
                )
                {
                    return false;
                }

                return true;
            }
            catch (FormatException)
            {
                return false;
            }
            catch (OverflowException)
            {
                return false;
            }
        }

        private static bool isLeapYear(uint year)
        {
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            {
                return true;
            }

            return false;
        }
    }
}
