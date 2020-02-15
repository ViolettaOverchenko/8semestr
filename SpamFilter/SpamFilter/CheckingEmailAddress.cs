using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace SpamFilter
{
    class CheckingEmailAddress:Handler
    {
        public override void HandleRequest(ILetter letter)
        {
            List<string> lines = File.ReadAllLines("badAddress.txt", Encoding.GetEncoding(1251)).ToList();
            foreach(string component in lines)
            {
                if (component == letter.GetSender())
                {
                    letter.SetCategories(true);
                    return;
                }
                    
            }
            if (successor != null)
                successor.HandleRequest(letter);
        }
    }
}
