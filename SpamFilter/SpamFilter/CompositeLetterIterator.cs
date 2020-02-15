using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpamFilter
{
    class CompositeLetterIterator:Iterator
    {
        private readonly CompositeLetter _compLetter;
        private int _current;
        public CompositeLetterIterator(CompositeLetter compLetter)
        {
            this._compLetter = compLetter;
        }
        public override void First()
        {
            _current = 0;
        }
        public override void Next()
        {
            _current++;
        }
        public override ILetter CurrentItem()
        {
            return _compLetter.GetCurrentLetter(_current);
        }
        public override bool IsDone()
        {
            return _current >= _compLetter.GetNumberLetters();
        }
    }
}
