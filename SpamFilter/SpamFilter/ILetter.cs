using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpamFilter
{
    abstract class ILetter
    {
        public abstract void Display();
        public abstract void SetCategories(bool b);
        public abstract string GetSender();
    }
}
