using CsvHelper;
using CsvHelper.Configuration.Attributes;
using System.Collections;
using System.IO;
using System.Globalization;
using System;
using System.Collections.Generic;

namespace SpamFilter
{
    public interface ICloneable
    {
        object Clone();
    }

    public class LetterInfo : ICloneable
    {
        [Index(0)]
        public string Sender { get; set; }
        [Index(1)]
        public string Subject { get; set; }
        [Index(2)]
        public string Text { get; set; }
        [Index(3)]
        public string Category { get; set; }

        public object Clone()
        {
            return new LetterInfo { 
                Sender = this.Sender, 
                Subject = this.Subject,
                Text = this.Text,
                Category = this.Category
            };
        }
    } 

    class LetterBox
    {
        public List<LetterInfo> ReaderCsv()
        {
            List<LetterInfo> lettersInfo = new List<LetterInfo>();
            string pathCsvFile = "letters.csv";

            using (var streamReader = new StreamReader(pathCsvFile))
            {
                using (var csvReader = new CsvReader(streamReader, CultureInfo.InvariantCulture))
                {
                    // в csv-писем нет заголовка
                    csvReader.Configuration.HasHeaderRecord = false;
                    // указываем используемый разделитель
                    csvReader.Configuration.Delimiter = ",";
                    // получаем строки
                    var letters = csvReader.GetRecords<LetterInfo>();
                    foreach (LetterInfo letter in letters)
                    {
                        lettersInfo.Add((LetterInfo)letter.Clone());
                    }
                }
            }

            return lettersInfo;
        }
    }
}
