using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Collections;

namespace SpamFilter
{
    public partial class SpamFilterForms : Form
    {
        public SpamFilterForms()
        {
            InitializeComponent();
        }

        private void SpamFilterForms_Load(object sender, EventArgs e)
        {
            inbox_Click(sender, e);
        }

        private void inbox_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();

            LetterBox letterBox = new LetterBox();
            List<LetterInfo> letters = letterBox.ReaderCsv();
            List<string[]> data = new List<string[]>();

            foreach (LetterInfo letter in letters)
            {
                if (letter.Category == "False")
                {
                    data.Add(new string[3]);

                    data[data.Count - 1][0] = letter.Sender;
                    data[data.Count - 1][1] = letter.Subject;
                    data[data.Count - 1][2] = letter.Text;
                }
            }

            foreach (string[] s in data)
                dataGridView1.Rows.Add(s);
        }

        private void spam_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();

            LetterBox letterBox = new LetterBox();
            List<LetterInfo> letters = letterBox.ReaderCsv();
            List<string[]> data = new List<string[]>();

            foreach (LetterInfo letter in letters)
            {
                if (letter.Category == "True")
                {
                    data.Add(new string[3]);

                    data[data.Count - 1][0] = letter.Sender;
                    data[data.Count - 1][1] = letter.Subject;
                    data[data.Count - 1][2] = letter.Text;
                }
            }

            foreach (string[] s in data)
                dataGridView1.Rows.Add(s);
        }

        private void GetLetters_Click(object sender, EventArgs e)
        {
            Handler h1 = new CheckingEmailAddress();
            Handler h2 = new CheckingEmailSubject();
            Handler h3 = new CheckingEmailText();
            h1.SetSuccessor(h2);
            h2.SetSuccessor(h3);

            List<string> lines = File.ReadAllLines("input.txt", Encoding.GetEncoding(1251)).ToList();
            if (lines.Count > 3)
            {
                CompositeLetter compLet = new CompositeLetter();
                for (int j = 0; j < lines.Count; j += 3)
                {
                    List<string> l = new List<string>();
                    l.Add(lines[j]);
                    l.Add(lines[j + 1]);
                    l.Add(lines[j + 2]);
                    Letter letter = new Letter();
                    letter.SetLetter(l);
                    compLet.Add(letter);
                }

                CompositeLetterIterator i = new CompositeLetterIterator(compLet);
                for (i.First(); !i.IsDone(); i.Next())
                {
                    h1.HandleRequest(i.CurrentItem());
                }
                compLet.Display();
            }
            else
            {
                Letter letter = new Letter();
                letter.SetLetter(lines);
                h1.HandleRequest(letter);
                letter.Display();
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            string _sender = dataGridView1.Rows[e.RowIndex].Cells[0].Value.ToString();
            string _theme = dataGridView1.Rows[e.RowIndex].Cells[1].Value.ToString();
            string _text = dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString();
            MessageBox.Show("ОТПРАВИТЕЛЬ: " + _sender + "\nТЕМА: " + _theme + "\nСОДЕРЖАНИЕ ПИСЬМА:\n" + _text, "Письмо");

        }
    }
}
