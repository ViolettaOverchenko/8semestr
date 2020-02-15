using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpamFilter
{
    class CheckingEmailText : Handler
    {
        public override void HandleRequest(ILetter letter)
        {
            BayesSpamFilter bayesSpamFilter = BayesSpamFilter.GetInstance();
            if (bayesSpamFilter.BayesFilter())
            {
                letter.SetCategories(true);
                return;
            }
            else if (successor != null)
            {
                successor.HandleRequest(letter);
            }
        }
    }
}

