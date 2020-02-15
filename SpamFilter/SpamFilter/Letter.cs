using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace SpamFilter
{
    class Letter: ILetter
    {
        private string sender;
        private string messageSubject;
        private string textLetter;
        private bool categories;    // false - не спам, true - спам
        public void SetLetter(List<string> lines)
        {
            sender = lines[0];
            messageSubject = lines[1];
            textLetter = lines[2];
            categories = false;
        }

        public override void SetCategories(bool b)
        {
            categories = b;
        }

        public override string GetSender()
        {
            return sender;
        }

        public string GetMessageSubject()
        {
            return messageSubject;
        }

        public string GetTextLetter()
        {
            return textLetter;
        }

        public bool GetCategories()
        {
            return categories;
        }

        public override void Display()
        {
            var csv = new StringBuilder();

            var newLine = string.Format("{0},{1},{2},{3}", sender, messageSubject,
                textLetter, categories.ToString());

            csv.AppendLine(newLine);

            File.AppendAllText("letters.csv", csv.ToString());
        }
    }
}
