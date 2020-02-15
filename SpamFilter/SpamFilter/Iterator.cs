using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpamFilter
{
    abstract class Iterator
    {
        public abstract void First();
        public abstract void Next();
        public abstract bool IsDone();
        public abstract ILetter CurrentItem();
    }
}
