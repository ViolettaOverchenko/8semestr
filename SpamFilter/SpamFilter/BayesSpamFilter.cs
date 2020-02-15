using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpamFilter
{
    class BayesSpamFilter
    {
        private BayesSpamFilter() { }
        private static BayesSpamFilter _instance;
        public static BayesSpamFilter GetInstance()
        {
            if (_instance == null)
            {
                _instance = new BayesSpamFilter();
            }
            return _instance;
        }

        public bool BayesFilter()
        {
            Random rnd = new Random();
            return Convert.ToBoolean(rnd.Next(0, 1));
        }
    }
}
