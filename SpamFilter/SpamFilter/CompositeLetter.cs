using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpamFilter
{
    class CompositeLetter:ILetter
    {
        private List<ILetter> messages = new List<ILetter>();
        private bool categories = false;
        private string sender = "";
        public override void SetCategories(bool b)
        {
            categories = b;
        }

        public override string GetSender()
        {
            return sender;
        }

        public int GetNumberLetters()
        {
           return messages.Count();
        }

        public ILetter GetCurrentLetter(int n)
        {
            return messages[n];
        }
        public void Add(ILetter component)
        {
            messages.Add(component);
        }

        public void Remove(ILetter component)
        {
            messages.Remove(component);
        }
        public override void Display()
        {
            CompositeLetterIterator i = new CompositeLetterIterator(this);
            for (i.First(); !i.IsDone(); i.Next())
            {
                i.CurrentItem().Display();
            }
        }
        public Iterator CreateIterator()
        {
            return new CompositeLetterIterator(this);
        }
    }
}
